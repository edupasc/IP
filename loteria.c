/* IP_GICIB_ MEMDIN | Loteria */

#include <stdio.h>
#include <stdlib.h>

int ** crearMatriz(int n, int m);
void rellenarMatriz(int n, int m, int **matriz);
int sumar(int n, int m, int **matriz);
void liberarMatriz(int n, int **matriz);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int **matriz = crearMatriz(n, m);
    rellenarMatriz(n, m, matriz);
    printf("%d", sumar(n, m, matriz));
    liberarMatriz(n, matriz);
    return 0;
}

int ** crearMatriz(int n, int m){
    int ** matriz;
    matriz = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i<n; i++){
        matriz[i]= (int *) malloc(m * sizeof(int));
    }
    return matriz;
}

void rellenarMatriz(int n, int m, int **matriz){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

int sumar(int n, int m, int **matriz){
    int casillas, x, y;
    int suma = 0;
    scanf("%d", &casillas);
    for (int i = 0; i<casillas; i++){
        scanf("%d %d", &x, &y);
        suma+=matriz[x][y];
    }
    return suma;
}

void liberarMatriz(int n, int **matriz){
    for (int i = 0; i<n; i++){
        free(matriz[i]);
    }
    free(matriz);
}