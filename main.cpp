#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include "myinputpanelcontext.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);

    MyInputPanelContext *ic = new MyInputPanelContext;
    a.setInputContext(ic);
    MainWindow w;
    LoginDialog dlg;

    if (dlg.exec() == QDialog::Accepted) {
        w.show();
        return a.exec();
    } else {
        return 0;
    }
}
