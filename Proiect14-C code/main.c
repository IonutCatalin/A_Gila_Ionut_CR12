
#include <stdio.h>
#include <stdlib.h>
#define MAX 500
#define lenghtM 100
int adjMatrix[MAX][MAX];

int verificareCiclu(int adjMatrix[MAX][MAX]){

    ///param adjMatrix[MAX][MAX] - matricea de adiacenta

    /// Functia VerificareCiclu() verifica daca graful generat random este aciclic sau nu.

    int iterator1;
    int iterator2;
    int count=lenghtM;
    int gradintern;
    int sw;
    int aux[MAX][MAX];
    int flag[MAX];
    /// initializarea matricei auxiliare
    for(iterator1=0; iterator1 < lenghtM; iterator1++){
        for(iterator2=0; iterator2 < lenghtM; iterator2++){
            aux[iterator1][iterator2]=adjMatrix[iterator1][iterator2];
        }
    }
    /// initializarea vectorului flag cu 0
    for(iterator1=0; iterator1 < lenghtM; iterator1++)
        flag[iterator1]=0;
    /// structura repetitiva while() parcurge fiecare nod al grafului si testeaza
    /// daca nodul respectiv formeaza sau nu ciclu cu un alt grup de noduri.
    while(count!=0){
        sw=0;
        for(iterator1=0; iterator1 < lenghtM; iterator1++){
            gradintern=0;
            if(flag[iterator1]==0){
                for(iterator2=0; iterator2 < lenghtM; iterator2++){
                   gradintern+=aux[iterator2][iterator1];
                }
                if(gradintern==0){
                    sw=1;
                    flag[iterator1]=1;
                    count--;
                    for(iterator2=0; iterator2 < lenghtM; iterator2++)
                        aux[iterator1][iterator2]=0;
                }
            }

        }

        if(sw==0) return 0;
    }

    return 1;

}
void randGraph(int adjMatrix[MAX][MAX]){

    ///\fn void randGraph(int adjMatrix[MAX][MAX])
    ///\param adjMatrix[MAX][MAX] - matricea de adiacenta
    ///\brief randGraph.
    /// Functia randGraph() genereaza un graf random.
    int iterator1, iterator2;
    time_t t;
    srand((unsigned)time(&t));


    for(iterator1=0; iterator1 < lenghtM; iterator1++){
        for(iterator2=0; iterator2 < lenghtM; iterator2++){
    /// punem conditia ca nodul sa nu aiba drum catre el insusi.
            if(iterator1==iterator2){
                continue;
            }
    /// vom genera 1 sau 0 in matricea de diacenta.
            if(adjMatrix[iterator2][iterator1]==0){
                adjMatrix[iterator1][iterator2]=rand() % 2;

            }
    /// daca generarea anterioara de "1" a produs ciclu intre nodurile grafului vom reinitializa cu 0.
            if(verificareCiclu(adjMatrix)==0){
                adjMatrix[iterator1][iterator2]=0;
            }

        }
    }
    /// Afisarea matricei de adiacenta in consola.
    for(iterator1=0; iterator1 < lenghtM; iterator1++){
        for(iterator2=0; iterator2 < lenghtM; iterator2++){
            printf("%d ",adjMatrix[iterator1][iterator2]);
        }
        printf("\n");
    }

}
void topSort(int adjMatrix[MAX][MAX]){

    ///Sortarea topologica a matricei
    int iterator1,iterator2,count=lenghtM,gradintern,flag2[MAX];
    for(iterator1=0; iterator1 < lenghtM; iterator1++)
        flag2[iterator1]=0;
    printf("Ordinea in care Alexanderr trebuie sa aseze piesele: ");
    while(count!=0){
        for(iterator1=0; iterator1 < lenghtM; iterator1++){
            gradintern=0;
            if(flag2[iterator1]==0){
                for(iterator2=0; iterator2 < lenghtM; iterator2++){
                   gradintern+=adjMatrix[iterator2][iterator1];
                }
                if(gradintern==0){
                    flag2[iterator1]=1;
                    printf("%d ",iterator1+1);
                    count--;
                    for(iterator2=0; iterator2 < lenghtM; iterator2++)
                        adjMatrix[iterator1][iterator2]=0;
                }
            }

        }

    }

    printf("\n");



}
int main()
{
    randGraph(adjMatrix);
    topSort(adjMatrix);
    return 0;
}
