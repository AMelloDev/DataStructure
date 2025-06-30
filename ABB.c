
#include <stdio.h>
#include <stdlib.h>
#ifndef ARVORE_H
#define ARVORE_H

typedef struct no_arvore{
    int chave;
    struct no_arvore *esq;
    struct no_arvore *dir;

}no_arvore;

typedef struct {
    no_arvore *raiz;
}Arvore;

Arvore* cria_arvore(){ 
    Arvore* arv = malloc(sizeof(Arvore));
    arv-> raiz = NULL;
    return arv;
    
}
int inserir_arvore(Arvore * arv, int chave){
    no_arvore * novo = malloc(sizeof(no_arvore));
    no_arvore * aux, anterior;
    novo->chave = chave;
    novo -> esq = NULL;
    novo -> dir = NULL;
    if(arv->raiz==NULL){
        arv-> raiz = novo;
        return chave;
    }
    aux= arv -> raiz;
    anterior = aux;
    
    while(aux!= NULL){
        if(aux-> chave == chave){
            anterior = aux;
            aux = aux-> esq;
        }else {
            if(aux->chave < chave){
                anterior= aux;
                aux = aux ->dir;
            }else{
                return 0; //chave já existe
            }
        }
    }
    if(anterior-> chave > chave){
        anterior->esq = novo;
    }else{
        anterior->dir = novo;
    }
    return chave;
}


int ehABB(no_arvore* no, int* anterior){
    if(no == NULL){
        return 1;
    }
   
    if( !ehABB(no->esq, anterior){
        return 0;
    }
     if (*anterior >= no->chave) {
        return 0; 
    }
    *anterior = no->chave; 
   
    return ehABB(no->dir, anterior);
    
}
 int verifica_abb(Arvore* arv){
     int anterior = -2147483648;
     ehABB(arv->raiz, anterior);
     
     return ehABB(arv->raiz, &anterior);
 }
 
int main(){
    Arvore* arvore =cria_arvore();
    inserir_arvore(arvore,4);
    inserir_arvore(arvore,3);
    inserir_arvore(arvore,5);
    
    if (verifica_abb(arvore)) {
        printf("A árvore é uma ABB.\n");
    } else {
        printf("A árvore não é uma ABB.\n");
    }
    
    return 0;
} 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 