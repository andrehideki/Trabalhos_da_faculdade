typedef struct Operandos{
	char opn[100];
	int topo;
}operandos;


void opn_incializar_pilha(operandos *);
int opn_esta_cheia(operandos *);
int opn_esta_vazia(operandos *);
int opn_push(operandos *,char opn);//Empilha operando
int opn_pop(operandos *);//Desempilha operando
void opn_exibe_pilha(operandos *);//Imprime a pilha inteira






