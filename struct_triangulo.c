#include <stdio.h>
#include <math.h>

//Definindo uma struct para representar um triângulo retângulo
typedef struct {
    float hipotenusa;  //lado oposto ao ângulo reto
    float cateto_a;    //primeiro cateto
    float cateto_b;    //segundo cateto
} triangulo_retangulo;

int main() {

    //hipotenusa começando com 0 para ser calculada 
    //cateto_a = 3, cateto_b = 4
    triangulo_retangulo triangulo_1 = {0, 3, 4};

    //Calcula a hipotenusa usando o Teorema de Pitágoras
    //hipotenusa² = cateto_a² + cateto_b²
    triangulo_1.hipotenusa = sqrt( 
        pow(triangulo_1.cateto_a, 2) +
        pow(triangulo_1.cateto_b, 2) );

    printf("A hipotenusa do triangulo é: %.2f", triangulo_1.hipotenusa);

    return 0;
}
