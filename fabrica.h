typedef enum {LIVRE, CONSTANTE, FUNCAO} Amarracao;
typedef enum {VOID, CHAR, INT, FLOAT, DOUBLE, POINTER} Tipo;

typedef union
{
	char   vChar;
	int    vInt;
	float  vFloat;
	double vDouble;
	void  *vPointer;
} Valor;

typedef struct
{
	Amarracao amarracao;
	Tipo tipo;
	Valor valor;
} Parametro;
void *create (void *f, Tipo ret, unsigned n, Parametro *params);
/** \details Encontra parte do codigo de maquina no indice i da tabela
        \param leitura Argumento imediato no formato de string
        \param principais Ponteiro para os parametros
        \param i posicao da informacao requerida do vetor associado ao opcode
        \return Parte do opcode salvo na tabela em um inteiro
    */
void destroy(void *f,int recursivo);
/** \details Encontra parte do codigo de maquina no indice i da tabela
        \param leitura Argumento imediato no formato de string
        \param principais Ponteiro para os parametros
        \param i posicao da informacao requerida do vetor associado ao opcode
        \return Parte do opcode salvo na tabela em um inteiro
    *