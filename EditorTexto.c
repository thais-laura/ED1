#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EditorTexto.h"

Lista* cria_lista()
{
    Lista *li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

Elem* cria_cursor(Lista *li)
{
    Elem *cursor = (Elem*)malloc(sizeof(Elem));
    cursor = *li;
    return cursor;
}

Elem* insere_inicio(Lista *li, char palavra[10])
{
    if(li == NULL)
        li = cria_lista();
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
      printf("ERRO: no == NULL\n");
    strcpy(no->palavra, palavra);
    no->prox = (*li);
    *li = no;
    return no;
}

Elem* insere_fim(Lista *li, char palavra[10])
{
    if(li == NULL)
        li = cria_lista();
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        printf("ERRO: no == NULL\n");

    strcpy(no->palavra,palavra);
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
    return no;
}

Elem* insere_depois(Lista *li, char palavra[10], Elem *cursor)
{
    Elem *aux;
    Elem *no = (Elem*) malloc(sizeof(Elem));

    aux = cursor;
    strcpy(no->palavra, palavra);

    no->prox = aux->prox;
    aux->prox = no;
    return no;
}

Elem* insere_antes(Lista *li, char palavra[10], Elem *cursor)
{
    if(li == NULL)
        li = cria_lista();
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        printf("ERRO: no == NULL\n");

    strcpy(no->palavra,palavra);
    no->prox = cursor;

    if((*li) == NULL){
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        if(aux == cursor){
            *li = no;
            no->prox = cursor;
        }else{
            while(aux->prox != cursor){
                aux = aux->prox;
            }
            aux->prox = no;
        }

    }
    return no;
}

Elem* procurar(Elem *cursor, char palavra[10])
{
    int flag = 0;
    Elem *aux = (Elem*) malloc(sizeof(Elem));
    aux = cursor->prox;
    while(aux != NULL){
        if(strcmp(aux->palavra, palavra) == 0){
            flag = 1;
            break;
        }else{
            aux = aux->prox;
        }
    }
    if(flag == 0){
        return cursor;
    }else{
        return aux;
    }
}


Elem* go_inicio(Lista *li)
{
    if(li == NULL)
        li = cria_lista();
    return *li;
}

Elem* go_fim(Lista *li)
{
    if(li == NULL)
        li = cria_lista();
    Elem *aux = (Elem*) malloc(sizeof(Elem));
    aux = *li;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    return aux;
}

Elem* go_prox(Elem* cursor)
{
    if(cursor->prox != NULL){
        Elem *aux;
        aux = cursor->prox;
        return aux;
    }else{
        return cursor;
    }
}

Elem* go_antes(Lista *li, Elem* cursor)
{
    Elem *aux = (Elem*) malloc(sizeof(Elem));
    aux = *li;
    if(aux != cursor){
        while(aux->prox != cursor){
            aux = aux->prox;
        }
    }
    return aux;
}

Elem* remover(Lista *li, Elem *cursor)
{
    Elem *aux = (Elem*) malloc(sizeof(Elem));
    aux = go_antes(li, cursor);
    if(aux == cursor){
        *li = cursor->prox;
    }else{
        aux->prox = cursor->prox;
    }
    free(cursor);
    return aux;
}

void listar_texto(Lista *li)
{
    Elem* no = *li;
    while(no != NULL){
        printf("%s",no->palavra);
        no = no->prox;
        if(no == NULL){
            printf("\n");
        }else{
            printf(" ");
        }
    }
}

void listar_palavra(Elem* cursor)
{
    Elem* no = cursor;
    printf("%s\n", no->palavra);
}

void terminar_edicao(Lista *li)
{
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }else{
        printf("Erro: li == NULL");
    }
}
