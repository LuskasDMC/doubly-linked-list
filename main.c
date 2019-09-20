#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSE.c"
#include "listaDE.c"

ListaSE LerDados(char* nomeArquivoRodovia, char* nomeArquivoCidades)
{
    ListaSE lstRodovias = inicListaSE();
    int i;
    char CR, CC; // CR = char Rodovia | CC = char Cidade
    char auxiliar[MAX];
    FILE *arquivoRodovia;
    arquivoRodovia = fopen(nomeArquivoRodovia, "r");
    if(arquivoRodovia == 0)
    {
        printf("Falha ao abrir o arquivo de Rodovias\n");
        fclose(arquivoRodovia);
    }
    else
    {
        int j;
        FILE* arquivoCidade;
        arquivoCidade = fopen(nomeArquivoCidades, "r");
        if(arquivoCidade == 0)
        {
            printf("Falha ao abrir o arquivo de Rodovias\n");
            fclose(arquivoCidade);
        }
        else
        {
            i = 0;
            do
            {
                CR = getc(arquivoRodovia);
                if(CR != '\n' && CR != EOF)
                {
                    auxiliar[i] = CR;
                    i++;
                }
                else
                {
                    auxiliar[i] = '\0';
                    if(auxiliar[0] != '\0')
                    {
                        printf("[ %s ]\n", auxiliar); // Printa a rodovia //

                        // Cria o info rodovia e adiciona a rodovia no no a tual
                        InfoRodovia infoRodovia;
                        infoRodovia.cidades = inicListaDE();
                        strcpy(infoRodovia.rodovia, auxiliar);
                        anxListaSE(lstRodovias, infoRodovia);
                        ultListaSE(lstRodovias);
                        strcpy(infoListaSEC(lstRodovias), infoRodovia.rodovia);


                        //Anexar as cidades na rodovia
                        ListaDE lstCidades = infoRodovia.cidades;
                        j = 0;

                        do
                        {
                            CC = getc(arquivoCidade);
                            if(CC != '\n' && CC != EOF && CC != ' ')
                            {
                                auxiliar[j] = CC;
                                j++;
                            }
                            else
                            {
                                auxiliar[j] = '\0';

                                if(auxiliar[0] != '\0')
                                {
                                    printf("- % s \n", auxiliar); //Printa a cidade

                                    //Anexa a cidade e deixa o iterador no ultimo elemento
                                    anxListaDE(lstCidades, auxiliar);
                                    ultListaDE(lstCidades);
                                }

                                j = 0;
                            }
                        }while(CC != '\n' && CC != EOF); //cidaddes
                    }
                    printf("\n---------------------\n\n");
                    i = 0;
                }
            }while(CR != EOF); //rodovias

            //Fecha a lista de cidade e rodovias
            fclose(arquivoRodovia);
            fclose(arquivoCidade);
        }
    }
    return lstRodovias;
}

void rodoviasCidade(char nomeCidade[100], ListaSE lstRodovia)
{
    int i=0;

    printf("\nA cidade de %s passa pelas rodovias: ", nomeCidade);
    printf("(");
    for(primListaSE(lstRodovia); !fimListaSE(lstRodovia); segListaSE(lstRodovia))
    {
        for(primListaDE(infoListaSE(lstRodovia).cidades); !fimListaDE(infoListaSE(lstRodovia).cidades); segListaDE(infoListaSE(lstRodovia).cidades)){

            TipoL elemDE;
            strcpy(elemDE, infoListaDE(infoListaSE(lstRodovia).cidades));

            if(strcmp(nomeCidade, elemDE) == 0)
            {
                    printf("- %s -", infoListaSEC(lstRodovia));
                    i = 1;
            }
        }
    }
    if( i == 0)
    {
        printf(" nao foi encontrada nenhuma rodovia que passa por essa cidade ");
    }
    printf(")");
}


int main()
{
    char aux[MAX];
    int op = 1;

    printf(">>>>>>>>>>>>DADOS CARREGADOS<<<<<<<<<<<<<<\n\n");
    ListaSE lstRodovia = LerDados("listaRodovias.txt", "listaCidades.txt");

    do{
        printf("\n--Buscar por uma cidade: ");
        scanf("%s", aux);

        //printListaSE(lstRodovia);

        rodoviasCidade(aux, lstRodovia);
        //printf("%s", aux);

        printf("\n\nPara finalizar digite 0 - Para continuar digite 1\n");
        scanf("%i", &op);

    }while(op == 1);

    return 0;
}
