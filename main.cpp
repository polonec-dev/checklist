#include <exception>

#include "menu.hpp"
#include "table.hpp"

// TODO
// Add handling for case 2
// Add case to list items
// Fix infinite loop when inputting number
// Add filename input
// Refactor main

int main()
{
    int menu = 0;
    std::string filename = "test.csv";
    CTable * table = nullptr;
    try {
        table= new CTable(filename);
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    while (1) {
            try {
            menu = run_menu();
            break;
            } catch (const std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
    }
    while (menu != 3) {
        if (menu == 1) {
            table->new_item();
        }
        while (1) {
            try {
            menu = run_menu();
            break;
            } catch (const std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
        }
    }
    if (menu != 3) {
        std::cout << "Something went wrong." << std::endl;
        return 1;
    }
    else {
        std::cout << "File " << filename << " saved." << std::endl;
        return 0;
    }
}