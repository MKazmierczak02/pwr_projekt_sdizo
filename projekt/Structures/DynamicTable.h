//
// Created by ja on 2023-03-13.
//

#include "../utils/Logger.h"

using namespace std;

class DynamicTable {
     Logger logger = Logger("../logs/dynamicTable.log");

     int size;
     int *table;
public:
    DynamicTable() {
        this->size=0;                           // dane inicjalizacyjne, size=0, tablica wskazuje na null
        this->table= nullptr;
     }

     void add(int value){
         int * T = new int [ size +1 ];
         for( int i = 0; i < size; i++ ) {                      //przepisujemy nasza tabele do tabeli pomocniczej
             T [ i ] = table [ i ];
         }
         delete [ ] table;                                      // zwalniamy miejsce
         table = T;                                             // przypisujemy table
         *(table + size) = value;                               // przypisujemy wartosc na koniec tabeli
         size ++;

         logger.log("Adding an element to table: " + to_string(value) +
         " changing size of table from: " + to_string(size-1) + " to: " + to_string(size) );
     }

    void del(int index){
        if (index >= 0 || index < this->size) {
            int *T = new int[size - 1];
            int mark = 0;
            for (int i = 0; i < size; i++) {
                if (i == index) {
                    mark++;
                }
                T[i] = table[mark];
                mark++;
            }
            delete[] table;
            size--;
            table = T;
        }
     }

     void delFront(){
        del(0);
     }

    void delBack(){
        del(size-1);
    }


     int get(int index){
         if(index < size){
             return (*(table + index));
         } else {
             return -1;
         }
    }

    void print(){
        for (int i = 0; i < this->getSize(); i++) {
            cout << "T[" <<i<<  "] = " << this->get(i) << endl;
        }
    }

    int getSize(){
        return this -> size;
    }

};

