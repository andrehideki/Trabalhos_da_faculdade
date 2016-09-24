#include<stdio.h>
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

typedef struct Operandos{
	int topo;
	char vetOperandos[100];
}operandos;

typedef struct Operadores{
	int topo;
	char vetOperadores[100];
}operadores;

void le_expressao(char c,int *auxi,int *auxf){
	switch(c){
		case 40://(
			auxi++;
		case 41://)
			auxf++;
		case 42://+
		case 43://*
		case 45://-
		case 47:// /
			push(operadores *ope ,op)//Empilha na pilha de Operadores
			break;
		case 48://48 é o decimal do caractere'0'
		case 57://57 é o decimal do caractere'9'
			//Empilha na pilha de Operandos
			break;
		default;
			printf("Operador ou numero invalido!!!");//Coisas ruins podem acontecer!
				
		}

}
int resolve_expressao(char expressao[]){
	int i=0,res;
	char c;
	
	int auxi=0,auxf=0,num=0;//Variavel de controle
	do{
		c=expressao[i];
		le_expressao(c,&auxi,&auxf);
		
		if(auxf){	//Se auxf != 0 ele entra aqui e realiza a operação
			/*
				1.Desempilha ) e zera auxf
				2.Realiza a operação com os dois primeiros operandos + o primeiro operador 
				3.Desempilha Operador , desempilha 2 primeiros operandos 
				4.Empilha o resultado da operação;
			*/
			pop(ope);
			auxf--;
			rest=atoi(pop(opn))+atoi(pop(ope))+atoi(pop(opn));//res recebe a soma das conveções para int dos 2 ultimos operandos e operador
			push(opn,res);
		}
		
		i++;
	}while(i==100||auxi=0);//Quando o auxi zerar quer dizer a expressão terminou
	return pop(opn);
}


int main(){
	
	//Incializar as pilhas...
	operandos opn;
	operadores ope;
	incializar_pilha(opn);
	incializar_pilha(ope);
	
	//1-Pedir
	char expressao[100];
	printf("Digite uma expressao:n>>>");
	scanf("%100[^\n]",expressao);
	
	//2-Ler
	printf("%d\n",resolve_expressao(expressao));	//imprime o resultado da operação;


	getchar();
	return 0;
}
