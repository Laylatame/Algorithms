//
//  main.cpp
//  examenFinal
//
//  Created by Layla Tame on 5/10/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

// Nombre: Layla Tame
// Matrícula: A01192934

// EXAMEN FINAL DE ANÁLISIS Y DISEÑO DE ALGORITMOS EM19
// 10 de mayo 2019

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const int n1 = 6; //caso prueba
const int n = 45;
//const int m = 3; //COLORES PRUEBA

//Caso prueba
int distancias1[n1][n1] = {{9999,1,1,9999,9999,9999},{1,9999,1,1,1,9999},{1,1,9999,9999,9999,9999},{9999,1,9999,9999,1,1},{9999,1,9999,1,9999,9999},{9999,9999,9999,1,9999,9999}};

int distancias[n][n] =
{{0, 9999, 9999, 9999, 276, 9999, 9999, 321, 9999, 9999, 59, 9999, 9999, 9999, 9999, 1320, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 1500},
    { 9999, 0, 542, 9999, 9999, 134, 9999, 9999, 9999, 9999, 9999, 164, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 542, 0, 9999, 9999, 9999, 9999, 9999, 1048, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 0, 150, 9999, 9999, 9999, 9999, 872, 9999, 9999, 9999, 9999, 85, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 276, 9999, 9999, 150, 0, 125, 178, 200, 543, 321, 765, 342, 111, 90, 999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 134, 9999, 9999, 125, 0, 9999, 9999, 9999, 9999, 9999, 9999, 631, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 178, 9999, 0, 722, 43, 9999, 9999, 9999, 9999, 892, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 321, 9999, 9999, 9999, 200, 9999, 722, 0, 277, 9999, 9999, 9999, 9999, 9999, 722, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 1048, 9999, 543, 9999, 43, 277, 0, 9999, 9999, 421, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 872, 321, 9999, 9999, 9999, 9999, 0, 25, 9999, 50, 9999, 100, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 59, 9999, 9999, 9999, 765, 9999, 9999, 9999, 9999, 25, 0, 9999, 9999, 175, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 164, 9999, 9999, 342, 9999, 9999, 9999, 421, 9999, 9999, 0, 9999, 9999, 501, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 111, 631, 9999, 9999, 9999, 50, 9999, 9999, 0, 453, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 90, 9999, 892, 9999, 9999, 9999, 175, 9999, 453, 0, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 85, 999, 9999, 9999, 722, 9999, 100, 9999, 501, 9999, 9999, 0, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 1320, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 0, 9999, 9999, 9999, 276, 9999, 9999, 321, 9999, 9999, 59, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 0, 542, 9999, 9999, 134, 9999, 9999, 9999, 9999, 9999, 164, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 542, 0, 9999, 9999, 9999, 9999, 9999, 1048, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 0, 150, 9999, 9999, 9999, 9999, 872, 9999, 9999, 9999, 9999, 85, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 276, 9999, 9999, 150, 0, 125, 178, 200, 543, 321, 765, 342, 111, 90, 999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 134, 9999, 9999, 125, 0, 9999, 9999, 9999, 9999, 9999, 9999, 631, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 178, 9999, 0, 722, 43, 9999, 9999, 9999, 9999, 892, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 321, 9999, 9999, 9999, 200, 9999, 722, 0, 277, 9999, 9999, 9999, 9999, 9999, 722, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 1048, 9999, 543, 9999, 43, 277, 0, 9999, 9999, 421, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 872, 321, 9999, 9999, 9999, 9999, 0, 25, 9999, 50, 9999, 100, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 59, 9999, 9999, 9999, 765, 9999, 9999, 9999, 9999, 25, 0, 9999, 9999, 175, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 164, 9999, 9999, 342, 9999, 9999, 9999, 421, 9999, 9999, 0, 9999, 9999, 501, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 111, 631, 9999, 9999, 9999, 50, 9999, 9999, 0, 453, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 90, 9999, 892, 9999, 9999, 9999, 175, 9999, 453, 0, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 85, 999, 9999, 9999, 722, 9999, 100, 9999, 501, 9999, 9999, 0, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 0, 9999, 9999, 9999, 276, 9999, 9999, 321, 9999, 9999, 59, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 0, 542, 9999, 9999, 134, 9999, 9999, 9999, 9999, 9999, 164, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 542, 0, 9999, 9999, 9999, 9999, 9999, 1048, 9999, 9999, 9999, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 0, 150, 9999, 9999, 9999, 9999, 872, 9999, 9999, 9999, 9999, 85},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 276, 9999, 9999, 150, 0, 125, 178, 200, 543, 321, 765, 342, 111, 90, 999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 134, 9999, 9999, 125, 0, 9999, 9999, 9999, 9999, 9999, 9999, 631, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 178, 9999, 0, 722, 43, 9999, 9999, 9999, 9999, 892, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 321, 9999, 9999, 9999, 200, 9999, 722, 0, 277, 9999, 9999, 9999, 9999, 9999, 722},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 1048, 9999, 543, 9999, 43, 277, 0, 9999, 9999, 421, 9999, 9999, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 872, 321, 9999, 9999, 9999, 9999, 0, 25, 9999, 50, 9999, 100},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 59, 9999, 9999, 9999, 765, 9999, 9999, 9999, 9999, 25, 0, 9999, 9999, 175, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 164, 9999, 9999, 342, 9999, 9999, 9999, 421, 9999, 9999, 0, 9999, 9999, 501},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 111, 631, 9999, 9999, 9999, 50, 9999, 9999, 0, 453, 9999},
    { 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 90, 9999, 892, 9999, 9999, 9999, 175, 9999, 453, 0, 9999},
    { 1500, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 85, 999, 9999, 9999, 722, 9999, 100, 9999, 501, 9999, 9999, 0}};

int vcolor[n+1]; //Almacena el color asignado al nodo i
int iSum = 0; //Llevar cuenta de cuantas soluciones existen (no aplica en este caso)
bool found = false; //Parar después de encontrar la primera solución

bool valido(int i)
{
    int j = 1;
    bool SW = true;
    
    while(j < i && SW)
    {
        //Validar que las casas adyacentes no tengan el color i
        if(distancias[i-1][j-1] != 9999 && vcolor[i] == vcolor[j])
        {
            return false;
        }
        j++;
    }
    return true;
}

void coloreado(int i, int m)
{
    vector<int> cantColores(m, 0);
    
    if(valido(i))
    {
        if(i==n)
        {
            cout << "--------------------------" << endl;
            iSum++;
            for(int x=1; x<=n; x++)
            {
                cout << "Casa: " << x << " se pinta del color #" << vcolor[x] << endl;
                //Almacenar cuantas casas se pintan de un color
                cantColores[vcolor[x]-1]++;
            }
            cout << endl;
            for(int i=0; i<m; i++)
            {
                //Imprimir cuantas casas hay por color
                cout << "Casas con color " << i+1 << ": " << cantColores[i] << endl;
            }
            found = true;
        }
        else
        {
            for(int color = 1; color <= m; color++)
            {
                //Asignar el color a la casa i
                vcolor[i+1] = color;
                coloreado(i+1, m);
                //Si ya se encontró una solución, parar de buscar
                if(found)
                {
                    break;
                }
            }
        }
    }
}

int main()
{
    int m;
    cout << "Cantidad de colores a utilizar: ";
    cin >> m;
    coloreado(0, m);
}