#include <iostream>
#include <stdexcept>

#include "menu.hpp"

static void show_menu()
{
    std::cout << "Enter a number to continue\n1. New Item\n2. Edit Item\n3. Show table\n4. Save and Exit\n> " << std::flush;
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
    if (input > 4) 
    {
        throw std::invalid_argument("Input must be 4 or less");
    }
    switch (input) {
        case 1: return M_NEW;
        case 2: return M_EDIT;
        case 3: return M_SHOW;
        case 4: return M_END;
    }
    return M_INVALID;
}
static menu_opt run_menu()
{
    show_menu();
    return get_input();
}
menu_opt ask_until_valid()
{
    menu_opt menu;
    while (1) {
        try {
        menu = run_menu();
        break;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
    }
    return menu;
}