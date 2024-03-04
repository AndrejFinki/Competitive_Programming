#include <bits/stdc++.h>
using namespace std;

int main()
{
    double sum = 0;
    int N; cin >> N;

    for( int i = 0 ; i < N ; i++ ) {
        double x, y;
        cin >> x >> y;
        sum += x * y;
    }

    cout << fixed << setprecision(3) << sum << endl;
}