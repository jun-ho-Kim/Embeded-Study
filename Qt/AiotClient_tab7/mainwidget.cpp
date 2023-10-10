#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->pTabWidget->setCurrentIndex(2);
    pTab1DevControl = new Tab1DevControl(ui->pTab1);
    ui->pTab1->setLayout(pTab1DevControl->layout());
    pTab2SocketClient = new Tab2SocketClient(ui->pTab2);
    ui->pTab2->setLayout(pTab2SocketClient->layout());
    pTab3ControlPannel = new Tab3ControlPannel(ui->pTab3);
    ui->pTab3->setLayout(pTab3ControlPannel->layout());
    pTab4ChartPlot = new Tab4ChartPlot(ui->pTab4);
    ui->pTab4->setLayout(pTab4ChartPlot->layout());
    pTab5DataBase = new Tab5DataBase(ui->pTab5);
    ui->pTab5->setLayout(pTab5DataBase->layout());
    pTab6WebCamera = new Tab6WebCamera(ui->pTab6);
    ui->pTab6->setLayout(pTab6WebCamera->layout());
    pTab7CamSecurity = new Tab7CamSecurity(ui->pTab7);
    ui->pTab7->setLayout(pTab7CamSecurity->layout());

    connect(pTab2SocketClient,SIGNAL(ledWriteSig(int)),pTab1DevControl->getpQDial(),SLOT(setValue(int)));
    connect(pTab3ControlPannel, SIGNAL(socketSendDataSig(QString)),pTab2SocketClient->pSocketClient,SLOT(slotSocketSendData(QString)));
    connect(pTab2SocketClient, SIGNAL(tab3RecvDataSig(QString)), pTab3ControlPannel, SLOT(tab3RecvDataSlot(QString)));
    connect(pTab2SocketClient, SIGNAL(tab4RecvDataSig(QString)),pTab4ChartPlot, SLOT(slotTab4RecvData(QString)));
    connect(pTab2SocketClient, SIGNAL(tab5RecvDataSig(QString)),pTab5DataBase, SLOT(slotTab5RecvData(QString)));

    connect(pTab7CamSecurity->pGetCameracapture(),SIGNAL(sigSocketSendData(QString)),pTab2SocketClient->pSocketClient,SLOT(slotSocketSendData(QString)));
}

MainWidget::~MainWidget()
{
    delete ui;
}
