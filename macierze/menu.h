#ifndef MACIERZE_MENU_H
#define MACIERZE_MENU_H

#include <iostream>
using namespace std;

/**
 * Klasa odpowiedzialna za wypisywanmie interfejsu.
 */
class Menu
        {
        private:
            int answer{};

        public:

            void showMenu();
            void showMenu1();
            void showMenu2();
            void showMenu3();
        };
#endif