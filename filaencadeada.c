#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct Elemento {
    int dado;
    struct Elemento* proximoElemento;
} Elemento;


typedef struct Fila {
    Elemento* ponteiroInicio;
    Elemento* ponteiroFim;
} Fila;


Fila* criar_fila() {
    Fila* novaFila = malloc(sizeof(Fila));
    novaFila->ponteiroInicio = NULL;
    novaFila->ponteiroFim = NULL;
    return novaFila;
}

void inserir(Fila* fila, int numero) {
    Elemento* novoElemento = malloc(sizeof(Elemento));
    novoElemento->dado = numero;
    novoElemento->proximoElemento = NULL;

    if (fila->ponteiroFim != NULL) {
        fila->ponteiroFim->proximoElemento = novoElemento;
    } else {
        fila->ponteiroInicio = novoElemento;
    }

    fila->ponteiroFim = novoElemento;
}

int remover(Fila* fila){
    if(fila->ponteiroInicio ==NULL){
        printf("Fila vazia");
        return -1;
    }
    
    Elemento* elementoRemovido = fila->ponteiroInicio;
    int valor = elementoRemovido->dado;
    
    fila->ponteiroInicio = fila->ponteiroInicio->proximoElemento;
    
    if (fila->ponteiroInicio == NULL) {
    fila->ponteiroFim = NULL;
    }
    free(elementoRemovido);
    return valor;
}

void destruir_fila(Fila* fila) {
    while (fila->ponteiroInicio != NULL) {
        remover(fila);
    }
    free(fila);
}

int tamanho(Fila* fila) {
    int contador = 0;
    Elemento* atual = fila->ponteiroInicio;

    while (atual != NULL) {
        contador++;
        atual = atual->proximoElemento;
    }

    return contador;
}

void listar_fila(Fila* fila) {
    if (fila->ponteiroInicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    Elemento* atual = fila->ponteiroInicio;
    printf("Elementos na fila:\n");
    while (atual != NULL) {
        printf("  %d\n", atual->dado);
        atual = atual->proximoElemento;
    }
}

void ver_primeiro(Fila* fila) {
    if (fila->ponteiroInicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Primeiro elemento da fila: %d\n", fila->ponteiroInicio->dado);
}

#endif // FILA_H_INCLUDED
int main() {
    Fila* filaNumeros = criar_fila();
    char opcao;

    do {
        printf("\nEscolha uma opção:\n"
               "a) Ver quantidade de elementos na fila\n"
               "b) Remover primeiro da fila\n"
               "c) Adicionar número à fila\n"
               "d) Listar todos os números na fila\n"
               "e) Ver primeiro da fila\n"
               "s) Sair\n");

        scanf(" %c", &opcao);

        switch (opcao) {
            case 'a':
                printf("Quantidade de elementos: %d\n", tamanho(filaNumeros));
                break;

            case 'b': {
                int removido = remover(filaNumeros);
                if (removido != -1) {
                    printf("Número %d removido.\n", removido);
                }
                break;
            }

            case 'c': {
                int novoNumero;
                printf("Digite um número: ");
                scanf("%d", &novoNumero);
                inserir(filaNumeros, novoNumero);
                break;
            }

            case 'd':
                listar_fila(filaNumeros);
                break;

            case 'e':
                ver_primeiro(filaNumeros);
                break;

            case 's':
                destruir_fila(filaNumeros);
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 's');

    return 0;
}