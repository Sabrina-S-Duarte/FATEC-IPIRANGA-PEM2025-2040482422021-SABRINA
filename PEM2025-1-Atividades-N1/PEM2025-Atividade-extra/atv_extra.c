#include <stdio.h>

//mostra os endereços dos elementos do array
void mostrarEnderecos(int array[], int tamanho) {
    printf("Enderecos dos elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: %p\n", i, (void*)&array[i]);
    }
}

//encontra o maior elemento do array
int encontrarMaior(int array[], int tamanho) {
    int maior = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

//calcula a soma dos elementos do array
int calcularSoma(int array[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma;
}

// modifica o array para novos valores
void modificarArray(int array[], int tamanho) {
    int novosValores[] = {10, 20, 6, 16, 30};
    for (int i = 0; i < tamanho; i++) {
        array[i] = novosValores[i];
    }
    printf("Array modificado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

//mostra a posição de memória do elemento específico
void mostrarPosicaoMemoria(int array[], int tamanho, int posicao) {
    if (posicao >= 0 && posicao < tamanho) {
        printf("Posicao de memoria do elemento %d: %p\n", posicao, (void*)&array[posicao]);
    } else {
        printf("Posicao invalida!\n");
    }
}

int main() {
    int arrayOriginal[] = {5, 10, 3, 8, 15};
    int tamanho = 5; // Tamanho do array

    //mostra os endereços dos elementos do array
    mostrarEnderecos(arrayOriginal, tamanho);

    //encontra e mostrar o maior elemento
    int maior = encontrarMaior(arrayOriginal, tamanho);
    printf("Maior elemento do array: %d\n", maior);

    //calcula e mostra a soma dos elementos
    int soma = calcularSoma(arrayOriginal, tamanho);
    printf("Soma dos elementos do array: %d\n", soma);

    //modifica o array para novos valores
    modificarArray(arrayOriginal, tamanho);

    //mostra a posição de memória do elemento específico
    int posicao = 2;
    mostrarPosicaoMemoria(arrayOriginal, tamanho, posicao);

    return 0;
}
