#include <iostream>
#include "arvoreBinaria.h"

// FUNCÇÕES DE PILHA:
// CRIAR:
void criar(pilha*& p) {
	p = NULL;
}

// EMPILHAR:
void empilhar(pilha*& p, no* r) {
	pilha* a;

	a = new pilha;

	a->info = r;
	a->prox = p;
	p = a;
}

// DESEMPILHAR:
no* desempilhar(pilha*& p) {
	pilha* a;
	no* aux;

	a = p;
	p = p->prox;
	aux = a->info;
	delete(a);
	return aux;
}

// É VAZIA:
int evazia(pilha* p) {
	return p == NULL;
}


// FUNÇÕES DE ÁRVORE:
// INICIALIZAR UMA ÁRVORE VAZIA:
void arvoreVazia(no*& r) {
	r = NULL;
}

// INSERIR (RECURSIVO):
bool inserirR(no*& r, int num) {
	if (r == NULL) {
		r = new no;
		r->info = num;
		r->dir = r->esq = NULL;
		return true;
	}
	else if (num == r->info) {
		return false;
	}
	else if (num < r->info) {
		inserirR(r->esq, num);
	}
	else {
		inserirR(r->dir, num);
	}
}

// INSERIR (ITERATIVO):
bool inserirI(no*& r, int num) {
	no* a, * b;

	if (r == NULL) {
		r->info = num;
		r->esq = r->dir = NULL;
		return true;
	}
	else {
		a = r;
		while (a != NULL) {
			if (num < a->info) {
				if (a->esq == NULL) {
					b = new no;
					b->info = num;
					b->esq = b->dir = NULL;
					a->esq = b;
					return true;
				}
				else {
					a = a->esq;
				}
			}
			else if (num > a->info) {
				if (a->dir == NULL) {
					b = new no;
					b->info = num;
					b->esq = b->dir = NULL;
					a->dir = b;
					return true;
				}
				else {
					a = a->dir;
				}
			}
			else {
				return false;
			}
		}
	}
}

// NÚMERO DE FOLHAS (RECURSIVO):
int numFolhasR(no*& r) {
	if (r == NULL) {
		return 0;
	}
	else if (r->dir == NULL && r->esq == NULL) {
		return 1;
	}
	else {
		return numFolhasR(r->esq) + numFolhasR(r->dir);
	}
}

// NÚMERO DE FOLHAS (ITERATIVO):
int numFolhasI(no*& r) {
	no* aux;
	pilha* p = NULL;
	int cont = 0;

	if (r != NULL) {
		empilhar(p, r);
		while (!evazia(p)) {
			aux = desempilhar(p);
			if (aux->dir != NULL) {
				empilhar(p, r->dir);
			}
			if (aux->esq != NULL) {
				empilhar(p, r->esq);
			}
			if (r->esq == NULL && r->dir == NULL) {
				cont++;
			}
		}
	}
	return cont;
}

// PERCORRER ÁRVORE EM-ORDEM:
void emOrdem(no* r) {
	pilha* p;

	criar(p);

	if (r != NULL) {
		while (!evazia(p) || r != NULL) {
			while (r != NULL) {
				empilhar(p, r);
				r = r->esq;
			}
			r = desempilhar(p);
			printf("%i ", r->info);
			r = r->dir;
		}
	}
	printf("\n");
	system("pause");
}

// PERCORRER ÁRVORE PRE-ORDEM:
void preOrdem(no* r) {
	pilha* p;

	criar(p);

	if (r != NULL) {
		empilhar(p, r);
		while (!evazia(p)) {
			r = desempilhar(p);
			printf("%i ", r->info);
			if (r->dir != NULL) {
				empilhar(p, r->dir);
			}
			if (r->esq != NULL) {
				empilhar(p, r->esq);
			}
		}
	}
	printf("\n");
	system("pause");
}

// PERCORRER ÁRVORE POS-ORDEM:
void posOrdem(no* r) {
	pilha* p, * p2;

	criar(p);
	criar(p2);

	if (r != NULL) {
		empilhar(p, r);
		while (!evazia(p)) {
			r = desempilhar(p);
			empilhar(p2, r);
			if (r->esq != NULL) {
				empilhar(p, r->esq);
			}
			if (r->dir != NULL) {
				empilhar(p, r->dir);
			}
		}
		while (!evazia(p2)) {
			r = desempilhar(p2);
			printf("%i ", r->info);
		}
	}
	printf("\n");
	system("pause");
}

//void frequencia(no *r){

