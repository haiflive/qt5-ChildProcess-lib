#include "childprocess.h"

ChildProcess::ChildProcess(const QString &p_Command, QObject *p_Parent)
    : QObject(p_Parent)
{
    command = p_Command;
}

void ChildProcess::runCommand(const QString &p_Command) {
    command = p_Command;
    runCommand();
}

void ChildProcess::runCommand() {
    QProcess *console = new QProcess(this);
    console->connect(console, SIGNAL(readyRead()),
        this, SLOT(out()));
    console->connect(console, SIGNAL(finished(int)),
        this, SLOT(processFinished(int)));
    console->start(command);
}

void ChildProcess::out() {
    QProcess *console = qobject_cast<QProcess*>(QObject::sender());
    QByteArray processOutput = console->readAll();
    emit readyRead(processOutput);
}

void ChildProcess::processFinished(int p_Code) {
    QProcess *console = qobject_cast<QProcess*>(QObject::sender());
    QByteArray processOutput = console->readAll()
        + QString("Finished with code %1").arg(p_Code).toLatin1();
    emit readyRead(processOutput);
}

QString ChildProcess::getCommand() const {
    return command;
}

void ChildProcess::setCommand(const QString &p_Command) {
    command = p_Command;
}
