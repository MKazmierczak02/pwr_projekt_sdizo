#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

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
    void print ( const string& sp, const string& sn, int v )
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

        if(size--)
        {
            v = tab [size];
            i = 0;
            j = 1;

            while( j < size )
            {
                if( j + 1 < size && tab [ j + 1 ] > tab [ j ] ) j++;
                if( v >= tab [ j ] ) break;
                tab [ i ] = tab [ j ];
                i = j;
                j = 2 * j + 1;
            }
            tab [ i ] = v;
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
        j = ( i - 1 ) / 2;

        while( i > 0 && temp [ j ] < value)
        {
            temp [ i ] = temp [ j ];
            i = j;
            j = ( i - 1 ) / 2;
        }
        temp[i] = value;
        size++;
        tab = temp;
    }
};


