#include "crud_for_table1.h"

crud_for_table1::crud_for_table1(QObject *parent) : QObject(parent){}

void crud_for_table1::connectDB()
{
    qDebug() << "Sql Driver" << QSqlDatabase::drivers();
    qDebug() << db.isDriverAvailable("QPSQL");

    db.setHostName("127.0.0.1"); //default
    db.setDatabaseName("postgres"); //default
    db.setUserName("user_1"); //specified with CREATE USER user_1;
    db.setPassword("123"); // specified with; WITH PASSWORD '123';
    db.setPort(5432); //default

    if(!db.open())
    {
        qDebug() << "Connection Failed!";
        qDebug() << db.lastError();
    }
    else
    {
        qDebug() << "Success!";
    }
}

void crud_for_table1::createUserTable()
{
    QSqlQuery query;
    query.exec("CREATE TABLE user_parameters "
                      "(id integer primary key, "
                      "firstname varchar(50), "
                      "lastname varchar(50), "
                      "age integer, "
                      "username varchar(50), "
                      "password varchar(100), "
                      "city_id varchar(5) references city(id))");

    qDebug()<<query.lastError();
}


void crud_for_table1::insertUserData_1(QString fName, QString lName, int age, QString userName, QString password, QString city)
{
    QSqlQuery insertQuery;
    int last_id = maxIdValue() + 1;

    insertQuery.prepare("INSERT INTO user_parameters (id, firstname, lastname, age, username, password, city_id)"
                        "VALUES(:id, :firstname, :lastname, :age, :username, :password, :cityID)");

    insertQuery.bindValue(":id", last_id);
    insertQuery.bindValue(":firstname", fName);
    insertQuery.bindValue(":lastname", lName);
    insertQuery.bindValue(":age", age);
    insertQuery.bindValue(":username", userName);
    insertQuery.bindValue(":password", password);
    insertQuery.bindValue(":cityID", city);

    if(insertQuery.exec())
    {
        qDebug() << "ADDED";
    }
    else
    {
        qDebug() << "NOT ADDED";
        qDebug() << db.lastError() << "\n";
        qDebug() << insertQuery.lastError() << "\n";
    }
}

//void crud_for_table1::updateUserData_1(QString updatedFname, QString updatedLname, int updatedAge,
//                                       QString updatedUserName, QString updatedPassword, int updatedCityID, int u_id)
//{
//    QSqlQuery updateQuery(db);
//    updateQuery.prepare("UPDATE user_parameters SET firstname=:fName, lastname=:lName, age=:uAge, "
//                        "username=:uName, password=:pw, cityID=:c_id WHERE id=:uId;");

//    updateQuery.bindValue(":fName", updatedFname);
//    updateQuery.bindValue(":lName", updatedLname);
//    updateQuery.bindValue(":uAge", updatedAge);
//    updateQuery.bindValue(":uName", updatedUserName);
//    updateQuery.bindValue(":pw", updatedPassword);
//    updateQuery.bindValue(":c_id", updatedCityID);
//    updateQuery.bindValue(":uId", u_id);

//    updateQuery.addBindValue(updatedFname);
//    updateQuery.addBindValue(updatedLname);
//    updateQuery.addBindValue(updatedAge);
//    updateQuery.addBindValue(updatedUserName);
//    updateQuery.addBindValue(updatedPassword);
//    updateQuery.addBindValue(updatedCityID);
//    updateQuery.addBindValue(u_id);

//    if (updateQuery.exec())
//    {
//        qDebug() << "id: " << u_id << " UPDATED!";
//    }
//    else
//    {
//        qDebug() << "id: " << u_id << " NOT UPDATED!";
//        qDebug() << db.lastError();
//        qDebug() << updateQuery.lastError();
//    }
//}

void crud_for_table1::updateUserData_1(int u_id, QString updatedFname, QString updatedLname, int updatedAge,
                                       QString updatedUserName, QString updatedPassword, int updatedCityID)
{
    QSqlQuery updateQuery(db);
    updateQuery.prepare("UPDATE user_parameters SET firstname=:fName, lastname=:lName, age=:uAge, "
                        "username=:uUname, password=:uPassword, city_id=:cityId WHERE id=:ID");



    updateQuery.addBindValue(updatedFname);
    updateQuery.addBindValue(updatedLname);
    updateQuery.addBindValue(updatedAge);
    updateQuery.addBindValue(updatedUserName);
    updateQuery.addBindValue(updatedPassword);
    updateQuery.addBindValue(updatedCityID);
    updateQuery.addBindValue(u_id);

    if (updateQuery.exec())
    {
        qDebug() << "id: " << u_id << " UPDATED!";
    }
    else
    {
        qDebug() << "id: " << u_id << " NOT UPDATED!";
        qDebug() << db.lastError();
        qDebug() << updateQuery.lastError();
    }
}

void crud_for_table1::readFromTable_1()
{
    QSqlQuery readQuery(db);

    if(!readQuery.exec("SELECT firstname, cityName FROM user_parameters JOIN city ON city.id = user_parameters.city_id"))
    {
        qDebug() << readQuery.lastError().text();
    }
    else
    {
        readQuery.first();
        do
        {
            qDebug() << "-------------------------------";

            qDebug() << "name: " << readQuery.value("firstname").toString();
            qDebug() << "city: " << readQuery.value("cityName").toString();

        } while(readQuery.next());

        qDebug() << "-------------------------------";
    }
}

int crud_for_table1::maxIdValue()
{
    QSqlQuery maxIdQuery(db);

    if(!maxIdQuery.exec("SELECT id FROM user_parameters"))
    {
        qDebug() << maxIdQuery.lastError().text();
    }
    else
    {
        maxIdQuery.first();
        do
        {
            if(maxIdQuery.value("id").toInt() > lastId) {
                lastId = maxIdQuery.value("id").toInt();
            }

        } while(maxIdQuery.next());

    }
    return lastId;
}
