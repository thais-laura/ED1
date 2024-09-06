#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "JumpNode.h"

int main()
{
    FILE *arq = fopen("dados.txt", "r");
    if (arq == NULL)
        printf("Nao foi possivel abrir o arquivo!\n");
    Lista *li = cria_lista();
    Lista *li_aux = cria_lista();
    char ch;
    Tipo_Dado x, y;

    do{
        if((fscanf(arq, "%f %f", &x, &y))==0){
            printf("Erro ao ler o arquivo por fscanf\n");
        }else{
            if((insere_lista_ordenada(li, x, y))== 0)
               printf("Erro ao inserir o nodo\n");
            if((insere_lista_ordenada(li_aux, x, y))== 0)
               printf("Erro ao inserir o nodo\n");
        }
    }while((ch=fgetc(arq))!= EOF);

    fclose(arq);
    printf("\n\n");
    imprime_lista(li);

    if(0 == reorganiza_lista(li)){
        printf("Erro ao reorganizar a lista\n");
    }
    if(0 == reorganiza_lista(li_aux)){
        printf("Erro ao reorganizar a lista\n");
    }
    imprime_lista(li); //imprime sem alguns dados
    imprime_lista_especial(li, li_aux);

    libera_lista(li);
    libera_lista(li_aux);
    return 0;
}
