// Arquivo de defini??es das fun??es auxiliares em C
// Este arquivo pode ser declarado no seu programa fonte como uma bilbioteca
// mas deve ser utilizado " " no lugar de < >. Este arquivo deve estar no mesmo
// diret?rio que o arquivo fonte principal.

#include <windows.h>

void cor(int cor_letra) {
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut, cor_letra);
}

void gotoxy(int x, int y) {
    COORD c;
    c.X = y - 1;
    c.Y = x - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void janela1(int l1, int c1, int l2, int c2) {
    int j1;
    int j2;
    for (j1 = l1; j1 < l2; j1++)
        for (j2 = c1; j2 < c2; j2++) {
            gotoxy(j1, j2);
            printf(" ");
        }

    for (j1 = l1 + 1; j1 < l2; j1++) {
        gotoxy(j1, c1);
        printf("%c", 186);
    }
    for (j1 = l1 + 1; j1 < l2; j1++) {
        gotoxy(j1, c2);
        printf("%c", 186);
    }
    for (j1 = c1 + 1; j1 < c2; j1++) {
        gotoxy(l1, j1);
        printf("%c", 205);
    }
    for (j1 = c1 + 1; j1 < c2; j1++) {
        gotoxy(l2, j1);
        printf("%c", 205);
    }

    gotoxy(l1, c1);
    printf("%c", 201);
    gotoxy(l1, c2);
    printf("%c", 187);
    gotoxy(l2, c1);
    printf("%c", 200);
    gotoxy(l2, c2);
    printf("%c", 188);
}

void janela2(int l1, int c1, int l2, int c2) {
    int j1;
    int j2;
    for (j1 = l1; j1 < l2; j1++)
        for (j2 = c1; j2 < c2; j2++) {
            gotoxy(j1, j2);
            printf(" ");
        }
    for (j1 = l1 + 1; j1 < l2; j1++) {
        gotoxy(j1, c1);
        printf("%c", 179);
    }
    for (j1 = l1 + 1; j1 < l2; j1++) {
        gotoxy(j1, c2);
        printf("%c", 179);
    }
    for (j1 = c1 + 1; j1 < c2; j1++) {
        gotoxy(l1, j1);
        printf("%c", 196);
    }
    for (j1 = c1 + 1; j1 < c2; j1++) {
        gotoxy(l2, j1);
        printf("%c", 196);
    }

    gotoxy(l1, c1);
    printf("%c", 218);
    gotoxy(l1, c2);
    printf("%c", 191);
    gotoxy(l2, c1);
    printf("%c", 192);
    gotoxy(l2, c2);
    printf("%c", 217);
}

void janela1sombra(int l1, int c1, int l2, int c2) {
    int j1;
    int j2;
    for (j1 = l1; j1 < l2; j1++)
        for (j2 = c1; j2 < c2; j2++) {
            gotoxy(j1, j2);
            printf(" ");
        }
    for (j1 = l1 + 1; j1 < l2; j1++) {
        gotoxy(j1, c1);
        printf("%c", 186);
    }
    for (j1 = l1 + 1; j1 < l2; j1++) {
        gotoxy(j1, c2);
        printf("%c", 186);
    }
    for (j1 = c1 + 1; j1 < c2; j1++) {
        gotoxy(l1, j1);
        printf("%c", 205);
    }
    for (j1 = c1 + 1; j1 < c2; j1++) {
        gotoxy(l2, j1);
        printf("%c", 205);
    }

    gotoxy(l1, c1);
    printf("%c", 201);
    gotoxy(l1, c2);
    printf("%c", 187);
    gotoxy(l2, c1);
    printf("%c", 200);
    gotoxy(l2, c2);
    printf("%c", 188);

    cor(8);
    for (j1 = l1 + 1; j1 <= l2 + 1; j1++) {
        gotoxy(j1, c2 + 1);
        printf("%c", 219);
    }
    for (j1 = c1 + 1; j1 <= c2 + 1; j1++) {
        gotoxy(l2 + 1, j1);
        printf("%c", 223);
    }
}

void janela2sombra(int l1, int c1, int l2, int c2) {
    int j1;
    int j2;
    for (j1 = l1; j1 < l2; j1++)
        for (j2 = c1; j2 < c2; j2++) {
            gotoxy(j1, j2);
            printf(" ");
        }
    for (j1 = l1 + 1; j1 < l2; j1++) {
        gotoxy(j1, c1);
        printf("%c", 179);
    }
    for (j1 = l1 + 1; j1 < l2; j1++) {
        gotoxy(j1, c2);
        printf("%c", 179);
    }
    for (j1 = c1 + 1; j1 < c2; j1++) {
        gotoxy(l1, j1);
        printf("%c", 196);
    }
    for (j1 = c1 + 1; j1 < c2; j1++) {
        gotoxy(l2, j1);
        printf("%c", 196);
    }

    gotoxy(l1, c1);
    printf("%c", 218);
    gotoxy(l1, c2);
    printf("%c", 191);
    gotoxy(l2, c1);
    printf("%c", 192);
    gotoxy(l2, c2);
    printf("%c", 217);

    cor(8);
    for (j1 = l1 + 1; j1 <= l2 + 1; j1++) {
        gotoxy(j1, c2 + 1);
        printf("%c", 219);
    }
    for (j1 = c1 + 1; j1 <= c2 + 1; j1++) {
        gotoxy(l2 + 1, j1);
        printf("%c", 223);
    }
}

int menu(int c1, int c2, int linha, int col) {
    int op = 0, t = 19;
    int pos = 1;

    do {
        if (pos == 1) {
            cor(c1);

            gotoxy(linha, col);
            printf(" %c Inserir na lista   %c ", 16, 17);

        } else {
            cor(c2);

            gotoxy(linha, col);
            printf("   Inserir na lista     ");
        }
        if (pos == 2) {
            cor(c1);

            gotoxy(linha + 1, col);
            printf(" %c Pesquisar na lista (chave) %c ", 16, 17);

        } else {
            cor(c2);

            gotoxy(linha + 1, col);
            printf("   Pesquisar na lista (chave)   ");
        }
        if (pos == 3) {
            cor(c1);

            gotoxy(linha + 2, col);
            printf(" %c Pesquisar na lista (nome) %c ", 16, 17);

        } else {
            cor(c2);

            gotoxy(linha + 2, col);
            printf("   Pesquisar na lista (nome)  ");
        }
        if (pos == 4) {
            cor(c1);

            gotoxy(linha + 3, col);
            printf(" %c Excluir da lista (chave)  %c ", 16, 17);

        } else {
            cor(c2);

            gotoxy(linha + 3, col);
            printf("   Excluir da lista  (chave)   ");
        }
        if (pos == 5) {
            cor(c1);

            gotoxy(linha + 4, col);
            printf(" %c Excluir da lista (nome)  %c ", 16, 17);

        } else {
            cor(c2);

            gotoxy(linha + 4, col);
            printf("   Excluir da lista  (nome)   ");
        }
        if (pos == 6) {
            cor(c1);

            gotoxy(linha + 5, col);
            printf(" %c Imprime lista  %c ", 16, 17);

        } else {
            cor(c2);

            gotoxy(linha + 5, col);
            printf("   Imprime lista  ");
        }
        if (pos == 7) {
            cor(c1);
            gotoxy(linha + 6, col);
            printf(" %c SAIR               %c ", 16, 17);

        } else {
            cor(c2);

            gotoxy(linha + 6, col);
            printf("   SAIR                 ");
        }

        op = getch();
        if ((op == 80) || (op == 77))
            pos = (pos % 7) + 1;
        else if ((op == 72) || (op == 75)) {
            if (pos == 1)
                pos = 7;
            else
                pos--;
        }

    } while (op != 13);

    return pos;
}
