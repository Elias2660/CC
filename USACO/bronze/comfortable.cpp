/*
C++ SOLUTION


USACO 2021 February Contest, Bronze
Problem 2. Comfortable Cows
Link to Problem
http://www.usaco.org/index.php?page=viewproblem2&cpid=1108
*/
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int cowPasture[1001][1001], N, num_comfortable;

void new_check_comfortable(int x1, int y1) {
    cowPasture[x1][y1]++;
    if (cowPasture[x1 + 1][y1] != 0) cowPasture[x1][y1]++;
    if (cowPasture[x1 - 1][y1] != 0) cowPasture[x1][y1]++;
    if (cowPasture[x1][y1 + 1] != 0) cowPasture[x1][y1]++;
    if (cowPasture[x1][y1 - 1] != 0) cowPasture[x1][y1]++;

    if (cowPasture[x1][y1] == 4) {
        num_comfortable += 1;
    }

}

void neighbors_check_comfortable(int x1, int y1) {
    if (cowPasture[x1][y1] != 0) {
        cowPasture[x1][y1]++;

        if (cowPasture[x1][y1] == 4) {
            num_comfortable++;
        }
        if (cowPasture[x1][y1] == 5) {
            num_comfortable--;
        }

    }
}


int main() {
    cin >> N;
    num_comfortable=0;

    for (int i = 0; i < N; i++) {
        int xi, yi;
        cin >> xi >> yi;
        xi++; yi++;

        new_check_comfortable(xi, yi);


        neighbors_check_comfortable(xi + 1, yi);
        neighbors_check_comfortable(xi - 1, yi);
        neighbors_check_comfortable(xi, yi + 1);
        neighbors_check_comfortable(xi, yi - 1);
        
        cout << num_comfortable << endl;
    }
}
