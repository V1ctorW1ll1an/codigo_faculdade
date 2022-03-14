#include <stdio.h>
#include <stdlib.h>

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

void Insere(TipoItem x, TipoLista *Lista) {
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void Imprime(TipoLista l) {
    TipoApontador Aux = l.Primeiro->Prox;

    while (Aux != NULL) {
        printf("\n\nItem: %d", Aux->Item.Chave);
        printf("\tNome: %s", Aux->Item.Nome);
        printf("\tFone: %d", Aux->Item.Telefone);
        Aux = Aux->Prox;
    }
}

void PesquisaX2(TipoItem x, TipoLista *l) {
    TipoApontador Aux = l->Primeiro->Prox;
    int Encontrei = 0;
    while (Aux != NULL) {
        if (Aux->Item.Chave == x.Chave) {
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

void Pesquisa(TipoItem x, TipoLista l) {
    TipoApontador Aux = l.Primeiro->Prox;
    int Encontrei = 0;
    while (Aux->Prox != NULL) {
        if (Aux->Item.Chave == x.Chave)
            Encontrei = 1;
        Aux = Aux->Prox;
    }
    if (Encontrei)
        printf("\nO Elemento %d está na Lista!", x.Chave);
    else
        printf("\nO Elemento %d não está na Lista!", x.Chave);
}

void Retira(TipoLista *Lista, TipoItem x) {
    TipoApontador p, q;

    p = Lista->Primeiro;

    while (p->Prox != NULL && p->Prox.Item != x) {
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

/*void Imprime(TipoLista Lista)
{ TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL)
    { printf("%d\n", Aux -> Item.Chave);
      Aux = Aux -> Prox;
    }
}*/

/* ========================================================================== */

int main() {
    TipoItem valor;
    int i;
    TipoLista lista;

    FLVazia(&lista);

    for (i = 0; i < 3; i++) {
        printf("\nInforme um valor para inserir na lista: ");
        scanf("%d", &valor.Chave);
        printf("Digite o nome: ");
        fflush(stdin);
        gets(valor.Nome);
        printf("Digite o Telefone: ");
        scanf("%d", &valor.Telefone);
        Insere(valor, &lista);
    }

    Imprime(lista);

    printf("Digite um valor: ");
    scanf("%d", &valor.Chave);

    PesquisaX2(valor, &lista);

    getch();

    Imprime(lista);

    // printf("O que deseja pesquisar: ");
    // scanf("%d",&valor.Chave);
    // Pesquisa(valor,lista);

    getch();

    // TipoLista lista;
    // TipoItem item;
    // int vetor[MAX];
    // TipoApontador p;
    // int i, j, k, n;
    // float  tamanho=0;

    // FLVazia(&lista);

    /*Gera uma permutacao aleatoria de chaves entre 1 e MAX*/
    // for(i = 0; i < MAX; i++) vetor[i] = i + 1;
    // for(i = 0; i < MAX; i++)
    //   { k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
    //     j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
    //     n = vetor[k];
    //     vetor[k] = vetor[j];
    //     vetor[j] = n;
    //   }
    /*Insere cada chave na lista */
    // for (i = 0; i < MAX; i++)
    //   { item.Chave = vetor[i];
    //     Insere(item, &lista);
    //     tamanho++;
    //     printf("Inseriu: %d \n", item.Chave);
    //   }
    // Imprime(lista);

    /*Retira cada chave da lista */
    // for(i = 0; i < MAX; i++)
    //{ /*escolhe uma chave aleatoriamente */
    //   k = (int) ((tamanho) * rand() / (RAND_MAX + 1.0));
    //   p = lista.Primeiro;
    /*retira chave apontada */
    //   Retira(p, &lista, &item);
    //   tamanho--;
    //   printf("Retirou: %d\n", item.Chave);
    // }
    // Imprime (lista);
    // return(0);
}
