#include <windows.h>
#include "start.h"
#include "menu.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    start();
    Menu s;
    s.showMenu();

    return 0;
}