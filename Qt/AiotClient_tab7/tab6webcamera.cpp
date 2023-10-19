#include "tab6webcamera.h"
#include "ui_tab6webcamera.h"

Tab6WebCamera::Tab6WebCamera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab6WebCamera)
{
    ui->setupUi(this);
    pQProcess = new QProcess(this);
    pWebCamView = new QWebEngineView(this);
    pWebCamView->load(QUrl(QStringLiteral("http://10.10.14.199:8080/?action=stream")));
    ui->pGPCamView->setLayout(pWebCamView->layout());
    connect(ui->pPBCamStart, SIGNAL(clicked(bool)), this, SLOT(camStartSlot(bool)));

}
void Tab6WebCamera::camStartSlot(bool bCheck)
{
    QString program = "/home/ubuntu/openCV/examples/mjpg-streamer-master/mjpg-streamer-experimental/mjpg_streamer -i \"/home/ubuntu/openCV/examples/mjpg-streamer-master/mjpg-streamer-experimental/input_uvc.so\" -o \"/home/ubuntu/openCV/examples/mjpg-streamer-master/mjpg-streamer-experimental/output_http.so -w ./www\"";

    if(bCheck)
    {
          pQProcess->start(program);
          if(pQProcess->waitForStarted())
          {
            QThread::msleep(500);
            pWebCamView->load(QUrl(QStringLiteral("http://10.10.14.199:8080/?action=stream")));
            qDebug() << "start" ;
            ui->pPBCamStart->setText("CamStop");
          }
    }
    else
    {
          pWebCamView->stop();
          pQProcess->kill();
          qDebug() << "stop" ;
          ui->pPBCamStart->setText("CamStart");
    }
}
Tab6WebCamera::~Tab6WebCamera()
{
    delete ui;
}
