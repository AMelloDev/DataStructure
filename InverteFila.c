#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct Elementos{
       int dado;
       struct Elementos * proximo;
       
 }Elementos;
   
typedef struct Pilha{
       Elementos * topo;
 }Pilha;
 
 Pilha * cria_pilha(){
    Pilha * p = malloc(sizeof(Pilha)); 
    p-> topo = NULL;  
    return p;
}
    
void push(Pilha * p, int x){
    Elementos * novo =malloc(sizeof(Elementos)); 
    novo-> dado = x; 
    novo-> proximo = p-> topo;
    p-> topo = novo; 
}

int pop(Pilha * p){

    Elementos * aux = p->topo; 
    int dado= -999;
    if ( aux!= NULL){
    dado =aux-> dado;
    p -> topo = aux ->proximo;
    free(aux);
    }
    return dado;
}
 //----------------------------------------
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

Fila* mover_valores(Fila * origem){
    Fila * filaFim = criar_fila();
    Pilha* p = cria_pilha();
    
    int tamanhofila= tamanho(origem);
    int valor;
    
    for (int i = 0; i < tamanhofila; i++) {
        valor = remover(origem);
        push(p, valor);
    }
    
    for (int i = 0; i < tamanhofila; i++) {
        valor= pop(p);
        inserir(filaFim, valor);
    }
    
    return filaFim;
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
    
    inserir(filaUm, 2);
    inserir(filaUm, 4);
    inserir(filaUm, 8);
  

    printf("Fila 1: ");
    listar_fila(filaUm);
    
    Fila* filaInvertida = mover_valores(filaUm);
   
    printf("fila Final: ");
    listar_fila(filaInvertida);
  
    return 0;
}