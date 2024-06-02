#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

int main()
{
    ios::sync_with_stdio( false );

    int A, B; cin >> A >> B;

    int Ax = ( B - A + 360 ) % 360;
    int Bx = ( A - B + 360 ) % 360;

    cout << ( abs(Ax) <= abs(Bx) ? Ax : -Bx ) << endl;
}
