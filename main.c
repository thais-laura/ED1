#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BigBrother.h"

int main()
{
    char tag[9], ch, x[2], entrada[20], comando;
    strcpy(x, "x");
    int status;
    FILE *arq = fopen("arq.txt", "r");
    Lista* li = cria_lista();
    ArvBin* raiz = cria_ArvBin();

    if (arq == NULL)
        printf("Nao foi possivel abrir o arquivo!");
    do{
        if((fscanf(arq, "%s", tag))==0 || (fscanf(arq, "%d", &status))==0){
            printf("Erro ao ler o arquivo por fscanf\n");
        }else{
            if((strncmp(tag, x, 1))!=0){
                if((insere_lista_ordenada(li, tag, status))== 0 || insere_ArvBin(raiz, tag, status) == 0)
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
        printf("NL:%d NA:%d\n", tamanho_lista(li), totalNO_ArvBin(raiz));

    }else if(comando == '1'){
        int *qtd_arv, *qtd_li, s_arv, s_li;
        qtd_arv = (int *) malloc(sizeof(int));
        qtd_li = (int *) malloc(sizeof(int));
        s_arv = consulta_ArvBin(raiz, tag, qtd_arv);
        s_li = consulta_lista_dado(li, tag, qtd_li);
        if(s_arv == s_li)
            printf("S:%d NL:%d NA:%d\n", s_arv, *qtd_li, *qtd_arv);

    }else if(comando == '2'){
        imprime_lista(li);

    }else if(comando == '3'){
        preOrdem_ArvBin(raiz);
    }

    fclose(arq);
    libera_lista(li);
    libera_ArvBin(raiz);

    return 0;
}
