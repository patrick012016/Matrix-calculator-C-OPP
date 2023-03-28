#ifndef MACIERZE_MENU2_H
#define MACIERZE_MENU2_H

#include <iostream>
using namespace std;

/**
 * Klasa abstrakcyjna odpowiada za bazę dla późniejszych klas pochodnych.
 */
class Menu2
        {
        public:
            virtual void add()=0;
            virtual void subtract()=0;
            virtual void multiply()=0;
        };
#endif
