#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "T3-BBB.h" //inclui os Protótipos


//ARVORE BINARIA

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO_abo* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, char tag[9], Tipo_Dado valor){
    if(raiz == NULL)
        return ERRO;
    struct NO_abo* novo;
    novo = (struct NO_abo*) malloc(sizeof(struct NO_abo));
    if(novo == NULL)
        return ERRO;
    novo->info = valor;
    strcpy(novo->id, tag);
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO_abo* atual = *raiz;
        struct NO_abo* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if((strcmp(atual->id, tag))== 0){ //são iguais
                free(novo);
                return ERRO;//elemento já existe
            }

            if((strcmp(atual->id, tag)) < 0){ //tag é maior do que o id atual
                atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if((strcmp(ant->id, tag)) < 0){
            ant->dir = novo;
        }else{
            ant->esq = novo;
        }
    }
    return OK;
}


int totalNO_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return ERRO;
    if(*raiz == NULL)
        return 0;
    int nos_esq, nos_dir;
    nos_esq = totalNO_ArvBin(&((*raiz)->esq));
    nos_dir = totalNO_ArvBin(&((*raiz)->dir));

    return(nos_dir + nos_esq +1);
}

int consulta_ArvBin(ArvBin *raiz, char tag[9], int* qtd){
    *qtd = 0;
    if(raiz == NULL)
        return -1;
    struct NO_abo* atual = *raiz;
    while(atual != NULL){
        if((strcmp(atual->id, tag))==0){
            (*qtd)++;
            return 0;
        }
        (*qtd)++;
        if((strcmp(atual->id, tag))<0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return -1;
}



void preOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%s %d\n", (*raiz)->id, (*raiz)->info);          // Info é Int
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void Procura_preOrdem_ArvBin(ArvBin *raiz, char tag[9], int *achou)
{
    if(raiz == NULL)
        return;
    if (*achou)
        return;
    if(*raiz != NULL)
    {
        if ((strcmp((*raiz)->id, tag))==0)
        {
            printf("Achou: %s! \n",(*raiz)->id);   // Info é Int
            *achou=1;
        }
        Procura_preOrdem_ArvBin(&((*raiz)->esq),tag,achou);
        Procura_preOrdem_ArvBin(&((*raiz)->dir),tag,achou);
    }
}


ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO_AVL(struct NO_avl* no){
    if(no == NULL)
        return;
    libera_NO_AVL(no->esq);
    libera_NO_AVL(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO_AVL(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int altura_NO(struct NO_avl* no){
    if(no == NULL)
        return -1;
    else
    return no->altura;
}

int fatorBalanceamento_NO(struct NO_avl* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

int estaVazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}


void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%s %d\n",(*raiz)->id, (*raiz)->info);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}


int consulta_ArvAVL(ArvAVL *raiz, char tag[9], int* qtd){
    *qtd = 0;
    if(raiz == NULL)
        return -1;
    struct NO_avl* atual = *raiz;
    while(atual != NULL){
        if(strcmp(atual->id, tag) ==0){
            (*qtd)++;
            return 0;
        }
        (*qtd)++;
        if((strcmp(atual->id, tag))<0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return -1;
}

//=================================
void RotacaoLL(ArvAVL *A){//LL
    struct NO_avl *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;
    *A = B;
}

void RotacaoRR(ArvAVL *A){//RR
    struct NO_avl *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;
    (*A) = B;
}

void RotacaoLR(ArvAVL *A){//LR
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvAVL *A){//RL
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_ArvAVL(ArvAVL *raiz, char tag[9], Tipo_Dado valor){
    int res;
    if(*raiz == NULL){//árvore vazia ou nó folha
        struct NO_avl *novo;
        novo = (struct NO_avl*)malloc(sizeof(struct NO_avl));
        if(novo == NULL)
            return 0;

        novo->info = valor;
        strcpy(novo->id, tag);
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO_avl *atual = *raiz;
    if(strcmp(atual->id, tag) > 0){
        if((res = insere_ArvAVL(&(atual->esq), tag, valor)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(strcmp((*raiz)->esq->id, tag) > 0){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else{
        if(strcmp(atual->id, tag) < 0){
            if((res = insere_ArvAVL(&(atual->dir), tag, valor)) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if(strcmp((*raiz)->esq->id, tag) < 0){
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}

struct NO_avl* procuraMenor(struct NO_avl* atual){
    struct NO_avl *no1 = atual;
    struct NO_avl *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}
