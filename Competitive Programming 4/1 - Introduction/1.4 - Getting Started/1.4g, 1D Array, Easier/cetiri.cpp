#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

int main()
{
    ios::sync_with_stdio( false );

    int A[3];
    for( int i = 0 ; i < 3 ; i++ ) cin >> A[i];
    sort( A, A+3 );
    
    int d = min( A[1] - A[0], A[2] - A[1] );
    
    if( A[1] - A[0] == A[2] - A[1] ) cout << A[2] + d << endl;
    else if( A[1] - A[0] == d ) cout << A[1] + d << endl;
    else                        cout << A[0] + d << endl;
}
