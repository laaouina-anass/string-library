#include <iostream>
#include "String.h"

int main()
{
    String text = "hello world";
    //////// EXPERIMENTS ///////////

    std::cout << text.slice(0 , 4) + ".";


    ////////////////////////////////
    std::cout << "\nPress Enter to Close the Window ...";
    std::cin.get();
}