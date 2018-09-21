#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void list() {
    double number;
    int int_end;
    ofstream file;

    file.open("Readings.txt");//initialize file called Reading.txt
    srand(time(NULL));//set seed number
    int_end = rand() % 512 + 512;//random for lis length

    //make list and put in Readings file
    for (int i = 0; i < int_end; i++) {
        number = (double)(rand() % 50000 + 40000) / 1000;
        file << i << " " << fixed << setprecision(3) << number << endl;
    }
    file.close();
}


int main() {
    list();//calling function list


    return 0;
}