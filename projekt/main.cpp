//
// Created by ja on 2023-03-13.
//

#include <iostream>
#include "DynamicTable.h"
#include "TableHandler.h"
using namespace std;

void printMenu() {
    cout <<endl<<endl;
    cout << "1. Tablice dynamiczne" << endl;
    cout << "2. Lista dwukierunkowa" << endl;
    cout << "3. Kopiec binarny" << endl;
    cout << "4. Drzewo przeszukiwan binarnych (BST)" << endl;
    cout << "5. Drzewo czerowno-czarne " << endl;
    cout << "0. Wyjdz" << endl;
}


int main() {
    cout << "Projekt Struktury danych i zlozonosc obliczeniowa";
    bool app = true;
    int choice;

    while (app) {
        printMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                TableHandler handler = *new TableHandler;
                handler.handle();
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
            case 0: {
                app = false;
                break;
            }
            default: {
                cout << "Wpisano zly numer" << endl;
                break;
            }
        }
    }
}




