#include <iostream>
#include <fstream>
#include <random>

using namespace std;

class Elem {
public:
    int data;
    Elem* next;
    Elem* prev;

    explicit Elem(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class List {

private:
    Elem* head;
    Elem* tail;
    int count;

public:
    List() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    void printFront() {
        Elem* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl<< "Wszystkich elementow jest: " << count <<endl;
    }

    void printBack() {
        Elem* temp = tail;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl<< "Wszystkich elementow jest: " << count <<endl;
    }

    void pushFront(int value) {
        Elem* newElem = new Elem(value);

        if (head == nullptr) {
            head = newElem;
            tail = newElem;
        }
        else {
            head->prev = newElem;
            newElem->prev = nullptr;
            newElem->next = head;
            head = newElem;
        }
        count++;
    }

    void pushBack(int value) {
        Elem* newElem = new Elem(value);
        if (head == nullptr) {
            head = newElem;
            tail = newElem;
        }
        else {
            newElem->next = nullptr;
            newElem->prev = tail;
            tail->next = newElem;
            tail = newElem;
        }
        count++;
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
            count--;
            return val;
        }
        else {
            int val = head->data;
            Elem* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            count--;
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
            return val;
        }
        else {
            Elem* temp = tail;
            int val = tail -> data;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            return val;
        }
        count--;
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
            count++;
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
            count++;
        }
    }

    void deleteItem(int value){
        Elem * elem = findElementByValue(value);
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
        count--;
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
            pushFront(1+rand()%100);
        }
    }
};
