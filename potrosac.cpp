#include "potrosac.h"
#include "common.h"

Potrosac::Potrosac(QObject *parent): QThread(parent)
{

}


void Potrosac::run()
{
    QMutex mutex;
    for(int i=0; i<DataSize; ++i){
        mutex.lock();
        iskoristeniBajti.acquire();
        fprintf(stderr,"%c", buffer[i%BufferSize]);
        slobodniBajti.release();
        this->msleep(3000);
        emit promjenaNapunjenihBuffera(iskoristeniBajti.available());
        emit promjenaPotrosenih(i);
        mutex.unlock();
    }
    fprintf(stderr,"\n");
}
