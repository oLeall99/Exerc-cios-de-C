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