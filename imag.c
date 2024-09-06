#include <stdlib.h>
#include <stdio.h>
#include "imag.h"

struct cplx{
    float real;
    float imag;
};

tipo_cplx* cria_complexo(float real, float imag){
    tipo_cplx *cplx = (tipo_cplx *)malloc(sizeof(tipo_cplx));
    cplx->real = real;
    cplx->imag = imag;
    return cplx;
}

void libera_complexo(tipo_cplx *c){
    free(c);
}

void soma_complexo(tipo_cplx *c1, tipo_cplx *c2, tipo_cplx *soma){
    soma->real = c1->real + c2->real;
    soma->imag = c1->imag + c2->imag;
}

void subt_complexo(tipo_cplx *c1, tipo_cplx *c2, tipo_cplx *subt){
    subt->real = c1->real - c2->real;
    subt->imag = c1->imag - c2->imag;
}

void multip_complexo(tipo_cplx *c1, tipo_cplx *c2, tipo_cplx *mult){
    mult->real = (c1->real)*(c2->real) - (c1->imag)*(c2->imag);
    mult->imag = (c1->real)*(c2->imag) + (c1->imag)*(c2->real);
}

void div_complexo(tipo_cplx *c1, tipo_cplx *c2, tipo_cplx *div){
    div->real = ((c1->real)*(c2->real)+(c1->imag)*(c2->imag))/((c2->real)*(c2->real)+(c2->imag)*(c2->imag));
    div->imag = (-1*(c1->real)*(c2->imag)+(c1->imag)*(c2->real))/((c2->real)*(c2->real)+(c2->imag)*(c2->imag));
}

void exibe_complexo(tipo_cplx *c){
    if(c->imag <0){
        printf("%.2f %.2f i", c->real, c->imag);
    }else{
        printf("%.2f + %.2f i", c->real, c->imag);
    }
}

