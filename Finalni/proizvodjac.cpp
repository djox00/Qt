#include "proizvodjac.h"
#include "common.h"
#include <QDebug>
Proizvodjac::Proizvodjac(QObject *parent):QThread(parent)
{

}


void Proizvodjac::run()
{
    QMutex mutex;
    for(int i=0; i<DataSize; ++i){
        mutex.lock();
        char c;
        int n;
        n = qrand()%26;
        c = 'A'+n;
        slobodniBajti.acquire();
        buffer[i%BufferSize]=c;
        emit sendslovo(c);
        iskoristeniBajti.release();
        this->msleep(3000);
        emit promjenaNapunjenihBuffera(iskoristeniBajti.available());
        emit promjenaProizvedenih(i);
        mutex.unlock();



    }
}
