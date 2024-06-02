#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio( false );

    int x, y; cin >> x >> y;

    if( x > 0 && y > 0 ) cout << 1 << endl;
    if( x < 0 && y > 0 ) cout << 2 << endl;
    if( x < 0 && y < 0 ) cout << 3 << endl;
    if( x > 0 && y < 0 ) cout << 4 << endl;
}