#include "tab5database.h"
#include "ui_tab5database.h"

Tab5DataBase::Tab5DataBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab5DataBase)
{
    ui->setupUi(this);
    sqlDb = QSqlDatabase::addDatabase("QSQLITE");
    sqlDb.setDatabaseName("temp.db");
    if(sqlDb.open()){
        qDebug() << "success DB connection\n";
    }
    else{
        qDebug() << "fail DB connection\n";
    }
    QString query = "CREATE TABLE temp_db ("
            "id integer primary key,"
            "date DATETIME,"
            "illu VARCHAR(10),"
            "temp VARCHAR(10),"
            "humi VARCHAR(10))" ;
    QSqlQuery qry;
    if(!qry.exec(query))
    {
//         qDebug() << "error creating table\n";
    } else
         qDebug() << "create table\n";

    connect(ui->pPBsearchDb,SIGNAL(clicked()),this,SLOT(slotSearchDb()));
    connect(ui->pPBdeleteDb,SIGNAL(clicked()),this,SLOT(slotDeleteDb()));
}
void Tab5DataBase::slotSearchDb() {
    QSqlQuery query;
    QDateTime from_datetime = ui->pDateTimeEditFrom->dateTime();
    QString from_str = from_datetime.toString("yy/MM/dd hh:mm:ss");
    QDateTime to_datetime = ui->pDateTimeEditTo->dateTime();
    QString to_str = to_datetime.toString("yy/MM/dd hh:mm:ss");
    QString temp, date_time;

    int row_count = 0;

//    ui->tableWidget->clear();
    ui->tableWidget->clearContents();
    if(query.exec("select * from temp_db where date>'" + from_str + "' AND date<'" + to_str + "'")){
//        qDebug() << query.lastQuery();
        while(query.next()){
            row_count++;
            ui->tableWidget->setRowCount(row_count);
            QTableWidgetItem *id = new QTableWidgetItem();
            QTableWidgetItem *date = new QTableWidgetItem();
            QTableWidgetItem *illu = new QTableWidgetItem();
            QTableWidgetItem *temp = new QTableWidgetItem();
            QTableWidgetItem *humi = new QTableWidgetItem();
            id->setText(query.value("id").toString());
            date->setText(query.value("date").toString());
            illu->setText(query.value("illu").toString());
            temp->setText(query.value("temp").toString());
            humi->setText(query.value("humi").toString());
//           qDebug() << "id " << id->text() << " illu " << illu->text() << " date " << date->text();
           ui->tableWidget->setItem(row_count-1, 0, id);
           ui->tableWidget->setItem(row_count-1, 1, date);
           ui->tableWidget->setItem(row_count-1, 2, illu);
           ui->tableWidget->setItem(row_count-1, 3, temp);
           ui->tableWidget->setItem(row_count-1, 4, humi);
        }
        ui->tableWidget->resizeColumnToContents(1);
    }
}
void Tab5DataBase::slotDeleteDb() {
    QSqlQuery query;
    QDateTime from_datetime = ui->pDateTimeEditFrom->dateTime();
    QString from_str = from_datetime.toString("yy/MM/dd hh:mm:ss");
    QDateTime to_datetime = ui->pDateTimeEditTo->dateTime();
    QString to_str = to_datetime.toString("yy/MM/dd hh:mm:ss");
    QString temp, date_time;
    if(query.exec("delete from temp_db where date>'" + from_str + "' AND date<'" + to_str + "'")){
    }
}

void Tab5DataBase::slotTab5RecvData(QString recvData)
{
    QDateTime dateTime = QDateTime::currentDateTime();
//    QDate date = QDate::currentDate();
    QSqlQuery query;

    QStringList qlist = recvData.split("@");
    QString illu = qlist[3];        //조도
    QString temp = qlist[4];        //온도
    QString humi = qlist[5];        //습도

    if(query.exec("insert into temp_db(date, illu, temp, humi) values('" + dateTime.toString("yy/MM/dd hh:mm:ss") +"' , '" + illu +"' , '" +  temp + "' , '" + humi +  "')")){
 //         qDebug() << query.lastQuery();
    }
    else {
  //        qDebug() << query.lastError().text();
    }
}
Tab5DataBase::~Tab5DataBase()
{
    delete ui;
}
