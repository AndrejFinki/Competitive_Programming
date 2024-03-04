#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio( false );

    int X, Y, N;
    cin >> X >> Y >> N;
    for( int i = 1 ; i <= N ; i++ )
    {
        if( i % X && i % Y ) {
            cout << i << endl;
            continue;
        }
        if( !( i % X ) ) cout << "Fizz";
        if( !( i % Y ) ) cout << "Buzz";
        cout << endl;
    }
}