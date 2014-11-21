#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <windows.h>
#include "FallingSand.h"

using namespace std;

// run functions and show only the final result
FallingSand::FallingSand(string file_path) {
    readInputFile(file_path);

    no_more_steps = false; // init value

    while(!no_more_steps) {
        nextStep();
    }
    clearConsole();
    printSandBox();
}

// animate with time milliseconds between the steps
FallingSand::FallingSand(string file_path, int milliseconds) {
    readInputFile(file_path);

    no_more_steps = false; // init value

    while(!no_more_steps) {
        clearConsole();
        printSandBox();
        nextStep();
        Sleep(milliseconds);
    }
}

// read N param and put sandbox in vector
void FallingSand::readInputFile(string file_path) {
    ifstream input_file(file_path.c_str(), fstream::in);
    string current_line;

    if(input_file.good()) {
        // file opened correctly
    } else {
        // sth goes wrong
    }

    getline(input_file, current_line);
    N = atoi(current_line.c_str());


    while(!input_file.eof()) {
        getline(input_file, current_line);
        current_line.resize(N, ' '); // just in case I fulfill line wioth spaces up to N chars
        falling_sand_box.push_back(current_line);
    }
}

// print current version of falling_sand_box
void FallingSand::printSandBox(void) {

    // loop in c++11, for older version uncomment next loop
//    for(auto x : falling_sand_box) {
//        cout << x << endl;
//    }

    // for c++ previous c++11
    for(int i = 0; i < N; i++) {
        cout << falling_sand_box[i] << endl;
    }

}


// next step in sand box
// checking from down to up. If find sand than check that it can fall.
void FallingSand::nextStep(void) {
    size_t found;// = 0;
    int next_search = -1;
    bool move_done = false; // if any move (fall sand) has done it is true. If it is false than

    for(int i = (N-2); i >= 0; i--) {
        while(found != string::npos) {
            found = falling_sand_box[i].find(sand_char, next_search+1); // search for sand
            if(found != string::npos) {
                next_search = found;

                // check that sand can fall?
                if(falling_sand_box[i+1][found] == ' ') {
                    falling_sand_box[i+1][found] = sand_char;
                    falling_sand_box[i][found] = ' ';
                    move_done = true;
                }
            }
        }
        found = 0;
        next_search = -1;
    }

    no_more_steps = !move_done;

}

// clear console
void FallingSand::clearConsole(void) {
    if (system("CLS")) system("clear");
}
