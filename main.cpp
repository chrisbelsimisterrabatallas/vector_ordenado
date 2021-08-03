#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

//LECTURA DEL VECTOR
void leer_vector(int num[], int tamanio)
{
    //los vectores siempre pasan por referencia
    for (int i=0; i<tamanio; i++)
    {
        cout<<endl<<"Inrese el elemento # " << (i+1)<<" : ";
        cin>>num[i];
    }
}

//impresion del vector
void imprime_vector(int vector[], int tamanio)
{
    cout<<endl<<endl<<"ELEMENTOS DE VECTOR";
    for (int i=0; i<tamanio; i++)
    {
        cout<<endl<<"Ingrese el elemento # " << (i+1)<<" : " <<vector[i];
    }
}

//REALIZAR LA SUMATORIA DE LOS ELEMENTOS DEL VECTOR
double sumatoria_vector(int vector[], int tamanio)
{
    double suma=0;
    for(int i=0; i<tamanio; i++)
        suma+=vector[i];
    return suma;
}


//REALIZAR EL PROMEDIO DE LOS ELEMENTOS DEL VECTOR:

double promedio_vector(int vector[], int tamanio)
{
    double promedio = 0.0;

    for (int i = 0; i < tamanio; i++)
        promedio += vector[i];

    return promedio / (float) tamanio;
}


//Funcion que llene el vector con valores aletorios
void  vector_aletorio(int num[], int tamanio)
{
    srand(time(NULL));
    for(int i = 0; i<tamanio; i++)
    {
        num[i] = 1+ rand () % 1000;
    }
}
// 1)Función que devuelve el elemento máximo del vector
double maximo_vector (int* vector, int num)
{
    double maximo;

    maximo = vector[0];
    for (int i = 1; i < num; i++)
        if (vector[i] > maximo)
            maximo = vector[i];
    return (maximo);
}

//2)Función que devuelve el elemento mínimo del vector
double minimo_vector (int* vector, int num)
{
    int i;
    double min;

    min = vector[0];
    for (i = 1; i < num; i++)
        if (vector[i] < min)
            min = vector[i];
    return (min);
}

//ordena el vector
void ordenacion_secuencial (int vector[], int tamanio)
{
    for(int i=0; i<tamanio; i++)
    {
        for(int j=i+1; j<tamanio; j++)
        if(vector[i] > vector[i+1])
        {
            int aux;
            aux=vector[i];
            vector[i]=vector[j];
            vector[j]=aux;
        }
    }
}

//1) diseñe la funcion que busque un numero entero en el vector.
//la funcion debe devolver verdadero si el elemento existe en el vector
//o falso en caso contrario.

double Existentes_vector (int vector[], int tamanio)

{
    char verdad='t';
    {
        srand(time(NULL));
        for(int i = 0; i<tamanio; i++)
        {
            vector[i] = 1+ rand () % 1000;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i!=j){
                if(vector[i]==vector[j]){
                    verdad='t';
                }
                else{
                    verdad='f';
                }
            }
        }
    }
    if(verdad=='t'){
        cout<<endl<<endl<<"verdadero"<<endl;
    }
    else{
        cout<<endl<<endl<<"falso"<<endl;
    }
    return 0;
}



//2) diseñe la funcion que busque un numero entero en el vector.
//la funcion debe devolver la posicion donde el elemento fue encontrado.
//devuelve -1 si no existe.
// Función que busca dentro del arreglo
void posicion_elemento (int vector[], int tamanio) {
    int buscar;
    int j = -1;
    int i = -1;
    do {
        i++;
        if (vector[i] == buscar)
            j = i;
    } while ((i < buscar) && (vector[i] != buscar));

    if (j == -1) {
        cout<<"-1";
    }
    else
    {
        cout<<"verdadero" ;
        cout<<"esta en la posicion: "<<j;
    }
}

int main() {
    const int MAX=10;
    int num[MAX];
    //llamada a la funcion para llenar el vector
    //leer_vector(num, MAX);  // Lectura por teclado
    vector_aletorio(num, MAX); //llenar el vecto con numeros aletorios
    imprime_vector(num, MAX);

    int suma= sumatoria_vector(num, MAX);
    cout<<endl<<"LA SUMATORIA DEL VECTOR ES: "<<suma;

    int promedio= promedio_vector(num, MAX);
    cout<<endl<<"EL PROMEDIO DE LOS VECTOR ES: "<<promedio;

    cout<<endl<<"VECTOR ORIGINAL";
    imprime_vector(num, MAX);

    cout<<endl<<endl<<"VECTOR ORDENADO";
    ordenacion_secuencial(num, MAX);
    imprime_vector(num, MAX);

    Existentes_vector(num, MAX);

    posicion_elemento(num, MAX);

    return 0;
}
