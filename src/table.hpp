#include <cstddef>
#include <ostream>
#include <vector>
#include <iostream>

class CItem
{
    private:
        bool plugged_;
    public:
        CItem(bool plugged);
        bool plugged() const;
};

class CTable
{
    private:
        std::vector<CItem> items_;
        void file_init();
    public:
        void write_all(std::ostream& os);
        CTable();
        void new_item(bool plugged);
        void edit_item(size_t id, bool plugged);
        int count() const;
        bool is_plugged(size_t id) const;
};