#include <stdio.h>


typedef struct no_arvore{
    int chave;
    struct no_arvore *esq;
    struct no_arvore *dir;

}no_arvore;

typedef struct {
    no_arvore * raiz;
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
    aux=aux -> raiz;
    anterior = aux;
    
    while(aux!= NULL){
        if(aux-> chave > chave){
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
        anterior->esq = novo
    }else{
        anterior->dir = novo;
    }
    return chave;
}

no_arvore* buscar_arvore(Arvore * arv, int chave){
    no_arvore * aux = arv -> raiz;
    
    while(aux!=NULL ){
        if(chave == aux-> chave){
             return aux;
        }else 
        if(chave< aux-> chave){
            aux= aux->esq;
        }else{
                aux= aux->dir;
            
        }
    }
    return aux;
}
void pre_ordem(no_arvore* no){
    if(no == NULL){
        return;
    }
    printf("%d", no ->chave);
    pre_ordem(no->esq);
    pre_ordem(no->dir);
}
void in_ordem(no_arvore*no){
    if(no == NULL){
        return;
    }
    pre_ordem(no->esq);
    printf("%d", no ->chave);
    pre_ordem(no->dir);
}

void pos_ordem(no_arvore* no){
    if(no == NULL){
        return;
    }
    pre_ordem(no->esq);
    
    pre_ordem(no->dir);
    printf("%d", no ->chave);
}
void percorrer_pre_orden(no_arvore *arv){
    pre_ordem(arv-> raiz);
}
void percorrer_in_ordem(no_arvore *arv){
    in_ordem(arv-> raiz);
}
void percorrer_pos_ordem(no_arvore *arv){
    pos_ordem(arv-> raiz);
}

void remover_arvore(Arvore *arv, int chave){
     no_arvore * aux , *pai = NULL , *filho;
     no_arvore * novo, *ant;
     aux = arv -> raiz;
    
    while(aux!=NULL ){
        if(chave == aux-> chave){
            break;
            pai =aux;
            
        }else if(chave< aux-> chave){
            aux= aux->esq;
        }else{
     
                aux= aux->dir;
        } 
        
        if(aux == NULL){
            return 0;
        }
    }
    
    if(aux-> esq ==NULL && aux->dir==NULL){
        if(aux==pai->esq)
            pai->esq =NULL;
        else
            pai ->dir =NULL;
        free(aux);
        return 1;
    }

    if(auxn -> esq == NULL || aux -> dir == NULL){
        if(aux -> esq == NULL){
            filho = aux -> dir;
        }else{
            filho = aux-> esq;
        }if(aux==pai->esq)
            pai->esq =filho;
        else
            pai ->dir =filho;
        free(aux);
        return 1;
    }else{
        novo = aux-> esq;
        ant = aux;
        
        while(novo ->dir != NULL){
            ant = novo;
            novo = novo -> dir;
        }
        aux = chave = novo-> chave;
        ant -> dir = NULL;
        free(novo);
        return 1;
    }
    
}

void destruir_no(no_arvore* no) {
    if (no == NULL) return;
    destruir_no(no->esq);
    destruir_no(no->dir);
    free(no);
}


void destruir_arvore(Arvore *arv){
    destruir_no(arv->raiz);
    free(arv);
    
}


#ifndef HASH_H
#define HASH_H

#include "arvore.h"

#define TAM_HASH 10  // Tamanho da tabela hash

typedef struct {
    Arvore tabelas[TAM_HASH];
} HashTable;

// Interface da TAD Hash
void criar_hash(HashTable *h){
    Arvore* hash = malloc(TAM_HASH);
    
    for (int i = 0; i < TAM_HASH; i++) {
        h->tabelas[i] = cria_arvore();
    }
}

int inserir_hash(HashTable *h, int chave){
    int resto = chave%10;
    inserir_arvore( h->tabelas[resto], chave);
    return resto;
}

int buscar_hash(HashTable *h, int chave){
    int resto = chave%10;
    buscar_arvore( h->tabelas[resto], chave);
    return h->tabelas[resto];
}
int remover_hash(HashTable *h, int chave){
    int resto = chave%10;
    remover_arvore( h->tabelas[resto], chave);
    return h->tabelas[resto];
}
void destruir_hash(HashTable *h){
    for (int i = 0; i < TAM_HASH; i++) {
        destruir_arvore(h->tabelas[i]);
    }
}
void imprimir_hash(HashTable *h){
    for (int i = 0; i < TAM_HASH; i++) {
        printf("Posição %d da tabela hash:\n", i);
        in_ordem(h->tabelas[i]);
    }
}

#endif