#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_BT_login_clicked()
{
    accept();

    /*
    if (ui->LE_username->text().trimmed() == tr("user") &&
            ui->LE_password->text() == tr("1234")) {
        accept();
    } else {
        QMessageBox::warning(this, tr("Warning"),
                             tr("user name or password error!"),
                             QMessageBox::Yes);
    }
    */
}
