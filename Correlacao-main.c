#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Correlacao.h"

int main()
{
    Lista *li_pib = cria_lista();
    Lista *li_ce = cria_lista();
    Tipo_Dado n, med_ce, med_pib, cov, var_pib, var_ce, corr;
    char ch;

    FILE *arq_pib = fopen("PIB.txt", "r");
    if(arq_pib == NULL){
        printf("Erro ao abrir o arquivo PIB.txt\n");
    }
    FILE *arq_ce = fopen("CE.txt", "r");
    if(arq_ce == NULL){
        printf("Erro ao abrir o arquivo CE.txt\n");
    }

    do{
        if((fscanf(arq_pib, "%f", &n ))==0){
            printf("Erro ao ler o arquivo por fscanf\n");
        }else{
            if((insere_lista_final(li_pib, n))== 0)
               printf("Erro ao inserir o nodo\n");
            else{
            }
        }
    }while((ch=fgetc(arq_pib))!= EOF);
    fclose(arq_pib);

    do{
        if((fscanf(arq_ce, "%f", &n ))==0){
            printf("Erro ao ler o arquivo por fscanf\n");
        }else{
            if((insere_lista_final(li_ce, n))== 0)
               printf("Erro ao inserir o nodo\n");
        }
    }while((ch=fgetc(arq_ce))!= EOF);
    fclose(arq_ce);

    med_pib = media(li_pib);
    med_ce = media(li_ce);
    cov = covariancia(li_pib, li_ce);
    var_pib = variancia(li_pib);
    var_ce = variancia(li_ce);
    corr = correlacao_pearson(cov, var_pib, var_ce);

    printf("\n>>> Calculo da Correlacao: Consumo Eletrico e PIB <<<\n");
    printf("\n>> Lendo arquivos de dados...\n");
    printf("%d dados lidos\n", tamanho_lista(li_ce));

    printf("\nCalculo da media do Consumo Eletrico e do PIB\n");
    printf("Media do Consumo Eletrico: %f\n", med_ce);
    printf("Media do PIB: %f\n", med_pib);

    printf("\nCalculo da Correlacao...\n");
    printf("Covariancia: %f\n", cov);
    printf("Variancia do Consumo Eletrico: %f\n", var_ce);
    printf("Variancia do PIB: %f\n", var_pib);
    printf("Correlacao: %f\n", corr);

    printf("\n>>> Resultado Final <<<\n");
    printf("Correlacao dos Dados: %d\n", interpretacao_correlacao(corr));


    libera_lista(li_pib);
    libera_lista(li_ce);
    return 0;
}
