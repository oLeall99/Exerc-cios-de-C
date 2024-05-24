#include <stdio.h>
#include <ctype.h>
#include "exe.h"


// 1. Soma de valores de Array:
int somaArray(){
    int array[ARRAY_SIZE];
    int pos = 0;
    int soma;
    int opcao;

    do{
        soma = 0;
        for(int i = 0; i < pos; i++){
            soma += array[i];
        }

        printf("\n\033[34m");
        printf("|=======================|\n");
        printf("|    Soma de valores    |\n");
        printf("|=======================|\n");
        printf("| Soma Atual: %d\n", soma);
        printf("|=======================|\n");
        printf("| > Opcoes:             |\n");
        printf("|   1. Adicionar valor  |\n");
        printf("|   2. Limpar Lista     |\n");
        printf("|   0. Sair             |\n");
        printf("|=======================|\n");
        printf("| > Opção Desejada: ");
        scanf("%d", &opcao);
        clearBuffer();

        if(opcao == 1){
            if(pos >= ARRAY_SIZE){
                printf("\033[31m");
                printf("| Limite da lista atingido,\n");
                printf("| Limpe a lista para adicionar \n");
                printf("| um novo valor...\n");
            }
            else{
                int new;
                printf("| > Novo Valor: ");
                scanf("%d", &new);

                array[pos] = new;
                pos++;
            }
        }
        else if(opcao == 2){
            memset(array, 0, sizeof(array));
            printf("| > Limpando Lista...\n");
            pos = 0;
        }
        else if(opcao == 0){
            printf("| > Voltando para o menu...\n");
        }
        else{
            printf("| > Opção inválida, tente novamente...\n");
        }
    }while(opcao != 0);

    return 0;
}

// 2. Contagem de Vogais de uma Array:
int countVogais(){
    int opcao;
    do{
        char text[ARRAY_SIZE];
        int count = 0;


        printf("\n\033[34m");
        printf("|=======================|\n");
        printf("|  Contagem de Vogais   |\n");
        printf("|=======================|\n");
        printf("| > Opcoes:             |\n");
        printf("|   1. Digitar Frase    |\n");
        printf("|   0. Sair             |\n");
        printf("|=======================|\n");
        printf("| > Opção Desejada: ");
        scanf("%d", &opcao);
        clearBuffer();

        if(opcao == 1){
            printf("| > Digite a frase: ");
            fgets(text, ARRAY_SIZE, stdin);
            text[strcspn(text, "\n")] = '\0';

            for (int i = 0; text[i] != '\0'; i++) {
                char ch = tolower(text[i]);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    count++;
                }
            }

            printf("| > Total de Vogais: %d\n", count);
        }
        else if(opcao == 0){
            printf("| > Voltando para o menu...\n");
        }
        else{
            printf("| > Opção inválida, tente novamente...\n");
        }
    }while(opcao != 0);

    return 0;
}

// 3. Cadastro de Produto
int painelProdutos(){
    Produto estoque[ARRAY_SIZE];
    int pos;
    int opcao;
    do{

        printf("\n\033[34m");
        printf("|=======================|\n");
        printf("| Cadastro de Produtos  |\n");
        printf("|=======================|\n");
        printf("| > Opcoes:             |\n");
        printf("|   1. Cadastro         |\n");
        printf("|   2. Listar           |\n");
        printf("|   0. Sair             |\n");
        printf("|=======================|\n");
        printf("| > Opção Desejada: ");
        scanf("%d", &opcao);
        clearBuffer();

        if(opcao == 1){
            if(pos >= ARRAY_SIZE){
                printf("| > Limite de Estoque Atingido...");
            }
            else{
                Produto novoProd;

                printf("| > Nome do produto: ");    
                fgets(novoProd.nome, NAME_SIZE, stdin);
                novoProd.nome[strcspn(novoProd.nome, "\n")] = '\0';
                printf("| > Preço do produto: ");
                scanf("%d", &novoProd.price);
                printf("| > Estoque: ");
                scanf("%d", &novoProd.qtd);

                estoque[pos] = novoProd;
                pos++;
            }
        }
        else if(opcao == 2){
            printf("| > Lista:\n");
            for(int i = 0; i < pos; i++){
                printf("|======================\n");
                printf("| > Nome: %s\n", estoque[i].nome);
                printf("| > Preço: %d\n", estoque[i].price);
                printf("| > Estoque: %d\n", estoque[i].qtd);
                printf("| > Valor em estoque: %d\n", estoque[i].qtd * estoque[i].price);
            }
        }
        else if(opcao == 0){
            printf("| > Voltando para o menu...\n");
        }
        else{
            printf("| > Opção inválida, tente novamente...\n");
        }
    }while(opcao != 0);

    return 0;
}


// Multiplicação de Matrizes
int matriz() {
    int opcao;

    do {
        printf("\n\033[34m");
        printf("|=======================|\n");
        printf("| Operações Matriciais  |\n");
        printf("|=======================|\n");
        printf("| > Opcoes:             |\n");
        printf("|   1. Multiplicação    |\n");
        printf("|   0. Sair             |\n");
        printf("|=======================|\n");
        printf("| > Opção Desejada: ");
        scanf("%d", &opcao);
        clearBuffer();

        if (opcao == 1) {
            int col1, lin1, col2, lin2;

            printf("| > Quantidade de colunas na 1º Matriz: ");
            scanf("%d", &col1);
            clearBuffer();

            printf("| > Quantidade de linhas na 1º Matriz: ");
            scanf("%d", &lin1);
            clearBuffer();

            printf("| > Quantidade de colunas na 2º Matriz: ");
            scanf("%d", &col2);
            clearBuffer();

            printf("| > Quantidade de linhas na 2º Matriz: ");
            scanf("%d", &lin2);
            clearBuffer();

            if (col1 != lin2) {
                printf("\033[31m");
                printf("Erro: O número de colunas da 1ª matriz deve ser igual ao número de linhas da 2ª matriz para multiplicação.\n");
                printf("\n\033[34m");
                continue;
            }

            int matriz1[lin1][col1];
            int matriz2[lin2][col2];
            int resultado[lin1][col2];
            int transposta[col2][lin1];

            printf("| > Elementos da 1ª Matriz:\n");
            for (int i = 0; i < lin1; i++) {
                for (int j = 0; j < col1; j++) {
                    printf("| > matriz1[%d][%d] = ", i, j);
                    scanf("%d", &matriz1[i][j]);
                }
            }

            printf("| > Elementos da 2ª Matriz:\n");
            for (int i = 0; i < lin2; i++) {
                for (int j = 0; j < col2; j++) {
                    printf("| > matriz2[%d][%d] = ", i, j);
                    scanf("%d", &matriz2[i][j]);
                }
            }

            multiplyMatrices(lin1, col1, matriz1, lin2, col2, matriz2, resultado);
            transposeMatrix(lin1, col2, resultado, transposta);

            printf("\nMatriz 1:\n");
            printMatrix(lin1, col1, matriz1);
            printf("\nMatriz 2:\n");
            printMatrix(lin2, col2, matriz2);
            printf("\nMatriz Resultante (Multiplicação):\n");
            printMatrix(lin1, col2, resultado);
            printf("\nMatriz Transposta da Resultante:\n");
            printMatrix(col2, lin1, transposta);
        }
        else if(opcao == 0){
            printf("| > Voltando para o menu...\n");
        }
        else{
            printf("| > Opção inválida, tente novamente...\n");
        }

    } while (opcao != 0);

    return 0;
}

// String em Maiúscula
int stringUpper(){
    int opcao;

    do {
        printf("\n\033[34m");
        printf("|=======================|\n");
        printf("|  String em Maiuscula  |\n");
        printf("|=======================|\n");
        printf("| > Opcoes:             |\n");
        printf("|   1. Digitar Frase    |\n");
        printf("|   0. Sair             |\n");
        printf("|=======================|\n");
        printf("| > Opção Desejada: ");
        scanf("%d", &opcao);
        clearBuffer();

        if (opcao == 1) {
           char str[ARRAY_SIZE];
            printf("| > Frase: ");
            fgets(str, ARRAY_SIZE, stdin);
            str[strcspn(str, "\n")] = '\0';

            toUpperCase(str);
            printf("|> String todoa em maiúscula: \n| > %s\n", str);

        }
        else if(opcao == 0){
            printf("| > Voltando para o menu...\n");
        }
        else{
            printf("| > Opção inválida, tente novamente...\n");
        }


    } while (opcao != 0);

    return 0;
}

// Registro Binário
int structOrder(){
    Pessoa pessoas[] = {
        {"Arthur", 20},
        {"Albertini", 19},
        {"Carlos", 20},
        {"Beatriz", 35},
        {"Bianca", 21},
        {"Marcos", 75},
        {"Felipe", 17},
    };
    int size = sizeof(pessoas) / sizeof(pessoas[0]);
    int opcao;
    do{

        printf("\n\033[34m");
        printf("|=======================|\n");
        printf("|    Ordenar Structs    |\n");
        printf("|=======================|\n");
        printf("| > Opcoes:             |\n");
        printf("|   1. Listar           |\n");
        printf("|   2. Ordenar por Nome |\n");
        printf("|   3. Ordenar por Idade|\n");
        printf("|   0. Sair             |\n");
        printf("|=======================|\n");
        printf("| > Opção Desejada: ");
        scanf("%d", &opcao);
        clearBuffer();

        if(opcao == 1){
            for(int i = 0; i < size; i++){
                printf("| > Lista:\n");
                printf("|======================\n");
                printf("| > Nome: %s\n", pessoas[i].nome);
                printf("| > Preço: %d\n", pessoas[i].idade);
            }
        }
        else if(opcao == 2){
            qsort(pessoas, size, sizeof(Pessoa), comparaNome);
        }
        else if(opcao == 3){
            qsort(pessoas, size, sizeof(Pessoa), comparaIdade);
        }
                else if(opcao == 0){
            printf("| > Voltando para o menu...\n");
        }
        else{
            printf("| > Opção inválida, tente novamente...\n");
        }
    }while(opcao != 0);
    return 0;
}