#include <iostream>
#include <fstream>
#include <random>

using namespace std;

class Elem {
public:
    int data;   // - przechowuje wartość elementu
    Elem* next; // - wskazuje na następny element listy
    Elem* prev; // - wskazuje na poprzedni element listy

    explicit Elem(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class List {

private:
    Elem *head; //  - wskazuje na pierwszy element listy
    Elem *tail; // - wskazuje na ostatni element listy
    int size; // - przechowuje ilość elementów w liście

public:
    List() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void printFront() {
        Elem* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl<< "Wszystkich elementow jest: " << size <<endl;
    }

    void printBack() {
        Elem* temp = tail;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl<< "Wszystkich elementow jest: " << size <<endl;
    }

    void pushFront(int value) {
        Elem* newElem = new Elem(value);
        newElem->prev = NULL;
        newElem->next = head;
        head  = newElem;
        if( newElem->next ) newElem->next->prev = newElem;
        else tail = newElem;
        size++;
    }

    void insertOnIndex(int index, int value){
        if (index==0){
            pushFront(value);
        } else if (index==size+1) {
            pushBack(value);
        } else{
            Elem* prev = get(index-1);
            Elem* newElem = new Elem(value);
            newElem->next = prev->next;
            newElem->prev = prev;
            if (prev->next != nullptr){
                prev->next->prev=newElem;
            }
            prev->next = newElem;
            size++;
        }
    }

    void pushBack(int value) {
        Elem* newElem = new Elem(value);

        newElem->next = NULL;
        newElem->prev = tail;
        tail  = newElem;

        if( newElem->prev ) newElem->prev->next = newElem;
        else head = newElem;
        size++;
    }

    int popFront() {
        if (head == nullptr) {
            return -1;
        }
        else if (head == tail) {
            int val = head-> data;
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return val;
        }
        else {
            int val = head->data;
            Elem* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            size--;
            return val;
        }

    }

    int popBack() {
        if (head == nullptr) {
            return -1;
        }
        else if (head == tail) {
            int val = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return val;
        }
        else {
            Elem* temp = tail;
            int val = tail -> data;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            size--;
            return val;
        }

    }

    Elem* findElementByValue(int value){
        Elem* temp = head;

        while (temp != nullptr) {
            if(temp->data==value){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void insertBefore(Elem * elem, int value){
        Elem * newElem;
        if(elem == head) pushFront(value);
        else
        {
            newElem = new Elem(value);
            newElem->next = elem;
            newElem->prev = elem->prev;
            elem->prev->next = newElem;
            elem->prev = newElem;
            size++;
        }
    }

    void insertAfter ( Elem * elem, int value )
    {
        Elem * newElem;

        if(elem == tail) pushBack( value);
        else
        {
            newElem = new Elem(value);
            newElem->next = elem->next;
            newElem->prev = elem;
            elem->next->prev = newElem;
            elem->next = newElem;
            size++;
        }
    }

    void deleteItem(int value){
        Elem * elem = findElementByValue(value);
        if (elem==nullptr) return;
        if(elem->prev) {
            elem->prev->next = elem->next;
        }else {
            head = elem->next;
        }
        if(elem->next){
            elem->next->prev = elem->prev;
        }
        else {
            tail = elem->prev;
        }
        delete elem;
        size--;
    }

    Elem* get(int index){
        if(index>=0 && index<size){
        Elem* temp = head;

        for(int i=0; i<index; i++){
            temp=temp->next;
        }
        return temp;
        }
        return nullptr;
    }

    void clear(){
        head = nullptr;
        tail = nullptr;
        size = 0;
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
                        pushFront(val);
                }
            file.close();
        }
        else
            cout << "File error - OPEN" << endl;
    }

    void fillUpWithRandomValues(int size) {
        for(int i =0; i<size; i++){
            pushFront(1+rand()%1000000000);
        }
    }
};
