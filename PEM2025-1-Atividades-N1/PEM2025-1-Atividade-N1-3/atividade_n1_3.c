/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Organizar o setor de estoque de  *
* uma empresa de comercio atacadista com refatoramento   *
* Data - 07/03/2025                                      * 
* Autor: Sabrina Silva Duarte;2040482422021              *
*--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define RUAS 3
#define GONDOLAS 10
#define PRODUTOS 1

//funcao para encontrar um produto no estoque
int encontrar_produto(char estoque[RUAS][GONDOLAS][PRODUTOS][5], char codigo[5], int *rua, int *gondola) {
    for (int i = 0; i < RUAS; i++) {
        for (int j = 0; j < GONDOLAS; j++) {
            if (strcmp(estoque[i][j][0], codigo) == 0) {
                *rua = i;
                *gondola = j;
                return 1; //produto encontrado
            }
        }
    }
    //produto nao encontrado
    return 0;
}

//funcao para estocar um produto
void estocar_produto(char estoque[RUAS][GONDOLAS][PRODUTOS][5], char codigo[5]) {
    int rua, gondola;

    //verifica se o produto ja esta estocado
    if (encontrar_produto(estoque, codigo, &rua, &gondola)) {
        printf("O produto %s ja esta estocado na rua %c, gondola %d.\n", codigo, 'A' + rua, gondola + 1);
        return;
    }

    //encontra a primeira gondola vazia
    for (int i = 0; i < RUAS; i++) {
        for (int j = 0; j < GONDOLAS; j++) {
            if (strcmp(estoque[i][j][0], "") == 0) {
                strcpy(estoque[i][j][0], codigo);
                printf("Produto %s estocado na rua %c, gondola %d.\n", codigo, 'A' + i, j + 1);
                return;
            }
        }
    }

    printf("Nao ha espaço disponivel no estoque.\n");
}

//funcao para retirar um produto
void retirar_produto(char estoque[RUAS][GONDOLAS][PRODUTOS][5], char codigo[5]) {
    int rua, gondola;

    //verifica se o produto esta estocado
    if (encontrar_produto(estoque, codigo, &rua, &gondola)) {
        printf("Produto %s retirado da rua %c, gondola %d.\n", codigo, 'A' + rua, gondola + 1);
        //marca a gondola como vazia
        strcpy(estoque[rua][gondola][0], "");
    } else {
        printf("Produto %s nao encontrado no estoque.\n", codigo);
    }
}

//funcao para exibir o estoque
void exibir_estoque(char estoque[RUAS][GONDOLAS][PRODUTOS][5]) {
    printf("\nSituacao atual do estoque:\n");
    for (int i = 0; i < RUAS; i++) {
        for (int j = 0; j < GONDOLAS; j++) {
            if (strcmp(estoque[i][j][0], "") != 0) {
                printf("Rua %c, gondola %d: %s\n", 'A' + i, j + 1, estoque[i][j][0]);
            } else {
                printf("Rua %c, gondola %d: Vazia\n", 'A' + i, j + 1);
            }
        }
    }
}

//funcao principal
int main() {
    //inicia o estoque vazio
    char estoque[RUAS][GONDOLAS][PRODUTOS][5] = {0};
    int opcao;
    char codigo[5];

    while (1) {
        printf("\nSelecione uma opcao:\n");
        printf("1- Estocar produto\n");
        printf("2- Retirar produto\n");
        printf("3- Exibir estoque\n");
        printf("4- Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o codigo do produto: ");
                scanf("%s", codigo);
                estocar_produto(estoque, codigo);
                break;
            case 2:
                printf("Digite o codigo do produto: ");
                scanf("%s", codigo);
                retirar_produto(estoque, codigo);
                break;
            case 3:
                exibir_estoque(estoque);
                break;
            case 4:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida, tente novamente.\n");
        }
    }

    return 0;
}
