#include<stdio.h>
#include "Pilha.h"

void incializar_pilha(pilha* op){
	op->topo = -1;
}

int esta_cheia(pilha* op){
	return op->topo+1 >= 100;
}

int esta_vazia(pilha *op){
	return op->topo+1<=0;
}

int push(pilha *ope ,char op){//Empilha um operador
	if(esta_cheia(ope)){
		printf("A lista esta cheia!\n");
		return 0;
	}else{
		ope->op[++ope->topo] = op;
		return 1;
	}

}

char pop(pilha *op){
	/*if(esta_vazia(op))
		printf("Esta vazia\n");*/
    op->topo--;
	return op->op[op->topo];

}
