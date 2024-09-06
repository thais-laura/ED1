#include <stdio.h>
#include <stdlib.h>

#include "JumpNode.h" //inclui os Protótipos
#define LIMIAR 0.5

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

/*
int consulta_lista_pos(Lista* li, int pos, Tipo_Dado *dt)
{
    if (li == NULL || pos <= 0)
        return ERRO;
    Elem *no = *li;
    int i = 1;
    while (no != NULL && i < pos)
	{
        no = no->prox;
        i++;
    }
    if (no == NULL)
        return ERRO;
    else
	{
        *dt = no->dado;
        return OK;
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


int insere_lista_inicio(Lista* li, Tipo_Dado dt)
{
    if (li == NULL)
        return ERRO;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;

    no->dado = dt;
    no->prox = (*li);
    no->ant = NULL;

	if (*li != NULL) //lista não vazia: apontar para o anterior!
        (*li)->ant = no;
    *li = no;
    return OK;
}*/


int insere_lista_ordenada(Lista* li, Tipo_Dado abs, Tipo_Dado ord)
{
    if (li == NULL)
        return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;
    no->x = abs;
    no->y = ord;
    if ((*li) == NULL)
	{  //lista vazia: insere início
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return OK;
    }
    else{
        Elem *ante;
        Elem *atual = *li;
        while (atual != NULL && atual->x <= abs){
            if(atual->x == abs){
                if(atual->y <= ord){
                    ante = atual;
                    atual = atual->prox;
                }
            }
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
        printf("Dado: X= %.3f - Y= %.3f \n",no->x, no->y);
        no = no->prox;
    }
    printf("-------------- FIM LISTA -----------------\n");
}

int reorganiza_lista(Lista *li)
{
    if (li == NULL)
        return ERRO;
    Elem* no;
    no = *li;
    while(no->prox != NULL){
        if((no->prox->x - no->x <= LIMIAR)||(no->prox->y - no->y <= LIMIAR)){
           // printf("DIF MENOR DO QUE O LIMIAR\n no->prox->x :%f eeee no->x: %f\n", no->prox->x, no->x);
            no->prox = no->prox->prox;
        }else{
           // printf("DIF MAIOR DO QUE O LIMIAR\n no->prox->x :%f eeee no->x: %f\n", no->prox->x, no->x);
            no = no->prox;
        }
    }
    return OK;
}


void imprime_lista_especial(Lista *li, Lista *li_aux)
{
    Elem *no;
    no = *li;
    while(no->prox != NULL){
        no = no->prox;
    }
    int tam = tamanho_lista(li);
    Tipo_Dado dado[2][tam];
    int i=0;
    int flag = 0;
    Elem *aux = *li_aux;
    while (aux->prox != NULL){
        while((aux->prox)->ant != aux){
            //printf("aux->prox->ant não eh o proprio aux, ou seja, pelo menos um nodo foi pulado\n");
            //printf("aux->prox->x: %f \t aux->prox->ant->x: %f\n", aux->prox->x, aux->prox->ant->x);
            dado[0][i] = ((aux->prox)->ant)->x;
            //printf("dado x %d: %f\n", i, dado[0][i]);
            dado[1][i] = ((aux->prox)->ant)->y;
            //printf("dado y %d: %f\n", i, dado[1][i]);
            i++;
            aux->prox->ant = aux->prox->ant->ant;
        }
        aux = aux->prox;
    }
    printf("Dado: X= %.3f - Y= %.3f \n", no->x, no->y);
    while(no->ant != NULL){
        no = no->ant;
        for(i=0; i<=tam && flag != 1; i++){
            if(no->x == dado[0][i] && no->y == dado[1][i]){
                printf("PULOU NODO => Dado: X= %.3f - Y= %.3f \n",no->x, no->y);
                flag = 1;
            }
        }
        if(flag == 0){
            printf("Dado: X= %.3f - Y= %.3f \n", no->x, no->y);
        }
        flag = 0;
    }
}
