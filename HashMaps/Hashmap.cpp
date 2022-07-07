#include <iostream>
#include "Hashtable.h"
using namespace std;

int main()
{
    Hashmap<int> map;
    map.insert("abc1", 1);
    map.insert("abc2", 2);
    map.insert("abc3", 3);
    map.insert("abc4", 4);
    map.insert("abc5", 5);
    map.insert("abc6", 6);
    map.insert("abc7", 7);
    map.insert("abc8", 8);
    map.insert("abc9", 9);
    map.insert("abc10", 10);
    map.insert("abc11", 11);

    cout << map.size() << endl;

    cout << map.getValue("abc4") << endl;
    cout << map.getValue("abc6") << endl;
    cout << map.getValue("abc8") << endl;
    cout << map.getValue("abc2") << endl;

    cout << "Deleted Value: " << map.remove("abc11") << endl;
    cout << "Deleted Value: " << map.remove("abc10") << endl;

    cout << map.size() << endl;
}