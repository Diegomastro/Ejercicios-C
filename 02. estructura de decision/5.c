/**Decir si un nro. N es divisible por M. */

#include <stdio.h>

int main(){
    int n, m;
    printf("Insertar dos numeros, a ver si el primero es divisible por el segundo: \n");
    scanf("%d%d", &n, &m);
    if (n%m){
        printf("NO!");
    }
    else{
        printf("SI!");
    }
    return 0;
}
