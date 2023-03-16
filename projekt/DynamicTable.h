//
// Created by ja on 2023-03-13.
//

using namespace std;

class DynamicTable {

     int size;
     int *table;

public:
    DynamicTable() {
        this->size=0;
        this->table= nullptr;
     }
     void add(int value){
         int * T = new int [ size +1 ];
         for( int i = 0; i < size; i++ ) {
             T [ i ] = table [ i ];
         }
         delete [ ] table;
         table = T;
         *(table + size) = value;
         size ++;
     }

    void del(int index){
        if (index < 1 || index > this->size) {
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

     void del_front(){
        del(0);
     }

    void del_last(){
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
            cout << this->get(i) << ", ";
        }
    }

    int getSize(){
        return this -> size;
    }

};

