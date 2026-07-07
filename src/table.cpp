#include <fstream>
#include <vector>
#include <iostream>

#include "table.hpp"

CItem::CItem(bool plugged)
: plugged_(plugged) {}
bool CItem::plugged() const {return plugged_;}


CTable::CTable(std::string filename)
: out_file(filename)
{
    if (!out_file)
    {
        throw std::runtime_error("Could not open file: " + filename);
    }
    file_init();
}
void CTable::file_init()
{
    out_file << "Index,Plugged\n";
}
void CTable::write_to_file(const CItem & item)
{
    out_file << items_.size() << "," << item.plugged() << std::endl;
}
void CTable::new_item()
{
    bool plugged;
    std::cout << "Is the item plugged in?\n> ";
    std::cin >> plugged;
    items_.push_back({plugged});
    write_to_file(items_.back());
}