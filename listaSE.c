#ifndef LISTASE_H_INCLUDED
    #include "listaSE.h"
#endif

//Inicia a lista
ListaSE inicListaSE()
{
    ListaSE lst;
    lst = (ListaSE) malloc(sizeof(struct TListaSE));
    lst -> longitude = 0;
    lst -> iterador = NULL;
    lst -> primeiro = NULL;
    lst -> ultimo = NULL;
    return lst;
}

//3 casos: ListaSE vazia, iterador sobre o ultimo elemento, iterador sobre um elemento intermediario
void anxListaSE( ListaSE lst, InfoRodovia elem )
{
    if(lst->iterador == NULL && lst->longitude > 0)
    {
        printf("\n erro: iterador indefinido e ListaSE cheia \n");

    }
    else
    {
        pListaNoSE novoNo = ( pListaNoSE )malloc( sizeof( struct ListaNoSE ) );
        novoNo->info = elem; // atribuir o elemento a ser armazenado
        novoNo->prox= NULL;  // atribuir NULL para deixar o novoNo preparado

        if (lst->longitude == 0)  // ListaSE vazia
        {
            //apontar para o novoNo
            lst->primeiro = novoNo;
            lst->ultimo = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
        else if (lst->iterador == lst->ultimo )  // iterador sobre o ultimo elemento
        {
            lst->iterador->prox = novoNo;
            lst->ultimo = novoNo;
            lst->iterador = novoNo;
            //incrementar a quantidade de nos
            lst->longitude++;
        }
        else  //iterador sobre um noh intermediario
        {
            novoNo->prox = lst->iterador->prox;
            lst->iterador->prox = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }

    }

}

void insListaSE( ListaSE lst, InfoRodovia elem )
{

    if(lst->iterador == NULL && lst->longitude > 0)
    {
        printf("\n erro: iterador indefinido e ListaSE cheia \n");

    }
    else
    {

        //alocar memória para o novoNo a ser adicionado
        pListaNoSE novoNo = ( pListaNoSE )malloc( sizeof( struct ListaNoSE ) );
        novoNo->info = elem; // atribuir o elemento a ser armazenado
        novoNo->prox= NULL;  // atribuir NULL para deixar o novoNo preparado

        if (lst->longitude == 0)  // ListaSE vazia
        {
            //apontar para o novoNo
            lst->primeiro = novoNo;
            lst->ultimo = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
        else if ( lst->iterador == lst->primeiro)  // iterador sobre o primeiro elemento
        {
            //novoNo->prox = lst->iterador;
            novoNo->prox = lst->primeiro;
            lst->primeiro = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
        else  //iterador sobre qualquer outro noh
        {
            //usar um segundo iterador para percorrer a ListaSE e parar uma posicao antes do iterador
            pListaNoSE p;
            for(p = lst->primeiro; p->prox != lst->iterador ; p = p->prox )
            {

            }
            //ao sair do for, p esta um noh antes do iterador
            //acertar os ponteiros
            novoNo->prox = lst->iterador;
            p->prox = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }

    }

}

void primListaSE(ListaSE lst)
{
    //por o iterador sobre o primeiro No da ListaSE
    lst->iterador = lst->primeiro;
}

void ultListaSE(ListaSE lst){
    //por o iterador sobre o ultimo No da ListaSE
    lst->iterador = lst->ultimo;
}

int fimListaSE(ListaSE lst)
{

    return (lst->iterador == NULL);

}

void segListaSE(ListaSE lst)
{

    if(lst->iterador == NULL)
    {
        printf("\n erro: iterador indefindio \n");
    }
    else
    {
        lst->iterador = lst->iterador->prox;
    }
}

InfoRodovia infoListaSE(ListaSE lst)
{
    if(lst->iterador == NULL)
    {
        printf("\n erro: iterador indefinido \n");
    }
    else
        return lst->iterador->info;
}

char* infoListaSEC(ListaSE lst)
{
    if(lst->iterador == NULL)
    {
        printf("\n erro: iterador indefinido \n");
    }
    else
        return lst->iterador->info2;
}

int longListaSE(ListaSE lst)
{
    return lst->longitude;
}

void elimListaSE( ListaSE lst )
{

    if(lst->iterador != NULL)
    {

        pListaNoSE noAserDesalocado;
        if (lst->iterador == lst->primeiro)  // se o iterador estiver sobre o primeiro elemento
        {
            if (lst->longitude == 1){

                noAserDesalocado = lst->iterador;
                lst->iterador = NULL;
                lst->primeiro = NULL;
                lst->ultimo = NULL;
                lst->longitude--;
                free(noAserDesalocado);

            }
            else{

                noAserDesalocado = lst->iterador;
                lst->iterador = lst->iterador->prox;
                lst->primeiro = lst->iterador;
                lst->longitude--;
                free(noAserDesalocado);
            }
        }
        else  // iterador esta sobre qualquer outro no que nao o primeiro no
        {
            //iterador sobre no intermediario ou o ultimo no
            pListaNoSE p;
            for(p = lst->primeiro; p->prox != lst->iterador; p = p->prox)
            {
            }
            noAserDesalocado = lst->iterador;
            p->prox = lst->iterador->prox;

            if( lst->iterador == lst->ultimo) // se o iterador estiver sobre o utlimo no
                lst->ultimo = p;

            lst->iterador = lst->iterador->prox;
            free(noAserDesalocado);
            lst->longitude--;
        }
    }
    else
    {
        printf("\n erro: iterador indefinido \n");
    }
}

void printListaSE(ListaSE lst)
{
    for(primListaSE(lst); !fimListaSE(lst); segListaSE(lst))
    {
            printf("%s", lst->iterador->info);
    }
}
