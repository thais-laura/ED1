#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0


typedef float Tipo_Dado;

//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    Tipo_Dado x;
    Tipo_Dado y;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
//int insere_lista_inicio(Lista* li, Tipo_Dado abs, Tipo_Dado ord);
int insere_lista_final(Lista* li, Tipo_Dado abs, Tipo_Dado ord);
int tamanho_lista(Lista* li);
void imprime_lista(Lista* li);
int remove_lista(Lista* li, Tipo_Dado abs, Tipo_Dado ord);
void agrupa_lista(Lista *li);
float modulo(float a, float b);
