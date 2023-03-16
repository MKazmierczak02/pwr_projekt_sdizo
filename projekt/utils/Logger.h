#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

class Logger {
public:
    Logger(const string& filename) {
        if (!fs::exists(filename)) {
            ofstream file(filename);
            file.close();
        }
        m_file.open(filename, ios_base::app);
        this -> log ("********************************************************");
    }

    template<typename T>
    void log(const T& message) {
        auto now = chrono::system_clock::now();
        time_t timestamp = chrono::system_clock::to_time_t(now);
        tm timeinfo = *localtime(&timestamp);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);

        m_file << buffer << " - " << message << endl;
        cout << buffer << " - " << message << endl;
    }

private:
    ofstream m_file;
};