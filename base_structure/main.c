#include <stdio.h>
#include <stdlib.h>

#include "MinhaBiblioteca.c"

int main() {
    int option = 0;

    do {
        system("cls");
        cor(63);
        janela1(3, 3, 10, 40);
        option = menu(111, 63, 4, 4);
        switch (option) {
            case 1:
                cor(2);
                system("cls");
                printf("Inserir Cliente na Lista");
                system("pause");
                break;
            case 2:
                cor(2);
                system("cls");
                printf("Pesquisar pelo cpf");
                system("pause");
                break;
            case 3:
                cor(2);
                system("cls");
                printf("Apagar cliente da lista");
                system("pause");
                break;
            case 4:
                cor(2);
                system("cls");
                printf("Mostrar todos clientes");
                system("pause");
                break;
            case 5:
                cor(2);
                system("cls");
                printf("Salvar clientes em txt");
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
