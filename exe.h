#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000
#define NAME_SIZE 30

typedef int (*exe)(); // Forma simplificada de chamar as funções principais

typedef struct {
    char nome[NAME_SIZE];
    int price;
    int qtd;

} Produto;

typedef struct {
    char nome[NAME_SIZE];
    int idade;

} Pessoa;

// Exercícios:

// 1. Soma de Arrays:
int somaArray();

// 2. Contagem de Arrays:
int countVogais();

// 3. Cadastro de Produtos:
int painelProdutos();

// 4. multiplicação de Matrizes:
int matriz();
void multiplyMatrices(int row1, int col1, int matrix1[row1][col1], int row2, int col2, int matrix2[row2][col2], int result[row1][col2]);
void transposeMatrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);

// 5. Frase Maiúscula:
int stringUpper();
void toUpperCase(char *str);

// 6. Ordernar Array de structs:
int structOrder();
int comparaIdade(const void *a, const void *b);
int comparaNome(const void *a, const void *b);

// Funções auxiliares
void clearBuffer(); // Limpeza de Buffer



