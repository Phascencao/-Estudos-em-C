#include <stdio.h>
#include <stdlib.h>  //malloc

//cada nó guarda um número e sabe onde fica o próximo
struct No {
    int dado;
    struct No* proximo;
};

int main() {

    //reserva espaço na memória para três nós
    struct No* primeiro = malloc(sizeof(struct No));
    struct No* segundo  = malloc(sizeof(struct No));
    struct No* terceiro = malloc(sizeof(struct No));

    //monta a corrente: 10 -> 20 -> 30 -> NULL
    primeiro->dado = 10;
    primeiro->proximo = segundo;

    segundo->dado = 20;
    segundo->proximo = terceiro;

    terceiro->dado = 30;
    terceiro->proximo = NULL;  //fim da lista

    //percorre a lista do início ao fim e imprime cada valor
    struct No* atual = primeiro;

    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->proximo;  // avança para o próximo nó
    }

    //--- insere um novo nó entre o primeiro e o segundo ---

    struct No* novo = malloc(sizeof(struct No));
    novo->dado = 15;

    novo->proximo = primeiro->proximo;  //novo aponta para segundo (salva o elo antes de quebrar)
    primeiro->proximo = novo;           //agora primeiro aponta para novo: 10 -> 15 -> 20 -> 30

    //reseta atual para o início e imprime a lista atualizada
    atual = primeiro;

    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }

    return 0;
}
