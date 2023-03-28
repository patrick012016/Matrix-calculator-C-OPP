#include "general.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Funkcja odpowiedzialna za wprowadzanie danych do macierzy, werfikacje czy
 * użytkownik nie wprowadził innego symbolu niż liczba, sumowanie dwóch macierzy oraz jej wypisanie.
 * @tparam T szablon przyjmujący wartości zmiennoprzecinkowe vectorów w których przechowywane są macierze
 * @param w ilość wierszy
 * @param k ilość kolumn
 */
template <typename T>
void generalCheck(int w, int k)
{
    vector<vector<T>> vec1( w , vector<T> (k));
    vector<vector<T>> vec2( w , vector<T> (k));
    vector<vector<T>> vecw( w , vector<T> (k));
    bool help25;
    do
    {
        help25=false;
        cout <<"Podaj swoją pierwszą macierz: " << endl;

        for(int i = 0; i < w; i++)
        {
            for(int j = 0; j < k; j++)
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
        for(int i = 0; i < w; i++)
        {
            for(int j = 0; j < k; j++)
            {
                cin >> vec2[i][j];
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

    cout << endl << "Macierz wynikowa po dodaniu dwóch macierzy: " << endl;
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cout << vecw[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * Funkcja odpowiedzialna za wprowadzanie danych do macierzy, werfikacje czy
 * użytkownik nie wprowadził innego symbolu niż liczba, różnice dwóch macierzy oraz jej wypisanie.
 * @tparam T szablon przyjmujący wartości zmiennoprzecinkowe vectorów w których przechowywane są macierze
 * @param w ilość wierszy
 * @param k ilość kolumn
 */
template <typename T>
void generalCheck1(int w, int k)
{
    vector<vector<T>> vec1( w , vector<T> (k));
    vector<vector<T>> vec2( w , vector<T> (k));
    vector<vector<T>> vecw( w , vector<T> (k));
    bool help25;
    do
    {
        help25=false;
        cout <<"Podaj swoją pierwszą macierz: " << endl;
        for(int i = 0; i < w; i++)
        {
            for(int j = 0; j < k; j++)
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
        for(int i = 0; i < w; i++)
        {
            for(int j = 0; j < k; j++)
            {
                cin >> vec2[i][j];
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
    cout << endl << "Macierz wynikowa po odjęciu dwóch macierzy: " << endl;
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cout << vecw[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * Funkcja odpowiedzialna za wprowadzanie danych do macierzy, werfikacje czy
 * użytkownik nie wprowadził innego symbolu niż liczba, mnożenie dwóch macierzy oraz jej wypisanie.
 * @tparam T szablon przyjmujący wartości zmiennoprzecinkowe vectorów w których przechowywane są macierze
 * @param w ilość wierszy pierwszej macierzy
 * @param k ilość wierszy drugiej macierzy
 * @param w1 ilość wierszy drugiej macierzy
 * @param k1 ilość kolumn drugiej macierzy
 */
template <typename T>
void generalCheck2(int w, int k, int w1, int k1)
{
    vector<vector<T>> vec1( w , vector<T> (k));
    vector<vector<T>> vec2( w1 , vector<T> (k1));
    vector<vector<T>> vecw( 10 , vector<T> (10));
    bool help25;
    do
    {
        help25=false;
        cout <<"Podaj swoją pierwszą macierz: " << endl;

        for(int i = 0; i < w; i++)
        {
            for(int j = 0; j < k; j++)
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

        for(int i = 0; i < w1; i++)
        {
            for(int j = 0; j < k1; j++)
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
    cout << endl << "Macierz wynikowa po wymnożeniu dwóch macierzy: " << endl;

    for(int i = 0; i < w; ++i)
        for(int j = 0; j < k1; ++j)
            for(int l = 0; l < k; ++l)
            {
                vecw[i][j] += vec1[i][l] * vec2[l][j];
            }
    for(int i = 0; i < w; ++i)
        for(int j = 0; j < k1; ++j)
        {
            cout << vecw[i][j] << " ";
            if (j == k1-1)
                cout << endl;
        }
}

/**
 * Funkcja główna dodawania odpowiedzialna za wczytanie danych o macierzy użytkownika oraz walidację wpisanych danych.
 */
void General:: add ()
{
    {
        bool help;
        bool help1;
        do
        {
            help=false;
            cout << "Podaj ilość wierszy pierwszej macierzy: " << endl;
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
        generalCheck<float>(w, k);
    }
}

/**
 * Funkcja główna odejmowania odpowiedzialna za wczytanie danych o macierzy użytkownika oraz walidację wpisanych danych.
 */
void General:: subtract ()
{
    {
        bool help;
        bool help1;
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
        generalCheck1<float>(w, k);
    }
}

/**
 * Funkcja główna mnożenia odpowiedzialna za wczytanie danych o macierzy użytkownika oraz walidację wpisanych danych.
 * Funkcja sprawdza czy dane macierze mogą zostać pomnożone. Jeśli nie progam się kończy.
 */
void General:: multiply()
{
    {
        bool help;
        bool help1;
        do
        {
            help=false;
            cout << "Podaj ilość wierszy pierwszej macierzy: " << endl;
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
            help=false;
            cout << "Podaj ilość kolumn pierwszej macierzy: " << endl;
            cin >> k;
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
            help=false;
            cout << "Podaj ilość wierszy drugiej macierzy: " << endl;
            cin >> w1;
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
            cout << "Podaj ilość kolumn drugiej macierzy: " << endl;
            cin >> k1;
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
        if (k!=w1)
        {
            cout << "Macierzy o podanych rozmiarach nie da się wymnożyć!!!" << endl;
            exit (0);
        }
        generalCheck2<float>(w, k, w1, k1);
    }
}