#ifndef MACIERZE_START_H
#define MACIERZE_START_H

#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

/**
 * Funkcja przywitalna z opisem programu i przejściem sekwencyjnym do menu głównego programu.
 */
void start()
{
    cout << endl << "***************************************************" << endl;
    cout << " Projekt PK 'Kalkulator do działania na macierzach" << endl << endl;
    cout << "               RE 1 POLSL 2021" << endl <<endl;
    cout << "***************************************************" << endl;
    Sleep (1000);
    for (int i=5; i>0; i--)
    {
        cout << "\rPrzekierowanie do menu głównego za: " << i << "s." <<flush;
        Sleep (1000);
    }
    system ("cls");
}
#endif