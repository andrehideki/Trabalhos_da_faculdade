#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Pilha.h"

/*
	Resumo do c�digo:
	1-Incializa pilhas
	2-Le uma express�o do usuario
	3-Joga a express�o coletada para a fun��o resolve_expressao()
		Que sera responsavel pelo controle de ler a express�o inteira atraves da fun��o le_expressao();
			Fun��o le_expressao()
				� responsavel por empilhar ,na pilha correspondente ,o caractere passado nos argumentos e 
				incementar 1 na variavel auxi e auxf que servem de controle na hora da resosu��o da
				express�o digitada pelo usuario	
		Quando auxf = 1 ,(incrementado quando le_expressao acha ')'), 
			ele desempilha os ultimo 2 operandos ,3 operadores e realiza
			as opera��es nescessarias.
		Quando c = '\0 'quer dizer que a express�o terminou e 
			j� foram feitos os processos nescessarios para a 
			conclus�o do algoritimo.  
	

*/
void imprime_intrucoes(){
	
	printf("==========ALGORITIMO DE DIJKSTRA v1.0==========\n\n");
	printf("------------------------------------------\n\n");
	printf("->>INSTRUCOES:\n\n");
	printf("\t1-Operacoes devem ser feitas somente dentro de parenteses;\n");
	printf("\t2-O programa processa somente as operacoes:\n");
	printf("\t\tSoma\t\t+\n");
	printf("\t\tSubtracao\t-\n");
	printf("\t\tMultiplicacao\t*\n\n");
	printf("-------------------------------------------\n\n");
}

int le_expressao(pilha *operadores ,pilha *operandos,char c,int *auxi,int *auxf){
	
	if(c>=48&&c<=57){
	    if(push(operandos,c)){//Empilha na pilha de Operandos
            printf("%c empilhado na pilha de operandos\n",c);
        }
	}else if(c==40||c==41||c==42||c==43||c==45){
        if(c==40){
            ++(*auxi);
            //printf("auxi = %d\n",*auxi);
        }

        if(c==41){
            ++(*auxf);
            //printf("auxf = %d\n",*auxf);
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


int resolve_expressao(pilha* operadores ,pilha* operandos,char expressao[]){
	int i=0,resultado;
	int auxi=0,auxf=0,tam_expressao = strlen(expressao)-1;//Variaveis de controle
	char c;

    getchar();
    c=expressao[i];
    
	while(auxi>=0||i!=tam_expressao-1||c!='\0'){
		
		if(le_expressao(operadores,operandos,c,&auxi,&auxf)){
            printf("Falha na leitura da expressao!\n");
            return 1;
		}		
		if(auxf==1){	//Se auxf != 0 ele entra aqui e realiza a opera��o
 			
			auxf--;
			pop(operadores);
            printf(") desempilhado da pilha de operadores\n");
            auxi--;
            //printf("Agora o auxf ta valendo 1\n");	

            int num1 = (int)pop(operandos)-48;
            int num2 =  (int)pop(operandos)-48;
            getchar();
            printf("Operador desempilhado da pilha de operadores\n");
            switch(pop(operadores)){
            case 43:
                resultado = num1+num2;
                printf("%d + %d\n",num1,num2);
                break;
            case 45:
                resultado = num1-num2;
                printf("%d - %d\n",num1,num2);
                break;
            case 42:
                resultado = num1*num2;
                printf("%d * %d\n",num1,num2);
                break;
            }
			
			pop(operadores);
            printf("Desempilhou '('\n");
			
			push(operandos,(char)resultado+48);
            printf("Resultado atual = %d\n",resultado);

		
		}
		++i;
		
		c=expressao[i];
		if(c == '\0'){
			break;	
		}	
	}
	return 0;
}


int main(){
	
	
	int sair=0,opc_sair;//sair = false
	char expressao[100];
	
	//1-Duas pilhas s�o criadas...
	pilha operadores;
	pilha operandos;
		
	//2-L� uma express�o digitada pelo usu�rio
		
	while(!sair){
		
		system("cls");
		imprime_intrucoes();
		incializar_pilha(&operadores);
		incializar_pilha(&operandos);
		
		printf("--------------------------------------\n");
		printf("\nDigite uma expressao:\n>>>  ");
	    fgets(expressao,100,stdin);
	    fflush(stdin);
		expressao[strlen(expressao)-1] = '\0';
		
		
		/*3-Imprime o resultado da expressa� atrav�s da fun��o "resolve_express�o"
		*/
		if(resolve_expressao(&operadores,&operandos,expressao)){
	        printf("Falhou!\n");
	        getchar();
	        exit(1);
		}
		printf("----------------------------------------------\n");
		printf("\nOperacao finalizada com sucesso!\n\n");
		printf("Operacao:\t%s\nResultado final da operacao:\t%d\n\n",expressao,(int)pop(&operandos)-48);
		getchar();
		fflush(stdin);
		system("cls");
		
		printf("Deseja realizar outra operacao?\n\t'1'para sim;\n\t'0'para nao;\n>>>  ");
		scanf("%d",&opc_sair);
		fflush(stdin);
		if(!opc_sair){
			system("cls");
			printf("\nAplicacao finalizada com sucesso !\nPressione qualquer tecla para sair...\n");
			getchar();
			sair = 1;
			
		}
		system("cls");
		
	}
	
	return 0;
}

