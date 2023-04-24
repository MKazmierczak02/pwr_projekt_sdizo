#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class Heap {

private:
    string cr, cl, cp;      // łańcuchy znaków do wyświetlania kopca
    int size = 0;
    int *tab;


public:

    Heap(){
        cr = cl = cp = "  ";
        cr [0] = 218; cr [1] = 196;
        cl [0] = 192; cl [1] = 196;
        cp [0] = 179;
        this -> tab = nullptr;
    }

    //Źródło Stackoverflow
    void print ( const string& sp = "", const string& sn = "", int v = 0)
    {
        string s;
        if( v < size )
        {
            s = sp;
            if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
            print ( s + cp, cr, 2 * v + 2 );

            s = s.substr ( 0, sp.length( ) - 2 );

            cout << s << sn << tab[v]<< endl;

            s = sp;
            if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
            print ( s + cp, cl, 2 * v + 1 );
        }
    }

    void pop()
    {
        int i, j, v;
        if(size>0)
        {
            v = tab [size-1];
            i = 0;
            j = 1;

            while( j < size -1 )
            {
                if( j  < size && tab [ j + 1 ] > tab [ j ] ) j++;
                if( v >= tab [ j ] ) break;
                tab [ i ] = tab [ j ];
                i = j;
                j = 2 * j + 1;          // index lewego syna
            }
            tab [ i ] = v;
            size--;
            int *temp = new int [size];
            for (int i=0; i<size;i++){
                temp[i]=tab[i];
            }
            delete [] tab;
            tab = temp;
        }
    }

    void push ( int value)
    {
        int i, j;

        int *temp = new int [size + 1];
        for (int i=0; i<size;i++){
            temp[i]=tab[i];
        }
        delete [] tab;

        i = size;
        j = ( i - 1 ) / 2;    // index rodzica

        while( i > 0 && temp [ j ] < value)
        {
            temp [ i ] = temp [ j ];
            i = j;
            j = ( i - 1 ) / 2;   // index rodzica
        }
        temp[i] = value;
        size++;
        tab = temp;
    }

    int getSize(){
        return size;
    }

    int peek() const {
        if (size == 0) {
                cerr << "Heap is empty" << endl;
                exit(EXIT_FAILURE);
        }
        return tab[0];
    }

    int search(int value) const {
        for (int i = 0; i < size; i++) {
            if (tab[i] == value) {
                return i;
            }
        }
        return -1;
    }

    void fillUpWithRandomValues(int size) {
        for(int i =0; i<size; i++){
            push(1+rand()%100);
        }
    }

    void loadFromFile(const string& fileName) {
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
                        push(val);
                }
            file.close();
        }
        else
            cout << "File error - OPEN" << endl;
    }

    void clear() {
        delete[] tab;
        tab = nullptr;
        size = 0;
    }

    bool isEmpty() const {
        return size == 0;
    }

};