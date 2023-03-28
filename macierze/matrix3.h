#ifndef MACIERZE_MATRIX3_H
#define MACIERZE_MATRIX3_H
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * Funkcja odpowiedzialna za wprowadzanie danych do macierzy oraz werfikacje czy
 * użytkownik nie wprowadził innego symbolu niż liczba.
 * @param n stopień macierzy
 * @param tab tablica wprowadzonej macierzy przez użytkownika
 */
void checkInverse(int n, double ** tab)
{
    bool help;
    do
    {
        help=false;
        cout << "Podaj swoją macierz: " << endl;
        for(int k = 0; k < n; ++k)
        {
            tab[k] = new double [n];
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> tab[i][j];
            }
        }
        if (cin.fail())
        {
            cout << endl << "Wprowadzono symbol, który nie jest liczbą!  " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            help=true;
        }
    }
    while (help);
}

/**
 * Funkcja odpowiedzialna za wypisanie wyliczonej końcowej macierzy odwrotnej.
 * @param ar tablica końcowej macierzy
 * @param n ilość wierszy
 * @param m ilość kolumn
 */
void PrintInverse(double** ar, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < m; j++)
        {
            cout  << fixed << ar[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * Funckja odpowiedzialna za wyliczenie macierzy odwrotnej poprzez implementację metody tzw. eliminacji Gaussa.
 * Polega ona na rozszerzeniu macierzy właściwej o macierz jednostkową oraz poprzez podstawowe operację na wierszach
 * utworzyć macierz schodkową.
 * Wzorowano na kodzie umieszczonym na stronie:
 * https://www.geeksforgeeks.org/finding-inverse-of-a-matrix-using-gauss-jordan-method/
 * @param matrix tablica wprowadzonej macierzy przez użytkownika
 * @param order stopień macierzy
 */
void InverseOfMatrix(double** matrix, int order)
{
    double temp;
    for (int i = 0; i < order; i++)                         // tworzenie macierzy rozszerzonej
    {
        for (int j = 0; j < 2 * order; j++)
        {
            if (j == (i + order))
                matrix[i][j] = 1;                           // tworzenie macierzy jednostkowej
        }
    }

    for (int i = order - 1; i > 0; i--)                     // zamiana wierszy macierzy
    {
        if (matrix[i - 1][0] < matrix[i][0])
        {
            double* temp1;
            temp1= matrix[i];
            matrix[i] = matrix[i - 1];
            matrix[i - 1] = temp1;
        }
    }

    for (int i = 0; i < order; i++)                         // zastępowanie wiersza sumą
    {
        for (int j = 0; j < order; j++)
        {
            if (j != i)
            {
                temp = matrix[j][i] / matrix[i][i];
                for (int k = 0; k < 2 * order; k++)
                {
                    matrix[j][k] -= matrix[i][k] * temp;    //   mnożenie przez stałą
                }
            }
        }
    }

    for (int i = 0; i < order; i++)                         // mnożenie każdego wiesza
    {

        temp = matrix[i][i];
        for (int j = 0; j < 2 * order; j++)
        {

            matrix[i][j] = matrix[i][j] / temp;             // dzielenie elemtu rzędu
        }
    }
    cout << endl << "Wyliczona macierz odwrotna: " << endl << endl;
    PrintInverse (matrix, order, 2 * order);
}

/**
 * Funkcja główna odpowiedzialna za wczytywanie macierzy użytkownika oraz walidację wpisanych danych.
 * Sprawdza też czy wyznacznik wprowadzonej macierzy jest równy zero. Jeśli tak kończy program.
 */
void matrixInverse()
{
    int n=0;
    bool help;
    double** tab;
    tab = new double*[n];
    do
    {
        help=false;
        cout << "Podaj stopień macierzy: " << endl;
        cin >> n;
        if(cin.peek() != '\n')
        {
            cout << endl << "Wprowadzono symbol, który nie jest liczbą! " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            help=true;
        }
    }
    while (help);
    cout << endl;
    checkInverse(n, tab);
    if(determinantUniversal(tab, n)==0)
    {
        cout << endl << "Nie można wyliczyć macierzy odwrotnej." << endl;
        cout << "Wyznacznik macierzy jest równy zero!!! " << endl;
    }
    else
    {
        InverseOfMatrix(tab, n);
    }

    for (int i = 0; i < n; ++i)
    {
        delete[] tab[i];
    }
    delete[] tab;
}
#endif