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

    QPixmap iconA(pathA + ".jpg");
    QPixmap iconB(pathB + ".jpg");
    QPixmap iconC(pathC + ".jpg");

    ui->BT_picA->setIcon(iconA);
    ui->BT_picA->setIconSize(iconA.size());
    ui->BT_picB->setIcon(iconB);
    ui->BT_picB->setIconSize(iconB.size());
    ui->BT_picC->setIcon(iconC);
    ui->BT_picC->setIconSize(iconC.size());
}

void VideoListDialog::on_BT_picA_clicked()
{
    emit sendPath(pathA + ".wmv");
    this->hide();
    videoPlayerDlg->show();
    videoPlayerDlg->exec();
    this->show();
}

void VideoListDialog::on_BT_picB_clicked()
{
    emit sendPath(pathB + ".wmv");
    this->hide();
    videoPlayerDlg->show();
    videoPlayerDlg->exec();
    this->show();
}

void VideoListDialog::on_BT_picC_clicked()
{
    emit sendPath(pathC + ".wmv");
    this->hide();
    videoPlayerDlg->show();
    videoPlayerDlg->exec();
    this->show();
}
