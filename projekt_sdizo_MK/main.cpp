//
// Created by ja on 2023-03-13.
//

#include <iostream>
#include "Handlers/TableHandler.h"
#include "Handlers/HeapHandler.h"
#include "Handlers/ListHandler.h"
#include "Handlers/BSTHandler.h"

using namespace std;

void printMenu() {
    cout <<endl<<endl;
    cout << "1. Tablice dynamiczne" << endl;
    cout << "2. Lista dwukierunkowa" << endl;
    cout << "3. Kopiec binarny" << endl;
    cout << "4. Drzewo przeszukiwan binarnych (BST)" << endl;
    cout << "0. Wyjdz" << endl;
}


int main() {
    cout << "Michal Kazmierczak"<<endl;
    cout << "Grupa: Wtorek 15:15, TN"<<endl;
    cout << "Projekt Struktury danych i zlozonosc obliczeniowa";
    bool app = true;
    int choice;

    while (app) {
        printMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                TableHandler::handle();
                break;
            }
            case 2: {
                ListHandler::handle();
                break;
            }
            case 3: {
                HeapHandler::handle();
                break;
            }
            case 4: {
                BSTHandler::handle();
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




