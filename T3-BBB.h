#define OK         1
#define ERRO       0

typedef int Tipo_Dado;

//Definição do tipo Arvore
struct NO_abo{
    Tipo_Dado info;
    char id[9];
    struct NO_abo *esq;
    struct NO_abo *dir;
};

typedef struct NO_abo NodoArvBin;
typedef struct NO_abo *ArvBin;

struct NO_avl{
    int info;
    char id[9];
    int altura;
    struct NO_avl *esq;
    struct NO_avl *dir;
};
typedef struct NO_avl* ArvAVL;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, char tag[9], Tipo_Dado valor);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, char tag[9], int* qtd);
void preOrdem_ArvBin(ArvBin *raiz);
void Procura_preOrdem_ArvBin(ArvBin *raiz, char tag[9], int *achou);

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, char tag[9], Tipo_Dado valor);
int totalNO_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, char tag[9], int* qtd);
void preOrdem_ArvAVL(ArvAVL *raiz);

