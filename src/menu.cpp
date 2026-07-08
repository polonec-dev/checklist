#include <iostream>
#include <stdexcept>

#include "menu.hpp"

    static void show_menu()
    {
        std::cout << "Enter a number to continue\n1. New Item\n2. Edit Item\n3. Save and Exit\n> " << std::flush;
    }
    
    static menu_opt get_input()
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
        switch (input) {
            case 1: return M_NEW;
            case 2: return M_EDIT;
            case 3: return M_SHOW;
            case 4: return M_END;
        }
        return M_INVALID;
    }
    int run_menu()
    {
        show_menu();
        return get_input();
    }