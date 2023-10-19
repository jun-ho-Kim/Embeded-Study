#ifndef TAB4CHARTPLOT_H
#define TAB4CHARTPLOT_H

#include <QWidget>
//#include <QSplineSeries>
#include <QLineSeries>
#include <QChartView>
#include <QDebug>
#include <QDateTimeAxis>
#include <QDate>
#include <QTime>
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class Tab4ChartPlot;
}

class Tab4ChartPlot : public QWidget
{
    Q_OBJECT

public:
    explicit Tab4ChartPlot(QWidget *parent = nullptr);
    ~Tab4ChartPlot();

private:
    Ui::Tab4ChartPlot *ui;
//    QSplineSeries *series;
    QLineSeries* illuLine;
    QLineSeries* tempLine;
    QLineSeries* humiLine;
    QChart *chart = nullptr;
    QChartView *chartView = nullptr;
    QDateTimeAxis * axisX;
    QDateTime firstDate;
    QDateTime lastDate;
private slots:
    void chartPlotAdd();
    void chartPlotClear();
    void slotTab4RecvData(QString);
    void updateLastDateTime(int);
};

#endif // TAB4CHARTPLOT_H
