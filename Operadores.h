typedef struct Operadores{
	char op[100];
	int topo;
}operadores;

void incializar_pilha();
int esta_cheia(operadores *);
int esta_vazia(operadores *);
int push(operadores *,char op);//Empilha um operador
int pop(operadores *);
void exibe_pilha(operadores *);//Exibe a pilha inteira






