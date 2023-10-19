#include "tab2socketclient.h"
#include "ui_tab2socketclient.h"

Tab2SocketClient::Tab2SocketClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab2SocketClient)
{
    ui->setupUi(this);
    ui->pPBsendButton->setEnabled(false);
    pSocketClient= new SocketClient(this);
    connect(ui->pPBServerConnect,SIGNAL(clicked(bool)),this,SLOT(connetToServerSlot(bool)));
    connect(pSocketClient, SIGNAL(sigSocketRecv(QString)),this, SLOT(socketRecvUpdateSlot(QString)));
    connect(ui->pPBsendButton,SIGNAL(clicked()),this,SLOT(socketSendDataSlot()));
    connect(ui->pPBRecvDataClear, SIGNAL(clicked()),ui->pTErecvData,SLOT(clear()));
    connect(pSocketClient->getpQTcpSocket(),SIGNAL(disconnected()),this,SLOT(slotClosedByServer()));
    connect(pSocketClient->getpQTcpSocket(),SIGNAL(connected()),this,SLOT(slotConnectServer()));
}

void Tab2SocketClient::connetToServerSlot(bool bCheck)
{
    bool bOk;
    if(bCheck)
    {
        pSocketClient->slotConnectToServer(bOk);
        if(bOk) {
//            ui->pPBServerConnect->setText("서버 해제");
//            ui->pPBsendButton->setEnabled(true);

        }
        ui->pPBServerConnect->setChecked(false);
    }
    else
    {
        pSocketClient->slotClosedByServer();
        ui->pPBServerConnect->setText("서버 연결");
        ui->pPBsendButton->setEnabled(false);
    }
}

void Tab2SocketClient::socketRecvUpdateSlot(QString strRecvData)
{
    QTime time = QTime::currentTime();
    QString strTime = time.toString();
    strRecvData.chop(1);   //'\n' 문자 제거

    strTime = strTime + " " + strRecvData;
    ui->pTErecvData->append(strTime);
    ui->pTErecvData->moveCursor(QTextCursor::End);

    strRecvData.replace("[","@");
    strRecvData.replace("]","@");
    QStringList qlist = strRecvData.split("@");

    if(strRecvData.indexOf("LED") != -1 )
    {
        bool bOk;
        int ledNo = qlist[3].toInt(&bOk,16); //x000~0xff
        if(bOk)
            emit ledWriteSig(ledNo);
    }
    else if((strRecvData.indexOf("LAMP") != -1 ) || (strRecvData.indexOf("PLUG") != -1 ) || (strRecvData.indexOf("GAS") != -1 ))
    {
        emit tab3RecvDataSig(strRecvData);
    }
    else if(strRecvData.indexOf("SENSOR") != -1 )
    {
        emit tab4RecvDataSig(strRecvData);
        emit tab5RecvDataSig(strRecvData);
    }
}

void Tab2SocketClient::socketSendDataSlot()
{
    QString strRecvId;
    QString strSendData;
    strRecvId = ui->pLErecvId->text();
    strSendData = ui->pLEsendData->text();
    if(!strSendData.isEmpty())
    {
        if(strRecvId.isEmpty())
            strSendData = "[ALLMSG]" + strSendData;
        else
            strSendData = "["+strRecvId+"]" + strSendData;

        pSocketClient->slotSocketSendData(strSendData);
        ui->pLEsendData->clear();
    }
}

void Tab2SocketClient::slotConnectServer()
{
    ui->pPBServerConnect->setChecked(true);
    ui->pPBServerConnect->setText("서버 해제");
    ui->pPBsendButton->setEnabled(true);
}
void Tab2SocketClient::slotClosedByServer()
{
    ui->pPBServerConnect->setChecked(false);
    ui->pPBServerConnect->setText("서버 연결");
    ui->pPBsendButton->setEnabled(false);
}
Tab2SocketClient::~Tab2SocketClient()
{
    delete ui;
}
