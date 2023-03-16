//
// Created by ja on 2023-03-15.
//
#include <iostream>
using namespace std;


class TableHandler {

public:
    static void printMenu(){
        cout <<endl<<endl;
        cout << "1. Wyswietl tablice" << endl;
        cout << "2. Dodaj element na koniec" << endl;
        cout << "3. Usun elelement po indexie" << endl;
        cout << "4. Usun element z przodu" << endl;
        cout << "5. Usun element z tylu" << endl;
        cout << "0. Wyjdz" << endl;
    }

    static void handle() {
        bool app = true;
        int choice;

        auto *table = new DynamicTable;


        while(app){
            printMenu();
            cin >> choice;
            switch (choice) {
                case 1: {
                    cout << endl <<"Tablica:" << endl;
                    table->print();
                    break;
                }
                case 2: {
                    int value;
                    cout << endl << "Podaj wartosc" <<endl;
                    cin >> value;
                    table->add(value);
                    break;
                }
                case 3: {
                    int index;
                    cout << endl << "Podaj index" <<endl;
                    cin >> index;
                    table->del(index);
                    break;
                }
                case 4: {
                    table->del_front();
                    break;
                }
                case 5: {
                    table->del_last();
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
