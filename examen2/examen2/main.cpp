//
//  main.cpp
//  Examen Practico 2
//
//  Created by Layla Tame on 4/24/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

// Nombre: Layla Tame
// Matrícula: A01192934

// EXAMEN PRÁCTICO #2 ADA EM19

#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

const int TAM = 15;
const int TAM2 = 5;
const int MAX = 500;

int datos[MAX] = {150, 807, 963, 323, 331, 618, 329, 952, 311, 294, 379, 746, 995, 803, 871, 839, 168, 472, 950, 249, 173, 650, 681, 501, 266, 165, 703, 398, 441, 920, 755, 898, 900, 132, 581, 432, 475, 792, 905, 892, 438, 274, 586, 417, 163, 953, 375, 325, 802, 382, 764, 333, 491, 741, 586, 788, 293, 730, 807, 790, 606, 222, 290, 618, 334, 415, 856, 740, 235, 800, 824, 251, 128, 826, 876, 548, 230, 331, 902, 555, 565, 960, 848, 902, 157, 704, 627, 447, 726, 523, 424, 485, 763, 321, 253, 846, 315, 835, 786, 463, 677, 394, 863, 245, 391, 637, 672, 478, 902, 414, 703, 574, 362, 624, 537, 981, 283, 499, 159, 471, 589, 796, 157, 795, 361, 882, 880, 319, 540, 396, 746, 552, 468, 525, 701, 654, 398, 771, 606, 944, 388, 709, 189, 400, 997, 546, 378, 162, 973, 798, 338, 986, 484, 966, 167, 910, 825, 971, 939, 161, 644, 561, 778, 987, 859, 321, 126, 913, 498, 207, 263, 201, 608, 410, 855, 130, 555, 668, 415, 377, 331, 656, 723, 416, 265, 356, 304, 709, 759, 719, 480, 394, 325, 785, 233, 838, 754, 563, 686, 634, 619, 904, 142, 999, 189, 923, 416, 898, 314, 446, 721, 909, 624, 361, 996, 250, 172, 499, 370, 874, 506, 416, 120, 701, 965, 311, 928, 165, 100, 553, 492, 127, 482, 554, 739, 174, 743, 385, 274, 962, 204, 900, 604, 466, 558, 555, 196, 558, 639, 962, 195, 589, 187, 355, 763, 347, 182, 792, 878, 413, 452, 226, 497, 201, 831, 722, 500, 785, 141, 245, 877, 774, 645, 223, 692, 963, 667, 960, 571, 615, 666, 362, 615, 939, 290, 217, 627, 752, 267, 764, 558, 919, 802, 895, 398, 856, 122, 570, 868, 702, 474, 741, 466, 131, 560, 676, 761, 494, 920, 127, 150, 841, 334, 788, 492, 659, 123, 756, 894, 630, 854, 628, 180, 552, 909, 586, 693, 897, 839, 519, 848, 510, 272, 522, 948, 436, 270, 655, 788, 518, 103, 545, 915, 207, 525, 659, 690, 203, 959, 912, 340, 771, 302, 447, 296, 313, 717, 246, 843, 747, 207, 214, 663, 692, 217, 266, 449, 247, 269, 844, 916, 558, 987, 478, 779, 325, 244, 209, 388, 240, 840, 776, 619, 948, 804, 499, 457, 514, 505, 231, 137, 624, 903, 865, 347, 102, 411, 833, 100, 421, 950, 501, 592, 966, 575, 758, 996, 404, 630, 560, 404, 698, 243, 723, 923, 308, 951, 140, 221, 217, 166, 356, 958, 994, 570, 264, 670, 175, 466, 555, 586, 923, 293, 347, 561, 273, 383, 984, 170, 476, 439, 747, 557, 441, 677, 817, 875, 545, 841, 416, 430, 904, 557, 901, 250, 358, 965, 799, 372, 788, 627, 137, 159, 503, 153, 583, 509, 386, 624, 581, 702, 735, 949, 950, 880, 345, 521, 410, 529, 944, 491, 353, 528, 622, 514, 355, 639, 368, 591, 768, 640, 203, 865, 115, 246, 465, 491, 362, 894, 664};

int datos2[TAM] = {5, 2, 8, 12, 4, 17, 19, 22, 1, 9, 13, 3, 15, 6, 11}; //Datos de prueba

int grafo[TAM][TAM] = {    {0, 2, 3, 2, 999, 4, 5, 2, 9, 999, 3, 2, 999, 5, 6},
    {2, 0, 2, 8, 999, 5, 999, 4, 6, 999, 8, 2, 3, 4, 1},
    {3, 2, 0, 1, 6, 3, 999, 5, 6, 1, 999, 4, 2, 7, 999},
    {2, 8, 1, 0, 1, 6, 1, 3, 3, 3, 999, 8, 1, 4, 999},
    {999, 999, 6, 1, 0, 999, 1, 4, 1, 999, 3, 1, 999, 1, 999},
    {4, 5, 3, 6, 999, 0, 999, 7, 1, 7, 6, 999, 2, 7, 4},
    {5, 999, 999, 1, 1, 999, 0, 4, 1, 4, 7, 4, 999, 1, 5},
    {2, 4, 5, 3, 4, 7, 4, 0, 2, 999, 4, 999, 1, 4, 1},
    {9, 6, 6, 3, 1, 1, 1, 2, 0, 9, 1, 2, 3, 6, 4},
    {999, 999, 1, 3, 999, 7, 4, 999, 9, 0, 4, 999, 999, 6, 2},
    {3, 8, 999, 999, 3, 6, 7, 4, 1, 4, 0, 4, 2, 999, 4},
    {2, 2, 4, 8, 1, 999, 4, 999, 2, 999, 4, 0, 7, 2, 999},
    {999, 3, 2, 1, 999, 2, 999, 1, 3, 999, 2, 7, 0, 7, 4},
    {5, 4, 7, 4, 1, 7, 1, 4, 6, 6, 999, 2, 7, 0, 8},
    {6, 1, 999, 999, 999, 4, 5, 1, 4, 2, 4, 999, 4, 8, 0}};

int grafo2[TAM2][TAM2] = {   {0, 2, 3, 2, 999},
    {2, 0, 2, 8, 999},
    {3, 2, 0, 1, 6},
    {2, 8, 1, 0, 1},
    {999, 999, 6, 1, 0}};



// Problema 1
int minoresimo (int datos[MAX], int k)
{
    priority_queue<int> mypq;
    
    for (int i=0; i<MAX; i++)
    {
        mypq.push(datos[i]);
    }
    
    for(int i=MAX-1; i>=0; i--)
    {
        datos[i] = mypq.top();
        mypq.pop();
    }
    
    return datos[k-1];
}

// Problema 2
// Documenta con comentarios TODOS los cambios que hagas a este código.
// Cuida la eficiencia pues se evaluará estrictamente.
int *numeros; // arreglo que guardará los números que forman parte de una suma válida.
// la posición i guarda el dato i si es parte de la solución, si no, guarda 0

void sumatorias (int i, int acum, int total, int N, int k)
// i es el nivel del árbol, acum el acumulado de la sumatoria en el nodo,
// total guarda el acumulado de todos los números aún no incluidos en la suma y
// N es el valor que se desea acumular en la sumatoria final.
{
    int x = 1;
    if (acum+total>=N && (acum == N || acum+i+1 <= N)) // condición para expandir nodo
        if (acum==N)  // Caso de fondo del árbol
        {    // se depliega solución encontrada
            //Contar el número de elementos que conforman la solución
            int iCount = 0;
            for(int m = 1; m<=N; m++)
            {
                if(numeros[m] != 0)
                {
                    iCount++;
                }
            }
            //Si el número de elementos es igual a k, imprimir la solución
            if(iCount == k)
            {
                while (numeros[x] == 0) x++;
                cout << numeros[x]; //Despliega el primer número de la sumatoria
                for(int k=x+1; k<=N; k++) //despliega el resto de los números separados por +
                    if (numeros[k] != 0) cout << "+" << numeros[k];
                cout << endl;
            }
        }
        else
        {
            numeros[i+1] = i+1;
            sumatorias(i+1, acum+i+1, total-(i+1), N, k); //expande considerando el valor i
            numeros[i+1] = 0;
            sumatorias(i+1, acum, total-(i+1), N, k); //expande sin considerar el valor i
        }
}

// Problema 3
// Algoritmos de referencia

void camino (int T[], int v) //Función auxiliar para desplgar los caminos más cortos del nodo 1 al v
{  if (T[v] != 1)
{  camino(T, T[v]);
    cout << "-" << T[v];  }
}

void dijkstra (int W[TAM][TAM])
{    int L[TAM+1], T[TAM+1], R[TAM+1], min, vmin;
    // el arreglo L guardará los costos de los caminos más cortos del nodo 1 al nodo i según se vayan acumulando
    // el arreglo T guarda el índice de un nodo de tal manera que el arco T[i] a i es el último en el camino más corto del nodo 1 al i.
    // el arreglo R guardará el resultado del camino más corto del nodo 1 al i.
    for (int i = 2; i<=TAM; i++)
    {  L[i] = W[0][i-1];
        T[i] = 1;     }
    for (int x = 1; x < TAM; x++)
    {    min = 999;
        for (int i = 2; i<= TAM; i++)
            if ( 0 <= L[i] && L[i] <= min)
            {  min = L[i];  vmin = i; }
        for (int i=2; i<= TAM; i++)
            if (L[vmin]+W[vmin-1][i-1] < L[i]) //aqui es donde se considera acumular caminos
            {    L[i] = L[vmin]+W[vmin-1][i-1];
                T[i] = vmin; }
        R[vmin] = L[vmin];
        L[vmin] = -1;
    }
    cout << "\nCAMINOS MAS CORTOS\n"; // para desplegar todos los caminos resultantes a partir del nodo 1
    for (int i = 2; i <= TAM; i++)
    {
        cout << "de 1 a " << i << ": 1";
        
        camino(T, i);
        cout << "-" << i << " cuesta " << R[i] << " unidades\n";
    }
}

void ArbolExtMax (int W[TAM][TAM], int vmin, int min, int L[])
// Esta función deberá desplegar los arcos que conforman el árbol de extensión máxima del grafo dado como entrada
{
    for(int i=0; i<TAM; i++)
    {
        if(L[i+1] == -1)
        {
            if(W[vmin-1][i] == min)
            {
                cout << "Arco: " << i+1 << " - " << vmin << endl;
                break;
            }
        }
    }
}

int Prim (int W[TAM][TAM])
// recibe matriz de adyacencias
// Intencionalmente para este examen, esta función NO despliega ningún resultado. Tu deberás adaptarla para que genere lo necesario
{    int L[TAM+1], T[TAM+1], min = 999, vmin = 0, iCost = 0;
    // el arreglo L guardará los costos de los arcos del los nodos i necesarios de conectar
    // el arreglo T guarda los arcos solución siendo T[i] el origen e i el destino de cada arco.
    
    for (int i = 1; i<=TAM; i++)// se inicializan arreglos con los arcos del primer nodo
    {
        L[i] = W[0][i-1];
        T[i] = 1;
        
    }
    
    L[1] = -1; // el primer nodo ya es parte de la solución
    for (int x = 1; x < TAM; x++) // ciclo para buscar el arco más pequeño
    {
        min = 999;
        for (int i = 1; i<= TAM; i++)
        {
            if ( 0 <= L[i] && L[i] <= min)
            {
                min = L[i];
                vmin = i;
            }
        }
      
        iCost += min;
        
        // ciclo para actualizar los nuevos arcos que "concursan" para la solución
        for (int i=1; i<= TAM; i++)
        {
            if (W[vmin-1][i-1] < L[i])
            {
                L[i] = W[vmin-1][i-1];
                T[i] = vmin;
            }
        }

        ArbolExtMax(W, vmin, min, L);
        L[vmin] = -1; //se descarta arco del nodo que ya está en la solución
    }
    return iCost;
}


int costoTotal(int grafo[TAM][TAM])
{
    int iCount = 0;
    for(int i=0; i<TAM; i++)
    {
        for(int j=i; j<TAM; j++)
        {
            if(grafo[i][j] != 999)
            {
                iCount += grafo[i][j];
            }
        }
    }
    return iCount;
}

int main()
{
    
    // Ejecución del problema 1
    cout << "PROBLEMA #1 - k-esimo menor" << endl;
    int k;
    cout << "Cual es el valor de k para obtener el k-esimo dato menor? ";
    cin >> k;
    cout << "El k-esimo menor de los datos es: " << minoresimo(datos, k) << endl;
    
    
    
    // Ejecución del problema 2
    // Documenta con comentarios TODOS los cambios que hagas a este código.
    // Cuida la eficiencia pues se evaluará estrictamente.
    cout << endl << "PROBLEMA #2 - Sumatorias de K dígitos que obtienen N" << endl;
    int N;
    cout << "Cual es el valor de k (cantidad de digitos) para obtener las sumatorias? ";
    cin >> k;
    cout << "Cual es el valor de N para obtener sumatorias? ";
    cin >> N;
    // incialización del arreglo de numeros que requiere el proceso
    numeros = new int[N+1];
    for (int i=0; i<=N; i++) numeros[i]=0;
    // llamada al proceso de solución
    sumatorias(0,0,N*(N+1)/2,N, k); // el tercer parámetro es la sumatoria de 1 a N, que es el total inicial.
    
    
    //Ejecución del problema 3
    cout << endl << "PROBLEMA #3 - Arbol de extension MAXIMA" << endl;
    cout << "Arcos del arbol de extensión máxima: " << endl;
    int costoMinimo = Prim(grafo);
    int costoMaximo = costoTotal(grafo);
    
    cout << endl << "Diferencia de costo total: " << costoMaximo - costoMinimo << endl;
    
}


