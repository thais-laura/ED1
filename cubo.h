//Cubo projetado para estar somente no espaço positivo
typedef struct cubo tipo_cubo;

//void cria_cubo(float x1, float y1, float z1, float x2, tipo_cubo *c);
    //em cima, não estou criando realmente o cubo, pq tenho que passar o tipo_cubo
tipo_cubo* cria_cubo(float x1, float y1, float z1, float x2);
void libera_cubo(tipo_cubo *c); //nao havia colocado, tem que liberar a memoria alocada dinamicamente
void coordenadas(tipo_cubo *c); //dps de criar, tenho que passar o cubo so
float lado_cubo(tipo_cubo *c); //idem do de cima
float area_cubo(float lado);
float volume_cubo(float lado);
