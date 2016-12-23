#include "qtclickablelabel.h"
#include <QKeyEvent>

QtClickableLabel::QtClickableLabel(const QString &text, QWidget *parent)
    :QLabel(parent)
{
    this->setText(text);
}

QtClickableLabel::QtClickableLabel(QWidget *parent) :
    QLabel(parent)
{
}

QtClickableLabel::~QtClickableLabel()
{

}

void QtClickableLabel::mousePressEvent(QMouseEvent *)
{
    emit clicked();
}

void QtClickableLabel::keyPressEvent(QKeyEvent *e)
{
    // For test
    if (e->key() == Qt::Key_Enter) {
        emit clicked();
    }
    QLabel::keyPressEvent(e);
}
