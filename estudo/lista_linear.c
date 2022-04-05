#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "MinhaBiblioteca.c"

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    char Nome[50];
    int Telefone;
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct {
    TipoApontador Primeiro, Ultimo;
    
} TipoLista;

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem item, TipoLista *Lista) {
	
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = item;
    Lista->Ultimo->Prox = NULL;
}

void Imprime(TipoLista l) {
    TipoApontador Aux = l.Primeiro->Prox;

    while (Aux != NULL) {
        printf("\n\nItem: %d", Aux->Item.Chave);       
		printf("\nNome: %s", Aux->Item.Nome);
        printf("\nFone: %d\n", Aux->Item.Telefone);
        Aux = Aux->Prox;
   }
 }

 void PesquisaX2(TipoItem item, TipoLista *l) {
     TipoApontador Aux = l->Primeiro->Prox;
     int Encontrei = 0;
     while (Aux != NULL) {
         if (Aux->Item.Chave == item.Chave) {
             Encontrei = 1;
             Aux->Item.Chave *= 2;
         }
         Aux = Aux->Prox;
     }
     if (Encontrei)
         printf("\nO elemento foi multiplicado");
     else
         printf("\nO elemento não foi multiplicado");
}

void ImprimeItem(TipoItem item){
	printf("\n\nItem: %d", item.Chave);       
	printf("\nNome: %s", item.Nome);
    printf("\nFone: %d\n", item.Telefone);
}

 void Pesquisa(TipoItem item, TipoLista l, int tipo) {
     TipoApontador Aux = l.Primeiro->Prox;
     int encontrou = 0;
     while(Aux != NULL) {
        if(tipo == 1){
        	if(!strcmp(Aux->Item.Nome,  item.Nome)){
        		encontrou = 1;
        		break;
			}		
		}
		else{
			if (Aux->Item.Chave == item.Chave){
				encontrou = 1;
				break;
			}            	
		}
         Aux = Aux->Prox;
     }
     
	 if(encontrou == 1){
		ImprimeItem(Aux->Item);
	 }
	 else{
		printf("Item não encontrado");
	 }
	 
}

 void Retira(TipoLista *Lista, TipoItem *item) {
   TipoApontador p, q;

    p = Lista->Primeiro;

    while (p->Prox != NULL && p->Prox->Item.Chave != item->Chave) {
        p = p->Prox;
    }

     if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
         printf(" Erro! Lista vazia ou posição não existe\n");
         return;
     }
    q = p->Prox;
    p->Prox = q->Prox;
    if (p->Prox == NULL) Lista->Ultimo = p;

    free(q);
}



/* ========================================================================== */

int main() {
    TipoLista lista;
    TipoItem item;
    FLVazia(&lista);

    int i, j, resp = 0;
    do {
        system("cls");
        cor(63);
        janela1(3, 3, 18, 58);
        resp = menu(111, 63, 4, 4);
        switch (resp) {
            case 1:  // inserir elemento na lista
                cor(2);
                system("cls");
                printf("Digite valor da chave: ");
                scanf("%d", &item.Chave);
                fflush(stdin);
                printf("Digite o nome: ");
                gets(&item.Nome);
                printf("Digite a telefone: ");
                scanf("%d", &item.Telefone);
                fflush(stdin);
                Insere(item, &lista);
                printf("\nPessoa inserida na lista\n\n");
                system("pause");
                break;
            case 2: //pesquisar elemento na lista por chave
                 cor(2);
                 system("cls");
                 printf("Digite uma chave para pesquisar: ");
                 fflush(stdin);
                 scanf("%d", &item.Chave);
                 fflush(stdin);
                 Pesquisa(item, lista, 0);
                 system("pause");
                break;
            case 3:  // pesquisar elemento na lista por nome
                 cor(2);
                 system("cls");
                 printf("Digite o nome para pesquisar: ");
                 scanf("%s", &item.Nome);
                 Pesquisa(item, lista, 1);
                 system("pause");
                break;
            case 4:  // remover elemento da lista por chave
                 cor(2);
                 system("cls");
                 printf("Digite uma chave para remover: ");
                 fflush(stdin);
                 scanf("%d", &item.Chave);
                 fflush(stdin);
                 Pesquisa(item, lista, 0);
//                 if (retorno > -1) {
//                     Retira(retorno, &lista, &item);
//                    printf("Elemento retirado da lista\n\n");
//                 } else {
//                     printf("Elemento nao encontrado na lista\n\n");
//                 }
//                 system("pause");
                break;
            case 5:  // remover elemento da lista por nome
                // cor(2);
                // system("cls");
                // printf("Digite um nome para remover: ");
                // fflush(stdin);
                // scanf("%s", &item.Nome);
                // fflush(stdin);
                // retorno = Pesquisa(item, lista, 1);
                // if (retorno > -1) {
                //     Retira(retorno, &lista, &item);
                //     printf("Elemento retirado da lista\n\n");
                // } else {
                //     printf("Elemento nao encontrado na lista\n\n");
                // }
                // system("pause");
                break;
            case 6:  // imprime lista
                cor(2);
                system("cls");
                printf("Lista: \n");
                fflush(stdin);
                Imprime(lista);
                system("pause");
                break;
            default:  // Finalizar o sistema
                cor(2);
                system("cls");
                printf("DIGITE UMA TECLA PARA FINALIZAR");
                getch();
        }
    } while (resp != 7);
}

// int main() {
//     TipoItem valor;
//     int i;
//     TipoLista lista;

//     FLVazia(&lista);

//     for (i = 0; i < 3; i++) {
//         printf("\nInforme um valor para inserir na lista: ");
//         scanf("%d", &valor.Chave);
//         printf("Digite o nome: ");
//         fflush(stdin);
//         gets(valor.Nome);
//         printf("Digite o Telefone: ");
//         scanf("%d", &valor.Telefone);
//         Insere(valor, &lista);
//     }

//     Imprime(lista);

//     printf("Digite um valor: ");
//     scanf("%d", &valor.Chave);

//     PesquisaX2(valor, &lista);

//     getch();

//     Imprime(lista);

//     // printf("O que deseja pesquisar: ");
//     // scanf("%d",&valor.Chave);
//     // Pesquisa(valor,lista);

//     getch();

//     // TipoLista lista;
//     // TipoItem item;
//     // int vetor[MAX];
//     // TipoApontador p;
//     // int i, j, k, n;
//     // float  tamanho=0;

//     // FLVazia(&lista);

//     /*Gera uma permutacao aleatoria de chaves entre 1 e MAX*/
//     // for(i = 0; i < MAX; i++) vetor[i] = i + 1;
//     // for(i = 0; i < MAX; i++)
//     //   { k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
//     //     j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
//     //     n = vetor[k];
//     //     vetor[k] = vetor[j];
//     //     vetor[j] = n;
//     //   }
//     /*Insere cada chave na lista */
//     // for (i = 0; i < MAX; i++)
//     //   { item.Chave = vetor[i];
//     //     Insere(item, &lista);
//     //     tamanho++;
//     //     printf("Inseriu: %d \n", item.Chave);
//     //   }
//     // Imprime(lista);

//     /*Retira cada chave da lista */
//     // for(i = 0; i < MAX; i++)
//     //{ /*escolhe uma chave aleatoriamente */
//     //   k = (int) ((tamanho) * rand() / (RAND_MAX + 1.0));
//     //   p = lista.Primeiro;
//     /*retira chave apontada */
//     //   Retira(p, &lista, &item);
//     //   tamanho--;
//     //   printf("Retirou: %d\n", item.Chave);
//     // }
//     // Imprime (lista);
//     // return(0);
// }
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "MinhaBiblioteca.c"

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    char Nome[50];
    int Telefone;
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct {
    TipoApontador Primeiro, Ultimo;
    
} TipoLista;

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem item, TipoLista *Lista) {
	
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = item;
    Lista->Ultimo->Prox = NULL;
}

void Imprime(TipoLista l) {
    TipoApontador Aux = l.Primeiro->Prox;

    while (Aux != NULL) {
        printf("\n\nItem: %d", Aux->Item.Chave);       
		printf("\nNome: %s", Aux->Item.Nome);
        printf("\nFone: %d\n", Aux->Item.Telefone);
        Aux = Aux->Prox;
   }
 }

 void PesquisaX2(TipoItem item, TipoLista *l) {
     TipoApontador Aux = l->Primeiro->Prox;
     int Encontrei = 0;
     while (Aux != NULL) {
         if (Aux->Item.Chave == item.Chave) {
             Encontrei = 1;
             Aux->Item.Chave *= 2;
         }
         Aux = Aux->Prox;
     }
     if (Encontrei)
         printf("\nO elemento foi multiplicado");
     else
         printf("\nO elemento não foi multiplicado");
}

void ImprimeItem(TipoItem item){
	printf("\n\nItem: %d", item.Chave);       
	printf("\nNome: %s", item.Nome);
    printf("\nFone: %d\n", item.Telefone);
}

 void Pesquisa(TipoItem item, TipoLista l, int tipo) {
     TipoApontador Aux = l.Primeiro->Prox;
     int encontrou = 0;
     while(Aux != NULL) {
        if(tipo == 1){
        	if(!strcmp(Aux->Item.Nome,  item.Nome)){
        		encontrou = 1;
        		break;
			}		
		}
		else{
			if (Aux->Item.Chave == item.Chave){
				encontrou = 1;
				break;
			}            	
		}
         Aux = Aux->Prox;
     }
     
	 if(encontrou == 1){
		ImprimeItem(Aux->Item);
	 }
	 else{
		printf("Item não encontrado");
	 }
	 
}

 void Retira(TipoLista *Lista, TipoItem *item) {
   TipoApontador p, q;

    p = Lista->Primeiro;

    while (p->Prox != NULL && p->Prox->Item.Chave != item->Chave) {
        p = p->Prox;
    }

     if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
         printf(" Erro! Lista vazia ou posição não existe\n");
         return;
     }
    q = p->Prox;
    p->Prox = q->Prox;
    if (p->Prox == NULL) Lista->Ultimo = p;

    free(q);
}



/* ========================================================================== */

int main() {
    TipoLista lista;
    TipoItem item;
    FLVazia(&lista);

    int i, j, resp = 0;
    do {
        system("cls");
        cor(63);
        janela1(3, 3, 18, 58);
        resp = menu(111, 63, 4, 4);
        switch (resp) {
            case 1:  // inserir elemento na lista
                cor(2);
                system("cls");
                printf("Digite valor da chave: ");
                scanf("%d", &item.Chave);
                fflush(stdin);
                printf("Digite o nome: ");
                gets(&item.Nome);
                printf("Digite a telefone: ");
                scanf("%d", &item.Telefone);
                fflush(stdin);
                Insere(item, &lista);
                printf("\nPessoa inserida na lista\n\n");
                system("pause");
                break;
            case 2: //pesquisar elemento na lista por chave
                 cor(2);
                 system("cls");
                 printf("Digite uma chave para pesquisar: ");
                 fflush(stdin);
                 scanf("%d", &item.Chave);
                 fflush(stdin);
                 Pesquisa(item, lista, 0);
                 system("pause");
                break;
            case 3:  // pesquisar elemento na lista por nome
                 cor(2);
                 system("cls");
                 printf("Digite o nome para pesquisar: ");
                 scanf("%s", &item.Nome);
                 Pesquisa(item, lista, 1);
                 system("pause");
                break;
            case 4:  // remover elemento da lista por chave
                 cor(2);
                 system("cls");
                 printf("Digite uma chave para remover: ");
                 fflush(stdin);
                 scanf("%d", &item.Chave);
                 fflush(stdin);
                 Pesquisa(item, lista, 0);
//                 if (retorno > -1) {
//                     Retira(retorno, &lista, &item);
//                    printf("Elemento retirado da lista\n\n");
//                 } else {
//                     printf("Elemento nao encontrado na lista\n\n");
//                 }
//                 system("pause");
                break;
            case 5:  // remover elemento da lista por nome
                // cor(2);
                // system("cls");
                // printf("Digite um nome para remover: ");
                // fflush(stdin);
                // scanf("%s", &item.Nome);
                // fflush(stdin);
                // retorno = Pesquisa(item, lista, 1);
                // if (retorno > -1) {
                //     Retira(retorno, &lista, &item);
                //     printf("Elemento retirado da lista\n\n");
                // } else {
                //     printf("Elemento nao encontrado na lista\n\n");
                // }
                // system("pause");
                break;
            case 6:  // imprime lista
                cor(2);
                system("cls");
                printf("Lista: \n");
                fflush(stdin);
                Imprime(lista);
                system("pause");
                break;
            default:  // Finalizar o sistema
                cor(2);
                system("cls");
                printf("DIGITE UMA TECLA PARA FINALIZAR");
                getch();
        }
    } while (resp != 7);
}

// int main() {
//     TipoItem valor;
//     int i;
//     TipoLista lista;

//     FLVazia(&lista);

//     for (i = 0; i < 3; i++) {
//         printf("\nInforme um valor para inserir na lista: ");
//         scanf("%d", &valor.Chave);
//         printf("Digite o nome: ");
//         fflush(stdin);
//         gets(valor.Nome);
//         printf("Digite o Telefone: ");
//         scanf("%d", &valor.Telefone);
//         Insere(valor, &lista);
//     }

//     Imprime(lista);

//     printf("Digite um valor: ");
//     scanf("%d", &valor.Chave);

//     PesquisaX2(valor, &lista);

//     getch();

//     Imprime(lista);

//     // printf("O que deseja pesquisar: ");
//     // scanf("%d",&valor.Chave);
//     // Pesquisa(valor,lista);

//     getch();

//     // TipoLista lista;
//     // TipoItem item;
//     // int vetor[MAX];
//     // TipoApontador p;
//     // int i, j, k, n;
//     // float  tamanho=0;

//     // FLVazia(&lista);

//     /*Gera uma permutacao aleatoria de chaves entre 1 e MAX*/
//     // for(i = 0; i < MAX; i++) vetor[i] = i + 1;
//     // for(i = 0; i < MAX; i++)
//     //   { k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
//     //     j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
//     //     n = vetor[k];
//     //     vetor[k] = vetor[j];
//     //     vetor[j] = n;
//     //   }
//     /*Insere cada chave na lista */
//     // for (i = 0; i < MAX; i++)
//     //   { item.Chave = vetor[i];
//     //     Insere(item, &lista);
//     //     tamanho++;
//     //     printf("Inseriu: %d \n", item.Chave);
//     //   }
//     // Imprime(lista);

//     /*Retira cada chave da lista */
//     // for(i = 0; i < MAX; i++)
//     //{ /*escolhe uma chave aleatoriamente */
//     //   k = (int) ((tamanho) * rand() / (RAND_MAX + 1.0));
//     //   p = lista.Primeiro;
//     /*retira chave apontada */
//     //   Retira(p, &lista, &item);
//     //   tamanho--;
//     //   printf("Retirou: %d\n", item.Chave);
//     // }
//     // Imprime (lista);
//     // return(0);
// }
