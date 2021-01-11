#include <stdio.h>
#define L 180

void mayusculas(char *array, int indice);

int main(){
    int repeticiones;
    scanf("%d", &repeticiones);
    char nombre[L];
    for (int i = 0; i<repeticiones; i++){
        scanf("%s", nombre);
        mayusculas(nombre, 0);
        printf("%s\n", nombre);
    }
    return 0;
}

void mayusculas(char *array, int indice){
    if (array[indice] != 0){
        if (array[indice] > 96 && array[indice] < 123){
            array[indice] -= 32;
        }
        mayusculas(array, indice + 1);
    }
}