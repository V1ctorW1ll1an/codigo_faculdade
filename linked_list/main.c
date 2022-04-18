#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "MinhaBiblioteca.c"

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
    if (!list) {
        printf("\n\n A lista esta vazia!\n\n");
        return;
    }
    while (list) {
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
    while (temp) {
        if (!strcmp(temp->data.cpf, cpf)) {
            printNode(temp);
            return;
        }
        temp = temp->next;
    }

    printf("\nO cliente com cpf %s nao foi encontrado! \n\n", cpf);
}

void deleteByCpf(struct Node **headRef, struct Node **tail, char cpf[]) {
    struct Node *temp = *headRef;
    struct Node *prev;

    if (temp && !strcmp(temp->data.cpf, cpf)) {
        *headRef = temp->next;
        free(temp);
        printf("\nCliente cpf: %s apagado com sucesso!\n\n", cpf);
        return;
    }

    while (temp && strcmp(temp->data.cpf, cpf)) {
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

    printf("\nCliente cpf: %s apagado com sucesso!\n\n", cpf);
}

void saveBackup(struct Node *list) {
    FILE *fptr;
    fptr = fopen("backup.txt", "w");
    struct Node *iterator = list;

    if (fptr == NULL) {
        printf("Error\n");
        return;
    }

    else {
        while (iterator) {
            if (iterator->next)
                fprintf(fptr, "%s\n%s\n%s\n%s\n%d\n", iterator->data.nome, iterator->data.cpf, iterator->data.email, iterator->data.endereco, iterator->data.telefone);
            else
                fprintf(fptr, "%s\n%s\n%s\n%s\n%d", iterator->data.nome, iterator->data.cpf, iterator->data.email, iterator->data.endereco, iterator->data.telefone);
            iterator = iterator->next;
        }
    }

    printf("\n\nDados exportados com sucesso!\n\n");

    fclose(fptr);
}

void readBackup(struct Node **list, struct Node **tail) {
    FILE *reads;
    char telefone[15];

    reads = fopen("backup.txt", "r");

    if (reads == NULL) {
        printf("Error");
    } else {
        while (!feof(reads)) {
            TypeData *data = (TypeData *)malloc(sizeof(TypeData));
            fgets(data->nome, 50, reads);
            fgets(data->cpf, 15, reads);
            fgets(data->email, 50, reads);
            fgets(data->endereco, 100, reads);
            fgets(telefone, 15, reads);
            data->telefone = atoi(telefone);
            insertClient(list, tail, *data);
        }
    }
}

int main() {
    int option = 0;
    struct Node *list = NULL, *tail = NULL;
    struct Client client;
    // readBackup(&list, &tail);

    do {
        system("cls");
        cor(63);
        janela1(3, 3, 10, 40);
        option = menu(111, 63, 4, 4);
        switch (option) {
            case 1:
                cor(2);
                system("cls");
                client = readClient();
                insertClient(&list, &tail, client);
                printf("\n");
                system("pause");
                break;
            case 2:
                cor(2);
                system("cls");
                printf("Digite o CPF: ");
                fflush(stdin);
                gets(&client.cpf);
                searchByCpf(list, client.cpf);
                printf("\n");
                system("pause");
                break;
            case 3:
                cor(2);
                system("cls");
                printf("Digite o CPF: ");
                fflush(stdin);
                gets(&client.cpf);
                deleteByCpf(&list, &tail, client.cpf);
                system("pause");
                break;
            case 4:
                cor(2);
                system("cls");
                printList(list);
                printf("\n");
                system("pause");
                break;
            case 5:
                cor(2);
                system("cls");
                saveBackup(list);
                system("pause");
                break;
            default:
                cor(2);
                system("cls");
                printf("DIGITE UMA TECLA PARA FINALIZAR");
                getch();
        }
    } while (option != 6);

    return 0;
}
