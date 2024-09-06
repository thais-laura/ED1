#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cubo.h" //inclui os Protótipos

struct cubo{
    float x[8];
    float y[8];
    float z[8];
};

//void cria_cubo(float x1, float y1, float z1, float x2, tipo_cubo *c){
//em cima, já havia criado um cubo do tipo_cubo, oq n faz sentido no TAD
tipo_cubo* cria_cubo(float x1, float y1, float z1, float x2){
    //não havia alocado dinamicamente o ponteiro
    tipo_cubo *c = (tipo_cubo*) malloc(sizeof(tipo_cubo));
    float lado;
    int i;
    for (i=0; i<8; i++){
        if(i%2 == 0){ //x pares
            c->x[i] = x1;
        }else{
            c->x[i] = x2;
        }
    }
    lado = lado_cubo(c); //antes, coloca x1 e x2, mas tenho que colocar o ponteiro msm
    for (i=0; i<8; i++){
        if(i<4){
            c->y[i] = y1;
        }else{
            c->y[i] = y1 + lado;
        }
    }
    for (i=0; i<8; i++){
        if(i<2 || i==4 || i==5){
            c->z[i] = z1;
        }else{
            c->z[i] = z1 + lado;
        }
    }
    return c; //retornando a criacao do cubo
}

void libera_cubo(tipo_cubo *c){
    free(c);
}

void coordenadas(tipo_cubo *c){
    int i;
    for(i=0; i<8; i++){
        printf("C%d: (x,y,z)==(%.1f, %.1f, %.1f)\n", i+1, c->x[i], c->y[i], c->z[i]);
    }
}

//antes usava x1 e x2
//mas tenho que acessar a struct aqui!
float lado_cubo(tipo_cubo *c){
    int lado = c->x[1] - c->x[0];
    return lado;
}

float area_cubo(float lado){
    float area;
    area = 6 * lado * lado;
    return area;
}

float volume_cubo(float lado){
    float vol;
    vol = lado * lado * lado;
    return vol;
}

