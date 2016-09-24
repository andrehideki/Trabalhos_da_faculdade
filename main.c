#include<stdio.h>
#include <stdlib.h>
#include<string.h>
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


int le_expressao(pilha *operadores ,pilha *operandos,char c,int *auxi,int *auxf){

	if(c>=48&&c<=57){
	    if(push(operandos,c)){//Empilha na pilha de Operandos
            printf("%c empilhado na pilha de operandos\n",c);
        }
	}else if(c==40||c==41||c==42||c==43||c==45){
        if(c==40){
            ++(*auxi);
            printf("auxi = %d\n",*auxi);
        }

        if(c==41){
            ++(*auxf);
            printf("auxf = %d\n",*auxf);
        }
        if(push(operadores,c)){//Empilha na pilha de Operadores
            printf("%c empilhado na pilha de operadores\n",c);
        }
	}else{
        printf("%d nem entrou Valor digitado invalido!\n",c);
        getchar();
        return 1;
	}
	fflush(stdin);
    getchar();
    return 0;
}
//3
int resolve_expressao(pilha* operadores ,pilha* operandos,char expressao[]){
	int i=0,res;
	int auxi=0,auxf=0,tam_expressao = strlen(expressao)-1;//Variaveis de controle
	char c;

    printf("Esta cheia?%s\ntopo = %d\n",esta_cheia(operadores)?"sim":"Nao",operadores->topo);//linha teste
	printf("Esta cheia?%s\ntopo = %d\n",esta_cheia(operandos)?"sim":"Nao",operandos->topo);//linha teste
    getchar();
	do{
		c=expressao[i];
		if(le_expressao(operadores,operandos,c,&auxi,&auxf)){
            printf("Falha na leitura da expressao!\n");
            return 1;
		}

		if(auxf==1){	//Se auxf != 0 ele entra aqui e realiza a operação
            printf("Agora o auxf ta valendo 1\n");
			/*
                Se der true:
                    1.Desempilha ) e zera auxf
                    2.Realiza a operação com os dois primeiros operandos + o primeiro operador
                    3.Desempilha Operador , desempilha 2 primeiros operandos
                    4.Empilha o resultado da operação;
			*/
			auxi--;
			auxf--;
			pop(operadores);
            printf("Desempilhou ')'\n");

            int num1 = atoi(pop(operandos));
            printf("num1 =%d\n",num1);
            switch(pop(operadores)){
            case '+':
                res = num1+pop(operandos);
                break;
            case '-':
                res = num1-pop(operandos);
                break;
            case '*':
                res = num1*pop(operandos);
                break;
            }
			//res = (atoi(pop(operandos)))+(atoi(pop(operadores)))+(atoi(pop(operandos)));//res recebe a soma das conveções para int dos 2 ultimos operandos e operador
			push(operandos,res);
			printf("res = %d",res);
		}

		i++;
	}while(auxi<=1||i==tam_expressao-1);//Quando o auxi zerar quer dizer a expressão terminou
	return 0;
}


int main(){

	//1-Cria 2 pilhas e jpa incializa em seguida...
	pilha operadores;
	pilha operandos;
	incializar_pilha(&operadores);
	incializar_pilha(&operandos);

	printf("Esta cheia?%s\n",esta_cheia(&operadores)?"sim":"Nao");//linha teste
	printf("Esta cheia?%s\n",esta_cheia(&operandos)?"sim":"Nao");//linha teste


	//2-Lê uma expressão digitada pelo usuário
	char expressao[100];
	printf("Digite uma expressao:\n>>>");
    //scanf("%100[^\n]",expressao);
    fgets(expressao,100,stdin);
	/*3-Imprime o resultado da expressaõ através da função "resolve_expressão"
	*/
	if(resolve_expressao(&operadores,&operandos,expressao)){
        printf("Falhou!\n");
        getchar();
        exit(1);
	}
	printf("%d\n",pop(&operandos));	//imprime o resultado da operação;


	getchar();
	return 0;
}
