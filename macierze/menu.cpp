#include "menu.h"
#include "general.h"
#include "diax.h"
#include "matrix1.h"
#include "matrix2.h"
#include "matrix3.h"

using namespace std;

/**
 * Funkcja showMenu odpowiedzialna za wypisanie głównego menu oraz
 * walidacji danych wprowadzonych przez uźytkownika.
 */
void Menu::showMenu()
{
    bool help;
    do
    {
        help=false;
        cout << endl << "1. Wykonywanie działań na jednej macierzy." << endl;
        cout << "2. Wykonywanie działań na dwóch macierzach." << endl;
        cout << "3. Wykonywanie działań na dwóch macierzach diagonalnych." << endl;
        cout << "4. Zakończ program." << endl << endl;
        cout << "Wprowadź liczbę odpowiadajacą twojemu wyborowi: " << endl;
        cin >> answer;
        if (cin.peek() != '\n')
        {
            cout << endl;
            goto error;
        }
        cout << endl;
        switch (answer)
        {
            case 1:
            {
                cout << "1. Obliczenie wyznacznika macierzy." << endl;
                cout << "2. Obliczenie macierzy odwrotnej." << endl;
                cout << "3. Obliczenie macierzy transponowanej." << endl << endl;
                cout << "Wprowadź liczbę odpowiadajacą twojemu wyborowi: " << endl;
                showMenu1();
                break;
            }
            case 2:
            {
                cout << "1. Dodawanie do siebie dwóch macierzy." << endl;
                cout << "2. Odejmowanie od siebie dwóch macierzy." << endl;
                cout << "3. Mnożenie dwóch macierzy." << endl;
                cout << endl << "Wprowadź liczbę odpowiadajacą twojemu wyborowi: " << endl;
                showMenu2();
                break;
            }
            case 3:
            {
                cout << "1. Dodawanie do siebie dwóch macierzy diagonalnych." << endl;
                cout << "2. Odejmowanie od siebie dwóch macierzy diagonalnych." << endl;
                cout << "3. Mnożenie dwóch macierzy diagonalnych." << endl;
                cout << endl << "Wprowadź liczbę odpowiadajacą twojemu wyborowi: " << endl;
                showMenu3();
                break;
            }
            case 4:
            {
                cout << "Koniec programu. " << endl;
                exit(0);
            }
            error:
            default:
                system ("cls");
                cout << endl << "Wybór niepoprawny!!!" << endl;
                cout << "Wpisz ponownie swój wybór." << endl;
                help=true;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
    while (help);
}

/**
 * Funkcja showMenu1 odpowiedzialna za wypisanie podmenu (operacje na jednej macierzy) oraz
 * walidacji danych wprowadzonych przez uźytkownika.
 */
void Menu::showMenu1()
{
    bool help;
    do
    {
        help=false;
        cin >> answer;
        if (cin.peek() != '\n')
        {
            cout << endl;
            goto error1;
        }
        cout << endl;
        switch (answer)
        {
            case 1:
            {
                system ("cls");
                cout << endl << "Podaj stopień swojej macierzy aby obliczyć wyznacznik: " << endl;
                matrixDet();
                break;
            }
            case 2:
            {
                system ("cls");
                cout << endl <<"Podaj stopień macierzy aby obliczyć macierz odwrotną." << endl;
                matrixInverse();
                break;
            }
            case 3:
            {
                system ("cls");
                cout << endl << "Podaj wymiary macierzy aby ją stransponować." << endl;
                matrixTroanspose();
                break;
            }
            error1:
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
}

/**
 * Funkcja showMenu2 odpowiedzialna za wypisanie podmenu (operacje na dwóch macierzach) oraz
 * walidacji danych wprowadzonych przez uźytkownika.
 */
void Menu::showMenu2()
{
    bool help;
    do
    {
        help=false;
        cin >> answer;
        if (cin.peek() != '\n')
        {
            cout << endl;
            goto error2;
        }
        cout << endl;
        switch (answer)
    {
        case 1:
        {
            cout << "Podaj wielkość wprowadzanych macierzy. " << endl;
            /*funkcja wpisywania macierzy*/
            General x;
            General*wsk;
            wsk=&x;
            wsk->add();
            break;
        }
        case 2:
        {
            cout << "Podaj wielkość wprowadzanych macierzy. " << endl;
            /*funkcja wpisywania macierzy*/
            General d;
            General*wsk;
            wsk=&d;
            wsk->subtract();
            break;
        }
        case 3:
        {
            cout << "Podaj wielkość wprowadzanych macierzy. " << endl;
            /*funkcja wpisywania macierzy*/
            General s;
            General*wsk;
            wsk=&s;
            wsk->multiply();
            break;
        }
        error2:
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
}

/**
 * Funkcja showMenu3 odpowiedzialna za wypisanie podmenu (operacje na dwóch macierzach diagonalnych) oraz
 * walidacji danych wprowadzonych przez uźytkownika.
 */
void Menu::showMenu3()
{
    bool help;
    do
    {
        help=false;
        cin >> answer;
        if (cin.peek() != '\n')
        {
            cout << endl;
            goto error3;
        }
        cout << endl;
        switch (answer)
        {
            case 1:
            {
                Diax a;
                Diax*wsk;
                wsk=&a;
                wsk->add();
                break;
            }
            case 2:
            {
                Diax b;
                Diax*wsk;
                wsk=&b;
                wsk->subtract();
                break;
            }
            case 3:
            {
                cout << "Podaj stopień wprowadaznej macierzy:  " << endl;
                Diax c;
                Diax*wsk;
                wsk=&c;
                wsk->multiply();
                break;
            }
            error3:
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
}