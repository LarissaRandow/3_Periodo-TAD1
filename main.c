#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef float TipoP;
typedef struct ponto
{
    TipoP x,y,z;
}*Ponto;

Ponto criaPonto(TipoP X, TipoP Y, TipoP Z)
{
    Ponto p = NULL;
    p = (Ponto)malloc(sizeof(Ponto));
    if(p == NULL)
    {
        printf("Memoria insuficiente");
        exit(1);
    }
    p->x = X;
    p->y = Y;
    p->z = Z;
    return p;
}

TipoP getX (Ponto p)
{
    return p->x;
}

TipoP getY (Ponto p)
{
     return p->y;
}

TipoP getZ (Ponto p)
{
    return p->z;
}

float computaDist(Ponto A, Ponto B){
    float dist;
    dist = sqrt(pow(A->x - B->x , 2 ) + pow(A->y - B->y , 2 ) + pow(A->z - B->z , 2 ));
    return dist;
}

float calculaPerimetroQuadrilatero(Ponto *vet, int n)
{
    float perimetro;
    perimetro = computaDist(vet[0],vet[1]) + computaDist(vet[1],vet[2]) + computaDist(vet[2],vet[3]) + computaDist(vet[3],vet[0]);
    return perimetro;
}

int main()
{
    float perimetro;
    Ponto p1, p2, p3,p4;

    Ponto *vet = NULL;
    vet = (Ponto*)malloc(4 * sizeof(Ponto));
    if(vet == NULL)
    {
        printf("Deu ruim");
        exit(1);
    }


    p1 = criaPonto(1,1,1);
    p2 = criaPonto(2,2,2);
    p3 = criaPonto(3,3,3);
    p4 = criaPonto(4,4,4);
    vet[0] = p1;
    vet[1] = p2;
    vet[2] = p3;
    vet[3] = p4;

    perimetro = calculaPerimetroQuadrilatero(vet, 4);
    printf("O perimetro e: %f",perimetro);
    return 0;
}
