#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int Chave;
  char acao[30];
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Fundo, Topo;
  int Tamanho;
} TipoPilha;

void FPVazia(TipoPilha *Pilha);
int Vazia(TipoPilha Pilha);
void Empilha(TipoItem x, TipoPilha *Pilha);
void Desempilha(TipoPilha *Pilha, TipoItem *Item);
int Tamanho(TipoPilha Pilha);
int menu();
void trocarTopos(TipoPilha *pilha);
void desempilhaPelaAcao(TipoPilha *pilha, TipoItem item);


int main()
{ 

  TipoPilha pilha;
  TipoItem item;
  int option;
  
  FPVazia(&pilha);
  
  
  do{
  	
	option = menu();
	
	switch(option) {
	    case 1:
	      	system("cls");
			printf("Informe o numero para empilhar: ");
			fflush(stdin);
			scanf("%d", &item.Chave);
			printf("\nInforme a acao para empilhar: ");
			fflush(stdin);
			gets(item.acao);
			Empilha(item, &pilha);
			printf("\n\nItem empilhado com sucesso! \n\n");
			system("pause");
	    	break; 
	    case 2:
	    	system("cls");
	    	Desempilha(&pilha, &item);
	    	printf("\n\nItem desempilhado com sucesso \n\n");
	    	system("pause");
	    	break;
	    case 3:
	    	system("cls");
	    	printf("\n\n O tamanho da pilha eh %d \n\n", pilha.Tamanho);
	    	system("pause");
	    	break;
	    case 4:
	    	system("cls");
	    	printf("\n\n Trocar de lugar os dois ultimos elementos da pilha.\n\n");
	    	trocarTopos(&pilha);
	    	printf("\n Itens trocados com sucesso! \n");
	    	system("pause");
	    	break;
	    case 5:
	    	system("cls");
	    	printf("\n\n Informe a acao do item a ser desempilhado: \n\n");
	    	fflush(stdin);
	    	gets(item.acao);
	    	desempilhaPelaAcao(&pilha, item);
	    	system("pause");
	    	break;
	    	
	    case 6:
	    	system("cls");
	    	printf("\n\nSaindoooo...\n\n");
	    	system("pause");
	    	break;
	  
	   default:
			printf("Valor inválido!");
			break;
	}
  	
  }while(option != 6);
  
  return(0);
}



void FPVazia(TipoPilha *Pilha)
{ 
    Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
  	Pilha->Fundo = Pilha->Topo;
  	Pilha->Topo->Prox = NULL;
  	Pilha->Tamanho = 0;
} 

int Vazia(TipoPilha Pilha)
{ 
	return (Pilha.Topo == Pilha.Fundo); 
} 

void Empilha(TipoItem x, TipoPilha *Pilha)
{ 
	TipoApontador Aux;
  	Aux = (TipoApontador) malloc(sizeof(TipoCelula));
  	Pilha->Topo->Item = x;
 	Aux->Prox = Pilha->Topo;
 	Pilha->Topo = Aux;
 	Pilha->Tamanho++;
} 

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{ 
	TipoApontador q;
  	if (Vazia(*Pilha)) { 
	  printf("Erro: lista vazia\n"); 
	  return; 
	}
  	q = Pilha->Topo;
  	Pilha->Topo = q->Prox;
  	*Item = q->Prox->Item;
  	free(q);  
	Pilha->Tamanho--;
} 

int Tamanho(TipoPilha Pilha)
{ 
	return (Pilha.Tamanho); 
} 

int menu()
{
	
	int option;
	
	system("cls");
	printf("\n\n Menu \n\n");
	printf("1 - empilhar \n");
	printf("2 - desempilhar \n");
	printf("3 - tamanho da lista \n");
	printf("4 - trocar de lugar ultimos elementos \n");
	printf("5 - desempilhar pela acao \n");
	printf("6 - sair \n");

	printf("\n\n");
	
	printf("opcao: ");
	fflush(stdin);
	scanf("%d", &option);
	
	return option;
}

void trocarTopos(TipoPilha *pilha)
{
	if(Vazia(*pilha)){
		printf("A pilha esta vazia!");
		return;
	}
	if(pilha->Tamanho < 2){
		printf("A pilha precisa ter pelo menos 2 items, tamanho atual : %d", pilha->Tamanho);
		return;
	}
	
	TipoApontador aux;
  	aux = pilha->Topo->Prox;
  	pilha->Topo->Prox = pilha->Topo;
  	pilha->Topo = aux;
  	free(aux);  
}


void desempilhaPelaAcao(TipoPilha *pilha, TipoItem item){
	
	if(Vazia(*pilha)){
		printf("Pilha vazia!");
		return;
	}
	
	TipoPilha pilhaAux;
	TipoCelula prox = pilha->Topo->Prox;
	
	while(prox){
		Empilha(prox->Item, &pilhaAux);
		if(!strcmp(item.acao, prox->Item.acao)){
			
		}
		prox = prox->Prox;
	}
}


















