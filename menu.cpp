#include <iostream>
#include <stdexcept>

#include "menu.hpp"

    static void show_menu()
    {
        std::cout << "Enter a number to continue\n1. New Item\n2. Edit Item\n3. Save and Exit\n> " << std::flush;
    }
    
    static int get_input()
    {
        int input = 0;
        if(!(std::cin >> input))
        {
            throw std::invalid_argument("Input must be a number");
        }
        if (input <= 0)
        {
            throw std::invalid_argument("Input must be a positive number");
        } 
        if (input > 3) 
        {
            throw std::invalid_argument("Input must be 3 or less");
        }
        return input;
    }
    int run_menu()
    {
        show_menu();
        return get_input();
    }