#ifndef POTROSAC_H
#define POTROSAC_H
#include <QThread>
#include <QMutex>


class Potrosac : public QThread
{
    Q_OBJECT
public:
    explicit Potrosac(QObject *parent=0);
    void run();
signals:
    void promjenaNapunjenihBuffera(int);
    void promjenaPotrosenih(int);
private:

};

#endif // POTROSAC_H
