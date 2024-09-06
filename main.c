#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "T3-BBB.h"

int main()
{
    char tag[9], ch, x[2], entrada[20], comando;
    strcpy(x, "x");
    int status;
    FILE *arq = fopen("arq.txt", "r");
    ArvAVL* avl = cria_ArvAVL();
    ArvBin* abo = cria_ArvBin();

    if (arq == NULL)
        printf("Nao foi possivel abrir o arquivo!");
    do{
        if((fscanf(arq, "%s", tag))==0 || (fscanf(arq, "%d", &status))==0){
            printf("Erro ao ler o arquivo por fscanf\n");
        }else{
            if((strncmp(tag, x, 1))!=0){
                if((insere_ArvAVL(avl, tag, status))== 0 || insere_ArvBin(abo, tag, status) == 0)
                    printf("Erro ao inserir o nodo\n");
            }
        }
    }while((ch=fgetc(arq))!= EOF);


    fgets(entrada,20,stdin);
    comando = entrada[0];
    for(int i =0; i<8; i++){
        tag[i] = entrada[2+i];
    }
    tag[8] = '\0';

    if(comando == '0'){
        printf("NA:%d NB:%d\n", totalNO_ArvBin(abo), totalNO_ArvAVL(avl));

    }else if(comando == '1'){
        int *qtd_abo, *qtd_avl, s_abo, s_avl;
        qtd_abo = (int *) malloc(sizeof(int));
        qtd_avl = (int *) malloc(sizeof(int));
        s_abo = consulta_ArvBin(abo, tag, qtd_abo);
        s_avl = consulta_ArvAVL(avl, tag, qtd_avl);
        if(s_abo == s_avl)
            printf("S:%d NA:%d NB:%d\n", s_abo, *qtd_abo, *qtd_avl);

    }else if(comando == '2'){
        preOrdem_ArvBin(abo);

    }else if(comando == '3'){
        preOrdem_ArvAVL(avl);
    }

    fclose(arq);
    libera_ArvAVL(avl);
    libera_ArvBin(abo);

    return 0;
}
