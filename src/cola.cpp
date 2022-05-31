/* 5286580 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cola.h"
struct celda
{
    TInfo info;
    celda *sig;
};
struct _rep_cola
{
    celda *frente;
    celda *final;
};

TCola crearCola()
{
    TCola nueva = new _rep_cola;
    nueva->frente = NULL;
    nueva->final = NULL;
    return nueva;
}

void liberarCola(TCola c)
{
    celda *aux = c->frente;
    while (aux != NULL)
    {
        celda *aux2 = aux;
        aux = aux->sig;
        delete aux2;
    }
    delete c;
}

nat cantidadEnCola(TCola c)
{
    celda *aux = c->frente;
    int cont = 0;
    while (aux != NULL)
    {
        aux = aux->sig;
        cont++;
    }
    return cont;
}

TCola encolar(TInfo info, TCola c)
{
    celda *nueva = new celda;
    nueva->info = copiaInfo(info);
    nueva->sig = NULL;
    if (c->final == NULL)
    {
        c->frente = nueva;
        c->final = nueva;
    }
    else
    {
        c->final->sig = nueva;
        c->final = nueva;
    }
    return c;
}

TInfo frente(TCola c)
{
    return c->frente->info;
}

bool estaVaciaColaBinarios(TCola c)
{
    return c->frente == NULL;
}
TCola desencolar(TCola c)
{
    celda *aux = c->frente;
    if (!estaVaciaColaBinarios(c))
    {
        c->frente = c->frente->sig;
        if (aux->sig == NULL)
            c->final = NULL;
    }
    aux->sig = NULL;

    delete aux;
    return c;
}
