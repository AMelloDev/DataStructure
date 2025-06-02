#include <stdlib.h>
#include<stdio.h>
#define LISTA_H_INCLUDED

typedef struct Elemento{
	int valor;
	struct Elemento* prox;
} Elemento;

typedef struct Lista{
	Elemento* inicio;
} Lista;

Lista* criar_lista(){
    Lista * l = malloc(sizeof(Lista)); 
    l-> inicio = NULL;  
    return l;
};
int tamanho(Lista* l){
    int contador = 0;
    Elemento* atual = l->inicio;

    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }

    return contador;
};

int maior_elemento( Lista* l){
    int aux_maior =-999;
    int tamanho_Lista = tamanho(l);
     
    Elemento* atual = l->inicio;
    int contador = 0;

    while (contador != tamanho_Lista) {  
        if(atual->valor > aux_maior){
            aux_maior= atual-> valor;
        }
        contador++;
        atual = atual->prox;
    }
   
    return aux_maior;
}

int menor_elemento(Lista* l){
    int aux_menor =999;
    int tamanho_Lista = tamanho(l);
     
    Elemento* atual = l->inicio;
    int contador = 0;

    while (contador != tamanho_Lista) {  
        if(atual->valor < aux_menor){
            aux_menor= atual-> valor;
        }
        contador++;
        atual = atual->prox;
    }
   
    return aux_menor;
}

Elemento* inserir(Lista* l, int x){
     Elemento* aux;
     Elemento* novo = malloc(sizeof(Elemento));
     novo-> valor = x;
     novo->prox = NULL;
     
     aux= l->inicio;
     
     if(aux == NULL){
         l->inicio = novo;
         return novo;
     }
     while(aux->prox != NULL){
        aux= aux->prox;
     }
     aux-> prox = novo;
     return novo;
     
};

int main(){
    Lista* listaUm = criar_lista();
    
   
    
    inserir(listaUm, 3);
    inserir(listaUm,4);
    inserir(listaUm,2);
    inserir(listaUm, 8);
    
    printf("O maior elmento é %d \n", maior_elemento(listaUm));
    
    printf("O menor elmento é %d", menor_elemento(listaUm));
   

    
    

    return 0;
}
