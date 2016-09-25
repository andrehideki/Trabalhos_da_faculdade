typedef struct Pilha{
	char op[100];
	int topo;
}pilha;


void incializar_pilha(pilha*);//Incializa a pilha de operadores ou operandos
int esta_cheia(pilha *);//Verifica se a pilha está cheia
int esta_vazia(pilha *);//Verifica se a pilha está vazia
int push(pilha *,char op);//Empilha operando ou operador
char pop(pilha *);//Desempilha operando








