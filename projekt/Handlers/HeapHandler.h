//
// Created by ja on 2023-03-15.
//
#include <iostream>
#include "../Structures/Heap.h"
using namespace std;


class HeapHandler {

public:
    static void printMenu(){
        cout <<endl<<"KOPIEC"<<endl;
        cout << "1. Wyswietl kopiec" << endl;
        cout << "2. Dodaj element (push)" << endl;
        cout << "3. Usun elelement (pop)" << endl;
        cout << "4. Znajdz index elementu" <<endl;
        cout << "0. Wyjdz" << endl;
    }

    static void handle() {
        bool app = true;
        int choice;

        auto heap = Heap();


        while(app){
            printMenu();
            cin >> choice;
            switch (choice) {
                case 1: {
                    cout << endl <<"Kopiec:" << endl;
                    heap.print();
                    break;
                }
                case 2: {
                    int value;
                    cout << endl << "Podaj wartosc" <<endl;
                    cin >> value;
                    heap.push(value);
                    break;
                }
                case 3: {
                    heap.pop();
                    break;
                }
                case 4: {
                    int value;
                    cout << endl << "Podaj wartosc" <<endl;
                    cin >> value;
                    int index = heap.search(value);
                    cout << "Element: " << value << " znajduje sie pod indexem: " << index <<endl;
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


};
