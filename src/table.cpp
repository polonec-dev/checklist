#include <cstddef>
#include <ostream>
#include <vector>
#include <iostream>

#include "table.hpp"

CItem::CItem(bool plugged)
: plugged_(plugged) {}
bool CItem::plugged() const {return plugged_;}


CTable::CTable() {}
void CTable::write_all(std::ostream& os)
{
    os << "Index,Plugged\n";
    for (size_t i = 0; i < items_.size(); i++) {
        os << i+1 << "," << items_.at(i).plugged() << "\n";
    }
    os << std::flush;

}
void CTable::new_item(size_t id)
{
    bool plugged;
    std::cout << "Is the item plugged in?\n> ";
    std::cin >> plugged;
    if (items_.size() == id) {
        items_.push_back({plugged});
    }
    else {
        items_.at(id) = {plugged};
    }
}
void CTable::edit_item()
{
    size_t id = 0;
    std::cout << "Enter item id\n> ";
    std::cin >> id;
    new_item(id-1);
}
int CTable::count() {return items_.size();}