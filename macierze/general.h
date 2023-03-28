#ifndef MACIERZE_GENERAL_H
#define MACIERZE_GENERAL_H

#include <vector>
#include <iostream>
#include "menu2.h"

using namespace std;

/**
 * Klasa z metodami odpowiedzialnymi za działania na dwóch macierzach. (dziedziczenie i polimorfizm)
 */
class General :public Menu2
        {
        private:
            int w{};
            int k{};
            int w1{};
            int k1{};

        public:
            void add() override;
            void subtract() override;
            void multiply() override;
        };
#endif