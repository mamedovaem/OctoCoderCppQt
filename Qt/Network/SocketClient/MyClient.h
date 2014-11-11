#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QtCore>
#include <QTcpSocket>

class MyClient : public QObject {
    Q_OBJECT
private:
    QTcpSocket* m_pTcpSocket;
    quint16 m_nNextBlockSize;

private:
    void sendToServer(const QString& str);

public:
    MyClient(const QString& strHost, int nPort);

private slots:
    void slotReadyRead();
    void slotError (QAbstractSocket::SocketError);
    void slotConnected();
};
















#endif // MYCLIENT_H
