#include "Operadores.h"

void ope_incializar_pilha(operadores *ope){
	ope->topo= -1;
}

int ope_esta_cheia(operadores *ope){
	return ope->topo+1 >= 100;
}

int ope_esta_vazia(operadores *ope){
	return ope->topo+1<=0;
}

int ope_push(operadores *ope ,char op){//Empilha um operador
	if(esta_cheia()){
		printf("A lista esta cheia!\n");
		return 0;
	}else{
		ope->op[++topo] = op;
		return 1;
	}

}

char ope_pop(operadores *ope){
	if(esta_vazia()){
		printf("Esta vazia\n");
		return 0;
	}else{
		ope->topo--;
		return ope->op[topo];
	}

}

void exibe_pilha(operadores *ope){//Exibe a pilha inteira
	int i;
	printf("Topo %d\n",ope->topo);
	for(i=ope->topo;i<=0;i++){
		printf("%c\n",ope->op);
	}

}



