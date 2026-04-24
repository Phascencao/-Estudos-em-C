#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50  //tamanho máximo das estruturas (fila e pilha)

//Estrutura que representa uma pessoa
typedef struct {
    char nome[30]; //nome da pessoa (string)
    int idade;     //idade da pessoa
} Pessoa;

//Estrutura de FILA (FIFO - First In, First Out)
typedef struct {
    Pessoa dados[MAX]; //array que armazena as pessoas
    int inicio;        //índice do começo da fila
    int fim;           //índice do fim da fila
} Fila;

//Estrutura de PILHA (LIFO - Last In, First Out)
typedef struct {
    Pessoa dados[MAX]; //array que armazena as pessoas
    int topo;          //índice do topo da pilha
} Pilha;

//Inicializa a fila (começa vazia)
void inicializarFila(Fila *fila) {
    fila->inicio = 0; //início aponta para posição 0
    fila->fim = 0;    //fim também aponta para 0 (fila vazia)
}

//Inicializa a pilha (começa vazia)
void incializarPilha(Pilha *pilha) {
    pilha->topo = -1; //topo = -1 indica pilha vazia
}

//Verifica se a fila está vazia
int filaVazia(Fila *fila) {
    return (fila->inicio == fila->fim); //se inicio == fim → vazia
}

//Verifica se a fila está cheia (tentativa de fila circular)
int filaCheia(Fila *fila) {
    return ((fila->fim + 1) % MAX == fila->inicio);
}

//Verifica se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

//Verifica se a pilha está cheia
int pilhaCheia(Pilha *pilha) {
    return (pilha->topo == MAX - 1);
}

//Insere um elemento na fila (enqueue)
void inserirFila(Fila *fila, Pessoa pessoa) {
    if (filaCheia(fila)) { // verifica se está cheia
        printf("Fila cheia! Não é possível enfileirar.\n");
        return;
    }
    //adiciona a pessoa na posição "fim" e depois incrementa o fim
    fila->dados[fila->fim++] = pessoa;
}

//Remove um elemento da fila (dequeue)
Pessoa removerFila(Fila *fila) {
    if (filaVazia(fila)) { //verifica se está vazia
        printf("Fila vazia! Não é possível desenfileirar.\n");
        Pessoa pessoaVazia = {"", 0}; //retorna uma pessoa "vazia"
        return pessoaVazia;
    }
    //retorna o elemento do início e depois incrementa o início
    return fila->dados[fila->inicio++];
}

//Empilha um elemento (push)
void push(Pilha *pilha, Pessoa pessoa) {
    if (pilhaCheia(pilha)) { //verifica se está cheia
        printf("Pilha cheia! Não é possível empilhar.\n");
        return;
    }
    //incrementa o topo e adiciona o elemento
    pilha->dados[++pilha->topo] = pessoa;
}

//Desempilha um elemento (pop)
Pessoa pop(Pilha *pilha) {
    if (pilhaVazia(pilha)) { //verifica se está vazia
        printf("Pilha vazia! Não é possível desempilhar.\n");
        Pessoa pessoaVazia = {"", 0};
        return pessoaVazia;
    }
    //retorna o topo e depois decrementa
    return pilha->dados[pilha->topo--];
}

//Consulta o topo da pilha sem remover (peek)
Pessoa peek(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia! Não é possível acessar o topo.\n");
        Pessoa pessoaVazia = {"", 0};
        return pessoaVazia;
    }
    return pilha->dados[pilha->topo];
}

//Imprime todos os elementos da fila
void imprimirFila(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Pessoas na fila:\n");

    //percorre da posição inicio até fim
    for (int i = fila->inicio; i < fila->fim; i++) {
        printf("Nome: %s, Idade: %d\n", 
               fila->dados[i].nome, 
               fila->dados[i].idade);
    }
}

int main() {
    //Declara duas filas e uma pilha auxiliar
    Fila filaOriginal, filaReversa;
    Pilha auxiliar;

    //Inicializa as estruturas
    inicializarFila(&filaOriginal);
    inicializarFila(&filaReversa);
    incializarPilha(&auxiliar);

    //Array de pessoas (dados iniciais)
    Pessoa pessoas[] = {
        {"Alice", 45},
        {"Bob", 25},
        {"Charlie", 35},
        {"Diana", 62},
        {"Eve", 60}
    };

    //Insere todas as pessoas na fila original
    for (int i = 0; i < 5; i++) {
        inserirFila(&filaOriginal, pessoas[i]);
    }

    printf("fila original:\n");
    imprimirFila(&filaOriginal); //Imprime a fila original

    //Passo 1: tira da fila e joga na pilha
    //(isso já começa a inverter a ordem)
    while(filaOriginal.inicio < filaOriginal.fim) {
        push(&auxiliar, removerFila(&filaOriginal));
    }

    //Passo 2: tira da pilha e joga na nova fila
    //(aqui a ordem fica invertida de fato)
    while(auxiliar.topo >= 0) {
        inserirFila(&filaReversa, pop(&auxiliar));
    }

    //Imprime o resultado
    printf("fila invertida:\n");
    imprimirFila(&filaReversa);

    return 0;
}
