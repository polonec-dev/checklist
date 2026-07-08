#include <exception>
#include <iostream>
#include <fstream>

#include "menu.hpp"
#include "table.hpp"

// TODO
// Fix infinite loop when inputting number
// Add filename input
// Refactor main

int main()
{
    menu_opt menu;
    std::string filename = "test.csv";
    CTable * table = nullptr;
    try {
        table= new CTable();
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return 1;
    }

    menu = ask_until_valid();
    while (menu != M_END) {
        switch (menu) {
            case M_NEW: table->new_item(table->count()); break;
            case M_EDIT: table->edit_item(); break;
            case M_SHOW: table->write_all(std::cout); break;
            case M_END: break;
            case M_INVALID: break;
        }
        menu = ask_until_valid();
    }
    if (menu != M_END) {
        std::cout << "Something went wrong." << std::endl;
        return 1;
    }
    else {
        std::ofstream out_file(filename);
        table->write_all(out_file);
        std::cout << "File " << filename << " saved." << std::endl;
        return 0;
    }
}