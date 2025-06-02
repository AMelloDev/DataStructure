#include <stdlib.h>
#include <stdio.h>

typedef struct Elemento {
	int valor;
	struct Elemento* prox;
} Elemento;

typedef struct Lista {
	Elemento* inicio;
} Lista;

Lista* criar_lista() {
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

Elemento* inserir(Lista* l, int x) {
	Elemento* aux;
	Elemento* novo = malloc(sizeof(Elemento));
	novo-> valor = x;
	novo->prox = NULL;

	aux= l->inicio;

	if(aux == NULL) {
		l->inicio = novo;
		return novo;
	}
	while(aux->prox != NULL) {
		aux= aux->prox;
	}
	aux-> prox = novo;
	return novo;

};

int sum (Lista* l) {
	int tamanho_Lista = tamanho(l);
	int sum =0;

	Elemento* atual = l->inicio;
	int contador = 0;

	while (contador != tamanho_Lista) {
		sum = sum+ atual-> valor;
		contador++;
		atual = atual->prox;
	}

	return sum;
}

int main() {

	Lista* listaUm = criar_lista();
	
	inserir(listaUm, 3);
	inserir(listaUm, 5);
	inserir(listaUm, 2);
	
	printf("A soma dos elementos C %d", sum(listaUm));

	return 0;
}
