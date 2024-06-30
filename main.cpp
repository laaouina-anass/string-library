#include <iostream>
#include "String.h"

int main()
{
    String text = "hello world";
    //////// EXPERIMENTS ///////////
    size_t pos = text.find("wrld");
    std::cout << pos;
    ////////////////////////////////
    std::cout << "\nPress Enter to Close the Window ...";
    std::cin.get();
}