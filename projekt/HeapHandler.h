//
// Created by ja on 2023-03-15.
//
#include <iostream>
#include "Heap.h"
using namespace std;


class HeapHandler {

public:
    static void printMenu(){
        cout <<endl<<"KOPIEC"<<endl;
        cout << "1. Wyswietl kopiec" << endl;
        cout << "2. Dodaj element (push)" << endl;
        cout << "3. Usun elelement (pop)" << endl;
        cout << "0. Wyjdz" << endl;
    }

    static void handle() {
        bool app = true;
        int choice;

        auto *heap = new Heap;


        while(app){
            printMenu();
            cin >> choice;
            switch (choice) {
                case 1: {
                    cout << endl <<"Kopiec:" << endl;
                    heap->print("","",0);
                    break;
                }
                case 2: {
                    int value;
                    cout << endl << "Podaj wartosc" <<endl;
                    cin >> value;
                    heap->push(value);
                    break;
                }
                case 3: {
                    heap->pop();
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
