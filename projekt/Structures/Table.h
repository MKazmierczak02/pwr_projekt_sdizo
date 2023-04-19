//
// Created by ja on 2023-03-13.
//
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;

class Table {

     int size;
     int *table;
public:
    Table() {
        this->size=0;           // dane inicjalizacyjne, size=0, tablica wskazuje na null
        this->table= nullptr;
     }

     /*
      * Wstawienie wartosci na tyl tablicy
      */
     void insertBack(int value){
         int * T = new int [ size +1 ];
         for( int i = 0; i < size; i++ ) {                      //przepisujemy nasza tabele do tabeli pomocniczej
             T [ i ] = table [ i ];
         }
         delete [ ] table;                                      // zwalniamy miejsce
         table = T;                                             // przypisujemy table
         *(table + size) = value;                               // przypisujemy wartosc na koniec tabeli
         size ++;

     }

    /*
     * Wstawienie wartosci na przod tablicy
     */
    void insertFront(int value){
        int * T = new int [ ++size ];
        for( int i = 1; i < size ; i++ ) {
            T [ i ] = table [ i-1 ];
        }
        delete [ ] table;
        table = T;
        table[0] = value;
    }

    /*
      * Wstawienie wartosci na podany index tablicy
      */
    void insertOnIndex(int index, int value){
        if(index<0 || index>size){
            cerr << "Index out of bounds" << endl;
            exit(EXIT_FAILURE);
        }
        int * T = new int [ ++size ];
        int j = 0;
        for( int i = 0; i < size; i++ ) {
            if(i==index){
                T [ i ] = value;
            } else {
                T [ i ] = table [ j ];
                j++;
            }
        }
        delete [ ] table;
        table = T;
    }

    /*
    * Usuniecie ostatniego elementu tablicy
    */
    bool del(int index){
        if (index >= 0 && index < this->size) {
            int *T = new int[size - 1];
            int j = 0;
            for (int i = 0; i < size; i++) {
                if (i == index) {
                    j++;
                }
                T[i] = table[j];
                j++;
            }
            delete[] table;
            size--;
            table = T;
            return true;
        } else{
            cerr << "Index out of bounds" << endl;
            exit(EXIT_FAILURE);
        }
     }

    /*
    * Usuniecie pierwszego elementu tablicy
    */
     bool delFront(){
        return del(0);
     }

    /*
    * Usuniecie ostatniego elementu tablicy
    */
    bool delBack(){
        return del(size-1);
    }

     /*
     * Pobranie wartosci elementu o podanym indexie
     */
     int get(int index){
         if(index < size && index >= 0){
             return (*(table + index));
         } else {
             return -1;
         }
    }

    void print(){
         cout<<endl;
        for (int i = 0; i < this->getSize(); i++) {
            cout << "T[" <<i<<  "] = " << this->get(i) << endl;
        }
    }

    int getSize(){
        return this -> size;
    }

    /*
     * Funkcja zwraca index pierwszego wystapienia podanej wartosci
     */
    int indexOf(int value) {
        for (int i = 0; i < this->getSize(); i++) {
            if (this->get(i)==value){
                return i;
            }
        }
        return -1;
    }
     /*
     * Funkcja pomocnicza do wprowadzenia wartosci z pliku
     */
    void loadFromFile(string fileName) {
        fstream file(fileName);
        int size;
        int val;
        if(file.is_open())
        {
            file >> size;
            if(file.fail())
                cout << "File error - READ SIZE" << endl;
            else
                for(int i = 0; i < size; i++)
                {
                    file >> val;
                    if(file.fail())
                    {
                        cout << "File error - READ DATA" << endl;
                        break;
                    }
                    else
                        insertBack(val);
                }
            file.close();
        }
        else
            cout << "File error - OPEN" << endl;

    }
     /*
     * Funkcja pomocnicza do tworzenia wartosci o podanej wielkosci
     */
    void fillUpWithRandomValues(int size) {
        for(int i =0; i<size; i++){
            insertBack(1+rand()%1000000000);
        }
    }

    void clear(){
        delete [ ] table;
        table = nullptr;
        size=0;
    }
};

