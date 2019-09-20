#ifndef LISTASE_H_INCLUDED
#define LISTASE_H_INCLUDED
#define MAX 100

#include "listaDE.h"

typedef struct TinfoRodovia{
    char rodovia[MAX];
    ListaDE cidades;
} InfoRodovia;

typedef struct ListaNoSE
{
    InfoRodovia info;
    char info2[MAX];
    struct ListaNoSE *prox;
} *pListaNoSE;

typedef struct TListaSE
{
    pListaNoSE primeiro, ultimo, iterador;
    int longitude;
} * ListaSE;

ListaSE inicListaSE();

void primListaSE(ListaSE lst);

void ultListaSE(ListaSE lst);

void posListaSE(ListaSE lst, int pos);

int fimListaSE(ListaSE lst);

void segListaSE(ListaSE lst);

InfoRodovia infoListaSE(ListaSE lst);

int longListaSE(ListaSE lst);

void anxListaSE( ListaSE lst, InfoRodovia elem );

void insListaSE( ListaSE lst, InfoRodovia elem );

void elimListaSE( ListaSE lst );


#endif // LISTASE_H_INCLUDED
