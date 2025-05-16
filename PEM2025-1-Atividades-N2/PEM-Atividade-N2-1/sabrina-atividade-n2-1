/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Solicitar e ordenar dados em     *
* sequência                                              *
* Data - 15/05/2025                                      * 
* Autor: Sabrina Silva Duarte;2040482422021              *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> // Para usar o malloc e free

//funcao que mostra os números na tela
void mostrar(int *ponteiro_vetor, int tamanho) {
    //vai passar por cada posição do vetor
    for(int contador = 0; contador < tamanho; contador++) {
        //imprime o número atual + um espaço
        printf("%d ", ponteiro_vetor[contador]);
    }
    printf("\n"); //pula linha no final
}


// BUBBLE SORT
void bubble(int *vetor, int tam) {
    int temp; //variavel temporária para fazer a troca
    int i, j; //contadores para os loops
    
    //primeiro loop: controla quantas vezes vamos passar pelo vetor
    for(i = 0; i < tam-1; i++) {
        //segundo loop: compara elementos 
        for(j = 0; j < tam-i-1; j++) {
            //se o numero atual for maior que o proximo
            if(vetor[j] > vetor[j+1]) {
                //FAZ A TROCA:
                temp = vetor[j];          //guarda o número atual
                vetor[j] = vetor[j+1];    //coloca o próximo no lugar
                vetor[j+1] = temp;        //completa a troca
            }
        }
    }
}


//INSERTION SORT
void insertion(int *vetor, int tam) {
    int chave, j; 
    
    //começa do segundo elemento (indice 1)
    for(int i = 1; i < tam; i++) {
        chave = vetor[i]; //elemento atual a ser inserido
        j = i-1;          //começa a comparar com o anterior
        
        //enquanto nao chegar no inicio E o elemento anterior for maior
        while(j >= 0 && vetor[j] > chave) {
            vetor[j+1] = vetor[j]; //empurra o numero maior para direita
            j--;                   //vai para o elemento anterior
        }
        vetor[j+1] = chave; //coloca a chave na posicao correta
    }
}


int main() {
    int qtd;          //vai guardar quantos numeros o usuário quer
    int *original;    //ponteiro para o vetor original
    int *copia_bubble; //ponteiro para copia (Bubble Sort)
    int *copia_insert; //ponteiro para copia (Insertion Sort)
    
    
    //pede a quantidade de numeros
    printf("Quantos numeros voce quer ordenar? ");
    scanf("%d", &qtd);
    
    //aloca memoria para os vetores (tamanho qtd * tamanho de um int)
    original = (int*)malloc(qtd * sizeof(int));
    copia_bubble = (int*)malloc(qtd * sizeof(int));
    copia_insert = (int*)malloc(qtd * sizeof(int));
    
    //pede os numeros um por um
    printf("Digite os %d numeros (aperte ENTER apos cada um):\n", qtd);
    for(int i = 0; i < qtd; i++) {
        scanf("%d", &original[i]);       //le do teclado
        copia_bubble[i] = original[i];   //faz copia para Bubble
        copia_insert[i] = original[i];   //faz copia para Insertion
    }
    
    //mstra o vetor original
    printf("\nVetor original: ");
    mostrar(original, qtd);
    
    //ordena com Bubble Sort e mostra
    bubble(copia_bubble, qtd);
    printf("Bubble Sort:    ");
    mostrar(copia_bubble, qtd);
    
    //ordena com Insertion Sort e mostra
    insertion(copia_insert, qtd);
    printf("Insertion Sort: ");
    mostrar(copia_insert, qtd);
    
    //libera a memoria alocada
    free(original);
    free(copia_bubble);
    free(copia_insert);
    
    printf("\nFim do programa! Pressione ENTER para sair...");
    getchar(); //espera o usuario apertar ENTER
    return 0;
}
