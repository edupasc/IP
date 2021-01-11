/* IP_GICIB_ STRUCT | Final Fantasy VII */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int pv;
    int pa;
    int pm;
} tipoEquipo;

typedef struct{
    int ev;
    int ea;
    float ef;
    float em;
} tipoEnemigos;

tipoEquipo * crearEquipo();
void matarPersonaje(tipoEquipo personajes[], int x);

int main() {

    tipoEquipo * personajes = crearEquipo();


    int numeroDeEnemigos;
    scanf("%d", &numeroDeEnemigos);
    tipoEnemigos * enemigos = (tipoEnemigos *) malloc(sizeof(tipoEnemigos) * numeroDeEnemigos);


    int numAtaques, victorias=0, a=0;
    while (a!=-1 && a<numeroDeEnemigos){
        scanf("%d %d %f %f", &enemigos[a].ev, &enemigos[a].ea, &enemigos[a].ef, &enemigos[a].em);
        scanf("%d", &numAtaques);

        for (int x = 0; x<3; x++){
            if (personajes[x].pv<=0){
                matarPersonaje(personajes, x);
            }
            enemigos[a].ev -= personajes[x].pa*enemigos[a].ef + personajes[x].pm*enemigos[a].em;
        }

        int jugador;
        for (int j = 0; j<numAtaques; j++){
            scanf("%d", &jugador);
        }

        if (enemigos[a].ev <= 0){
            victorias++;
        }
        else {
            a=-2;
        }
        a++;
    }
    printf("%d", victorias);
    free(enemigos);
}

tipoEquipo * crearEquipo(){
    tipoEquipo * personajes = (tipoEquipo *) malloc(sizeof(tipoEquipo) * 3);
    for (int i =0; i<3; i++){
        scanf("%d %d %d", &personajes[i].pv, &personajes[i].pa, &personajes[i].pm);
    }
    return personajes;
}


void matarPersonaje(tipoEquipo personajes[], int x){
    personajes[x].pm=0;
    personajes[x].pa=0;
}