#include<stdio.h>
#include <stdlib.h>
#include "Operadores.h"
#include "Operandos.h"
/*
	1-Pedir e ler a expressão digitada pelo usuario
	2-Ler esse vetor,separar em vetores separados um para operadores e outro para operandos
		40-(
		41-)
		42-*
		43-+
		45--
		47-/

		Caso o operador for ')' incrementa 1 a variavel auxf , pois depois de sair do switch ele cai no frag e realiza os procedimentos nescessarios
		de empilhamento e desempilhamentpo

*/


void le_expressao(operadores *ope ,operandos *opn,char c,int *auxi,int *auxf){
	switch(c){
		case 40://(
			auxi++;
		case 41://)
			auxf++;
		case 42://+
		case 43://*
		case 45://-
			ope_push(ope ,c);//Empilha na pilha de Operadores
			break;
		case 48://48 é o decimal do caractere'0'
		case 57://57 é o decimal do caractere'9'
			opn_push(opn,c);//Empilha na pilha de Operandos
			break;
		default:
			printf("Operador ou numero invalido!!!");//Coisas ruins podem acontecer!
            break;
		}

}
int resolve_expressao(operadores *ope ,operandos *opn,char expressao[]){
	int i=0,res;
	char c;

	int auxi=0,auxf=0;//Variavel de controle
	do{
		c=expressao[i];
		le_expressao(ope,opn,c,&auxi,&auxf);

		if(auxf){	//Se auxf != 0 ele entra aqui e realiza a operação
			/*
				1.Desempilha ) e zera auxf
				2.Realiza a operação com os dois primeiros operandos + o primeiro operador
				3.Desempilha Operador , desempilha 2 primeiros operandos
				4.Empilha o resultado da operação;
			*/
			ope_pop(ope);
			auxf--;
			res=atoi(opn_pop(opn))+atoi(ope_pop(ope))+atoi(opn_pop(opn));//res recebe a soma das conveções para int dos 2 ultimos operandos e operador
			opn_push(opn,res);
		}

		i++;
	}while(i==100||auxi=0);//Quando o auxi zerar quer dizer a expressão terminou
	return opn_pop(opn);
}


int main(){

	//Incializar as pilhas...
	operandos opn;
	operadores ope;
	opn_incializar_pilha(opn);
	ope_incializar_pilha(ope);

	//1-Lê uma expressão digitada pelo usuário
	char expressao[100];
	printf("Digite uma expressao:n>>>");
	scanf("%100[^\n]",expressao);

	//2-Ler
	printf("%d\n",resolve_expressao(ope,opn,expressao));	//imprime o resultado da operação;


	getchar();
	return 0;
}
