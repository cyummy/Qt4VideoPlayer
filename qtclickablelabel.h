#ifndef QTCLICKABLELABEL_H
#define QTCLICKABLELABEL_H

#include <QLabel>

class QtClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit QtClickableLabel(QWidget *parent = 0);
    explicit QtClickableLabel(const QString &text = "", QWidget *parent = 0);
    ~QtClickableLabel();
    
signals:
    void clicked();
    
public slots:
    
protected:
    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
};

#endif // QTCLICKABLELABEL_H
