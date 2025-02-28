/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Selecionar os melhores candidatos*
* para residencia medica                                 *
* Data - 28/02/2025                                      * 
* Autor: Sabrina Silva Duarte;2040482422021              *
*--------------------------------------------------------*/

#include <stdio.h>

// estrutura para armazenar informações dos candidatos
typedef struct
{
    char nome[100];
    float notas_PE[4], notas_AC[5], notas_PP[10], notas_EB[3], nota_final;
} Candidato;

// obtem as notas de um candidato, com mensagens separando por matéria
void obterNotas(float *notas, int tamanho, const char *materia)
{
    int nota_valida;
    for (int i = 0; i < tamanho; i++)
    {
        do
        {
            printf("Para a materia %s\ninsira a nota %d: ", materia, i + 1);
            nota_valida = scanf("%f", &notas[i]);
            if (nota_valida != 1 || notas[i] < 0 || notas[i] > 10)
            {
                printf("Nota inválida!Digite apenas valores de 0 a 10.\n");
                // limpa o buffer de entrada
                while (getchar() != '\n')
                    ;
            }
        } while (nota_valida != 1 || notas[i] < 0 || notas[i] > 10);
    }
}

// calculo da nota final excluindo a maior e a menor nota
float calculo_nota(float *notas, int tamanho)
{
    if (tamanho <= 2)
    {
        float soma = 0;
        for (int i = 0; i < tamanho; i++)
            soma += notas[i];
        // para evitar erro de divisão por zero
        return soma / tamanho;
    }

    float soma = 0, maior = notas[0], menor = notas[0];
    for (int i = 0; i < tamanho; i++)
    {
        if (notas[i] > maior)
            maior = notas[i];
        if (notas[i] < menor)
            menor = notas[i];
        soma += notas[i];
    }
    return (soma - maior - menor) / (tamanho - 2);
}

int main()
{
    // definindo um máximo fixo de 50 candidatos
    Candidato candidatos[50];

    // entrada de dados para cada candidato
    for (int i = 0; i < 50; i++)
    {
        printf("Insira o nome do %d candidato: ", i + 1);
        // para permitir a entrada de nomes com espaços
        scanf(" %99[^\n]", candidatos[i].nome);

        // para obter as notas separadas por matéria
        obterNotas(candidatos[i].notas_PE, 4, "Prova Escrita (PE)");
        obterNotas(candidatos[i].notas_AC, 5, "Análise de Currículo (AC)");
        obterNotas(candidatos[i].notas_PP, 10, "Prova Prática (PP)");
        obterNotas(candidatos[i].notas_EB, 3, "Entrevista em Banca Avaliadora (EB)");

        // cálculo da nota final
        candidatos[i].nota_final = calculo_nota(candidatos[i].notas_PE, 4) * 0.3 +
                                   calculo_nota(candidatos[i].notas_AC, 5) * 0.1 +
                                   calculo_nota(candidatos[i].notas_PP, 10) * 0.4 +
                                   calculo_nota(candidatos[i].notas_EB, 3) * 0.2;
    }

    // ordenando os melhores candidatos pela nota final
    for (int i = 0; i < 50 - 1; i++)
    {
        for (int j = 0; j < 50 - i - 1; j++)
        {
            if (candidatos[j].nota_final < candidatos[j + 1].nota_final)
            {
                Candidato temp = candidatos[j];
                candidatos[j] = candidatos[j + 1];
                candidatos[j + 1] = temp;
            }
        }
    }

    // exibindo os 15 melhores candidatos
    printf("\nClassificação:\n");
    int limite = (50 < 15) ? 50 : 15;
    for (int i = 0; i < limite; i++)
    {
        printf("%d- %-30s | %.2f\n", i + 1, candidatos[i].nome, candidatos[i].nota_final);
    }

    return 0;
}
