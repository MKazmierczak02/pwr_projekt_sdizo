#include <iostream>
#include "../Structures/BST.cpp"
using namespace std;


class BSTHandler {

public:
    static void printMenu(){
        cout <<endl<<"Drzewo BST"<<endl;
        cout << "1. Wyswietl Drzewo BST" << endl;
        cout << "2. Dodaj element (insert)" << endl;
        cout << "3. Usun elelement (remove)" << endl;
        cout << "4. Znajdz index elementu" <<endl;
        cout << "5. Wczytaj drzewo z pliku" << endl;
        cout << "6. Wypelnij drzewo losowymi wartosciami z zakresu 1-100" << endl;
        cout << "7. Usun drzewo BST" << endl;
        cout << "0. Wyjdz" << endl;
    }

    static void handle() {
        bool app = true;
        int choice;

        auto bst = BST();


        while(app){
            printMenu();
            cin >> choice;
            switch (choice) {
                case 1: {
                    cout << endl <<"Drzewo BST:" << endl;
                    bst.print("","",bst.getRoot());
                    break;
                }
                case 2: {
                    int value;
                    cout << endl << "Podaj wartosc" <<endl;
                    cin >> value;
                    bst.insert(value);
                    break;
                }
                case 3: {
                    int value;
                    cout << endl << "Podaj wartosc elementu do usuniecia" <<endl;
                    cin >> value;
                    if (bst.remove(value)){
                        cout << "Usunieto poprawnie element"<<endl;
                    } else {
                        cout << "Nie ma elementu o podanej wartosci"<<endl;
                    }
                    break;
                }
                case 4: {
                    int value;
                    cout << endl << "Podaj wartosc" <<endl;
                    cin >> value;
                    Node* node = bst.search(value);

                    break;
                }
                case 5:{
                    string file;
                    cout << endl << "Podaj sciezke do pliku" <<endl;
                    cin >> file;
                    bst.loadFromFile(file);
                    break;
                }
                case 6:{
                    int size;
                    cout << endl << "Podaj wielkosc kopca: " <<endl;
                    cin >> size;
                    bst.fillUpWithRandomValues(size);
                    break;
                }
                case 7:{
                    bst.clear();
                    break;
                }
                case 0: {
                    app = false;
                    break;
                }
                default: {
                    cout << "Wpisano zly numer" << endl;
                    break;
                }
            }
        }

    }


};
