#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, N;
    cin >> X >> N;

    int total = X * ( N + 1 );

    for( int i = 0 ; i < N ; i++ ) {
        int P;
        cin >> P;
        total -= P;
    }

    cout << total << endl;
}