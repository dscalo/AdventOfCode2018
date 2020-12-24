//
// Created by Daniel Scalo on 12/24/20.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;
vector<int> readFreqList(string path) {
    vector<int> freqs;

    std::ifstream file(path);
    if (file.is_open() != 1) {
        cout << "UNABLE TO OPEN FILE" << endl;
    }
    string line;
    while (std::getline(file, line)) {
        int n = stoi(line);
        freqs.push_back(n);
    }
    file.close();

    return freqs;
}

int sumChanges(vector<int> freqs) {
    int tot = 0;
    for (int f : freqs) {
        tot += f;
    }

    return tot;
}

int getFirstDupe(vector<int> freqs) {
    map<int,int> M;
    int tot = 0;
    bool found = false;
    int safety = 0;

    while(!found) {
        safety++;
        if (safety > 5000) {
            cout << "ERROR\n";
            return tot;
        }
        for (int f : freqs) {

            tot += f;
            if (M.contains(tot)) {
                found = true;
                break;
            }

            M.insert(pair<int,int>(tot, 1));

        }
    }
    return tot;

}


void day01() {
    cout << "---- Day 01 ----" << endl;

    string files [] = {"test01", "puzzle"}; // ,
    for (const string &f : files) {
        string path = "../day01/" + f + ".input";
        vector<int> freqs = readFreqList(path);
        int ansP1 = sumChanges(freqs);
        int ansP2 = getFirstDupe(freqs);

        cout << f << ": part 1 answer is " << ansP1 << " ";
        cout << f << ": part 2 answer is " << ansP2 << endl;
    }
}