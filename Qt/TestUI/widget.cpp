#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pKeyLed = new KeyLed(this);
    connect(ui->pDial, SIGNAL(valueChanged(int)), ui->pLabelLedVal, SLOT(setNum(int)));
    connect(ui->pDial, SIGNAL(valueChanged(int)), pKeyLed, SLOT(writeLedData(int)));
    connect(ui->pDial, SIGNAL(updateKeydataSig(int)), ui->pLabelLedVal, SLOT(writeLedData(int)));
    connect(ui->pDial, SIGNAL(valueChanged(int)), ui->pProgressBar, SLOT(setNum(int)));
    //
    connect(pKeyLed, SIGNAL(updateKeydataSig(int)), ui->pDial, SLOT(setValue(int)));
    connect(pKeyLed, SIGNAL(updateKeydataSig(int)), ui->pLabelKeyVal, SLOT(setNum(int)));
    //connect(pKeyLed, SIGNAL(updateKeyDataSig(int)), ui->pProgressBar, SLOT(setValue((int)int/100)));

    //connect(ui->pDial, SIGNAL(valueChnage(int)), ui->pProgressBar, SLOT(setNum(int)));


}
//TODO:SetProgressBar




Widget::~Widget()
{
    delete ui;
}

