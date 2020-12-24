//
// Created by Daniel Scalo on 12/24/20.
//

#include "lev.h"

//
// Created by Daniel Scalo on 12/22/20.
//


#include <string>


using namespace std;

int MIN(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int lev(std::string s1, std::string s2) {
    // covert to char[]
    char c1[s1.size()+1];
    char c2[s2.size()+1];

    strcpy(c1,s1.c_str());
    strcpy(c2,s2.c_str());

    int c1Len = strlen(c1);
    int c2Len = strlen(c2);

    int  distance[50][50];
    int t = 0;
    int track = 0;

    for (int i = 0; i <= c1Len; i++) {
        distance[0][i] = i;
    }

    for (int j=0; j <= c2Len; j++) {
        distance[j][0] = j;
    }

    for (int j = 1; j <= c1Len; j++) {
        for (int i = 1; i <= c2Len; i++) {
            if (c1[i-1] == c2[j-1]) {
                track = 0;
            } else {
                track = 1;
            }
            t = MIN(distance[i-1][j] + 1, distance[i][j-1]+1);
            distance[i][j] = MIN(t, distance[i-1][j-1]+ track);
        }
    }

    return distance[c2Len][c1Len];
}
