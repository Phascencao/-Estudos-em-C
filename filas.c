#include <stdio.h>
#include <stdlib.h>

//Estrutura que representa uma pessoa
typedef struct {
    char nome[30]; //string com nome (até 29 chars + '\0')
    int idade;     //idade da pessoa
} Pessoa;

#define MAX 5 //tamanho máximo da fila

//Estrutura de FILA CIRCULAR
typedef struct {
    Pessoa pessoas[MAX]; //array que armazena os elementos
    int inicio;          //índice do primeiro elemento da fila
    int fim;             //índice onde o próximo elemento será inserido
    int tamanho;         //quantidade atual de elementos na fila
} Fila;

//Inicializa a fila
void inicializarFila(Fila *fila) {
    fila->inicio = 0;   //começo da fila
    fila->fim = 0;      //posição de inserção
    fila->tamanho = 0;  //fila começa vazia
}

//Verifica se a fila está vazia
int filaVazia(Fila *fila) {
    return (fila->tamanho == 0); //se não tem elementos
}

//Verifica se a fila está cheia
int filaCheia(Fila *fila) {
    return (fila->tamanho == MAX); //atingiu o limite
}

//Insere elemento na fila (enqueue)
void inserir(Fila *fila, Pessoa pessoa) {
    if (filaCheia(fila)) { //validação
        printf("Fila cheia! Não é possível enfileirar.\n");
        return;
    }

    //coloca o elemento na posição "fim"
    fila->pessoas[fila->fim] = pessoa;

    //avança o índice de forma CIRCULAR
    //se chegar no final do array, volta pro início
    fila->fim = (fila->fim + 1) % MAX;

    //aumenta o número de elementos
    fila->tamanho++;
}

//Remove elemento da fila (dequeue)
void remover(Fila *fila, Pessoa *pessoa) {
    if (filaVazia(fila)) { //validação
        printf("Fila vazia! Não é possível desenfileirar.\n");
        return;
    }

    //copia o elemento removido para a variável passada por referência
    *pessoa = fila->pessoas[fila->inicio];

    //avança o início de forma circular
    fila->inicio = (fila->inicio + 1) % MAX;

    //diminui a quantidade de elementos
    fila->tamanho--;
}

//Imprime a fila respeitando a circularidade
void imprimirFila(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Pessoas na fila:\n");

    //percorre exatamente "tamanho" elementos
    //começando do "inicio"
    for (
        int i = 0, idx = fila->inicio; //idx = posição real no array
        i < fila->tamanho;             //percorre só o que está ocupado
        i++, idx = (idx + 1) % MAX     //avança circularmente
    ) {
        printf("Nome: %s, Idade: %d\n",
               fila->pessoas[idx].nome,
               fila->pessoas[idx].idade);
    }

    printf("\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila); //fila começa vazia

    //criando algumas pessoas
    Pessoa p1 = {"Alice", 30};
    Pessoa p2 = {"Bob", 25};
    Pessoa p3 = {"Charlie", 35};

    //inserindo na fila (ordem importa - FIFO)
    inserir(&fila, p1);
    inserir(&fila, p2); 
    inserir(&fila, p3);

    //imprime estado atual
    imprimirFila(&fila);

    //remove um elemento (sempre o mais antigo)
    Pessoa removida;
    remover(&fila, &removida);

    //mostra quem saiu da fila
    printf("Pessoa removida: Nome: %s, Idade: %d\n",
           removida.nome, removida.idade);

    //imprime fila após remoção
    imprimirFila(&fila);

    return 0;
}
