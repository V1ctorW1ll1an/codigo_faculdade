#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Client {
    char nome[50];
    char cpf[15];
    char email[50];
    int telefone;
    char endereco[100];
};

typedef struct Client TypeData;

struct Node {
    TypeData data;
    struct Node *next;
};

struct Client readClient() {
    struct Client client;
    printf("\n Nome do cliente: ");
    fflush(stdin);
    gets(&client.nome);
    printf("\n CPF do cliente: ");
    fflush(stdin);
    gets(&client.cpf);
    printf("\n Email do cliente: ");
    fflush(stdin);
    gets(&client.email);
    printf("\n Telefone do cliente: ");
    fflush(stdin);
    scanf("%d", &client.telefone);
    printf("\n Endereco do cliente: ");
    fflush(stdin);
    gets(&client.endereco);
    return client;
}

void insertClient(struct Node **head, struct Node **tail, TypeData newData) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        (*head) = newNode;
        (*tail) = newNode;
    } else {
        (*tail)->next = newNode;
        (*tail) = newNode;
    }
    return;
}

void printList(struct Node *list) {
    while (list != NULL) {
        printf("\n Nome: %s", list->data.nome);
        printf("\n cpf: %s", list->data.cpf);
        printf("\n email: %s", list->data.email);
        printf("\n telefone: %d", list->data.telefone);
        printf("\n endereco: %s \n", list->data.endereco);

        list = list->next;
    }
}

void printNode(struct Node *node) {
    printf("\n Nome: %s", node->data.nome);
    printf("\n cpf: %s", node->data.cpf);
    printf("\n email: %s", node->data.email);
    printf("\n telefone: %d", node->data.telefone);
    printf("\n endereco: %s \n", node->data.endereco);
}

void searchByCpf(struct Node *list, char cpf[]) {
    struct Node *temp;
    temp = list;
    while (temp != NULL) {
        if (!strcmp(temp->data.cpf, cpf)) {
            printNode(temp);
            return;
        }
        temp = temp->next;
    }

    printf("\nO cliente com cpf %s nao foi encontrado! \n\n", cpf);
}

void deleteByCpf(struct Node **headRef, struct Node **tail, char cpf[]) {
    // struct Node *temp = *headRef;
    // struct Node *prev;

    // if (temp != NULL && !strcmp(temp->data.cpf, cpf)) {
    //     *headRef = temp->next;
    //     free(temp);
    //     return;
    // }

    // while (temp != NULL && strcmp(temp->data.cpf, cpf)) {
    //     prev = temp;
    //     temp = temp->next;
    // }

    // if (temp == NULL) {
    //     printf("O cpf %s nao foi encontrado!", cpf);
    //     return;
    // }

    // prev->next = temp->next;
    // if (prev->next == NULL) (*tail)->next = prev;

    // free(temp);

    struct Node *temp = *headRef;
    struct Node *prev;

    if (temp && !strcmp(temp->data.cpf, cpf)) {
        *headRef = temp->next;
        free(temp);
        printf("\nCliente apagado com sucesso!\n\n");
        return;
    }

    while (temp && !strcmp(temp->data.cpf, cpf)) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nO cpf %s nao foi encontrado!\n\n", cpf);
        return;
    }

    prev->next = temp->next;
    if (prev->next == NULL) (*tail)->next = prev;
    free(temp);

    printf("\nCliente apagado com sucesso!\n\n");
}

int main() {
    int option = 0;
    struct Node *list = NULL, *tail = NULL;
    struct Client client;

    strcpy(client.nome, "victor");
    strcpy(client.email, "victor@gmail.com");
    strcpy(client.endereco, "rua bla");
    strcpy(client.cpf, "12345");
    client.telefone = 1234456643;

    insertClient(&list, &tail, client);

    strcpy(client.nome, "marcos");
    strcpy(client.email, "marcos@gmail.com");
    strcpy(client.endereco, "rua foo");
    strcpy(client.cpf, "1234");
    client.telefone = 1234456643;

    insertClient(&list, &tail, client);

    strcpy(client.nome, "joao");
    strcpy(client.email, "joao@gmail.com");
    strcpy(client.endereco, "rua sla");
    strcpy(client.cpf, "12345678");
    client.telefone = 12344628383;

    insertClient(&list, &tail, client);

    deleteByCpf(&list, &tail, "12");
    printList(list);
    return 0;
}
