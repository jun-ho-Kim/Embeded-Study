#include "tab1devcontrol.h"
#include "ui_tab1devcontrol.h"

Tab1DevControl::Tab1DevControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab1DevControl)
{
    ui->setupUi(this);
    pKeyled = new KeyLed(this);
    connect(ui->pDialLed, SIGNAL(valueChanged(int)), pKeyled, SLOT(writeLedData(int)));

    //connect(ui->pDialLed, SIGNAL(valueChanged(int)), ui->pProgressBarLed, SLOT(setValue(int)));
    //위 코드를 사용자 정의 slot 함수로 변경해서 호출
    connect(ui->pDialLed, SIGNAL(valueChanged(int)), this, SLOT(progressBarSetSlot(int)));
    connect(ui->pDialLed, SIGNAL(valueChanged(int)), ui->pLcdNumberLed, SLOT(display(int)));


    //connect(pKeyled, SIGNAL(updateKeydataSig(int)), ui->pLcdNumberKey, SLOT(display(int)));
    //위 코드를 사용자 정의 slot 함수로 변경해서 호출
    connect(pKeyled, SIGNAL(updateKeydataSig(int)), this, SLOT(keyCheckBoxSlot(int)));

}

void Tab1DevControl::progressBarSetSlot(int ledVal)
{
    ledVal = int(ledVal / 255.0 * 100);
    ui->pProgressBarLed->setValue(ledVal);
}

void Tab1DevControl::keyCheckBoxSlot(int keyNo)
{
    static int lcdData;
    lcdData ^= (0x01 << (keyNo-1));
    ui->pLcdNumberKey->display(lcdData);

    //
    QCheckBox * pQCheckBoxArray[8] = {ui->pCBkey1, ui->pCBkey2, ui->pCBkey3, ui->pCBkey4, ui->pCBkey5, ui->pCBkey6, ui->pCBkey7, ui->pCBkey8};
    for(int i=0;i<8;i++)
    {
        if(keyNo == i+1)
        {
            //check box 눌려있는지 검사
            if(pQCheckBoxArray[i]->isChecked())         //눌려있는 경우
                pQCheckBoxArray[i]->setChecked(false);  //false로 해제
            else                                        //안 눌려있는 경우
                pQCheckBoxArray[i]->setChecked(true);   //true 로 체크
        }
    }


}

Tab1DevControl::~Tab1DevControl()
{
    delete ui;
}
