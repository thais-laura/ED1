#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EditorTexto.h"

int main()
{
    Lista *li = cria_lista();
    Elem *cursor = cria_cursor(li);
    char comando;
    char palavra[10];
    int tam;
    do{

        scanf("%c ", &comando);
        fgets(palavra, 10, stdin);

        tam = strlen(palavra) - 1;
        if (palavra[tam] == '\n'){
            if(palavra[tam-1] == '\r')
                palavra[tam-1] == '\0';
            else
                palavra[tam] = '\0';
        }

        if(comando == 'I'){
            cursor = insere_inicio(li, palavra);

        }else if(comando == 'F'){
            cursor= insere_fim(li, palavra);

        }else if(comando == 'A'){
            cursor= insere_antes(li, palavra, cursor);

        }else if(comando == 'D'){
            cursor= insere_depois(li, palavra, cursor);

        }else if(comando == 'P'){
            cursor = procurar(cursor, palavra);

        }else if(comando == 'G'){
            if(strcmp(palavra, "inicio") == 0){
                cursor = go_inicio(li);
            }
            else if(strcmp(palavra, "fim") == 0){
                cursor = go_fim(li);
            }
            else if(strcmp(palavra, "prox") == 0){
                cursor = go_prox(cursor);
            }
            else if(strcmp(palavra, "ant") == 0){
                cursor = go_antes(li, cursor);
            }

        }else if(comando == 'R' && strcmp(palavra, "atual") == 0){
            cursor = remover(li, cursor);

        }else if(comando == 'L'){
            if(strcmp(palavra, "texto") == 0){
                listar_texto(li);
            }
            else if(strcmp(palavra, "palavra") == 0){
                listar_palavra(cursor);
            }
        }else if(comando == 'X' && strcmp(palavra, "editor") == 0){
            terminar_edicao(li);
        }

    }while(comando != 'X' && strcmp(palavra, "editor") != 0);

    return 0;
}
