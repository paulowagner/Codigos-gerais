#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	char info;
	struct no *prox;
}no;

typedef struct fila
{
	no *ini;
	no *fim;
}fila;

typedef struct pilha
{
	no *ini;
	no *fim;
}pilha;

void push(fila *l,no *novo)
{
	novo->prox=NULL;
	if(l->ini==NULL)
	{
		l->ini=novo;
		l->fim=novo;
		return;
	}
	else{ 
		l->fim->prox=novo;
		l->fim=novo;
		return;
	}
}

void push_p(pilha *l,no *novo)
{
	novo->prox=NULL;
	if(l->ini==NULL)
	{
		l->ini=novo;
		l->fim=novo;
		return;
	}
	else{ 
		novo->prox=l->ini;
		l->ini=novo;
		return;
	}
}

no* pop(fila *l)
{
	if (l->ini==NULL)return NULL;
	no *aux=l->ini;
	if (l->ini==l->fim)
	{
		l->ini=l->fim=NULL;
		return aux;
	}
	l->ini=l->ini->prox;
	aux->prox=NULL;
	return aux;
}

void pop_p(pilha *p)
{
	if(p->ini==NULL)return;
	if(p->ini==p->fim)
	{
		p->ini=p->fim=NULL;
		return;
	}
	p->ini=p->ini->prox;
	return;
}

void imprimipilha(no *p)
{
	if(p==NULL)return;
	imprimipilha(p->prox);
	printf("%c ",p->info);
	return;
}
void permuta(fila *l,pilha *p)
{
	no *aux=pop(l),*aux2=aux;
	if (aux==NULL)
	{
		//imprimipilha(p->ini);
		//printf("\n");
		return;
	}
	do{
		
		push_p(p,aux2);	
		permuta(l,p);
		pop_p(p);
		push(l,aux2);
		if (l->ini!=aux)aux2=pop(l);
		else break;
	}while(1);
	return;
}

int main()
{
	fila *l;
	pilha *p;
	l=(fila*)malloc(sizeof(fila));
	p=(pilha*)malloc(sizeof(pilha));
	p->ini=p->fim=l->ini=l->fim=NULL;
	int n;
	scanf("%d",&n);	
	int i;
	char info[n];
	scanf("%s",info);
	no *novo;
	for(i=0;i<n;i++)
	{
		novo=(no*)malloc(sizeof(no));
		novo->info=info[i];
		novo->prox=NULL;
		push(l,novo);
	}
	permuta(l,p);
	return 0;
}
