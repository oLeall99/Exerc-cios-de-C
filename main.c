#include "exe.h"

exe exercicios[] = { somaArray, countVogais, painelProdutos, matriz, stringUpper, registroBinario };

int main(){

    int opcao;

    do{

        printf("\n\033[34m");
        printf("\n|========================|\n");
        printf("|    Exercicios de C     |\n");
        printf("|========================|\n");
        printf("| Opções:                |\n");
        printf("|  1. Soma em Arrays     |\n");
        printf("|  2. Contagem de Vogal  |\n");
        printf("|  3. Painel de Produtos |\n");
        printf("|  4. Operacao de Matriz |\n");
        printf("|  5. String maiusculas  |\n");
        printf("|  6. Registro binario   |\n");
        printf("|  0. Sair               |\n");
        printf("|========================|\n");
        printf("|Opção Desejada: ");
        scanf("%d", &opcao);
        clearBuffer();

        opcao--;

        if(opcao == -1){
            printf("| > Encerrando...\n");
        }
        else if(opcao >= 0 && opcao <= 4){
            int exe = exercicios[opcao]();
        }
        else{
            printf("| > Opção Inválida...\n");
        }

    }while(opcao != -1);

    return 0;
}