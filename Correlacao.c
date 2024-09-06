#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Correlacao.h" //inclui os Protótipos

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


int consulta_lista_dado(Lista* li, Tipo_Dado dt, Elem **el)
{
    if (li == NULL)
        return 0;
    Elem *no = *li;
    while (no != NULL && no->dado != dt){
        no = no->prox;
    }
    if (no == NULL)
        return ERRO;
    else
	{
        *el = no;
        return OK;
    }
}


int insere_lista_final(Lista* li, Tipo_Dado dt)
{
    Elem *no;

    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)  return ERRO;

    no->dado = dt;
    no->prox = NULL;

	if ((*li) == NULL)
	{   //lista vazia: insere início
        no->ant = NULL;
        *li = no;
    }else
	{
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return OK;
}


int tamanho_lista(Lista* li)
{
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while (no->dado >=0){
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
    while (no->dado >=0)
    {
        printf("%f\n", no->dado);
        no = no->prox;
    }
    printf("-------------- FIM LISTA -----------------\n");
}

Tipo_Dado media(Lista *li)
{
    Elem *no = *li;
    Tipo_Dado somat = 0;
    int qtd = tamanho_lista(li);
    Tipo_Dado med;

    while(no->dado >=0){
        somat = somat + no->dado;
        no = no->prox;
    }

    med = somat/qtd;
    return med;
}

Tipo_Dado covariancia(Lista *li1, Lista *li2)
{
    int qtd = tamanho_lista(li1);
    int qtd_ = tamanho_lista(li2);
    if(qtd != qtd_){
        printf("Erro: as llistas possuem quantidades diferentes \n");
    }
    int i;
    Elem *no1 = *li1;
    Elem *no2 = *li2;
    Tipo_Dado somat=0;
    Tipo_Dado med1 = media(li1);
    Tipo_Dado med2 = media(li2);
    Tipo_Dado cov;

    for(i=0; i<qtd; i++){
        somat = somat + (no1->dado - med1)*(no2->dado - med2);
        no1 = no1->prox;
        no2 = no2->prox;
    }

    cov = somat/(qtd-1);
    return cov;
}

Tipo_Dado variancia (Lista *li)
{
    int qtd = tamanho_lista(li);
    Elem *no = *li;
    int i;
    Tipo_Dado med = media(li);
    Tipo_Dado somat=0;
    Tipo_Dado quad;
    Tipo_Dado var;

    for(i=0; i<qtd; i++){
        quad = (no->dado - med)*(no->dado - med);
        somat = somat + quad;
        no = no->prox;
    }

    var = somat/(qtd-1);
    return var;
}

float correlacao_pearson(Tipo_Dado cov, Tipo_Dado var1, Tipo_Dado var2)
{
    Tipo_Dado mult, raiz;
    mult = var1 * var2;
    raiz = sqrt (mult);
    float corr = cov/raiz;

    return corr;
}

int interpretacao_correlacao(float corr)
{
    if(corr > (-0.5) && corr < (0.5)){
        return 0;
    }else if(corr < (-0.5)){
        return -1;
    }
    return 1;
}

