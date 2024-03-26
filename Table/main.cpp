#include <iostream>
#include "table.h"
using namespace std;


int main() {
    Table<int, string> table;
    table.add(1, "One");
    table.add(2, "Two");
    table.add(3, "Three");

    cout << "Table:" << endl;
    table.print();

    string value;
    if (table.find(2, value)) {
        cout << "Finded on key 2: " << value << endl;
    }
    else {
        cout << "Value on 2 is not finded." << endl;
    }

    table.remove(2);
    cout << "Table after removing 2:" << endl;
    table.print();

    return 0;
}
