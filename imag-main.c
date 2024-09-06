#include <stdio.h>
#include <stdlib.h>
#include "imag.h"

int main()
{
    tipo_cplx *c1, *c2, *soma, *subt, *mult, *div;
    c1 = cria_complexo(2,4);
    c2 = cria_complexo(3,7);
    soma = cria_complexo(0,0);
    subt = cria_complexo(0,0);
    mult = cria_complexo(0,0);
    div = cria_complexo(0,0);

    soma_complexo(c1, c2, soma);
    subt_complexo(c1, c2, subt);
    multip_complexo(c1, c2, mult);
    div_complexo(c1, c2, div);

    printf("Soma: ");
    exibe_complexo(soma);
    printf("\nSubtracao: ");
    exibe_complexo(subt);
    printf("\nMultiplicacao: ");
    exibe_complexo(mult);
    printf("\nDivisao: ");
    exibe_complexo(div);

    free(c1);
    free(c2);
    free(soma);
    free(subt);
    free(mult);
    free(div);

    return 0;
}
