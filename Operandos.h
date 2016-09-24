typedef struct Operandos{
	char opn[100];
	int topo;
}operandos;


void incializar_pilha(operandos *);
int esta_cheia(operandos *);
int esta_vazia(operandos *);
int push(operandos *,char opn);//Empilha operando
int pop(operandos *);//Desempilha operando
void exibe_pilha(operandos *);//Imprime a pilha inteira






