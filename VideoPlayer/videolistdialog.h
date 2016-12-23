#ifndef VIDEOLISTDIALOG_H
#define VIDEOLISTDIALOG_H

#include <QDialog>
#include "videoplayerdialog.h"

namespace Ui {
class VideoListDialog;
}

class VideoListDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit VideoListDialog(QWidget *parent = 0);
    ~VideoListDialog();
    
signals:
    void sendPath(QString);

private slots:
    void on_BT_back_clicked();

    void showData(QString);

    void on_LB_picA_clicked();
    void on_LB_picB_clicked();
    void on_LB_picC_clicked();

private:
    Ui::VideoListDialog *ui;
    VideoPlayerDialog *videoPlayerDlg;

    QString pathA, pathB, pathC;
};

#endif // VIDEOLISTDIALOG_H
