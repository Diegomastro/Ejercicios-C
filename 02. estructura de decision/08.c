/**Confeccionar un programa que permita ingresar un carácter alfanumérico y determine e informe si lo
ingresado corresponde a una vocal, con el mensaje 'VOCAL'. */
#include <stdio.h>
#include <ctype.h>

int main(){
    char let = tolower(getchar());
    switch(let)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("VOCAL");
    }
    return 0;
}
