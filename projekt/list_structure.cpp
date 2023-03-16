#include <iostream>

using namespace std;

struct slistEl
{
    slistEl * next;
    char data;
};

void l_printl ( slistEl * p )
{
    while( p!= NULL )
    {
        cout << p -> data<< endl;
        p = p->next;
    }
}

void l_push_front ( slistEl * & head, char v )
{
    slistEl * p = new slistEl;

    p->data = v;    // inicjujemy element
    p->next = head;
    head = p;
}

void l_pop_front ( slistEl * & head )
{
    slistEl * p;
    p = head;     // zapamiętujemy początek
    if( p )
    {
        head = p->next; // nowy początek
        delete p;    // usuń element z pamięci
    }
}

void l_push_back ( slistEl * & head, char v )
{
    slistEl * p, * e;

    e = new slistEl;  // tworzymy nowy element
    e->next = NULL;   // inicjujemy element
    e->data = v;
    p = head;
    if( p )
    {
        while( p->next ) p = p->next;
        p->next = e;
    }
    else head = e;
}

int main2() {
    slistEl * head;
    head = NULL;

    l_push_front(head, 'a' );
    l_push_front(head, 'b' );
    l_push_front(head, 'c' );
    l_push_back(head, 'd' );

    l_pop_front(head);

    l_printl(head);

    return 0;
}
