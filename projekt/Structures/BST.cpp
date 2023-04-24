#include <iostream>
#include <fstream>

using namespace std;

class Node {
public:
    int data;    // data = key   klucz odpowiadajacy za wartosc elementu
    Node *left;
    Node *right;

    Node(int k) {
        data = k;
        left = right = nullptr;
    }
};

class BST {
private:
    string cr, cl, cp;
    Node *root;
    int size;
public:

    BST() {
        cr = cl = cp = "  ";
        cr [0] = 218; cr [1] = 196;
        cl [0] = 192; cl [1] = 196;
        cp [0] = 179;
        root = nullptr;
        size=0;
    }
    // Źródło Stackoverflow
    void print ( string sp, string sn, Node * v )
    {
        string s;

        if( v )
        {
            s = sp;
            if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
            print ( s + cp, cr, v->right );

            s = s.substr ( 0, sp.length( ) - 2 );
            cout << s << sn << v->data << endl;

            s = sp;
            if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
            print ( s + cp, cl, v->left );
        }
    }


    void insert(int data) {
        Node *new_node = new Node(data);

        if (root == nullptr) {      // Sprawdzane jest, czy drzewo jest puste.
            root = new_node;        // Jeśli tak, to nowy węzeł jest ustawiany jako korzeń drzewa.
            size++;
            return;
        }

        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr) {            // zaczynamy od korzenia
            parent = current;

            if (data < current->data) {         // w zaleznosci od wartosci, lewe lub prawe poddrzewo
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (data < parent->data) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
        size++;
    }

    Node* search(int data) {
        Node *current = root;   // zaczynamy od korzenia

        while (current != nullptr && current->data != data) {       // dopóki nie zostanie znaleziona szukana wartość lub nie przejdziemy przez wszystkie węzły w drzewie.
            if (data < current->data) {
                current = current->left;        // przesuwamy się w lewo (do mniejszego węzła)
            } else {
                current = current->right;       // przesuwamy się w prawo (do większego węzła)
            }
        }

        return current;
    }

    bool remove(int data) {
        Node *current = root;
        Node *parent = nullptr;

        //wyszukanie elementu do usuniecia
        while (current != nullptr && current->data != data) {
            parent = current;

            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        // Brak elementu
        if (current == nullptr) {
            return false;
        }

        // Przypadek 1: element jest lisciem
        if (current->left == nullptr && current->right == nullptr) {
            if (current == root) {
                root = nullptr;
            } else if (parent->left == current) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }

            delete current;
        }
            // Przypadek 2: element ma 1 potomka
        else if (current->left == nullptr || current->right == nullptr) {
            Node *child;

            if (current->left != nullptr) {
                child = current->left;
            } else {
                child = current->right;
            }

            if (current == root) {
                root = child;
            } else if (parent->left == current) {
                parent->left = child;
            } else {
                parent->right = child;
            }

            delete current;
        }
            // Przypadek 3: element ma dwoch potomkow - metoda nastepnika
        else {
            Node *successor = current->right;
            Node *successor_parent = current;

            while (successor->left != nullptr) {
                successor_parent = successor;
                successor = successor->left;
            }

            current->data = successor->data;

            if (successor_parent->left == successor) {
                successor_parent->left = successor->right;
            } else {
                successor_parent->right = successor->right;
            }

            delete successor;
        }
        size--;
        return true;
    }

    Node* getRoot() {
        return root;
    }

    int getSize(){
        return size;
    }

    void clear() {
        if (root != nullptr) {
            root-> right = nullptr;
            root-> left = nullptr;
            size = 0;
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
                        insert(val);
                }
            file.close();
        }
        else
            cout << "File error - OPEN" << endl;
    }

    void fillUpWithRandomValues(int size) {
        for(int i =0; i<size; i++){
            insert(1+rand()%100);
        }
    }
};