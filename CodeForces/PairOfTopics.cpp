/*


Recommended Compile Command:
clang++ -std=c++11 -stdlib=libc++ PairOfTopics.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::upper_bound;
using std::vector;
using std::min;
long long N, count = 0;
vector<long long> a, b, c;

int main()
{
    // freopen("text", "r", stdin);
    cin.tie(0);
    cin >> N;
    a.resize(N);
    b.resize(N);
    for (auto &i : a)
    {
        cin >> i;
    }
    for (auto &i : b)
    {
        cin >> i;
    }
    for (long long i = 0; i < N; i++)
    {
        c.push_back(a[i] - b[i]);
    }
    sort(c.begin(), c.end());
    for (long long i = 0; i < N; i++)
    {
        if (c[i] > 0)
        {
            long long change = lower_bound(c.begin(), c.end(),- c[i] + 1) - c.begin();
            count += i - change;
        }
    }
    cout << count;
    return 0;
}

// 4 8 2 6 2 -> 0 3 -2 5 -1 ->

// c -> -2 -1 0 3 5
// d -> -5 -3 0 1 2
