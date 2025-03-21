#include <iostream>
#include <ctime>
using namespace std;
int main() {
    time_t timestamp;
    time(&timestamp);
    cout << asctime(localtime(&timestamp));
    cout << "HELLO WORLD\n";
    return 0;
}