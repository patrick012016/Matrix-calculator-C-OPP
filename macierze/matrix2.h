#ifndef MACIERZE_MATRIX2_H
#define MACIERZE_MATRIX2_H

#include <iostream>
#include <cmath>
using namespace std;

/**
 * Funkcja odpowiedzialna za transponowanie macierzy oraz jej wypisanie.
 * @param tab tablica wprowadzonej macierzy przez użytkownika
 * @param ww ilość wierszy
 * @param kk ilość kolumn
 */
void transposeUniversal(double** tab, int ww, int kk)
{
    double TabTranspose[10][10];
    for (int i = 0; i < ww; ++i)
        for (int j = 0; j < kk; ++j)
        {
            TabTranspose[j][i] = tab[i][j];
        }
    cout << endl << "Wrowadzona macierz po transponowaniu: " << endl;
    for (int i = 0; i < kk; ++i)
        for (int j = 0; j < ww; ++j)
        {
            cout << " " << TabTranspose[i][j];
            if (j == ww - 1)
                cout << endl;
        }
}

/**
 * Funkcja odpowiedzialna za wprowadzanie danych do macierzy oraz werfikacje czy
 * użytkownik nie wprowadził innego symbolu niż liczba.
 * @param w ilość wierszy
 * @param k ilość kolumn
 * @param tab tablica wprowadzonej macierzy przez użytkownika
 */
void check(int w, int k, double** tab)
{
    bool help;
    do
    {
        help=false;
        cout << "Podaj swoją macierz: " << endl;
        for(int m = 0; m < w; ++m)
        {
            tab[m] = new double [k];
        }
        for (int i = 0; i < w; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                cin >> tab[i][j];
            }
        }
        if (cin.fail())
        {
            cout << endl << "Wprowadzono symbol, który nie jest liczbą!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            help=true;
        }
    }
    while (help);
}

/**
 * Funkcja główna odpowiedzialna za wczytywanie macierzy użytkownika oraz walidację wpisanych danych.
 */
void matrixTroanspose()
{
    int w=0, k=0;
    bool help;
    bool help1;
    double** tab;
    tab = new double*[w];
        do
        {
            help=false;
            cout << "Podaj ilość wierszy: " << endl;
            cin >> w;
            if(cin.peek() != '\n')
            {
                cout << endl << "Wprowadzono symbol, który nie jest liczbą! " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                help=true;
            }
        }
        while (help);
        do
        {
            help1=false;
            cout << "Podaj ilość kolumn: " << endl;
            cin >> k;
            if(cin.peek() != '\n')
            {
                cout << endl << "Wprowadzono symbol, który nie jest liczbą! " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                help1=true;
            }
        }
        while (help1);
        cout << endl;
        check(w, k, tab);
        transposeUniversal(tab, w, k);
        for (int i = 0; i < w; ++i)
        {
            delete[] tab[i];
        }
        delete[] tab;
}
#endif