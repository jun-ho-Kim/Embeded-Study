#include "tab3controlpannel.h"
#include "ui_tab3controlpannel.h"

Tab3ControlPannel::Tab3ControlPannel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab3ControlPannel)
{
    ui->setupUi(this);
    connect(ui->pPBLamp,SIGNAL(clicked(bool)),this, SLOT(lampOnOffSlot(bool)));
    connect(ui->pPBPlug,SIGNAL(clicked(bool)),this, SLOT(plugOnOffSlot(bool)));
}

void Tab3ControlPannel::lampOnOffSlot(bool bCheck)
{
    if(bCheck)
    {
        emit socketSendDataSig("[HM_CON]GASON");
        ui->pPBLamp->setChecked(false);
    }
    else
    {
        emit socketSendDataSig("[HM_CON]GASOFF");
        ui->pPBLamp->setChecked(true);
    }

}
void Tab3ControlPannel::plugOnOffSlot(bool)
{

}
void Tab3ControlPannel::tab3RecvDataSlot(QString recvData)
{
    QStringList qList = recvData.split("@");
    if(qList[2] == "GASON")
    {
        ui->pPBLamp->setChecked(true);
    }
    else if(qList[2] == "GASOFF")
    {
        ui->pPBLamp->setChecked(false);
    }

}
Tab3ControlPannel::~Tab3ControlPannel()
{
    delete ui;
}
