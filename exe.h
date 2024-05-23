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


// Exercícios:

// 1. Soma de Arrays:
int somaArray();

// 2. Contagem de Arrays:
int countVogais();

// 3. Cadastro de Produtos;
int painelProdutos();





// Funções auxiliares
void clearBuffer(); // Limpeza de Buffer