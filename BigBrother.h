#define OK         1
#define ERRO       0

typedef int Tipo_Dado;

//Definição do tipo Arvore
struct NO{
    Tipo_Dado info;
    char id[8];
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO NodoArvBin;
typedef struct NO *ArvBin;

//Definicao da lista
struct elemento{
    struct elemento *ant;
    Tipo_Dado dado;
    char id[8];
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, char tag[8], Tipo_Dado valor);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, char tag[8], int* qtd);
void preOrdem_ArvBin(ArvBin *raiz);
void Procura_preOrdem_ArvBin(ArvBin *raiz, char tag[8], int *achou);

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_dado(Lista* li, char tag[8], int* qtd);
int insere_lista_ordenada(Lista* li, char tag[8], Tipo_Dado dt);
int tamanho_lista(Lista *li);
void imprime_lista(Lista* li);


