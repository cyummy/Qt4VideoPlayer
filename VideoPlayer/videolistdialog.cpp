#include "videolistdialog.h"
#include "ui_videolistdialog.h"

VideoListDialog::VideoListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoListDialog)
{
    ui->setupUi(this);

    videoPlayerDlg = new VideoPlayerDialog(this);
    connect(this, SIGNAL(sendPath(QString)), videoPlayerDlg, SLOT(init_player(QString)));
}

VideoListDialog::~VideoListDialog()
{
    delete ui;
}

void VideoListDialog::on_BT_back_clicked()
{
    this->close();
}

void VideoListDialog::showData(QString str)
{
    if (str == "最新热映") {
        ui->LB_name->setText(QString("最新热映"));
        pathA = "../resource/bcsd";
        pathB = "../resource/mghxd";
        pathC = "../resource/sqdwznl";
    } else if (str == "国产大片") {
        ui->LB_name->setText("国产大片");
        pathA = "../resource/beqs";
        pathB = "../resource/mghxd";
        pathC = "../resource/xms";
    } else if (str == "欧美大片") {
        ui->LB_name->setText("欧美大片");
        pathA = "../resource/bcsd";
        pathB = "../resource/sljz";
        pathC = "../resource/sqdwznl";
    }

    QImage image;
    image.load(pathA + ".jpg");
    ui->LB_picA->setPixmap(QPixmap::fromImage(image));
    ui->LB_picA->resize(QSize(image.width(), image.height()));
    image.load(pathB + ".jpg");
    ui->LB_picB->setPixmap(QPixmap::fromImage(image));
    ui->LB_picB->resize(QSize(image.width(), image.height()));
    image.load(pathC + ".jpg");
    ui->LB_picC->setPixmap(QPixmap::fromImage(image));
    ui->LB_picC->resize(QSize(image.width(), image.height()));
}

void VideoListDialog::on_LB_picA_clicked()
{
    emit sendPath(pathA + ".wmv");
    this->hide();
    videoPlayerDlg->show();
    videoPlayerDlg->exec();
    this->show();
}

void VideoListDialog::on_LB_picB_clicked()
{
    emit sendPath(pathB + ".wmv");
    this->hide();
    videoPlayerDlg->show();
    videoPlayerDlg->exec();
    this->show();
}

void VideoListDialog::on_LB_picC_clicked()
{
    emit sendPath(pathC + ".wmv");
    this->hide();
    videoPlayerDlg->show();
    videoPlayerDlg->exec();
    this->show();
}
