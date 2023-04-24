#include <iostream>
#include "../Structures/List.cpp"
#include <ctime>
using namespace std;


class ListHandler {

public:
    static void printMenu(){
        cout <<endl<<"Lista dwukierunkowa"<<endl;
        cout << "1. Wyswietl liste" << endl;
        cout << "2. Dodaj element" << endl;
        cout << "3. Usun element" << endl;
        cout << "4. Pobierz element" << endl;
        cout << "5. Wczytaj liste z pliku" << endl;
        cout << "6. Wypelnij liste losowymi wartosciami z zakresu 1-100" << endl;
        cout << "7. Usun liste" << endl;
        cout << "0. Wyjdz" << endl;
    }

    static void handle() {
        bool app = true;
        int choice;

        auto list = List();


        while(app){
            printMenu();
            cin >> choice;
            clock_t start, elapsed;
            switch (choice) {
                case 1: {
                    cout << "1. od przodu" <<endl;
                    cout << "2. od konca" <<endl;
                    int type;
                    cin >> type;
                    switch(type){
                        case 1:{
                            list.printFront();
                            break;
                        }
                        case 2:{
                            list.printBack();
                            break;
                        }
                        default:{
                            cout <<"Podano bledny rodzaj"<<endl;
                            break;
                        }
                    }
                    break;
                }
                case 2: {
                    cout << "1. na przod" <<endl;
                    cout << "2. na koniec" <<endl;
                    cout << "3. przed wybranym elementem" <<endl;
                    cout << "4. za wybranym elementem" <<endl;
                    cout << "5. Na wybrany index" <<endl;
                    int type;
                    cin >> type;
                    switch(type){
                        case 1:{
                            int value;
                            cout << endl << "Podaj wartosc" <<endl;
                            cin >> value;
                            list.pushFront(value);
                            break;
                        }
                        case 2:{
                            int value;
                            cout << endl << "Podaj wartosc" <<endl;
                            cin >> value;
                            list.pushBack(value);
                            break;
                        }
                        case 3: {
                            int elemvalue, value;
                            cout << endl << "Podaj wartosc elementu przed ktorym chcesz umiescic" << endl;
                            cin >> elemvalue;
                            Elem *elem = list.findElementByValue(elemvalue);
                            if (elem != nullptr) {
                            cout << endl << "Podaj wartosc ktora chcesz dodac" << endl;
                            cin >> value;
                            list.insertBefore(elem, value);
                            } else {
                                cout << endl << "Nie ma takiego elementu" << endl;
                            }
                            break;
                        }
                        case 4:{
                            int elemvalue, value;
                            cout << endl << "Podaj wartosc elementu za ktorym chcesz umiescic" <<endl;
                            cin >> elemvalue;
                            Elem* elem = list.findElementByValue(elemvalue);
                            if (elem != nullptr) {
                                cout << endl << "Podaj wartosc ktora chcesz dodac" << endl;
                                cin >> value;
                                list.insertAfter(elem, value);
                            } else {
                                cout << endl << "Nie ma takiego elementu" << endl ;
                            }
                            break;
                        }case 5:{
                            int index, value;
                            cout << endl << "Podaj index" <<endl;
                            cin >> index;
                            cout << endl << "Podaj wartosc ktora chcesz dodac" << endl;
                            cin >> value;
                            list.insertOnIndex(index, value);
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
                    cout << "3. z wybrana wartoscia" <<endl;
                    int type;
                    cin >> type;
                    switch(type){
                        case 1:{
                            list.popFront();
                            break;
                        }
                        case 2:{
                            list.popBack();
                            break;
                        }
                        case 3:{
                            int elemvalue, value;
                            cout << endl << "Podaj wartosc elementu ktory chcesz usunac" <<endl;
                            cin >> elemvalue;
                            Elem* elem = list.findElementByValue(elemvalue);
                            if (elem != nullptr) {
                                list.deleteItem(elemvalue);
                            } else {
                                cout << endl << "Nie ma takiego elementu" << endl ;
                            }
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
                    cout << "1. z przodu" <<endl;
                    cout << "2. z konca" <<endl;
                    int type;
                    cin >> type;
                    switch(type){
                        case 1:{
                            //TODO: POPFRONT METHOD
                            break;
                        }
                        case 2:{
                            //TODO: POPBACK METHOD
                            break;
                        }
                        default:{
                            cout <<"Podano bledny rodzaj"<<endl;
                            break;
                        }
                    }
                    break;
                }
                case 5:{
                    string file;
                    cout << endl << "Podaj sciezke do pliku" <<endl;
                    cin >> file;
                    list.loadFromFile(file);
                    break;
                }
                case 6:{
                    int size;
                    cout << endl << "Podaj wielkosc listy: " <<endl;
                    cin >> size;
                    list.fillUpWithRandomValues(size);
                    break;
                }
                case 7:{
                    int size;
                    list.clear();
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
