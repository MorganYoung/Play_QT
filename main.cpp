#include "mainwindow.h"
#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QStringList>
#include <QtSql>
#include <QSqlDatabase>
#include <QTableView>
#include <QObject>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QSqlDatabase dbconn = QSqlDatabase::addDatabase("QSQLITE");
    dbconn.setDatabaseName("mytest.db");
    if(!dbconn.open())
    {
        qDebug()<<"database couldn't open!!!";
    }
    QSqlQuery query;
    query.exec("create table student(id varchar2(20),name varchar2(20))");
    query.exec(QObject::tr("insert into student values(1,'李刚')"));
    query.exec(QObject::tr("insert into student values(2,'苹果')"));
    query.exec(QObject::tr("insert into student values(3,'葡萄')"));
    query.exec(QObject::tr("insert into student values(3,'李子')"));
    query.exec(QObject::tr("insert into student values(4,’橘子')"));
    query.exec(QObject::tr("insert into student values(5,'核桃')"));
    query.exec(QObject::tr("insert into student values(6,'芒果')"));
    query.exec("select id,name from student where id>=1");
    while(query.next())
    {
        int ele0 = query.value(0).toInt();//query.value(0)是id的值，将其转换为int型
        QString ele1 = query.value(1).toString();
        qDebug()<<ele0<<ele1;//输出两个值
    }
    //query.exec(QObject::tr("drop student"));
    return a.exec();

    /*
    qDebug() << "Available drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
    {
        qDebug() << "\t" << driver;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    qDebug() << "ODBC driver valid?" << db.isValid();
    */
}
