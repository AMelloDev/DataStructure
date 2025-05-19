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

Fila* intercalar(Fila*filaUm, Fila*filaDois){
    Fila* filaFinal = criar_fila();
    Elemento* aux1 , *aux2;
    
    aux1 = filaUm -> ponteiroInicio;
    aux2 = filaDois -> ponteiroInicio;
    
    while(aux1 != NULL || aux2 != NULL){
        if(aux1 != NULL){
            inserir(filaFinal, aux1->dado);
            aux1= aux1 -> proximoElemento;
        }
        if(aux2 != NULL){
            inserir(filaFinal, aux2 -> dado);
            aux2 = aux2 -> proximoElemento;
        }
    }
    listar_fila(filaFinal);
    return filaFinal;
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



void ver_primeiro(Fila* fila) {
    if (fila->ponteiroInicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Primeiro elemento da fila: %d\n", fila->ponteiroInicio->dado);
}

#endif // FILA_H_INCLUDED
int main() {
    Fila* filaUm = criar_fila();
    Fila* filaDois = criar_fila();
    
    
    char opcao;
    
    
    inserir(filaUm, 2);
    inserir(filaUm, 4);
    inserir(filaUm, 8);
    inserir(filaDois, 3);
    inserir(filaDois, 6);
    inserir(filaDois, 9);

    printf("Fila 1: ");
    listar_fila(filaUm);

    printf("Fila 2: ");
    listar_fila(filaDois);


    intercalar(filaUm, filaDois);
    return 0;
}