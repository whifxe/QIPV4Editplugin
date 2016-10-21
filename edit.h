#ifndef EDIT_H
#define EDIT_H

#include <QLineEdit>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QIntValidator>
class Edit : public QLineEdit
{
    Q_OBJECT
public:
    explicit Edit(QWidget *parent = 0);
signals:
    void Losefocus();
    void focusout();
public slots:
    void focusSet();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
private:
    bool sel;
};

#endif // EDIT_H
