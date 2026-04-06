#include <stdio.h>
struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

void salvarProdutos(struct  Produto produtos[], int totalProdutos);
int carregarProdutos(struct Produto produtos[]);

int main() {
    struct Produto produtos[100];
    int totalProdutos = carregarProdutos(produtos);
    
    int opcao = 0;

    while (opcao != 6) {
        printf("\n--- SISTEMA DE PRODUTOS ---\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto\n");
        printf("4 - Atualizar produto\n");
        printf("5 - Excluir produto\n");
        printf("6 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        // Cadastrar produto
        if (opcao == 1) {
            printf("\nCadastro de produto\n");

            printf("Codigo: ");
            scanf("%d", &produtos[totalProdutos].codigo);

            printf("Nome: ");
            scanf("%s", produtos[totalProdutos].nome);

            printf("Preco (use ponto): R$ ");
            scanf("%f", &produtos[totalProdutos].preco);

            printf("Quantidade: ");
            scanf("%d", &produtos[totalProdutos].quantidade);

            totalProdutos++;
            salvarProdutos(produtos, totalProdutos);

            printf("Produto cadastrado!\n");
        }
        
        // Listar produtos
        if (opcao == 2){
            printf("\n--- LISTA DE PRODUTOS ---\n");
            for (int i = 0; i < totalProdutos; i++){
                printf("\nCodigo: %d\n", produtos[i].codigo);
                printf("Nome: %s\n", produtos[i].nome);
                printf("Preco: R$%.2f\n", produtos[i].preco);
                printf("Quantidade: %d\n", produtos[i].quantidade);
            }
        }

        // Buscar produto
        if (opcao == 3){
            int codigoBusca;
            int encontrado = 0;

            printf("\nDigite o codigo do produto: ");
            scanf("%d", &codigoBusca);

            for (int i = 0; i < totalProdutos; i++){
                
                if (produtos[i].codigo == codigoBusca){

                    printf("\nProduto encontrado!\n");
                    printf("Codigo: %d\n", produtos[i].codigo);
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Preco: R$ %.2f\n", produtos[i].preco);
                    printf("Quantidade: %d\n", produtos[i].quantidade);
                    
                    encontrado = 1;
                }
            }
            if (encontrado == 0){
                printf("\nProduto nao encontrado!\n");
            }
        }

        // Atualizar produto
        if (opcao == 4){
            int codigoBusca;
            int encontrado = 0;

            printf("\nDigite o codigo do produto que deseja atualizar: ");
            scanf("%d", &codigoBusca);

            if (totalProdutos == 0){
                printf("\nNenhum produto cadastrado!\n");
            }

            for (int i = 0; i < totalProdutos; i++){
                if (produtos[i].codigo == codigoBusca){
                    
                    printf("\nProduto encontrado! Atualize os dados:\n");

                    printf("Novo nome: ");
                    scanf("%s", produtos[i].nome);

                    printf("Novo preco: R$ ");
                    scanf("%f", &produtos[i].preco);

                    printf("Nova quantidade: ");
                    scanf("%d", &produtos[i].quantidade);
                    
                    encontrado = 1;
                    printf("\nProduto atualizado!\n");
                    
                    salvarProdutos(produtos, totalProdutos);
                    break;
                }
                }
                if (encontrado == 0){
                    printf("\nProduto nao encontrado!\n");
            }
        }

        // Excluir produto
        if (opcao == 5){
            int codigoBusca;
            int encontrado = 0;

            printf("\nDigite o codigo do produto que deseja excluir: ");
            scanf("%d", &codigoBusca);

            for (int i = 0; i < totalProdutos; i++){
                if(produtos[i].codigo == codigoBusca){
                    for(int j = i; j < totalProdutos - 1; j++){
                        produtos[j] = produtos[j + 1];
                    }
                    totalProdutos--;
                encontrado = 1;
                printf("\nProduto excluido!\n");
                salvarProdutos(produtos, totalProdutos);
                break;
            }
            }
            if (encontrado == 0){
                printf("\nProduto nao encontrado!\n");
            }
        }
    }

    return 0;
}

// Função para salvar produtos em um arquivo
void salvarProdutos(struct Produto produtos[], int totalProdutos){
    FILE *arquivo = fopen("produtos.txt", "w");

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (int i = 0; i < totalProdutos; i++){
        fprintf(arquivo, "%d %s %.2f %d\n",
        produtos[i].codigo,
        produtos[i].nome,
        produtos[i].preco,
        produtos[i].quantidade
        );
    }
    fclose(arquivo);
}

// Função carregar
int carregarProdutos(struct Produto produtos[]){
    FILE *arquivos = fopen("produtos.txt", "r");
    int totalProdutos = 0;

    if(arquivos == NULL){
        return 0;
    }

    while(fscanf(arquivos, "%d %s %f %d\n",
    &produtos[totalProdutos].codigo,
    produtos[totalProdutos].nome,
    &produtos[totalProdutos].preco,
    &produtos[totalProdutos].quantidade) != EOF){
        totalProdutos++;
    }

    fclose(arquivos);
    return totalProdutos;

}