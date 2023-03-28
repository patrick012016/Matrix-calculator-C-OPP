#ifndef MACIERZE_DIAX_H
#define MACIERZE_DIAX_H

#include <vector>
#include <iostream>
#include "menu2.h"

using namespace std;

/**
 * Klasa z metodami odpowiedzialnymi za działania na dwóch macierzach diagonalnych. (dziedziczenie i polimorfizm)
 */
class Diax :public Menu2
        {
        private:
            int nn{};

        public:
            void add() override ;
            void subtract() override;
            void multiply() override;
        };
#endif
