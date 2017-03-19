#include "myudp.h"

MyUDP::MyUDP(QObject *parent) :
    QObject(parent)
{

    socket = new QUdpSocket(this);
    socket->bind(QHostAddress("127.0.0.1"), 1488);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void MyUDP::readyRead()
{

    QByteArray buf;
    buf.resize(socket->pendingDatagramSize());

    QHostAddress addr;
    quint16 port;

    socket->readDatagram(buf.data(), buf.size(), &addr, &port);
    qDebug() << "Message: " << buf;
}
