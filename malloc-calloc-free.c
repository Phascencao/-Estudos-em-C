#include <stdio.h>
#include <stdlib.h>  //necessário para malloc, calloc e free

int main(){

    int *a, b;
    //'a' ponteiro para int (vai apontar para heap ou stack)
    //'b' variável int normal (fica na stack)

    b = 10;
    //atribui valor 10 para 'b' (stack)

    a = calloc(5, sizeof(int));
    //aloca memória para 5 inteiros na HEAP
    //todos inicializados com 0
    //'a' aponta para o primeiro elemento

    *a = 20;
    //acessa o primeiro elemento do bloco alocado
    //e coloca o valor 20 nele

    free(a);
    //libera a memória da HEAP que foi alocada
    //depois disso, 'a' vira um ponteiro inválido (dangling pointer)

    a = &b;
    //agora 'a' passa a apontar para 'b' (que está na STACK)

}
