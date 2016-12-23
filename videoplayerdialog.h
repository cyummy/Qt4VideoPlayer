#ifndef VIDEOPLAYERDIALOG_H
#define VIDEOPLAYERDIALOG_H

#include <QDialog>
#include <phonon/MediaSource>
#include <phonon/VideoPlayer>

namespace Ui {
class VideoPlayerDialog;
}

class VideoPlayerDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit VideoPlayerDialog(QWidget *parent = 0);
    ~VideoPlayerDialog();
    
private slots:
    void on_BT_back_clicked();

    void on_BT_play_clicked();

    void init_player(QString);

    void on_BT_full_clicked();

private:
    Ui::VideoPlayerDialog *ui;
    int width, heigh;

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void keyPressEvent(QKeyEvent *);
};

#endif // VIDEOPLAYERDIALOG_H
