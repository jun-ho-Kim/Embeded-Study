#include "tab2socketclient.h"
#include "ui_tab2socketclient.h"

Tab2SocketClient::Tab2SocketClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab2SocketClient)
{
    ui->setupUi(this);
    pSocketClient= new SocketClient(this);
    connect(ui->pPBServerConnect,SIGNAL(clicked(bool)),this,SLOT(connetToServerSlot(bool)));
    connect(pSocketClient, SIGNAL(sigSocketRecv(QString)),this, SLOT(socketRecvUpdateSlot(QString)));
}

void Tab2SocketClient::connetToServerSlot(bool bCheck)
{
    bool bOk;
    if(bCheck)
    {
        pSocketClient->slotConnectToServer(bOk);
        if(bOk) {
            ui->pPBServerConnect->setText("서버 해제");
        }
    }
    else
    {
        ui->pPBServerConnect->setText("서버 연결");
        pSocketClient->slotClosedByServer();
    }
}

void Tab2SocketClient::socketRecvUpdateSlot(QString strRecvData)
{
    ui->pTErecvData->append(strRecvData);
}

Tab2SocketClient::~Tab2SocketClient()
{
    delete ui;
}
