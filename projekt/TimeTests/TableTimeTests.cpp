#include <windows.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include "../Structures/Table.h"
using namespace std;
vector<int> sizes = {5000, 25000, 50000, 75000, 100000}; // rozmiary listy do przetestowania

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

int runtests(){
    std::ofstream outfile("output.txt");
    std::cout.rdbuf(outfile.rdbuf());
    Table table = *new Table();
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    for (int size : sizes) {
        table.clear();
        table.fillUpWithRandomValues(size);
        start = read_QPC();
//        testy:
//        table.insertFront(4);
//        table.insertBack(4);
//        table.get(size-1);
        table.del(size-1);
        elapsed = read_QPC() - start;
//        cout << fixed << setprecision(5) << (float)elapsed /frequency << "\n"; //Time [s]
//        cout << setprecision(5) << (1000.0 * elapsed) /frequency << "\n";   // Time [ms]
        cout << setprecision(5) << (1000000.0 * elapsed) /frequency << "\n"; // Time [us]
//        cout << setprecision(5) << (1000000000.0 * elapsed) /frequency << "\n"; // "Time [ns]

    }
}

int main()
{
    runtests();
    system("PAUSE");
}

