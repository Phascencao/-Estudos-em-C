#include <stdio.h>

//array com os números que vamos pesquisar
int numeros[] = {10, 20, 30, 40, 50};
int alvo = 40;                                    //número que estamos procurando
int tamanho = sizeof(numeros) / sizeof(numeros[0]); //calcula quantos elementos tem o array
int encontrado = 0;                               //flag: começa como falso (0)

int main () {

    //percorre cada posição do array
    for (int i = 0; i < tamanho; i++) {

        //compara o elemento atual com o alvo
        if (numeros[i] == alvo) {
            printf("achou o alvo %d na posição: %d", alvo, i+1);
            encontrado = 1;  //marca que achou
            break;           //para o loop imediatamente, não precisa continuar
        }
    }

    //se encontrado ainda for 0, o alvo não estava em lugar nenhum
    if (!encontrado) {
        printf("Numero alvo nn está na lista");
    };
    
    return 0;
}
