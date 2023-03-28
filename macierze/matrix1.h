#ifndef MACIERZE_MATRIX1_H
#define MACIERZE_MATRIX1_H

#include <iostream>
#include <cmath>
using namespace std;

/**
 * Funkcja odpowiedzialna za wprowadzanie danych do macierzy oraz werfikacje czy
 * użytkownik nie wprowadził innego symbolu niż liczba.
 */
void matrixUniversal(int n, double** tab)
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
            cout << endl << "Wprowadzono symbol, który nie jest liczbą!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            help=true;
        }
    }
    while (help);
}

/**
 * Funkcja odpowiedzialna za rekurencyjną metedę wylicznania wyznacznika.
 * Funkcja została napisana w oparciu o kod zamieszczony na stronie:
 * https://www.tutorialspoint.com/cplusplus-program-to-compute-determinant-of-a-matrix
 * @param matrix tablica wprowadzonej macierzy przez użytkownika
 * @param n stopień macierzy
 * @param x zmienna pomocnicza
 * @param y zmienna pomocnicza
 * @return
 */
double **submatrix(double **matrix,  int n, int x, int y)
{
    double **submatrix;
    submatrix= new double *[n - 1];
    int subi = 0;
    for (int i = 0; i < n; i++)
    {
        submatrix[subi] = new double [n - 1];
        int subj = 0;
        if (i == y)
        {
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (j == x)
            {
                continue;
            }
            submatrix[subi][subj] = matrix[i][j];
            subj++;
        }
        subi++;
    }
    return submatrix;
}

/**
 * Funkcja odpowiedzialna za rekurencyjną metedę wylicznania wyznacznika (funkcja zwracająca końcowy wynik).
 * Funkcja została napisana w oparciu o kod zamieszczony na stronie:
 * https://www.tutorialspoint.com/cplusplus-program-to-compute-determinant-of-a-matrix
 * @param matrix tablica wprowadzonej macierzy przez użytkownika
 * @param n stopień macierzy
 * @return
 */
double determinantUniversal(double **matrix, int n)
{
    double det = 0;
    if (n == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }
    for (int x = 0; x < n; ++x)
    {
        det += ((x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinantUniversal(submatrix(matrix, n, x, 0), n - 1));
    }
    return det;
}

/**
 * Użycie dla 2 pierwszych przypadków wzorów bo uniwersalna funkcja, która jest wyżej jest zasobno i czaso chłonna.
 * Funkcja główna wraz z walidacją danych wprowadzonego stopnia macierzy przez użytkownika.
 */
void matrixDet()
{
    int n = 0;
    bool help;
    double** tab;
    tab = new double*[n];
    do
    {
        help=false;
        cin >> n;
        if (cin.peek() != '\n')
        {
            cout << endl;
            goto error;
        }
        cout << endl;
        switch (n)
        {
            case 1:
            {
                bool help1;
                float x;
                do
                {
                    help1=false;
                    cout << "Podaj swoją macierz: " << endl;
                    cin >> x;
                    if(cin.peek() != '\n')
                    {
                        cout << endl << "Wprowadzono symbol, który nie jest liczbą! " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        help1=true;
                    }
                }
                while (help1);
                cout << endl << "Wyznacznik " << n << " stopnia wprowadzonej macierzy wynosi: " << x << "." << endl;
                break;
            }
            case 2:
            {
                matrixUniversal(n, tab);
                double det2 = (tab[0][0] * tab[1][1]) - (tab[0][1] * tab[1][0]);
                cout << endl << "Wyznacznik " << n << " stopnia wprowadzonej macierzy wynosi: " << det2 << "." << endl;
                break;
            }
            case 3:
            {
                matrixUniversal(n, tab);
                cout << endl << "Wyznacznik " << n << " stopnia wprowadzonej macierzy wynosi: " << determinantUniversal(tab, n);
                cout << ". " << endl;
                break;
            }
            case 4:
            {
                matrixUniversal(n, tab);
                cout << endl << "Wyznacznik " << n << " stopnia wprowadzonej macierzy wynosi: " << determinantUniversal(tab, n);
                cout << ".  " << endl;
                break;
            }
            case 5:
            {
                matrixUniversal(n, tab);
                cout << endl << "Wyznacznik " << n << " stopnia wprowadzonej macierzy wynosi: " << determinantUniversal(tab, n);
                cout << ".   " << endl;
                break;
            }
            error:
            default:
                cout << "Wybór niepoprawny!!!" << endl;
                cout << "Wpisz ponownie swój wybór." << endl;
                help=true;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
    while (help);
    for (int i = 0; i < n; ++i)
    {
        delete[] tab[i];
    }
    delete[] tab; 
}
#endif