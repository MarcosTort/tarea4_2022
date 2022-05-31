/* 5286580 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/pila.h"
typedef TInfo *apuntador;

struct _rep_pila
{
    TInfo *array;
    int tope;
};

TPila crearPila()
{
    TPila nuevo = new _rep_pila;
    nuevo->tope = 0;
    nuevo->array = new TInfo[20];
    return nuevo;
}

bool pilaVacia(TPila p)
{
    return p->tope == 0;
}
void liberarPila(TPila p){
    for (int i = 0; i < p->tope - 1;i++ ){
        apuntador *mem = new apuntador;
        *mem = &p->array[p->tope - 1];
        delete mem;
        
    }
    delete[] p->array;
    delete p;
}

nat cantidadEnPila(TPila p) { return p->tope; }

TPila apilar(TInfo info, TPila p)
{

    p->tope++;
    p->array[p->tope] = copiaInfo(info);

    return p;
}

TInfo cima(TPila p) { return p->array[p->tope]; }

TPila desapilar(TPila p)
{
    if (p->tope > 0)
    {
        apuntador *mem = new apuntador;
        *mem = &p->array[p->tope - 1];

        delete mem;
        p->tope--;
    }
    return p;
}
