#include <stdio.h>
#include <stdlib.h>




typedef struct {
    char nome[20];
    float preco;
    int estoque;
}Produto;

void inserirSaldo(float* saldo) {
    system("cls");
    float notas[] = {2.0f,5.0f,10.0f, 20.0f,50.0f,100.0f};
    int quantidade_de_notas = sizeof(notas) / sizeof(float);

    for (int i = 0; i< quantidade_de_notas; i++) {
        printf("%d. R$%.2f\n", i+1, notas[i]);
    }

    printf("Escolha uma nota para inserir (0 para sair): ");
    int escolha;
    scanf("%d", &escolha);

    if (escolha == 0) {
        return;
    }else if (escolha >= 1 && escolha <= quantidade_de_notas) {
        *saldo += notas[escolha - 1];
        return;
    }else {
        printf("Opcao invalida!");
    }
}

void exibirProdutos(Produto *maquina[],int tamanho,  float saldo) {
    system("cls");
    printf("===MAQUINA DE VENDAS=== \n");

    printf("SALDO R$%.2f \n", saldo);


    for (int i = 0; i< tamanho; i++) {
        printf("%d. %s\t- R$%.2f (em estoque: %d)\n",
            i + 1, maquina[i]->nome, maquina[i]->preco, maquina[i]->estoque);
    }
    printf("\n0. Sair \n");



}

void vender(Produto* produto, float* saldo) {
    produto->estoque--;
    *saldo -= produto->preco;

}

int main(void) {
    Produto itens[] = {
        {"Refrigerante", 6.0, 10},
        {"cholocale", 4.0, 20},
        {"salgadinhho", 5.0, 10},
        {"suco", 4.50, 8}
    };

    const int PRODUTO_QTD = sizeof(itens) / sizeof(Produto);

    Produto *maquina[PRODUTO_QTD];
    for (int i = 0;i < PRODUTO_QTD; i++) {
        maquina[i] = &itens[i];
    }


    float saldo = 0.0f;

    int opcao = -1;

    while (opcao != 0) {

        inserirSaldo(&saldo);
        exibirProdutos(maquina, PRODUTO_QTD, saldo);

        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);


        vender(maquina[opcao - 1], &saldo);





    }

    printf("Programa encerrado!\n");
    return 0;
}