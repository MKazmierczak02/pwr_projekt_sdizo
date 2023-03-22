//
// Created by ja on 2023-03-15.
//
#include <iostream>
#include "../Structures/List.h"
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
        cout << "6. Wypelnmij liste losowymi wartosciami z zakresu 1-100" << endl;
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
                        case 3:{
                            //TODO: wstawianie na wybrany
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
                    cout << "3. z wybranego index" <<endl;
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
                            //TODO: usuwanie z dowolnego miejsca
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
