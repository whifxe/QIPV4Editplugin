#include "edit.h"
#include <QDebug>
Edit::Edit(QWidget *parent) :
    QLineEdit(parent),sel(false)
{
    QValidator *val=new QIntValidator(0,255,this);
    setValidator(val);
}
void Edit::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton&&!sel){
        selectAll();
        sel=true;
        return;
    }
    else if(event->button()==Qt::LeftButton&&sel){
        setCursorPosition(cursorPosition());
        sel=false;
        return;
    }
    QLineEdit::mousePressEvent(event);
}
void Edit::keyPressEvent(QKeyEvent *event){
    if(selectionStart()==0&&event->key()==Qt::Key_0){
        emit Losefocus();
        setText("0");
        return;
    }
    else if(selectionStart()==-1&&text()=="0"){//0| backspace
        if(event->key()==16777219){
            clear();
            return;
        }
        emit Losefocus();
        return;
    }
    if(event->key()==46){// .
        emit Losefocus();
        return;
    }
    QLineEdit::keyPressEvent(event);
    if(text().toInt()>25)
        emit Losefocus();
}
void Edit::focusOutEvent(QFocusEvent *event){
    emit focusout();
    QLineEdit::focusOutEvent(event);
}
void Edit::focusSet(){
    setFocus();
    selectAll();
}
