/* ========================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include "MinhaBiblioteca.c"

#define INICIOARRANJO   0
#define MAXTAM          100

typedef int TipoChave;

typedef int TipoApontador;

typedef struct {
  TipoChave Chave;
  char Nome[30];
  int Idade;
  char Curso[50];
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================== */

void FLVazia(TipoLista *Lista)
{ 
	Lista -> Primeiro = INICIOARRANJO;
  	Lista -> Ultimo = Lista -> Primeiro;
}  /* FLVazia */

int Vazia(TipoLista Lista)
{ 
	return (Lista.Primeiro == Lista.Ultimo);
}  /* Vazia */

void Insere(TipoItem item, TipoLista *Lista)
{ 
	if (Lista -> Ultimo >= MAXTAM) {
		printf("Lista esta cheia\n");
	}
  	else { 
	  	Lista -> Item[Lista -> Ultimo] = item;
        Lista -> Ultimo++;
    }
}  /* Insere */


void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{ 
	int Aux;
	TipoItem itemVazio;
  	if (Vazia(*Lista) || p >= Lista -> Ultimo) 
  	{ 
		printf(" Erro   Posicao nao existe\n");
    	return;
  	}
  	*Item = Lista -> Item[p];
  	Lista -> Ultimo--;
  	for (Aux = p; Aux < Lista -> Ultimo; Aux++)
    	Lista -> Item[Aux] = Lista -> Item[Aux + 1];
    Lista -> Item[Lista->Ultimo] = itemVazio;
}  /* Retira */

void Imprime(TipoLista Lista)
{ 
	int Aux;
	
	for (Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++)
	{
    	printf("Chave = %d\n", Lista.Item[Aux].Chave);
    	printf("Nome  = %s\n", Lista.Item[Aux].Nome);
    	printf("Idade = %d\n", Lista.Item[Aux].Idade);
    	printf("Curso = %s\n", Lista.Item[Aux].Curso);
    	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
}  /* Imprime */

TipoApontador Pesquisa(TipoItem item, TipoLista Lista, int porNome)
{ 	
	int Aux;
	for (Aux = Lista.Primeiro; Aux < (Lista.Ultimo); Aux++) {
	
		if(Lista.Item[Aux].Nome == item.Nome && porNome)
			return Aux;
	
		else{
			if (Lista.Item[Aux].Chave==item.Chave)
				return Aux;
		}
		
	}
	return -1;
}  /* Pesquisar */

void imprimeItemLista(TipoLista Lista, int index){
	printf("Chave = %d\n", Lista.Item[index].Chave);
	printf("Nome  = %s\n", Lista.Item[index].Nome);
	printf("Idade = %d\n", Lista.Item[index].Idade);
	printf("Curso = %s\n", Lista.Item[index].Curso);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}


/* ========================================================================== */
int main()
{
	TipoLista lista;
  	TipoItem item;
  	int retorno;
  	FLVazia(&lista);
  
	int i,j,resp=0;
    do{	
    	system("cls");
		cor(63);
    	janela1(3, 3, 18, 58);
		resp = menu(111,63,4,4);
    	switch (resp)
    	{
           case 1: //inserir elemento na lista
           		cor(2);
           		system("cls");
           		printf("Digite valor da chave: ");
           		scanf("%d",&item.Chave);
           		fflush(stdin);
           		printf("Digite o nome do Aluno: ");
           		gets(&item.Nome);
           		printf("Digite a Idade do Aluno: ");
           		scanf("%d",&item.Idade);
           		fflush(stdin);
           		printf("Digite o curso do Aluno: ");
           		gets(&item.Curso);
           		
      			Insere(item, &lista);
      			printf("\nAluno inserido na lista\n\n");
      			system("pause");
           		break;            
           case 2: //pesquisar elemento na lista por chave
           		cor(2);
           		system("cls");
           		printf("Digite uma chave para pesquisar: ");
	       		fflush(stdin);
           		scanf("%d",&item.Chave);
           		fflush(stdin);
           		retorno = Pesquisa(item, lista, 0);
           		if (retorno>-1) {
           			printf("Elemento encontrado na posicao %d da lista.\n\n",retorno); 
           			imprimeItemLista(lista, retorno);          			
				} else {
					printf("Elemento nao encontrado na lista\n\n");
				}
				system("pause");
                break;
            case 3: //pesquisar elemento na lista por nome
           		cor(2);
           		system("cls");
           		printf("Digite o nome para pesquisar: ");
           		scanf("%s",&item.Nome);
           		retorno = Pesquisa(item, lista, 1);
           		if (retorno>-1) {
           			printf("Elemento encontrado na posicao %d da lista.\n\n",retorno);
					imprimeItemLista(lista, retorno);            			
				} else {
					printf("Elemento nao encontrado na lista\n\n");
				}
				system("pause");
                break;
           case 4: //remover elemento da lista por chave
		   		cor(2);
           		system("cls");
           		printf("Digite uma chave para remover: ");
           		fflush(stdin);
           		scanf("%d",&item.Chave);
           		fflush(stdin);
           		retorno = Pesquisa(item, lista, 0);
				if (retorno>-1) {
					Retira(retorno, &lista, &item);
      				printf("Elemento retirado da lista\n\n");					
				} else {
					printf("Elemento nao encontrado na lista\n\n");					
				}
				system("pause");
                break;
            case 5: //remover elemento da lista por nome
		   		cor(2);
	       		system("cls");
	       		printf("Digite um nome para remover: ");
	       		fflush(stdin);
	       		scanf("%s",&item.Nome);
	       		fflush(stdin);
	       		retorno = Pesquisa(item, lista, 1);
				if (retorno>-1) {
					Retira(retorno, &lista, &item);
	  				printf("Elemento retirado da lista\n\n");					
				} else {
					printf("Elemento nao encontrado na lista\n\n");					
				}
				system("pause");
	            break;
	        case 6: //imprime lista
		   		cor(2);
	       		system("cls");
	       		printf("Lista: \n");
	       		fflush(stdin);
				Imprime(lista);
				system("pause");
	            break;
           default: //Finalizar o sistema
           		cor(2);
				system("cls");
                printf("DIGITE UMA TECLA PARA FINALIZAR");                
                getch();
    	}
	}while(resp!=7);    
}
