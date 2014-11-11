
#include "MyClient.h"

MyClient::MyClient(const QString& strHost, int nPort) : m_nNextBlockSize(0)
{
    m_pTcpSocket = new QTcpSocket(this);

    m_pTcpSocket = new QTcpSocket(this);

    m_pTcpSocket->connectToHost(strHost, nPort);
    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            SLOT(slotError(QAbstractSocket::SocketError)));


}

void MyClient::slotReadyRead()
{
    QDataStream in(m_pTcpSocket);
   in.setVersion(QDataStream::Qt_5_2);
    for(;;) {
        if (!m_nNextBlockSize) {
            if (m_pTcpSocket->bytesAvailable() < sizeof(quint16))
                break;
            in >> m_nNextBlockSize;
            if(m_pTcpSocket->bytesAvailable() < m_nNextBlockSize)
                break;
            QString str;
            in >> str;
            qDebug() << str;
            m_nNextBlockSize=0;
        }
    }
}

void MyClient::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
            "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                             "The host was not found." :
                             err == QAbstractSocket::RemoteHostClosedError ?
                             "The remote host is closed." :
                             err == QAbstractSocket::ConnectionRefusedError ?
                             "The connection was refused." :
                                     QString(m_pTcpSocket->errorString())

                             );
    qDebug() << strError;
}

void MyClient::sendToServer(const QString &str)
{
    QByteArray arrBlock;
       QDataStream out(&arrBlock, QIODevice::WriteOnly);
       out.setVersion(QDataStream::Qt_5_2);
       out << quint16(0) << str;

       out.device()->seek(0);
       out << quint16(arrBlock.size() - sizeof(quint16));

       m_pTcpSocket->write(arrBlock);
}

void MyClient::slotConnected()
{
    sendToServer("hello, server");
}
