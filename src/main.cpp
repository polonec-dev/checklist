#include <exception>
#include <iostream>
#include <fstream>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <qapplication.h>
#include <qboxlayout.h>
#include <qcheckbox.h>
#include <qcoreapplication.h>
#include <qitemselectionmodel.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qtablewidget.h>

#include "menu.hpp"
#include "table.hpp"

static void refresh_table(QTableWidget * table_w, const CTable & table)
{
    table_w->setRowCount(static_cast<int>(table.count()));

    for (int i = 0; i < table.count(); i++) {
    
        auto * index = new QTableWidgetItem(QString::number(i+1));
        auto * plugged = new QTableWidgetItem(table.is_plugged(i)? "Yes" : "No");

        table_w->setItem(static_cast<int>(i), 0, index);
        table_w->setItem(static_cast<int>(i), 1, plugged);
    }
}



int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    CTable table;
    QWidget window;

    window.setWindowTitle("checklist.exe");
    
    auto * layout = new QVBoxLayout;
    auto * table_w = new QTableWidget;
    table_w->setColumnCount(2);
    table_w->setHorizontalHeaderLabels({"ID", "Plugged"});

    auto * plugged_check = new QCheckBox("Item is plugged in");

    auto * button_layout = new QHBoxLayout;
    auto * add_button = new QPushButton("Add Item");
    auto * save_button = new QPushButton("Save");

    button_layout->addWidget(add_button);
    button_layout->addWidget(save_button);

    layout->addWidget(table_w);
    layout->addWidget(plugged_check);
    layout->addLayout(button_layout);

    window.setLayout(layout);

    QObject::connect(add_button, &QPushButton::clicked, [&]()
    {
        table.new_item(plugged_check->isChecked());
        refresh_table(table_w, table);
    });

    QObject::connect(save_button, &QPushButton::clicked, [&]()
    {
        std::ofstream of("test.csv");

        if (!of) {
            QMessageBox::critical(&window, "Error", "Could not open test.csv for writing.");
            return;
        }

        table.write_all(of);

        QMessageBox::information(&window, "Saved", "File test.csv saved.");
    });


    window.resize(300, 500);
    window.show();

    return app.exec();
}