#include "tab3controlpannel.h"
#include "ui_tab3controlpannel.h"

Tab3ControlPannel::Tab3ControlPannel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab3ControlPannel)
{
    ui->setupUi(this);
    paletteColorOn.setColor(ui->pPBLamp->backgroundRole(),QColor(255,0,0));
    paletteColorOff.setColor(ui->pPBLamp->backgroundRole(),QColor(0,0,255));;
    ui->pPBLamp->setPalette(paletteColorOff);
    ui->pPBPlug->setPalette(paletteColorOff);
    connect(ui->pPBLamp,SIGNAL(clicked(bool)),this, SLOT(lampOnOffSlot(bool)));
    connect(ui->pPBPlug,SIGNAL(clicked(bool)),this, SLOT(plugOnOffSlot(bool)));
}

void Tab3ControlPannel::lampOnOffSlot(bool bCheck)
{
    if(bCheck)
    {
        emit socketSendDataSig("[KSH_QT]LAMPON");
        ui->pPBLamp->setChecked(false);
    }
    else
    {
        emit socketSendDataSig("[KSH_QT]LAMPOFF");
        ui->pPBLamp->setChecked(true);
    }

}
void Tab3ControlPannel::plugOnOffSlot(bool bCheck)
{
    if(bCheck)
    {
//        emit socketSendDataSig("[KSH_QT]PLUGON");
        emit socketSendDataSig("[HM_CON]GASON");
        ui->pPBPlug->setChecked(false);
    }
    else
    {
//        emit socketSendDataSig("[KSH_QT]PLUGOFF");
        emit socketSendDataSig("[HM_CON]GASOFF");
        ui->pPBPlug->setChecked(true);
    }
}
void Tab3ControlPannel::tab3RecvDataSlot(QString recvData)
{
    QIcon buttonIcon;
    QStringList qList = recvData.split("@");
    if(qList[2] == "LAMPON")
    {
        ui->pPBLamp->setChecked(true);
        ui->pPBLamp->setPalette(paletteColorOn);
        buttonIcon.addFile(":/Images/Image/light_on.png");
        ui->pPBLamp->setIcon(buttonIcon);
    }
    else if(qList[2] == "LAMPOFF")
    {
        ui->pPBLamp->setChecked(false);
        ui->pPBLamp->setPalette(paletteColorOff);
        buttonIcon.addFile(":/Images/Image/light_off.png");
        ui->pPBLamp->setIcon(buttonIcon);
    }
//    else if(qList[2] == "PLUGON")
    else if(qList[2] == "GASON")
    {
        ui->pPBPlug->setChecked(true);
        ui->pPBPlug->setPalette(paletteColorOn);
        buttonIcon.addFile(":/Images/Image/plug_on.png");
        ui->pPBPlug->setIcon(buttonIcon);
    }
//    else if(qList[2] == "PLUGOFF")
    else if(qList[2] == "GASOFF")
    {
        ui->pPBPlug->setChecked(false);
        ui->pPBPlug->setPalette(paletteColorOff);
        buttonIcon.addFile(":/Images/Image/plug_off.png");
        ui->pPBPlug->setIcon(buttonIcon);
    }
}
Tab3ControlPannel::~Tab3ControlPannel()
{
    delete ui;
}
