#include <cstddef>
#include <ostream>
#include <stdexcept>
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
void CTable::new_item(bool plugged)
{
    items_.push_back({plugged});
}
void CTable::edit_item(size_t id, bool plugged)
{
    if (id > items_.size()) {
        throw std::out_of_range("Item index out of range");
    }
    items_.at(id) = {plugged};
}
int CTable::count() const {return items_.size();}
bool CTable::is_plugged(size_t id) const {return items_.at(id).plugged();}