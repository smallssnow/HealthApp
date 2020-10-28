#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>

class QNetworkAccessManager;
class QNetworkReply;
class QFile;
class QNetworkReply;
class HttpClient;
class QTableWidgetItem;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void updateStudyImageTable();
public:
    QUrl m_httpurl;

public slots:
    void on_m_getHttpData_clicked();
    void getItem(int row, int col);
    void readFromServer(int fd);

private slots:
    void on_m_getStudyImages_clicked();
    void on_m_tableWidget_cellClicked(int row, int column);

private:
    QFile *m_file;
    HttpClient *m_httpclient;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
