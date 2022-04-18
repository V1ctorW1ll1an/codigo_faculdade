/* ========================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/* ========================================================================== */

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

void Retira(TipoLista *Lista, TipoItem x) {
    TipoApontador p, q;
    p = Lista->Primeiro;
    while (p->Prox != NULL && p->Prox->Item.Chave != x.Chave) {
        p = p->Prox;
    }
    if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
        printf(" Erro! Lista vazia ou posi��o n�o existe\n");
        return;
    }
    q = p->Prox;
    p->Prox = q->Prox;
    if (p->Prox == NULL)
        Lista->Ultimo = p;
    printf("\nSucesso! Chave %d removida da lista\n", x.Chave);
    free(q);
}

void RetiraNome(TipoLista *Lista, TipoItem x) {
    TipoApontador p, q;
    p = Lista->Primeiro;
    while (p->Prox != NULL && strcmp(p->Prox->Item.Nome, x.Nome) != 0) {
        p = p->Prox;
    }

    if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
        printf(" Erro! Lista vazia ou posi��o n�o existe\n");
        return;
    }
    q = p->Prox;
    p->Prox = q->Prox;
    if (p->Prox == NULL) Lista->Ultimo = p;
    printf("\nSucesso! Nome %s removido da lista\n", q->Item.Nome);
    free(q);
}

void Imprime(TipoLista Lista) {
    TipoApontador p;
    p = Lista.Primeiro;

    while (p->Prox != NULL) {
        p = p->Prox;
        printf("Chave = %d\n", p->Item.Chave);
        printf("Nome  = %s\n", p->Item.Nome);
        printf("Idade = %d\n", p->Item.Telefone);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
} /* Imprime */

TipoApontador Pesquisa(TipoItem item, TipoLista Lista) {
    TipoApontador p;
    p = Lista.Primeiro;

    while (p != NULL) {
        if (p->Item.Chave == item.Chave)
            return p;
        p = p->Prox;
    }
    return -1;
} /* Pesquisar */

TipoApontador PesquisaNome(TipoItem item, TipoLista Lista) {
    TipoApontador p;
    p = Lista.Primeiro;

    while (p != NULL) {
        if (strcmp(p->Item.Nome, item.Nome) == 0)
            return p;
        p = p->Prox;
    }
    return -1;
} /* Pesquisar */

/* ========================================================================== */
int main() {
    TipoLista lista;
    TipoItem item;
    TipoApontador retorno;
    FLVazia(&lista);

    int i, j, resp = 0;
    do {
        system("cls");
        cor(63);
        janela1(3, 3, 11, 28);
        resp = menu(111, 63, 4, 4);
        fflush(stdin);
        item.Chave = 0;
        switch (resp) {
            case 1:  // inserir elemento na lista
                cor(2);
                system("cls");
                printf("Digite valor da chave: ");
                scanf("%d", &item.Chave);
                fflush(stdin);
                if (item.Chave <= 0) {
                    printf("\nChave invalida...\n\n");
                } else {
                    printf("Digite o nome do Aluno: ");
                    gets(&item.Nome);
                    fflush(stdin);
                    printf("Digite o Telefone do Aluno: ");
                    scanf("%d", &item.Telefone);
                    Insere(item, &lista);
                    printf("\nAluno inserido na lista\n\n");
                }
                system("pause");
                break;
            case 2:  // pesquisar elemento na lista
                cor(2);
                system("cls");
                printf("Digite uma chave para pesquisar: ");
                scanf("%d", &item.Chave);
                retorno = Pesquisa(item, lista);
                if (retorno != -1) {
                    printf("Sucesso! Elemento encontrado.\n");
                    printf("Chave = %d\n", retorno->Item.Chave);
                    printf("Nome  = %s\n", retorno->Item.Nome);
                    printf("Idade = %d\n", retorno->Item.Telefone);
                    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                } else {
                    printf("Elemento nao encontrado na lista\n\n");
                }
                system("pause");
                break;
            case 3:  // remover elemento da lista
                cor(2);
                system("cls");
                printf("Digite uma chave para remover: ");
                scanf("%d", &item.Chave);
                Retira(&lista, item);
                system("pause");
                break;
            case 4:  // imprimir a lista inteira
                cor(2);
                system("cls");
                Imprime(lista);
                system("pause");
                break;
            case 5:  // pesquisar por nome
                cor(2);
                system("cls");
                printf("Digite um nome para pesquisar: ");
                gets(&item.Nome);
                retorno = PesquisaNome(item, lista);
                if (retorno != -1) {
                    printf("Sucesso! Elemento encontrado.\n");
                    printf("Chave = %d\n", retorno->Item.Chave);
                    printf("Nome  = %s\n", retorno->Item.Nome);
                    printf("Idade = %d\n", retorno->Item.Telefone);
                    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                } else {
                    printf("Elemento nao encontrado na lista\n\n");
                }
                system("pause");
                break;
            case 6:  // Deletar por nome
                cor(2);
                system("cls");
                printf("Digite um nome para remover: ");
                gets(&item.Nome);
                RetiraNome(&lista, item);
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
