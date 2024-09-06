#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BigBrother.h" //inclui os Protótipos


//ARVORE BINARIA

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
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

int insere_ArvBin(ArvBin* raiz, char tag[8], Tipo_Dado valor){
    if(raiz == NULL)
        return ERRO;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return ERRO;
    novo->info = valor;
    strcpy(novo->id, tag);
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
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

int consulta_ArvBin(ArvBin *raiz, char tag[8], int* qtd){
    *qtd = 0;
    if(raiz == NULL)
        return -1;
    struct NO* atual = *raiz;
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

void Procura_preOrdem_ArvBin(ArvBin *raiz, char tag[8], int *achou)
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


Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li)
{
    if (li != NULL)
	{
        Elem* no;
        while ((*li) != NULL)
		{
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}


int consulta_lista_dado(Lista* li, char tag[8], int* qtd)
{
    *qtd = 0;
    if (li == NULL)
        return -1;
    Elem *no = *li;
    while (no != NULL && (strcmp(no->id, tag))<0){
        (*qtd)++;
        no = no->prox;
    }
    (*qtd)++;
    if (no == NULL){
        (*qtd)--;
        return -1;
    }else if(no != NULL && (strcmp(no->id, tag))>0) //ou seja, a comparação se encerrou antes da lista terminar
        return -1;
    else
        return 0;
}

int insere_lista_ordenada(Lista* li, char tag[8], Tipo_Dado dt)
{
    if (li == NULL)
        return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;
    no->dado = dt;
    strcpy(no->id, tag);
    if ((*li) == NULL)
	{  //lista vazia: insere início
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return OK;
    }
    else{
        Elem *ante, *atual = *li;
        while (atual != NULL && (strcmp(atual->id, tag)) <0)
		{
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *li)
		{   //insere início
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else
		{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if (atual != NULL)
                atual->ant = no;
        }
        return OK;
    }
}

int tamanho_lista(Lista* li)
{
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}


void imprime_lista(Lista* li)
{
    Elem* no = *li;

    if (li == NULL)
        return;
    while (no != NULL)
    {
        printf("%s %d\n", no->id, no->dado);
        no = no->prox;
    }
}
