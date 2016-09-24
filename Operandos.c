#include "Operandos.h"

void opn_incializar_pilha(operandos *opn){
	opn->topo= -1;
}

int opn_esta_cheia(operandos *opn){
	return opn->topo+1 >= 100;
}

int opn_esta_vazia(operandos *opn){
	return opn->topo+1<=0;
}

int opn_push(operandos *opn ,char op){//Empilha um operador
	if(esta_cheia()){
		printf("A lista esta cheia!\n");
		return 0;
	}else{
		opn->op[++topo] = op;
		return 1;
	}

}

char opn_pop(operandos *opn){
	if(esta_vazia()){
		printf("Esta vazia\n");
		return 0;
	}else{
		opn->topo--;
		return opn->op[topo];
	}

}

void opn_exibe_pilha(operandos *ope){//Exibe a pilha inteira
	int i;
	printf("Topo %d\n",opn->topo);
	for(i=opn->topo;i<=0;i++){
		printf("%c\n",opn->op);
	}

}



