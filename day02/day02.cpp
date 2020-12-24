//
// Created by Daniel Scalo on 12/24/20.
//

#include "day02.h"


#include <iostream>
#include "../utils/lev.h"
#include <fstream>
#include <vector>
#include <map>

using namespace std;

typedef  vector<string> BoxIds;


BoxIds readBoxIds(string path) {
    BoxIds ids;

    ifstream file(path);
    if (file.is_open() != 1) {
        cout << "UNABLE TO OPEN FILE" << endl;
    }
    string line;
    while (std::getline(file, line)) {

        ids.push_back(line);
    }
    file.close();

    return ids;
}

int getCharCounts(BoxIds ids) {
    int threes = 0;
    int twos = 0;

    for (const string& id : ids) {
        map<char,int> counts;
        char cstr[id.size() + 1];
        strcpy(cstr, id.c_str());

        for (const char c : cstr) {
            if (c == '\0') {
                continue;
            }
            if (counts.contains(c)) {
                counts[c] += 1;
            } else {
                counts.insert(pair<char, int>(c, 1));
            }
        }

        bool two = false;
        bool three = false;
        for (auto const& [key,val] : counts) {
            if (val == 2) {
                two = true;
            }

            if (val == 3) {
                three = true;
            }
        }

        if (two) {
            twos++;
        }

        if (three) {
            threes++;
        }
    }
    return threes * twos;
}

string getCommonLetters(BoxIds ids) {
    string commons = "";
    for (int i = 0; i < ids.size() -1; i++) {
        for (int j = i+1; j < ids.size(); j++) {
            if (lev(ids.at(i), ids.at(j)) == 1) {

                for (int k = 0; k < ids.at(i).size(); k++) {
                    if (ids.at(i)[k] == ids.at(j)[k]) {
                        commons += ids.at(i)[k];
                    }
                }
                break;

            }
        }
    }

    return commons;
}

void day02() {
    std::cout << "---- Day 02 ----" << std::endl;
    std::string files [] = {"test01", "puzzle"};
    for (const string &f : files) {
        string path = "../day02/" + f + ".input";

        BoxIds ids = readBoxIds(path);

        int ansP1 = getCharCounts(ids);
        string ansP2 = getCommonLetters(ids);

        cout << f << ": part 1 answer is " << ansP1 << " ";
        cout << f << ": part 2 answer is " << ansP2 << endl;
    }
}
