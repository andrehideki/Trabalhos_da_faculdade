typedef struct Operadores{
	char op[100];
	int topo;
}operadores;

void ope_incializar_pilha();
int ope_esta_cheia(operadores *);
int ope_esta_vazia(operadores *);
int ope_push(operadores *,char op);//Empilha um operador
int ope_pop(operadores *);
void ope_exibe_pilha(operadores *);//Exibe a pilha inteira






