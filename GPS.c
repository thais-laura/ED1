#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GPS.h"
#define Raio 0.2

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

int insere_lista_final(Lista* li, Tipo_Dado abs, Tipo_Dado ord)
{
    if(li == NULL)
        return ERRO;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return ERRO;
    no->x = abs;
    no->y = ord;
    no->prox = NULL;
    if((*li) == NULL){ //lista vazia: insere início
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return OK;
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
        printf("Dado: %.5f - %.5f\n",no->x, no->y);
        no = no->prox;
    }
    printf("-------------- FIM LISTA -----------------\n");
}

int remove_lista(Lista* li, Tipo_Dado abs, Tipo_Dado ord)
{   //TERMINAR
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL)//lista vazia
        return ERRO;

    Elem *no = *li;
    while (no != NULL && no->x != abs && no->y != ord){
        no = no->prox;
    }
    if (no == NULL)//não encontrado
        return ERRO;

    if (no->ant == NULL){//remover o primeiro?
        *li = no->prox;
        no->prox->ant = NULL;
    }else if(no->prox == NULL){ //é o ultimo
        no->ant->prox = NULL;
    }else{
        no->prox->ant = no->ant;
        no->ant->prox = no->prox;
    }
    free(no);
    return OK;
}
float modulo(float a, float b){
    float dif = a -b;
    if(dif >=0)
        return dif;
    else{
        dif = -1 * dif;
        return dif;
    }
}


void agrupa_lista(Lista *li)
{
    Elem *no;
    no = *li;
    Elem *aux = (Elem*) malloc(sizeof(Elem));
    float med_x, med_y, abs, ord;
    int flag = 0;
    while(flag ==0){
    if((modulo(no->prox->x, no->x) <= Raio)){
            printf("entrou no while\n");
            med_x = (no->prox->x + no->x)/2;
            med_y = (no->prox->y + no->y)/2;
            if(0 ==insere_lista_final(li, med_x, med_y)){
                printf("Erro ao inserir medias na lista\n");
            }else{
            printf("inseriu media\n");
            }
            aux = no->prox->prox;
            abs = no->x;
            ord = no->y;
            if(0 == remove_lista(li, abs, ord)){
                printf("Erro ao inserir medias na lista\n");
            }else{
            printf("removeu %f %f\n", abs, ord);
            }

            abs = no->prox->x;
            ord = no->prox->y;
            if(0 == remove_lista(li, abs, ord)){
                printf("Erro ao inserir medias na lista\n");
            }else{
            printf("removeu %f %f\n", abs, ord);
            }
            no = aux;
        }else{
            no = no->prox;
            if(no->prox == NULL){
                flag = 1;
            }
        }
    }
        printf("onde aponta no? %p", no);
}
