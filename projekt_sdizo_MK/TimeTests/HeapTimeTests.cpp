#include <windows.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "../Structures/Heap.cpp"
using namespace std;
vector<int> sizes = {5000, 10000, 15000, 20000, 25000,27500, 30000,32500, 35000,40000,45000, 50000,65000,70000, 75000,80000}; // rozmiary listy do przetestowania

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

void runtests(){
    std::ofstream outfile("output.txt");
    std::cout.rdbuf(outfile.rdbuf());
    Heap heap = *new Heap();
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    for (int size : sizes) {
        heap.clear();
        heap.fillUpWithRandomValues(size);
        start = read_QPC();
//        testy:
        int i = heap.peek();
        elapsed = read_QPC() - start;
//        cout << fixed << setprecision(5) << (float)elapsed /frequency << "\n"; //Time [s]
//        cout << setprecision(5) << (1000.0 * elapsed) /frequency << "\n";   // Time [ms]
        cout <<size<<"    "<< setprecision(5) << (1000000.0 * elapsed) /frequency << "\n"; // Time [us]
//        cout << setprecision(5) << (1000000000.0 * elapsed) /frequency << "\n"; // "Time [ns]

    }
}

int main()
{
    runtests();
    system("PAUSE");
}

