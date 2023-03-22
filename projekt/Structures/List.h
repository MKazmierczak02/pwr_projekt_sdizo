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

public:
    List() {
        head = nullptr;
        tail = nullptr;
    }

    void pushFront(int value) {
        Elem* newElem = new Elem(value);

        if (head == nullptr) {
            head = newElem;
            tail = newElem;
        }
        else {
            newElem->next = head;
            head->prev = newElem;
            head = newElem;
        }
    }

    void pushBack(int value) {
        Elem* newElem = new Elem(value);
        if (head == nullptr) {
            head = newElem;
            tail = newElem;
        }
        else {
            newElem->prev = tail;
            tail->next = newElem;
            tail = newElem;
        }
    }

    int popFront() {
        if (head == nullptr) {
            return -1;
        }
        else if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Elem* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
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
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    void printFront() {
        Elem* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void printBack() {
        Elem* temp = tail;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
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
