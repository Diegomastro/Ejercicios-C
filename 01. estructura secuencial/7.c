/**El precio para un vuelo es de $880 en clase turista y se aplica un
incremento del 30% en primera clase.
Se conoce la cantidad de pasajes de clase turista y de primera clase.
Obtener la recaudación del vuelo. */
#include <stdio.h>
#define TURISTA 880
#define PRIMERA TURISTA*1.3
int main(){
    int cant_turista, cant_primera;
    printf("Cantidad de pasajeros en clase turista: ");
    scanf("%d",&cant_turista);
    fflush(stdin);
    printf("Cantidad de pasajeros en primera clase: ");
    scanf("%d",&cant_primera);
    fflush(stdin);
    printf("Recaudacion: $%.2f", cant_turista*TURISTA + cant_primera*PRIMERA);
    return 0;
}
