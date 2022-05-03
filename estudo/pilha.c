#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int Chave;
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

int menu(){
	
	int option;
	
	system("cls");
	printf("\n\n Menu \n\n");
	printf("1 - empilhar \n");
	printf("2 - desempilhar \n");
	printf("3 - tamanho da lista \n");
	printf("4 - sair \n");

	printf("\n\n");
	
	printf("opcao: ");
	fflush(stdin);
	scanf("%d", &option);
	
	return option;
}

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
	    	printf("\n\nSaindoooo...\n\n");
	    	system("pause");
	    	break;
	  
	   default:
			printf("Valor inválido!");
			break;
	}
  	
  }while(option != 4);
  
  return(0);
}
