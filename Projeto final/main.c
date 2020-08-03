#include "Estrutura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 25


int MenuInicial()
{
    printf("\n--- Menu Inicial ---\n");
    printf("0 - Sair\n");
    printf("1 - Cadastra Elemento\n");
    printf("2 - Cadastra Componente\n");
    printf("3 - Exibe Elemento\n");
    printf("4 - Exibe Componente\n");
    printf("5 - Pede Emprestado\n");
}

int main()
{

    tElementos *e = NULL;
    tComponente *c = NULL;
    IniciaComponente(&c);
    IniciaElementos(&e);
    int comando;
    /*CadastraComponentes(&e, "RESISTOR", "40 OHM", 3, "CAIXA A1");
    CadastraComponentes(&e, "RESISTOR", "40 OHM", 1, "CAIXA A1");
    CadastraComponentes(&e, "RESISTOR", "20 OHM", 10, "CAIXA A1");
    CadastraComponentes(&e, "RESISTOR", "100 OHM", 15, "CAIXA A1");
    CadastraComponentes(&e, "RESISTOR", "2K OHM", 40, "CAIXA A1");
    CadastraComponentes(&e, "RESISTOR", "1K OHM", 22, "CAIXA A1");
    CadastraComponentes(&e, "RESISTOR", "3.3K OHM", 20, "CAIXA A1");
    //CAPACITOR
    CadastraComponentes(&e, "CAPACITOR", "40 OHM", 20, "CAIXA B1");
    CadastraComponentes(&e, "CAPACITOR", "40 OHM", 20, "CAIXA B1");
    CadastraComponentes(&e, "CAPACITOR", "20 OHM", 10, "CAIXA B1");
    CadastraComponentes(&e, "CAPACITOR", "100 OHM", 15, "CAIXA B1");
    CadastraComponentes(&e, "CAPACITOR", "2K OHM", 40, "CAIXA B1");
    CadastraComponentes(&e, "CAPACITOR", "1K OHM", 22, "CAIXA B1");
    CadastraComponentes(&e, "CAPACITOR", "3.3K OHM", 20, "CAIXA B1");
    //INDUTOR
    CadastraComponentes(&e, "INDUTOR", "40 OHM", 20, "CAIXA C1");
    CadastraComponentes(&e, "INDUTOR", "20 OHM", 10, "CAIXA C1");
    CadastraComponentes(&e, "INDUTOR", "100 OHM", 15, "CAIXA C1");
    CadastraComponentes(&e, "INDUTOR", "2K OHM", 40, "CAIXA C1");
    CadastraComponentes(&e, "INDUTOR", "1K OHM", 22, "CAIXA C1");
    CadastraComponentes(&e, "INDUTOR", "3.3K OHM", 20, "CAIXA C1");
    //Transistor
    CadastraComponentes(&e, "TRANSISTOR", "40 OHM", 20, "CAIXA C1");
    CadastraComponentes(&e, "TRANSISTOR", "20 OHM", 10, "CAIXA C1");
    CadastraComponentes(&e, "TRANSISTOR", "100 OHM", 15, "CAIXA C1");
    CadastraComponentes(&e, "TRANSISTOR", "2K OHM", 40, "CAIXA C1");
    CadastraComponentes(&e, "TRANSISTOR", "1K OHM", 22, "CAIXA C1");
    CadastraComponentes(&e, "TRANSISTOR", "3.3K OHM", 20, "CAIXA C1");

    ExibeComponentes(e,"RESISTOR");
    ExibeComponentes(e, "CAPACITOR");
    ExibeComponentes(e,"INDUTOR");
    ExibeComponentes(e, "TRANSISTOR");

    */
//CARREGA O ARQUIVO
    FILE *arq;
    char nome[MAX_CHAR], caract[MAX_CHAR], local[MAX_CHAR];
	int quant, indice = 0;

	arq = fopen("Componentes.txt", "r");
	if(arq == NULL){
	    printf("Erro, nao foi possivel realizar a leitura da base de dados\n");
        return -1;
    }

    //Arquivo na formatacao nome | caracteristica | quantidade | localizacao\n
    while((fscanf(arq,"%s %s %d %s\n", nome, caract, &quant, local))!=EOF ){
         strupr(nome);
         CadastraElementos(&e, nome);
         CadastraComponentes(&e, nome, caract, quant, local);
    }
	fclose(arq);


    while(comando =! 0){
       MenuInicial();
       scanf("%d", &comando);
       switch(comando){

            case 0:
                //salvar arquivos
                arq = fopen("Componentes.txt", "w");
                tComponente *no = (e)->comp;

                for(;e!=NULL;){
                    for(;no!=NULL ;){

                        fprintf(arq ,"%s %s %d %s\n", (e)->nome, (no)->desc.caracteristica, (no)->desc.quantidade, (no)->desc.localizacao);
                        no = no->prox;
                    }
                    e = (e)->prox;
                }
                fclose(arq);
                printf("Adeus...\n");
                return 1;
                break;
            case 1:
                printf("Digite o Elemento: ");
                scanf("%*c%s", &nome);
                strupr(nome);
                CadastraElementos(&e, nome);
                break;
            case 2:
                printf("Digite o Componente: ");
                scanf("%*c%s", &nome);
                strupr(nome);
                printf("Digite caracteristica: ");
                scanf("%*c%s", &caract);
                printf("Digite onde sera guardado o componente: ");
                scanf("%*c%s", &local);
                printf("Digite a quantidade: ");
                scanf("%d", &quant);

                CadastraComponentes(&e, nome, caract, quant, local);
                break;
            case 3:
                printf("\n----------- Tipos de elementos cadastrados -------------\n");
                ExibeElementos(e);
                printf("-------------------------------------------------------\n");
                break;
            case 4:
                printf("Digite o nome do componente: ");
                scanf("%*c%s", &nome);
                strupr(nome);

                ExibeComponentes(e, nome);
                break;
            case 5:
                printf("Digite o Componente: ");
                scanf("%*c%s", &nome);
                strupr(nome);
                printf("Digite caracteristica: ");
                scanf("%*c%s", &caract);
                printf("Digite a quantidade: ");
                scanf("%d", &quant);

                SolicitaComponente(&e, nome, caract, quant);

            default:
                printf("\nOpcao Impossivel");
        }

    }

}
