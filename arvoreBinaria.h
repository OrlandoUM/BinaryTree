#ifndef _minhas_funcoes_h_
#define _minhas_funcoes_h_

// STRUCTS:
struct no {
	int info;
	no* dir;
	no* esq;
};

struct pilha {
	no* info;
	pilha* prox;
};

// ASSINATURAS:
void criar(pilha*& p);
void empilhar(pilha*& p, no* r);
no* desempilhar(pilha*& p);
int evazia(pilha* p);

void arvoreVazia(no*& r);
bool inserirR(no*& r, int num);
bool inserirI(no*& r, int num);
int numFolhasR(no*& r);
int numFolhasI(no*& r);
void emOrdem(no* r);
void preOrdem(no* r);
void posOrdem(no* r);
//void frequencia(no *r);

#endif
#pragma once
