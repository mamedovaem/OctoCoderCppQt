#include "MyServer.h"

MyServer::MyServer(int nPort) : m_nNextBlockSize(0)
{
    m_ptcpServer = new QTcpServer(this);
    if (!m_ptcpServer->listen(QHostAddress::Any, nPort)) {
        qDebug() << "Server Error: Unable to start the Server: " + m_ptcpServer->errorString();
    m_ptcpServer->close();
    return;
    }
    connect(m_ptcpServer, SIGNAL(newConnection()),
            this, SLOT(slotNewConnection())
           );
}

void MyServer::slotNewConnection()
{
    QTcpSocket* pClientSocket = m_ptcpServer->nextPendingConnection();
    connect(pClientSocket, SIGNAL(disconnected()),
            pClientSocket, SLOT(deleteLater())
            );
    connect(pClientSocket, SIGNAL(readyRead()),
            this, SLOT(slotReadClient())
            );
 //   sendToClient(pClientSocket, "Server Response: Connected!");
}

void MyServer::slotReadClient()
{
    QTcpSocket* pClientSocket = (QTcpSocket*) sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_5_2);
    for(;;) {
        if (!m_nNextBlockSize) {
        if (pClientSocket->bytesAvailable() < sizeof (quint16))
            break;
        in >> m_nNextBlockSize;
    }

    if (pClientSocket->bytesAvailable() < m_nNextBlockSize)
        break;
    QString str;
    in >> str;

    qDebug() << str;

    m_nNextBlockSize = 0;

    sendToClient(pClientSocket, "hello, client");

    }
}

void MyServer::sendToClient(QTcpSocket* pSocket, const QString& str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);
    out << quint16(0) << str;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    pSocket->write(arrBlock);
}
