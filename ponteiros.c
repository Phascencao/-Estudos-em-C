#include <stdio.h>

int main() {
    
    int x =10;
    //usamos o símbolo ∗ para declarar um ponteiro, e o símbolo & para obter o endereço de uma variável.
    int* p = &x; //O ponteiro "p" recebe o endereço de "x".

    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x); //quando usamos o "*" na concatenação ele aponta o valor que está no endereço
    printf("Conteúdo de p: %p\n", p);
    printf("Valor apontado por p: %d\n", *p); //quando usamos o "*" na concatenação ele aponta o valor que está no endereço
    
    *p = 50;

    printf("Valor de x: %d\n", x);

    return 0;
}
