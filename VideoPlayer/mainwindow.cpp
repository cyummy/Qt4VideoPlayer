#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videolistdialog.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->BT_new->installEventFilter(this);
    ui->BT_domestic->installEventFilter(this);
    ui->BT_western->installEventFilter(this);
    ui->LB_picA->installEventFilter(this);
    ui->LB_picB->installEventFilter(this);

    QImage imageA, imageB;
    imageA.load("../resource/mghxd.jpg");
    imageB.load("../resource/sqdwznl.jpg");

    ui->LB_picA->setPixmap(QPixmap::fromImage(imageA));
    ui->LB_picA->resize(QSize(imageA.width(), imageA.height()));
    ui->LB_picB->setPixmap(QPixmap::fromImage(imageB));
    ui->LB_picB->resize(QSize(imageB.width(), imageB.height()));

    videoListDlg = new VideoListDialog(this);
    connect(this, SIGNAL(sendData(QString)), videoListDlg, SLOT(showData(QString)));

    videoPlayerDlg = new VideoPlayerDialog(this);
    connect(this, SIGNAL(sendPath(QString)), videoPlayerDlg, SLOT(init_player(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BT_new_clicked()
{
    emit sendData(ui->BT_new->text());
    this->hide();
    videoListDlg->show();
    videoListDlg->exec();
    this->show();
}

void MainWindow::on_BT_domestic_clicked()
{
    emit sendData(ui->BT_domestic->text());
    this->hide();
    videoListDlg->show();
    videoListDlg->exec();
    this->show();
}

void MainWindow::on_BT_western_clicked()
{
    emit sendData(ui->BT_western->text());
    this->hide();
    videoListDlg->show();
    videoListDlg->exec();
    this->show();
}

void MainWindow::on_LB_picA_clicked()
{
    emit sendPath("../resource/mghxd.wmv");
    this->hide();
    videoPlayerDlg->show();
    videoPlayerDlg->exec();
    this->show();
}

void MainWindow::on_LB_picB_clicked()
{
    emit sendPath("../resource/sqdwznl.wmv");
    this->hide();
    videoPlayerDlg->show();
    videoPlayerDlg->exec();
    this->show();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Space) {
            return true;
        }
    } else {
        return false;
    }
    return QObject::eventFilter(obj, event);
}
