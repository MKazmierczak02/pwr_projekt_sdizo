
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Zmienne globalne

string cr, cl, cp;      // łańcuchy do znaków ramek
int T [ 15 ], n = 0;

// Procedura wypisuje drzewo
//--------------------------
void printBT ( string sp, string sn, int v )
{
    string s;

    if( v < n )
    {
        s = sp;
        if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
        printBT ( s + cp, cr, 2 * v + 2 );

        s = s.substr ( 0, sp.length( ) - 2 );

        cout << s << sn << T [ v ] << endl;

        s = sp;
        if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
        printBT ( s + cp, cl, 2 * v + 1 );
    }
}

// procedura wstawia v do kopca
//-----------------------------
void heap_push ( int v )
{
    int i, j;

    i = n++;
    j = ( i - 1 ) / 2;

    while( i > 0 && T [ j ] < v )
    {
        T [ i ] = T [ j ];
        i = j;
        j = ( i - 1 ) / 2;
    }

    T [ i ] = v;
}

// **********************
// *** PROGRAM GŁÓWNY ***
// **********************

int main( )
{
    int i, v;

    srand ( time ( NULL ) );

    cr = cl = cp = "  ";
    cr [ 0 ] = 218; cr [ 1 ] = 196;
    cl [ 0 ] = 192; cl [ 1 ] = 196;
    cp [ 0 ] = 179;

    for( i = 0; i < 15; i++ )
    {
        v = rand( ) % 100;
        heap_push ( v );
    }

    cout << endl << endl;

    printBT ( "", "", 0 );
} 