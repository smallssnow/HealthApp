#include "mainapp.h"
#include "ui_mainapp.h"

#include <QProcess>
#include <QLocalSocket>

MainApp::MainApp(QWidget *parent): QMainWindow(parent), ui(new Ui::MainApp)
{
    ui->setupUi(this);
    m_QProcess = new QProcess(parent);


    //QLocalSocket *socket;
    //server = new QLocalServer(this);

    m_localSocket = new QLocalSocket(this);
}

MainApp::~MainApp()
{
    delete ui;
}


void MainApp::on_m_RunApp_clicked()
{
    m_QProcess->start("F:/temp/HealthApp/Tools/Test/TestHttpClient/release/TestHttpClient.exe");
}

void MainApp::on_m_SendData_clicked()
{
    if (m_QProcess)
    {
        QString message;
        message = "MainApp";
        //m_QProcess->connect("");
        m_QProcess->write(message.toLocal8Bit());
    }
}
void  MainApp::connectImageApp()
{
    m_localSocket->connectToServer(ImageAppName);
    if(m_localSocket->waitForConnected(1000)){
        //setOutputText("Connected");
        //qDebug() << "Connect to " + serverName + " succeed.";
    }else{
        //setOutputText("Connect failed");
        //qDebug() << "Connect to " + serverName + " failed";
    }
}
void  MainApp::sendToImageAppMsg()
{

}
void  MainApp::disconnectImageApp()
{

}
void  MainApp::ReadImageApp()
{

}
void  MainApp::connectImageAppCrash()
{

}

