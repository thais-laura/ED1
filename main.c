#include <stdio.h>
#include <stdlib.h>
#include "P2-2023.h"

int main()
{
    FILE *arq;
    arq = fopen("dados.txt", "r");
    if (arq == NULL)
        printf("Erro ao abrir arquivo\n");
    ArvAVL *arv_x, *arv_y, *arv_z;
    arv_x = cria_ArvAVL();
    arv_y = cria_ArvAVL();
    arv_z = cria_ArvAVL();
    int x, y, z;

    while (!feof(arq))
    {
        fscanf(arq,"%d %d %d", &x, &y, &z);
        if(x != 0 && y != 0 && z != 0){
            if(0 == insere_ArvAVL(arv_x, x, x, y, z))
                printf("erro ao inserir na arvore X\n"); //x
            if(0 == insere_ArvAVL(arv_y, y, x, y, z))
                printf("erro ao inserir na arvore Y\n"); //x
            if(0 == insere_ArvAVL(arv_z, z, x, y, z))
                printf("erro ao inserir na arvore Z\n"); //x
        }

    }
    fclose(arq);

    int opcao;
    scanf("%d", &opcao);
    if(opcao == 1){
        printf("%d %d", altura_ArvAVL(arv_x), totalNO_ArvAVL(arv_x));
    }else if(opcao == 2){
        int num;
        scanf("%d", &num);
        consulta_ArvAVL(arv_z, num);
    }else if(opcao == 3){
        int num;
        scanf("%d", &num);
        consulta_pos_ArvAVL(arv_y, num);
    }else if(opcao == 4){
        busca_menor_ArvAVL(arv_x);
        busca_menor_ArvAVL(arv_y);
        busca_menor_ArvAVL(arv_z);
    }

    libera_ArvAVL(arv_x);
    libera_ArvAVL(arv_y);
    libera_ArvAVL(arv_z);
    return 0;
}
