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
int consulta_lista_dado(Lista* li, Tipo_Dado dt, Elem **el);
int insere_lista_final(Lista* li, Tipo_Dado dt);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
Tipo_Dado media(Lista *li);
Tipo_Dado covariancia(Lista *li1, Lista *li2);
Tipo_Dado variancia (Lista *li);
float correlacao_pearson(Tipo_Dado cov, Tipo_Dado var1, Tipo_Dado var2);
int interpretacao_correlacao(float corr);

