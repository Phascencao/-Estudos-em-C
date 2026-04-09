#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIOS 5

//Definição da struct Territorio. Armazena o nome, a cor do exército dominante e a quantidade de tropas.
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

//Função auxiliar para limpar o buffer do teclado e evitar erros no fgets
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    //Declarando o vetor de structs com capacidade para 5
    Territorio territorios[MAX_TERRITORIOS];
    int cont_Registrados = 0;

    printf("\n=== Cadastro de %d Territorios ===\n", MAX_TERRITORIOS);

    //O laço garante que exatamente 5 territórios sejam preenchidos.
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("\n----------- REGISTRAR TERRITORIO %d -----------\n", i + 1);
        
        printf("Nome do territorio: ");
        fgets(territorios[i].nome, 30, stdin);
        //Remove o '\n' deixado pelo fgets
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Cor do exercito (Ex: Vermelho, Azul): ");
        fgets(territorios[i].cor, 10, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Numero de tropas: ");
        scanf("%d", &territorios[i].tropas);
        
        //Limpa o buffer após o scanf para o próximo fgets funcionar corretamente
        limparBufferEntrada();
        
        cont_Registrados++;
    }

    //Percorre o vetor após o cadastro e exibe as informações formatadas.
    printf("\n\n========== DADOS DOS TERRITORIOS REGISTRADOS ==========\n");
    for (int i = 0; i < cont_Registrados; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  - NOME: %s\n", territorios[i].nome);
        printf("  - COR DO EXERCITO: %s\n", territorios[i].cor);
        printf("  - QUANTIDADE DE TROPAS: %d\n", territorios[i].tropas);
        printf("------------------------------------------------------\n");
    }

    return 0;
}
