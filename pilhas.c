#include <stdio.h>
#include <stdlib.h>

//Estrutura que representa uma pessoa
typedef struct {
    char nome[30]; //string para armazenar o nome
    int idade;     //idade da pessoa
} Pessoa;

#define MAX 5   //tamanho máximo da pilha

//Estrutura de PILHA (LIFO - Last In, First Out)
typedef struct {
    Pessoa itens[MAX]; //array que armazena os elementos da pilha
    int topo;          //índice do topo da pilha
} Pilha;

//Inicializa a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1; //-1 indica que a pilha está vazia
}

//Verifica se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

//Verifica se a pilha está cheia
int pilhaCheia(Pilha *pilha) {
    return (pilha->topo == MAX - 1);
}

//Empilha um elemento (push)
void empilhar(Pilha *pilha, Pessoa pessoa) {
    if (pilhaCheia(pilha)) { // validação
        printf("Pilha cheia! Não é possível empilhar.\n");
        return;
    }

    //incrementa o topo (sobe na pilha)
    pilha->topo++;

    //adiciona o elemento na nova posição do topo
    pilha->itens[pilha->topo] = pessoa;
}

//Desempilha um elemento (pop)
void pop(Pilha *pilha, Pessoa *removida) {
    if (pilhaVazia(pilha)) { // validação
        printf("Pilha vazia! Não é possível desempilhar.\n");
        return;
    }

    //copia o elemento do topo para a variável de saída
    *removida = pilha->itens[pilha->topo];

    //diminui o topo (remove o elemento logicamente)
    pilha->topo--;
}

//Imprime os elementos da pilha
void imprimirPilha(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Pessoas na pilha:\n");

    //percorre do topo até a base (ordem LIFO)
    for (int i = pilha->topo; i >= 0; i--) {
        printf("Nome: %s, Idade: %d\n",
               pilha->itens[i].nome,
               pilha->itens[i].idade);
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha); //pilha começa vazia

    //criando algumas pessoas
    Pessoa p1 = {"Alice", 30};
    Pessoa p2 = {"Bob", 25};
    Pessoa p3 = {"Charlie", 35};

    //empilhando elementos (ordem importa)
    empilhar(&pilha, p1);
    empilhar(&pilha, p2);
    empilhar(&pilha, p3);

    //imprime estado atual da pilha
    imprimirPilha(&pilha);

    //remove o elemento do topo (último que entrou)
    Pessoa removida;
    pop(&pilha, &removida);

    //mostra quem saiu da pilha
    printf("Pessoa removida: Nome: %s, Idade: %d\n",
           removida.nome, removida.idade);

    //imprime pilha após remoção
    imprimirPilha(&pilha);

    return 0;
}
