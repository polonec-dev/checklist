#include <iostream>
#include <stdexcept>

enum menu_opt {M_NEW, M_EDIT, M_SHOW, M_END, M_INVALID};

menu_opt ask_until_valid();