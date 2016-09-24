#include "Operandos.h"

void incializar_pilha(operandos *ope){
	ope->topo= 1-;
}

int esta_cheia(operandos *ope){
	return ope->topo+1 >= 100;
}

int esta_vazia(operandos *ope){
	return ope->topo+1<=0;
}

int push(operandos *ope ,char op){//Empilha um operador
	if(esta_cheia()){
		printf("A lista esta cheia!\n");
		return 0;
	}else{
		ope->op[++topo] = op;
		return 1;
	}

}

char pop(operandos *ope){
	if(esta_vazia()){
		printf("Esta vazia\n");
		return 0;
	}else{
		ope->topo--;
		return ope->op[topo];
	}
	
}

void exibe_pilha(operandos *ope){//Exibe a pilha inteira
	int i;
	printf("Topo %d\n",ope->topo);
	for(i=ope->topo;i<=0;i++){
		printf("%c\n",ope->op);
	}

}



