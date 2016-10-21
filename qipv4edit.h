#ifndef QIPV4EDIT_H
#define QIPV4EDIT_H

#include <QWidget>
#include <edit.h>
#include <QEvent>
#include <QLabel>
#include <QHBoxLayout>
#include <arpa/inet.h>
class QIPV4Edit : public QWidget
{
    Q_OBJECT
private:
    Edit* ipedit[4];
    QLabel* point[3];
public:
    explicit QIPV4Edit(QWidget *parent = 0);
    QString IPV4valueS();
    int IPV4valueI();
protected:
    //void resizeEvent(QResizeEvent *event);
signals:

public slots:
    void statuschange();
};

#endif // QIPEDIT_H
