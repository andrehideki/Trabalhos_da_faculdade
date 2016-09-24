#include<stdio.h>
#include<stdlib.h>
#include "Pilha.h"

void incializar_pilha(pilha* op){
	op->topo = -1;
	printf("Pilha inicializada com sucesso!\nTopo = %d\n\n",op->topo);
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
		printf("\nTopo = %d\n",ope->topo);
		return 1;
	}

}

char pop(pilha *ope){
	/*if(esta_vazia(op))
		printf("Esta vazia\n");*/
    --(ope->topo);

	return ope->op[(ope->topo)+1];

}
