#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>
//#include <cstdint>

#include "cronometro.h"

using namespace std;
ofstream file;

void print_array(int *array, int tamano)
{
    int i = 0;
    for (i = 0; i < tamano - 1; i++) {
        cout << array[i] << ", ";
    }
    cout << array[i] << "\n";
}

void burbuja(int *array, int tamano)
{
    for (int i = 0; i < tamano; i++) {
        for (int j = i + 1; j < tamano; j++) {
            if(array[j] <= array[i]) {
                int aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

void sel_directa(int *array, int tamano)
{
    for (int i = 0; i < tamano; i++) {
        int aux = array[i];
        int p = 0;
        for (int j = i; j < tamano; j++) {
            if(array[j] <= aux) {
                aux = array[j];
                p = j;
            }
        }
        array[p] = array[i];
        array[i] = aux;
    }
}

void inser_directa(int *array, int tamano)
{
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            int x = array[j];
            if(x > array[j + 1]) {
                array[j] = array[j + 1];
                array[j + 1] = x;
            }
        }
    }
}

void permutaciones_burbuja(int *array, int n) {
    int total_num_perm = 0;
    int num_perm;
    int array_perms[n];
    double t;
    cronometro c;
    file.open("burbu.txt", ios::trunc);
    
    for (int i = 0; i < n; i++) {
        c.activar();
        t = 0;
        num_perm = 0;
        do {
            memcpy(array_perms, array, (sizeof (int)) * i);
            
            //print_array(array_perms, i);
            burbuja(array_perms, i);
            //print_array(array_perms, i);
            
            num_perm++;
            total_num_perm++;
        } while (next_permutation(array, array + i));
        c.parar();
        t = c.tiempo();
        
        cout << "Con tamaño " << (i) << " tiene " << num_perm << " permutaciones y tarda ";
        cout << t << "segundos.";
        cout << "\n";
        file << (i + 1) << "  " << t << "\n";
    }
    file.close();
    cout << "El numero de permutaciones total es => " << total_num_perm << ".\n";
}

void permutaciones_sel_directa(int *array, int n) {
    int total_num_perm = 0;
    int num_perm;
    int array_perms[n];
    double t;
    cronometro c;
    file.open("sel_directa.txt", ios::trunc);
    
    for (int i = 0; i < n; i++) {
        c.activar();
        t = 0;
        num_perm = 0;
        do {
            memcpy(array_perms, array, (sizeof (int)) * i);
            
            //print_array(array_perms, i);
            sel_directa(array_perms, i);
            //print_array(array_perms, i);
            
            num_perm++;
            total_num_perm++;
        } while (next_permutation(array, array + i));
        c.parar();
        t = c.tiempo();
        
        cout << "Con tamaño " << (i) << " tiene " << num_perm << " permutaciones y tarda ";
        cout << t << "segundos.";
        cout << "\n";
        file << (i + 1) << "  " << t << "\n";
    }
    file.close();
    cout << "El numero de permutaciones total es => " << total_num_perm << ".\n";
}

void permutaciones_inser_directa(int *array, int n) {
    int total_num_perm = 0;
    int num_perm;
    int array_perms[n];
    double t;
    cronometro c;
    file.open("inser_directa.txt", ios::trunc);
    
    for (int i = 0; i < n; i++) {
        c.activar();
        t = 0;
        num_perm = 0;
        do {
            memcpy(array_perms, array, (sizeof (int)) * i);
            
            //print_array(array_perms, i);
            inser_directa(array_perms, i);
            //print_array(array_perms, i);
            
            num_perm++;
            total_num_perm++;
        } while (next_permutation(array, array + i));
        c.parar();
        t = c.tiempo();
        
        cout << "Con tamaño " << (i) << " tiene " << num_perm << " permutaciones y tarda ";
        cout << t << "segundos.";
        cout << "\n";
        file << (i + 1) << "  " << t << "\n";
    }
    file.close();
    cout << "El numero de permutaciones total es => " << total_num_perm << ".\n";
}

void aleat_permutaciones(int *array, int n)
{
    double t;
    int array_perms[n];
    cronometro c;
    
    for (int i = 0; i < n; i += 1000) {
        c.activar();
        t = 0;
        
        memcpy(array_perms, array, (sizeof (int)) * i);
        random_shuffle(array_perms, array_perms + i);
        //print_array(array_perms, i);
        
        c.parar();
        t = c.tiempo();
    }
}

int main(int argc, const char *argv[])
{
    //int N = 20000;
    int N = 9;
    int numeros[N];
    for (int i = 0; i < N; i++)
    {
        numeros[i] = i;
    }
    
    //EJ 1
    //print_array(numeros, N);
    burbuja(numeros, N);
    print_array(numeros, N);
    sel_directa(numeros, N);
    
    print_array(numeros, N);
    
    //EJ 2
    inser_directa(numeros, N);
    
    print_array(numeros, N);
    
    //EJ 3
    permutaciones_burbuja(numeros, N);
    permutaciones_sel_directa(numeros, N);
    permutaciones_inser_directa(numeros, N);
    
    //aleat_permutaciones(numeros, N);
    
    return 0;
}
