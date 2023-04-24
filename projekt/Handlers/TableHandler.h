#include <iostream>
#include "../Structures/Table.cpp"
using namespace std;


class TableHandler {

public:
    static void printMenu(){
        cout <<endl<<"Tablica dynamiczna"<<endl;
        cout << "1. Wyswietl tablice" << endl;
        cout << "2. Dodaj element" << endl;
        cout << "3. Usun elelement" << endl;
        cout << "4. Wyszukaj element po wartości" << endl;
        cout << "5. Wczytaj tablice z pliku" << endl;
        cout << "6. Wypelnij tablice losowymi wartosciami z zakresu 1-100" << endl;
        cout << "7. Usun tablice" << endl;
        cout << "0. Wyjdz" << endl;
    }

    static void handle() {
        bool app = true;
        int choice;

        auto table = Table();


        while(app){
            printMenu();
            cin >> choice;
            switch (choice) {
                case 1: {
                    cout << endl <<"Tablica:" << endl;
                    table.print();
                    break;
                }
                case 2: {
                    cout << "1. na przod" <<endl;
                    cout << "2. na koniec" <<endl;
                    cout << "3. na wybrany index" <<endl;
                    int type;
                    cin >> type;
                    switch(type){
                        case 1:{
                            int value;
                            cout << endl << "Podaj wartosc" <<endl;
                            cin >> value;
                            table.insertFront(value);
                            break;
                        }
                        case 2:{
                            int value;
                            cout << endl << "Podaj wartosc" <<endl;
                            cin >> value;
                            table.insertBack(value);
                            break;
                        }
                        case 3:{
                            int index, value;
                            cout << endl << "Podaj index" <<endl;
                            cin >> index;
                            cout << endl << "Podaj wartosc" <<endl;
                            cin >> value;
                            table.insertOnIndex(index, value);
                            break;
                        }
                        default:{
                            cout <<"Podano bledny rodzaj"<<endl;
                            break;
                        }
                    }
                    break;
                }
                case 3: {
                    cout << "1. z przodu" <<endl;
                    cout << "2. z konca" <<endl;
                    cout << "3. z wybranego indexu" <<endl;
                    int type;
                    cin >> type;
                    switch(type){
                        case 1:{
                            table.delFront();
                            break;
                        }
                        case 2:{
                            table.delBack();
                            break;
                        }
                        case 3:{
                            int index;
                            cout << endl << "Podaj index" <<endl;
                            cin >> index;
                            table.del(index);
                            break;
                        }
                        default:{
                            cout <<"Podano bledny rodzaj"<<endl;
                            break;
                        }
                    }
                    break;
                }
                case 4: {
                    int value;
                    cout << endl << "Podaj wartosc" <<endl;
                    cin >> value;
                    int index = table.indexOf(value);
                    cout << "Wartosc "<< value << " znaduje sie pod indexem: " << index<<endl;
                    break;
                }
                case 5:{
                    string file;
                    cout << endl << "Podaj sciezke do pliku" <<endl;
                    cin >> file;
                    table.loadFromFile(file);
                    break;
                }
                case 6:{
                    int size;
                    cout << endl << "Podaj wielkosc listy: " <<endl;
                    cin >> size;
                    table.fillUpWithRandomValues(size);
                    break;
                }
                case 7:{
                    table.clear();
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
