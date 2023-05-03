/*
C++ Solution

USACO 2020 December Contest, Bronze
Problem 1. Do You Know Your ABCs?

Link to problem:
 http://www.usaco.org/index.php?page=viewproblem2&cpid=1059
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
int cow_nums[7];

for (int i = 0; i < 7; i++) {
   cin >> cow_nums[i];
}

sort(cow_nums, cow_nums+7);

cout << cow_nums[0] << " " << cow_nums[1] << " " << cow_nums[6] - cow_nums[0] - cow_nums[1] << endl;

}