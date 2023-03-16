#include <iostream>

using namespace std;

class Elem {
public:
    int data;
    Elem* next;
    Elem* prev;

    Elem(int value) {
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

    void insertFront(int value) {
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

    void insertBack(int value) {
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

    void delFront() {
        if (head == nullptr) {
            return;
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

    void delBack() {
        if (head == nullptr) {
            return;
        }
        else if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Elem* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    void print() {
        Elem* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};