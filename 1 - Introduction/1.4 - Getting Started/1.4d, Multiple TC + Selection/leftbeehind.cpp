#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio( false );

    int x, y;
    while( cin >> x >> y && ( x || y ) )
    {
        if( x + y == 13 ){ cout << "Never speak again." << endl; continue; }
        if( x == y ) cout << "Undecided." << endl;
        if( x  < y ) cout << "Left beehind." << endl;
        if( x  > y ) cout << "To the convention." << endl;
    }
}