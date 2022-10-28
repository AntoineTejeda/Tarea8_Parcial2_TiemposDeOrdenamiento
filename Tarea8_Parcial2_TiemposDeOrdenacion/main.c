#include <stdio.h>
#include <time.h>
# define N 10000

void GeneraArreglo(int A[N]);
void ImprimeArreglo(int A[N]);
void Burbuja(int A[N]);
void Baraja(int A[N]);
void Seleccion(int A[N]);
void QuickSort(int A[N],int inicio, int fin);

int main()
{
    time_t inicio,fin;
    int tiempo,i;
    int Arr[N];
   // for(i=0;i<10000;i++)
   // {
   //     Arr[i]=10000-i;
   // }
    srand(230);
    GeneraArreglo(Arr);
   // ImprimeArreglo(Arr);
   inicio=clock();
    Burbuja(Arr);
    //Baraja(Arr);
    //Seleccion(Arr);
    //QuickSort(Arr,0,N-1);
    fin=clock();
    tiempo= fin-inicio;
    ImprimeArreglo(Arr);
   printf("\n Tiempo de corrida: %d milisegundos",tiempo);
}


void QuickSort(int A[N],int inicio, int fin)
{
    int izq=inicio, der=fin, pos=inicio;
    int band=1;

    while(band==1)
    {
       band=0;
       while(A[pos]<=A[der] && pos !=der)
       {
           der--;
       }
       if(pos!=der)
       {
           Intercambia(&A[pos],&A[der]);
           pos=der;
       }
       while(A[pos]>=A[izq] && pos!=izq)
       {
           izq++;
       }
       if(pos!=izq)
       {
           Intercambia(&A[pos],&A[izq]);
           pos=izq;
           band=1;
       }
    }
    if(pos-1>inicio)
    {
        QuickSort(A,inicio,pos-1);
    }
    if(fin > pos+1)
    {
        QuickSort(A,pos+1, fin);
    }

 }



void Seleccion(int A[N])
{
    int p, pos, x;

    for(p=N-1; p>0 ; p--)
    {
        x=0;
        for(pos=1; pos<=p; pos++)
        {
            if(A[pos]>A[x])
            {
                x=pos;
            }
        }
        Intercambia(&A[x],&A[p]);
    }
}


void Baraja(int A[N])
{
    int p, pos;
    for (p= 1; p < N; p++)
    {
        for (pos=p;pos>0 &&A[pos]<A[pos-1]; pos--)
        {
            Intercambia(&A[pos],&A[pos-1]);
        }
    }
}

void Intercambia(int *a, int *b)
{
    int tmp;

    tmp=*a;
    *a=*b;
    *b=tmp;
}

void Burbuja(int A[N])
{
    int pos, t, p;

    for(p=1; p<N ; p++)
   {
    for(pos=0; pos<N-p; pos++)
    {
        if(A[pos]>A[pos+1])
        {
            t=A[pos];
            A[pos]=A[pos+1];
            A[pos+1]=t;
        }
    }
   }
}

void GeneraArreglo(int A[N])
{
    int i;

    for(i=0; i<N; i++)
    {
        A[i]=rand();
    }
}

void ImprimeArreglo(int A[N])
{
    int i;

    for(i=0; i<N; i++)
    {
        printf("%d \t",A[i]);
    }
    printf("\n");
}
