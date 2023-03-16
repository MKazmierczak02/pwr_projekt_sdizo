//
// Created by ja on 2023-03-15.
//
#include <iostream>
#include "../Structures/List.h"
using namespace std;


class ListHandler {

public:
    static void printMenu(){
        cout <<endl<<"Lista dwukierunkowa"<<endl;
        cout << "1. Wyswietl liste" << endl;
        cout << "2. Dodaj element na poczatek" << endl;
        cout << "3. Dodaj element na koniec" << endl;
        cout << "4. Usun element z poczatku" << endl;
        cout << "5. Usun element z konca" << endl;
        cout << "0. Wyjdz" << endl;
    }

    static void handle() {
        bool app = true;
        int choice;

        auto list = List();


        while(app){
            printMenu();
            cin >> choice;
            switch (choice) {
                case 1: {
                    cout << endl <<"Lista:" << endl;
                    list.print();
                    break;
                }
                case 2: {
                    int value;
                    cout << endl << "Podaj wartosc" <<endl;
                    cin >> value;
                    list.insertFront(value);
                    break;
                }
                case 3: {
                    int value;
                    cout << endl << "Podaj wartosc" <<endl;
                    cin >> value;
                    list.insertBack(value);
                    break;
                }
                case 4: {
                    list.delFront();
                    break;
                }
                case 5: {
                    list.delBack();
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
