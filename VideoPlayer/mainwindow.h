#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "videolistdialog.h"
#include "videoplayerdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void sendData(QString);
    void sendPath(QString);
    
private slots:
    void on_BT_new_clicked();

    void on_BT_domestic_clicked();

    void on_BT_western_clicked();

    void on_LB_picA_clicked();

    void on_LB_picB_clicked();

private:
    Ui::MainWindow *ui;
    VideoListDialog *videoListDlg;
    VideoPlayerDialog *videoPlayerDlg;

protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // MAINWINDOW_H
