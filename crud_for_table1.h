#ifndef CRUD_FOR_TABLE1_H
#define CRUD_FOR_TABLE1_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QModelIndexList>
#include <QSqlIndex>
#include <QSqlField>
#include <iostream>

class crud_for_table1 : public QObject
{
    Q_OBJECT

private:

    int maxIdValue();
    int lastId = 0;

public:
    explicit crud_for_table1(QObject *parent = nullptr);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    void createUserTable();

signals:

public slots:
    void connectDB();
    void insertUserData_1(QString fName, QString lName, int age, QString userName, QString password, QString city);
    void updateUserData_1(int u_id, QString updatedFname, QString updatedLname, int updatedAge,
                                            QString updatedUserName, QString updatedPassword, int updatedCityID);
    void readFromTable_1();
};

#endif // CRUD_FOR_TABLE1_H
