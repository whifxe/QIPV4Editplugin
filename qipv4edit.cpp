#include "qipv4edit.h"
#include <QDebug>
QIPV4Edit::QIPV4Edit(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(180,30);
    setMaximumSize(180,30);
    for(int i=0;i<4;++i){
        QString tmp("edit");
        tmp+=QString::number(i,10);
        ipedit[i]=new Edit(this);
        ipedit[i]->setObjectName(tmp);
        ipedit[i]->setAlignment(Qt::AlignRight);
        ipedit[i]->setFixedWidth(36);
        ipedit[i]->setText("0");
        connect(ipedit[i],SIGNAL(focusout()),this,SLOT(statuschange()));
    }
    QHBoxLayout *layout=new QHBoxLayout;
    for(int i=0;i<3;++i){
        point[i]=new QLabel(".",this);
        point[i]->setMinimumSize(2,20);
        point[i]->setMaximumSize(2,20);
        layout->addWidget(ipedit[i]);
        layout->addWidget(point[i]);
        connect(ipedit[i],SIGNAL(Losefocus()),ipedit[i+1],SLOT(focusSet()));
    }
    layout->addWidget(ipedit[3]);
    setLayout(layout);
}
void QIPV4Edit::statuschange(){
    for(int i=0;i<4;++i){
        if(ipedit[i]->text()=="")
            ipedit[i]->setText("0");
    }
}
QString QIPV4Edit::IPV4valueS(){
    QString ret;
    for(int i=0;i<3;++i){
        ret+=ipedit[i]->text();
        ret+=".";
    }
    ret+=ipedit[3]->text();
    return ret;
}
int QIPV4Edit::IPV4valueI(){
    QByteArray tmp=IPV4valueS().toLatin1();
    char *ip=tmp.data();
    return inet_addr(ip);
}
