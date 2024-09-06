//NRO.USP: 14608765
//NOME: Thaís Laura Anício Andrade

#include <stdio.h>
#include <stdlib.h>

#define OK         1
#define ERRO       0

typedef float Tipo_Dado;

struct elemento{
    struct elemento *ant;
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_ordenada(Lista* li, Tipo_Dado dt);
void imprime_lista(Lista* li);
int remove_dado(Lista* li, Tipo_Dado dado);
int remove_duplicado(Lista *li);
void imprime_lista_inversa(Lista* li);


int main()
{
    Lista *li = cria_lista();
    Tipo_Dado dado = 0;
    int flag = 1;
    while(flag){
        scanf("%f", &dado);
        if(dado + 1000 > 0)
            insere_lista_ordenada(li, dado);
        else
            flag = 0;
    }
    imprime_lista(li);

    if(remove_duplicado(li) == 0){
        printf("Erro ao remover os dados duplicados\n");
    }else{
        imprime_lista_inversa(li);
    }

    libera_lista(li);
    return 0;
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


int insere_lista_ordenada(Lista* li, Tipo_Dado dt)
{
    if (li == NULL)
        return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;
    no->dado = dt;
    if ((*li) == NULL)
	{  //lista vazia: insere início
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return OK;
    }
    else{
        Elem *ante, *atual = *li;
        while (atual != NULL && atual->dado < dt)
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
    //do inicio ao fim
    Elem* no = *li;
    while (no != NULL)
    {
        printf("%.2f\n", no->dado);
        no = no->prox;
    }
}
int remove_dado(Lista* li, Tipo_Dado dado)
{
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL)//lista vazia
        return ERRO;

    Elem *no = *li;
    int i = 0;
    while (no != NULL && i != 2){ //remove a segunda ocorrencia desse dado
        if(no->dado == dado)
            i++;
        if(i!= 2)
            no = no->prox;
    }
    if (no == NULL)//não encontrado
        return ERRO;

    if (no->ant == NULL){       //remove o primeiro
        *li = no->prox;
        no->prox->ant = NULL;
    }else if(no->prox == NULL){ //remove o ultimo
        no->ant->prox = NULL;
    }else{                      //remove no meio
        no->prox->ant = no->ant;
        no->ant->prox = no->prox;
    }
    free(no);
    return OK;
}

int remove_duplicado(Lista *li)
{
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL)//lista vazia
        return ERRO;

    Elem *no = *li;
    Elem *aux = (*li)->prox;
    int i, j;
    int tam = tamanho_lista(li);
    float dif;

    for(i=0; i<tam; i++){ //dado a ser comparado
        for(j=i+1; j<tam; j++){ //dado a ser removido
            dif = no->dado - aux->dado;
            if(dif > -0.01 && dif < 0.01){ //intervalo de seguranca
                if(remove_dado(li, aux->dado) ==0){
                    printf("Erro ao remover o segundo dado");
                }
                if(aux->prox != NULL)
                    aux = aux->prox;
            }else{
                if(aux->prox != NULL)
                    aux = aux->prox;
                else
                    j = tam;
            }
        }
        no = no->prox;
        if(no == NULL)
            return OK;
        aux = no->prox;
        if(aux == NULL)
            return OK;
    }
    return ERRO; //nao chegou ate o fim
}

void imprime_lista_inversa(Lista* li)
{
    Elem* no;
    Elem *aux = *li;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    no = aux;
    while (no != NULL)
    {
        printf("%.2f\n", no->dado);
        no = no->ant;
    }
}



