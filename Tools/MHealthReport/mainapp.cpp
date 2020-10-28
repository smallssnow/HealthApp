#include "mainapp.h"
#include "ui_mainapp.h"

#include <QProcess>

MainApp::MainApp(QWidget *parent): QMainWindow(parent), ui(new Ui::MainApp)
{
    ui->setupUi(this);
    m_QProcess = new QProcess(parent);

}

MainApp::~MainApp()
{
    delete ui;
}


void MainApp::on_m_RunApp_clicked()
{
    m_QProcess->start("E:\\Tool\\pacs工具\\Starviewer\\starviewer.exe");
}

void MainApp::on_m_SendData_clicked()
{
    if (m_QProcess)
    {
        QString message;
        message = "MainApp";
        m_QProcess->write(message.toLocal8Bit());
    }
}
