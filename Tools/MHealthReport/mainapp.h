#ifndef MAINAPP_H
#define MAINAPP_H

#include <QMainWindow>


#define ImageAppName  "StarViewer"


class QProcess;
class QLocalServer;
class QLocalSocket;

QT_BEGIN_NAMESPACE
namespace Ui { class MainApp; }
QT_END_NAMESPACE

class MainApp : public QMainWindow
{
    Q_OBJECT

public:
    MainApp(QWidget *parent = nullptr);
    ~MainApp();

public slots:
    void connectImageApp();
    void sendToImageAppMsg();
    void disconnectImageApp();
    void ReadImageApp();
    void connectImageAppCrash();

private slots:
    void on_m_RunApp_clicked();

    void on_m_SendData_clicked();

private:
    QProcess *m_QProcess;
    QLocalServer *m_ocalServer;
    QLocalSocket *m_localSocket;

private:
    Ui::MainApp *ui;
};
#endif // MAINAPP_H
