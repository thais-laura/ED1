#include <stdio.h>
#include <stdlib.h>

struct elemento{
    char palavra[10];
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Lista;

void menu();
Lista* cria_lista();
Elem* cria_cursor(Lista *li);
Elem* insere_inicio(Lista *li, char palavra[10]);
Elem* insere_fim(Lista *li, char palavra[10]);
Elem* insere_depois(Lista *li, char palavra[10], Elem *cursor);
Elem* insere_antes(Lista *li, char palavra[10], Elem *cursor);
Elem* procurar(Elem *cursor, char palavra[10]);
Elem* remover(Lista *li, Elem *cursor);
Elem* go_inicio(Lista *li);
Elem* go_fim(Lista *li);
Elem* go_prox(Elem* cursor);
Elem* go_antes(Lista *li, Elem* cursor);
void listar_texto(Lista *li);
void listar_palavra(Elem* cursor);
void terminar_edicao(Lista *li);

