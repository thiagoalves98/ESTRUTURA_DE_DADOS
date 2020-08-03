#ifndef ESTRUTURA_H_INCLUDED
#define ESTRUTURA_H_INCLUDED
#define MAX_CHAR 25 //define o numero maximo de caracteres permetidos na descricao

/*Componente|Característica|Quantidade|Localização*/

typedef struct Descricao{
    char caracteristica[MAX_CHAR];
    int quantidade;
    char localizacao[MAX_CHAR];
}tDescricao;

typedef struct Componente{
   tDescricao desc;
   struct tComponente *prox;
}tComponente;

typedef struct Elementos{
    char nome[MAX_CHAR];
    struct tComponente *comp;
    struct tElementos *prox;
}tElementos;

extern tElementos *getElementos(char *nom);
extern tComponente *getComponente(char *caract, int quant, char *local);

extern void IniciaElementos(tElementos **lista);
extern void IniciaComponente(tComponente **lista);

extern int CadastraElementos(tElementos **lista, char *nome);
extern int CadastraComponentes(tElementos **lista, char *nome, char *caract, int quant, char *local);

extern void ExibeElementos(const tElementos *elemento);
extern void ExibeComponentes(const tElementos *elemento, char *nome);

extern int SolicitaComponente(tElementos **lista, char *nome, char *caract, int quant);



#endif // ESTRUTURA_H_INCLUDED
