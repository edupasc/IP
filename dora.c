/* IP_GICIB_ MEMDIN | Dora Controladora */

#include <stdio.h>
#include <stdlib.h>

int *crearVector(int n);
void rellenarVector(int n, int vector[n]);
int buscarExpediente(int n, int vector[n]);

int main() {
    int totalEstudiantes, estudiantesBuscados;
    scanf("%d %d", &totalEstudiantes, &estudiantesBuscados);

    int *vectorExpedientes = crearVector(totalEstudiantes);

    rellenarVector(totalEstudiantes, vectorExpedientes);

    for (int x = 0; x<estudiantesBuscados; x++){
        printf("%d\n", buscarExpediente(totalEstudiantes, vectorExpedientes));
    }
}

int *crearVector(int n){
    int *vectorExpedientes;
    vectorExpedientes = (int *) malloc(sizeof(int)*n);
    return vectorExpedientes;
}

void rellenarVector(int n, int vector[n]){
    for (int i = 0; i<n; i++){
        scanf("%d", &vector[i]);
    }
}

int buscarExpediente(int n, int vector[n]){
    int numExpediente;
    int i = 0;
    int j = n-1;
    int m;
    scanf("%d", &numExpediente);
    while (i<j){
        m=(i+j)/2;
        if (numExpediente > vector[m]){
            i=m+1;
        }
        else{
            j=m;
        }
    }
    return i;


}