#include<stdio.h>
#include <stdlib.h>
#include "Pilha.h"
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


void le_expressao(pilha *operadores ,pilha *operandos,char c,int *auxi,int *auxf){
	switch(c){
		case 40://(
			auxi++;
		case 41://)
			auxf++;
		case 42://+
		case 43://*
		case 45://-
			push(operadores ,c);//Empilha na pilha de Operadores
			break;
		case 48://48 é o decimal do caractere'0'
		case 57://57 é o decimal do caractere'9'
			push(operandos,c);//Empilha na pilha de Operandos
			break;
		default:
			printf("Operador ou numero invalido!!!");//Coisas ruins podem acontecer!
            break;
		}

}
//3
int resolve_expressao(pilha* operadores ,pilha* operandos,char expressao[]){
	int i=0,res;
	int auxi=0,auxf=0;//Variaveis de controle
	char c;

	do{
		c=expressao[i];
		le_expressao(operadores,operandos,c,&auxi,&auxf);

		if(auxf){	//Se auxf != 0 ele entra aqui e realiza a operação
			/*
                Se der true:
                    1.Desempilha ) e zera auxf
                    2.Realiza a operação com os dois primeiros operandos + o primeiro operador
                    3.Desempilha Operador , desempilha 2 primeiros operandos
                    4.Empilha o resultado da operação;
			*/
			pop(operadores);
			auxf--;
			res = atoi(pop(operandos))+atoi(pop(operadores))+atoi(pop(operandos));//res recebe a soma das conveções para int dos 2 ultimos operandos e operador
			push(operandos,res);
		}

		i++;
	}while(i==100||auxi==0);//Quando o auxi zerar quer dizer a expressão terminou
	return pop(operandos);
}


int main(){

	//1-Cria 2 pilhas e jpa incializa em seguida...
	pilha operadores;
	pilha operandos;
	incializar_pilha(&operadores);
	incializar_pilha(&operandos);

	//2-Lê uma expressão digitada pelo usuário
	char expressao[100];
	printf("Digite uma expressao:\n>>>");
	scanf("%100[^\n]",expressao);

	/*3-Imprime o resultado da expressaõ através da função "resolve_expressão"




	*/
	printf("%d\n",resolve_expressao(&operadores,&operandos,expressao));	//imprime o resultado da operação;


	getchar();
	return 0;
}
