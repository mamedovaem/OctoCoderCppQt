#ifndef MYSERVER_H
#define MYSERVER_H

#include <QtNetwork/QtNetwork>
class QTcpServer;
class QTcpSocket;

class MyServer : public QObject {
Q_OBJECT
private:
    QTcpServer* m_ptcpServer;
    quint16 m_nNextBlockSize;
private:
    void sendToClient(QTcpSocket* pSocket, const QString& str);

public:
    MyServer(int nPort);

public slots:
    virtual void slotNewConnection();
    void slotReadClient();

};

#endif // MYSERVER_H
