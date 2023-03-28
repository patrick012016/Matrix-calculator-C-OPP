#include "diax.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Funkcja odpowiedzialna za wprowadzanie danych do macierzy, werfikacje czy
 * użytkownik nie wprowadził innego symbolu niż liczba, sumowanie dwóch macierzy diagonalnych oraz jej wypisanie.
 * @tparam T szablon przyjmujący wartości zmiennoprzecinkowe vectorów w których przechowywane są macierze
 * @param nn stopień macierzy
 */
template <typename T>
void diaxCheck(int nn)
{
    vector<vector<T>> vec1( nn , vector<T> (nn));
    vector<vector<T>> vec2( nn , vector<T> (nn));
    vector<vector<T>> vecw( nn , vector<T> (nn));
    bool help25;
    do
    {
        help25=false;
        cout <<"Podaj swoją pierwszą macierz: " << endl;
        for(int i = 0; i < nn; i++)
        {
            for(int j = 0; j < nn; j++)
            {
                cin >> vec1[i][j];
            }
        }
        if (cin.fail())
        {
            cout << endl << "Wprowadzono symbol, który nie jest liczbą!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            help25=true;
        }
    }
    while (help25);
    do
    {
        help25=false;
        cout << endl << "Podaj swoją drugą macierz: " << endl;
        for(int i = 0; i < nn; i++)
        {
            for(int j = 0; j < nn; j++)
            {
                cin >> vec2[i][j];
                if(i==j)
                    vecw[i][j]=vec1[i][j]+vec2[i][j];
            }
        }
        if (cin.fail())
        {
            cout << endl << "Wprowadzono symbol, który nie jest liczbą!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            help25=true;
        }
    }
    while (help25);

    cout << endl << "Macierz wynikowa po dodaniu dwóch macierzy diagonalnych: " << endl;
    for(int i = 0; i < nn; i++)
    {
        for(int j = 0; j < nn; j++)
        {
            cout << vecw[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * Funkcja odpowiedzialna za wprowadzanie danych do macierzy, werfikacje czy
 * użytkownik nie wprowadził innego symbolu niż liczba, mnożenie ze sobą dwóch macierzy diagonalnych oraz jej wypisanie.
 * @tparam T szablon przyjmujący wartości zmiennoprzecinkowe vectorów w których przechowywane są macierze
 * @param nn stopień macierzy
 */
template <typename T>
void diaxCheck1(int nn)
{
    vector<vector<T>> vec1( nn , vector<T> (nn));
    vector<vector<T>> vec2( nn , vector<T> (nn));
    vector<vector<T>> vecw( nn , vector<T> (nn));
    bool help25;
    do
    {
        help25=false;
        cout <<"Podaj swoją pierwszą macierz: " << endl;
        for(int i = 0; i < nn; i++)
        {
            for(int j = 0; j < nn; j++)
            {
                cin >> vec1[i][j];
            }
        }
        if (cin.fail())
        {
            cout << endl << "Wprowadzono symbol, który nie jest liczbą!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            help25=true;
        }
    }
    while (help25);
    do
    {
        help25=false;
        cout << endl << "Podaj swoją drugą macierz: " << endl;
        for(int i = 0; i < nn; i++)
        {
            for(int j = 0; j < nn; j++)
            {
                cin >> vec2[i][j];
                if(i==j)
                    vecw[i][j]=vec1[i][j]-vec2[i][j];
            }
        }
        if (cin.fail())
        {
            cout << endl << "Wprowadzono symbol, który nie jest liczbą!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            help25=true;
        }
    }
    while (help25);
    cout << endl << "Macierz wynikowa po odjęciu dwóch macierzy diagonalnych: " << endl;

    for(int i = 0; i < nn; i++)
    {
        for(int j = 0; j < nn; j++)
        {
            cout << vecw[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * * Funkcja odpowiedzialna za wprowadzanie danych do macierzy, werfikacje czy
 * użytkownik nie wprowadził innego symbolu niż liczba, mnożenie dwóch diagonalnych oraz jej wypisanie.
 * @tparam T szablon przyjmujący wartości zmiennoprzecinkowe vectorów w których przechowywane są macierze
 * @param nn stopień macierzy
 */
template <typename T>
void diaxCheck2(int nn)
{
    vector<vector<T>> vec1( nn , vector<T> (nn));
    vector<vector<T>> vec2( nn , vector<T> (nn));
    vector<vector<T>> vecw( 10 , vector<T> (nn));
    bool help25;
    do
    {
        help25=false;
        cout <<"Podaj swoją pierwszą macierz: " << endl;

        for(int i = 0; i < nn; i++)
        {
            for(int j = 0; j < nn; j++)
            {
                cin >> vec1[i][j];
            }
        }

        if (cin.fail())
        {
            cout << endl << "Wprowadzono symbol, który nie jest liczbą!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            help25=true;
        }
    }
    while (help25);
    do
    {
        help25=false;
        cout << endl << "Podaj swoją drugą macierz: " << endl;

        for(int i = 0; i < nn; i++)
        {
            for(int j = 0; j < nn; j++)
            {
                cin >> vec2[i][j];
            }
        }
        if (cin.fail())
        {
            cout << endl << "Wprowadzono symbol, który nie jest liczbą!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            help25=true;
        }
    }
    while (help25);
    cout << endl << "Macierz wynikowa po wymnożeniu dwóch macierzy diagonalnych: " << endl;

    for(int i = 0; i < nn; ++i)
        for(int j = 0; j < nn; ++j)
            for(int l = 0; l < nn; ++l)
            {
                if(i==j)
                    vecw[i][j] += vec1[i][l] * vec2[l][j];
            }
    for(int i = 0; i < nn; ++i)
        for(int j = 0; j < nn; ++j)
        {
            cout << vecw[i][j] << " ";
            if (j == nn-1)
                cout << endl;
        }
}

/**
 * Funkcja główna dodawania odpowiedzialna za wczytanie danych o macierzach diagonalnych użytkownika oraz
 * walidację wpisanych danych.
 */
void Diax:: add ()
{
    {
        bool help;
        do
        {
            help=false;
            cout << "Podaj stopień macierzy diagonalnej: " << endl;
            cin >> nn;
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
        diaxCheck<float>(nn);
    }
}

/**
 * Funkcja główna odejmowania odpowiedzialna za wczytanie danych o macierzach diagonalnych użytkownika oraz
 * walidację wpisanych danych.
 */
void Diax:: subtract()
{
    {
        bool help;
        do
        {
            help=false;
            cout << "Podaj stopień macierzy diagonalnej: " << endl;
            cin >> nn;
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
        diaxCheck1<float>(nn);
    }
}

/**
 * Funkcja główna mnożenia odpowiedzialna za wczytanie danych o macierzach diagonalnych
 * użytkownika oraz walidację wpisanych danych.
 */
void Diax::multiply()
{
    {
        bool help;
        do
        {
            help=false;
            cout << "Podaj stopień macierzy diagonalnej: " << endl;
            cin >> nn;
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
        diaxCheck2<float>(nn);
    }
}