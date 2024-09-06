#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cubo.h"

int main()
{
    tipo_cubo *cub;
    float x1, y1, z1, x2;
    float lado;
    //antes eu atribuía as coordenadas iniciais
    //diretamente no cubo, mas a funcao cria_cubo que deve fazer isso
    x1 = 5;
    y1 = 5;
    z1 = 5;
    x2 = 10;

    cub = cria_cubo(x1,y1,z1,x2);
    printf("Coordenadas:\n");
    //antes a impressao era feita na main e nao em uma funcao do TAD
    coordenadas(cub);

    lado = lado_cubo(cub);
    printf("Lado: %.1f\n", lado);
    printf("Area: %.1f\n", area_cubo(lado));
    printf("Volume: %.1f\n", volume_cubo(lado));
    libera(cub);

    return 0;
}
