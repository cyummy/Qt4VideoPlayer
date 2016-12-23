#include "videoplayerdialog.h"
#include "ui_videoplayerdialog.h"
#include <QKeyEvent>

VideoPlayerDialog::VideoPlayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoPlayerDialog)
{
    ui->setupUi(this);
    ui->videoPlayer->installEventFilter(this);

    width = ui->videoPlayer->width();
    heigh = ui->videoPlayer->height();
}

VideoPlayerDialog::~VideoPlayerDialog()
{
    delete ui;
}

void VideoPlayerDialog::on_BT_back_clicked()
{
    ui->videoPlayer->stop();
    ui->BT_play->setText("play");
    this->close();
}

void VideoPlayerDialog::on_BT_play_clicked()
{
    if (ui->BT_play->text() == "play") {
        ui->videoPlayer->play();
        ui->BT_play->setText("pause");
    } else if (ui->BT_play->text() == "pause") {
        ui->videoPlayer->pause();
        ui->BT_play->setText("play");
    }
}

void VideoPlayerDialog::init_player(QString path)
{
    ui->videoPlayer->load(Phonon::MediaSource(path));
}

void VideoPlayerDialog::on_BT_full_clicked()
{
    ui->videoPlayer->setWindowFlags(Qt::Window);
    ui->videoPlayer->showFullScreen();
}

bool VideoPlayerDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        if(obj==ui->videoPlayer)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if(keyEvent->key() == Qt::Key_Escape){
                ui->videoPlayer->setWindowFlags(Qt::SubWindow);
                ui->videoPlayer->showNormal();
                ui->videoPlayer->resize(width, heigh);
            }
        }
    }
    return QObject::eventFilter(obj, event);
}

void VideoPlayerDialog::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Escape:
        break;
    default:
        QDialog::keyPressEvent(event);
    }
}
