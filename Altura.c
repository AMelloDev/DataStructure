
#include <stdio.h>
#ifndef ARVORE_H
#define ARVORE_H

typedef struct no_arvore{
    int chave;
    struct no_arvore *esq;
    struct no_arvore *dir;

}no_arvore;

typedef struct {
    no_arvore * raiz;
}Arvore;

Arvore* cria_arvore();
int inserir_arvore(Arvore * arv, int chave);
no_arvore* buscar_arvore(Arvore * arv, int chave);
void pre_ordem(no_arvore* no);
void in_ordem(no_arvore*no);
void pos_ordem(no_arvore* no);
void percorrer_pre_orden(no_arvore *arv);
void percorrer_in_ordem(no_arvore *arv);
void percorrer_pos_ordem(no_arvore *arv);
void remover_arvore(Arvore *arv, int chave);
void destruir_no(no_arvore* no);
void destruir_arvore(Arvore *arv);


int altura_arvore(NoArvore* no){
  
    if(aux==NULL){
        return -1;
    }
    int esquerda=altura_arvore(no->esq);
    int direita=altura_arvore(no->dir);
    
    if(esquerda>direita){
        return esquerda+1;
    }else{
        return direita+1;
    }
}


