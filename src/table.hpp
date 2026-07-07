#include <fstream>
#include <vector>

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
        std::ofstream out_file;
        std::vector<CItem> items_;
        void file_init();
        void write_to_file(const CItem & item);
    public:
        CTable(std::string filename);
        void new_item();
};