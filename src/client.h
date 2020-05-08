#ifndef CLIENT_H

#define CLIENT_H

#include <string>
#include <memory>
#include<QApplication>

#include<QObject>

#include<QNetworkAccessManager>

#include<QNetworkRequest>

#include<QNetworkReply>

#include<QDebug>

#include<QJsonObject>

#include<QJsonDocument>

#include<iostream>

using namespace std;



struct User {

    int postId;

    int id;

    string name;

    string username;


    User(int postId, int id, string name, string username):

        postId(postId), id(id), name(name), username(username) {}

};



class Client: QObject {

Q_OBJECT

private:

    QNetworkAccessManager* networkManager;

    void blockUntilReplyReceived(QNetworkReply* reply) {

        QEventLoop loop;

        connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));

        loop.exec();

    }

    unique_ptr<User> parseJson(QNetworkReply& reply) {

        QString strReply = (QString) reply.readAll();

        QJsonDocument doc = QJsonDocument::fromJson(strReply.toUtf8());

        QJsonObject jsonObject = doc.object();



        int postId = jsonObject.value("postId").toInt();

        int id = jsonObject.value("id").toInt();

        string name = jsonObject.value("name").toString().toStdString();

        string username = jsonObject.value("username").toString().toStdString();

        unique_ptr<User> user = make_unique<User>(postId, id, name, username);

        return user;

    }

public:

    explicit Client(QObject *parent = nullptr) {

        networkManager = new QNetworkAccessManager(this);

        connect(networkManager, SIGNAL(finished(QNetworkReply*)), this,

          SLOT(onResult(QNetworkReply*)));

    }

    ~Client() {

        delete networkManager;

    }

    unique_ptr<User> request(int postId) {

        QNetworkRequest request;

        QNetworkReply* reply;



        request.setUrl(QUrl("http://jsonplaceholder.typicode.com/users/" // this will fail as it is an incorrect url

            + QString::number(postId)));

        reply = networkManager->get(request);

        blockUntilReplyReceived(reply);



        if (reply->error() != QNetworkReply::NoError) {

           qDebug() << reply->errorString();
           throw "Could not connect to server, see the above error.";
           //the throw might seem redundant cause of the qDebug but it stops the program from crashing

            return nullptr;

        }

        return parseJson(*reply);

    }

signals:

public slots:

    void onResult(QNetworkReply* reply) {

    }

};



#endif // CLIENT_H
