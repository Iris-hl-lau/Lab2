#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
    /**Create list of readings and puts it in Reading file*/
    double number;
    int int_end;
    //open file for writing
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

    /**Counts total of readings*/
    int read1;
    double read2;
    double readings[1024];
    int read_count = 0;
    //open a file for reading
    ifstream file_read;
    file_read.open("Readings.txt");

    while(!file_read.eof()) {
        file_read >> read1 >> read2;//draw input from file; end value of read is a double
        readings[read_count] = read2;

        //prevents reading the last line twice
        if(file_read.eof()) {
            break;
        }
        read_count++;
    }

    cout << "There are " << read_count << " readings in the file." << endl;
    file_read.close();


    /**Calculates average of Readings*/
    double sum;
    double avg;

    for (int i = 0; i < read_count; i++) {
        sum += readings[i];
    }

    avg = sum / read_count;
    cout << "The average reading is " << avg << "." << endl;

    /**Finds the highest and lowest reading*/
    double max = readings[0];
    double min = readings[0];
    for (int i = 1; i < read_count; i++) {
        if(max < readings[i]) {
            max = readings[i];
        } else if(min > readings[i]) {
            min = readings[i];
        }
    }

    cout << "The highest reading is " <<  max  << "." << endl;
    cout << "The lowest reading is " <<  min  << "." << endl;

    /**Finds the median reading*/
    double median;
    //Sorts readings from least to greatest
    for (int i = 0; i < read_count; i++) {
        if(readings[i] > readings[i + 1]) {
            double temp = readings[i];
            readings[i] = readings[i + 1];
            readings[i + 1] = temp;
        }
    }

    //Determines if list is odd or even to find the median
    if(read_count % 2 == 0) {
        double upper = readings[read_count / 2];
        double lower = readings[(read_count / 2) - 1];
        median = (upper + lower) / 2;
    } else {
        median = readings[(read_count - 1) / 2];
    }

    cout << "The median reading is " <<  median  << "." << endl;
    return 0;
}