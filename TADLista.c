#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Elemento{
	int valor;
	struct Elemento* prox;
} Elemento;

typedef struct Lista{
	Elemento* inicio;
} Lista;

// cria uma lista com tamanho definido
Lista* criar_lista(){
    Lista * l = malloc(sizeof(Lista)); 
    l-> inicio = NULL;  
    return l;
};

// destroi a lista
void destruir_lista(Lista* l){
     while (l->inicio != NULL) {
        remover(l);
    }
    free(l);
};

// retorna o tamanho da lista (numero de elementos inseridos)
int tamanho(Lista* l){
    int contador = 0;
    Elemento* atual = l->inicio;

    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }

    return contador;
};

// busca um dado pela chave x. retorna NULL em caso de falha
Elemento* buscar_por_elemento(Lista* l, int x){
    
    Elemento* atual = l->inicio;

    while (atual->valor != x && atual->prox != NULL) {  
        atual = atual->prox;
    }
    if(atual == NULL){
        return NULL;
    }
    return atual;
};

// busca um dado pela posicao pos. retorna NULL em caso de falha
Elemento* buscar_por_posicao(Lista* l, int pos){
    Elemento* atual = l->inicio;
    int contador = 0;

    while (contador != pos) {  
        contador++;
        atual = atual->prox;
    }
    if(atual == NULL){
        return NULL;
    }
    return atual;
};

// insere um dado pela (chave x) no inicio da lista. retorna NULL em caso de falha
Elemento* inserir_inicio(Lista* l, int x){
    Elemento* novo = malloc(sizeof(Elemento));
    
    if(novo == NULL){
        return NULL;
    }
    if(l==NULL){
        return NULL;
    }
    
    novo-> valor = x;
    novo->prox= l->inicio;
    l-> inicio = novo;
    
    return novo;
};

// insere um dado pela (chave x) na posicao pos. retorna NULL em caso de falha
Elemento* inserir_posicao(Lista* l, int x, int pos){
    Elemento* aux;
    Elemento* novo = malloc(sizeof(Elemento));
    int contador = 0;
    
    aux= l->inicio;
    novo-> valor = x;
    novo->prox=NULL;
     
    if(aux == NULL){
         l->inicio = novo;
         return novo;
    }

    while (aux->prox!=NULL && contador!= pos-1) {  
        contador++;
        atual = atual->prox;
    }
    
    novo->prox = aux->prox;
    aux->prox = novo;

    return novo;
    
    
};

// insere um dado pela (chave x) na lista. retorna NULL em caso de falha
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

// remove dado da lista
void remover(Lista* l, int x){
    Elemento* aux = l->inicio;
    Elemento* anterior = l-> inicio;

    while ( aux->prox != NULL) {  
        aux = aux->prox;
        anterior = anterior->aux;
    }
    if(atual == NULL){
        return NULL;
    }
    
    
    return atual;
};

// retorna o primeiro da lista
Elemento* primeiro(Lista* l){
    if (l->inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    printf("Primeiro elemento da lista: %d\n", l->inicio->valor);
};

// retorna o ultimo da lista
Elemento* ultimo(Lista* l){
    if(l->inicio ==NULL){
        printf("Lista vazia!\n");
    }

    Elemento* atual = l->inicio;

    while (atual->prox != NULL) {  
        atual = atual->prox;
    }

    return atual;
    }
};

// retorna um elemento pela posicao
Elemento* buscar_por_indice(Lista* l, int i){  if (i < 0) {
        return NULL;  // Indice inválido
    }

    Elemento* atual = l->inicio;
    int contador = 0;

    // Percorrer a lista até encontrar o índice
    while (atual != NULL && contador < i) {
        atual = atual->prox;
        contador++;
    }

    // Se não encontrar o índice, retorna NULL
    if (atual == NULL) {
        return NULL;
    }

    return atual;  // Retorna o elemento na posição i
};

#endif // LISTA_H_INCLUDED