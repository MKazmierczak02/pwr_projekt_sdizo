#include <windows.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include "../Structures/List.h"
using namespace std;
vector<int> sizes = { 50000, 250000, 500000, 750000, 1000000 }; // rozmiary listy do przetestowania

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

int runtests(){
    std::ofstream outfile("output.txt");
    std::cout.rdbuf(outfile.rdbuf());
    List list = *new List();
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    for (int size : sizes) {
        list.clear();
        list.fillUpWithRandomValues(size);
        start = read_QPC();
//        list.pushFront(7);
//        list.pushBack(7);
//        list.popBack();
        list.get(size-1);
        elapsed = read_QPC() - start;
//        cout << fixed << setprecision(5) << (float)elapsed /frequency << "\n"; //"Time [s]
//        cout << setprecision(5) << (1000.0 * elapsed) /frequency << "\n";   // Time [ms]
        cout << setprecision(5) << (1000000.0 * elapsed) /frequency << "\n"; // "Time [us]
//        cout << setprecision(5) << (1000000000.0 * elapsed) /frequency << "\n"; // "Time [ns]

    }
}

int main()
{
    runtests();
    system("PAUSE");
}

