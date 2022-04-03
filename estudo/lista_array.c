/* ========================================================================== */
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>


#define INICIOARRANJO   1
#define MAXTAM          100

typedef int TipoChave;

typedef int TipoApontador;

typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Primeiro, Ultimo;
} TipoLista;


/* ========================================================================== */

// FL => faz lista
void FLVazia(TipoLista *Lista)
{ 
	Lista -> Primeiro = INICIOARRANJO;
  	Lista -> Ultimo = Lista -> Primeiro;
}  /* FLVazia */

int Vazia(TipoLista Lista)
{ 
	return (Lista.Primeiro == Lista.Ultimo);
}  /* Vazia */

void Insere(TipoItem x, TipoLista *Lista)
{ 
	if (Lista->Ultimo > MAXTAM) {
		printf("Lista esta cheia\n");
	}
  	else { 
	  	Lista->Item[Lista->Ultimo - 1] = x;
        Lista->Ultimo++;
    }
}  /* Insere */

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{ 
	int Aux;

  	if (Vazia(*Lista) || p >= Lista -> Ultimo) 
  	{ 
		printf(" Erro Posicao nao existe\n");
    	return;
  	}
  	*Item = Lista -> Item[p - 1];
  	Lista -> Ultimo--;
  	for (Aux = p; Aux < Lista -> Ultimo; Aux++)
    	Lista -> Item[Aux - 1] = Lista -> Item[Aux];
}  /* Retira */

void Imprime(TipoLista Lista)
{ 
	int Aux;

  for (Aux = Lista.Primeiro - 1; Aux <= (Lista.Ultimo - 2); Aux++)
    printf("%d\n", Lista.Item[Aux].Chave);
}  /* Imprime */

/* ========================================================================== */

void menu(){
	printf("\nMenu\n");
	printf("\nOpcao 1: inserir na lista\n");
	printf("Opcao 2: Retirar da lista\n");
	printf("Opcao 3: Mostrar lista\n");
	printf("Opcao 4: Fechar programa\n");
}

int main(int argc, char *argv[])
{ 

	int option, itemToRemove;
	TipoLista lista;
    TipoItem item;
    int vetor[MAXTAM];
		
	FLVazia(&lista);


	do{
		system("cls");
		menu();
		printf("\nInforme a opcao: \n");
	    fflush(stdin);
     	scanf("%i", &option);
     	
		switch(option){
			
			case 1: 
			    system("cls");
				printf("Insira um numero para adicionar na lista: \n");
				fflush(stdin);
				scanf("%i", &item.Chave);
				Insere(item, &lista);
                printf("Inseriu: %d \n", item.Chave);
                system("pause");
				break;
			case 2:
				system("cls");
				printf("Insira um numero para remover da lista: \n");
				fflush(stdin);
				scanf("%i", &itemToRemove);
				Retira(itemToRemove, &lista, &item);
                printf("Retirou: %d\n", item.Chave);
                system("pause");
				break;
			case 3: 
			    system("cls");
				Imprime(lista);
				system("pause");
				fflush(stdin);
				break;
			case 4:
				break;
			default:
				printf("Opcao invalida!");
				system("pause");
				break;
		}
		
		// pegar opção
		
		
	}while(option != 4);
  
  
  return(0);
}

/* 
 struct timeval t;

  TipoLista lista;
  TipoItem item;
  int vetor[MAXTAM];
  int i, j, k, n, max;
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
  max = 10;
  FLVazia(&lista);
  
  //Gera uma permutacao aleatoria de chaves entre 1 e max
  for(i = 0; i < max; i++) 
  	vetor[i] = i + 1;
  	
  	
  for(i = 0; i < max; i++)
    {
	  k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      n = vetor[k];
      vetor[k] = vetor[j];
      vetor[j] = n;
    }
    
    
  //Insere cada chave na lista 
  for (i = 0; i < max; i++)
    { item.Chave = vetor[i];
      Insere(item, &lista);
      printf("Inseriu: %d \n", item.Chave);
    }
  Imprime(lista);
  
  

  //Retira cada chave da lista 
  for(i = 0; i < max; i++)
    { //escolhe uma chave aleatoriamente 
      j = (int) ((lista.Ultimo - 1) * rand() / (RAND_MAX + 1.0));
      //retira chave apontada 
      Retira(j, &lista, &item);
      printf("Retirou: %d\n", item.Chave);
    }
    
    
  Imprime (lista);
  */
