#ifndef TAB2SOCKETCLIENT_H
#define TAB2SOCKETCLIENT_H

#include <QWidget>
#include <QTime>
#include "socketclient.h"

namespace Ui {
class Tab2SocketClient;
}

class Tab2SocketClient : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2SocketClient(QWidget *parent = nullptr);
    ~Tab2SocketClient();
    SocketClient * pSocketClient;
private:
    Ui::Tab2SocketClient *ui;
//    SocketClient * pSocketClient;

signals:
    void ledWriteSig(int);
    void tab3RecvDataSig(QString);
    void tab4RecvDataSig(QString);
    void tab5RecvDataSig(QString);

private slots:
    void connetToServerSlot(bool);
    void socketRecvUpdateSlot(QString);
    void socketSendDataSlot();
    void slotConnectServer();
    void slotClosedByServer();
};

#endif // TAB2SOCKETCLIENT_H
