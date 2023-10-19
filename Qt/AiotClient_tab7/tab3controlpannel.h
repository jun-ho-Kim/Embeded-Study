#ifndef TAB3CONTROLPANNEL_H
#define TAB3CONTROLPANNEL_H

#include <QWidget>
#include <QPalette>

namespace Ui {
class Tab3ControlPannel;
}

class Tab3ControlPannel : public QWidget
{
    Q_OBJECT

public:
    explicit Tab3ControlPannel(QWidget *parent = nullptr);
    ~Tab3ControlPannel();

private:
    Ui::Tab3ControlPannel *ui;
    QPalette paletteColorOn;
    QPalette paletteColorOff;

signals:
    void socketSendDataSig(QString);

private slots:
    void lampOnOffSlot(bool);
    void plugOnOffSlot(bool);
    void tab3RecvDataSlot(QString);
};

#endif // TAB3CONTROLPANNEL_H
