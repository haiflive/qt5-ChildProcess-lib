#ifndef CHILDPROCESS_H
#define CHILDPROCESS_H

/**
  * source code example:
  * https://stackoverflow.com/questions/32593463/spawn-async-qprocess-from-dynamic-library-peek-output-until-done
  *
  * make dll file:
  * https://wiki.qt.io/How_to_create_a_library_with_Qt_and_use_it_in_an_application
**/

#include <QtCore/qglobal.h>
#include <QObject>
#include <QProcess>

#if defined(CHILDPROCESS_LIBRARY)
#  define CHILDPROCESSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CHILDPROCESSSHARED_EXPORT Q_DECL_IMPORT
#endif

class CHILDPROCESSSHARED_EXPORT ChildProcess : public QObject
{
    Q_OBJECT
public:
    ChildProcess(const QString &p_Command, QObject *p_Parent = nullptr);
    QString getCommand() const;

signals:
    void readyRead(QByteArray);

public slots:
    void runCommand(const QString &p_Command);
    void runCommand();
    void setCommand(const QString &p_Command);

private slots:
    void out();
    void processFinished(int p_Code);

private:
    QString command;
};

#endif // CHILDPROCESS_H
