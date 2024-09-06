#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GPS.h"

int main()
{
    Lista *li = cria_lista();
    Tipo_Dado x[6]= {1.1, 1.12, 1.14, 1.09, 2.78, 2.75};
    Tipo_Dado y[6]= {2.33, 2.31, 2.33, 2.32, 5.93, 5.89};
    int i;
    printf("inserindo dados na lista...\n");
    for(i=0; i<6; i++){
        if(0 == insere_lista_final(li, x[i], y[i]))
            printf("Erro ao inserir dados na lista\n");
    }
    imprime_lista(li);
    printf("agrupando lista...\n");
    agrupa_lista(li);
    printf("deu pra agrupar\n");
   printf("imprimindo lista...\n");
    imprime_lista(li);

    //libera_lista(li);
    return 0;
}
