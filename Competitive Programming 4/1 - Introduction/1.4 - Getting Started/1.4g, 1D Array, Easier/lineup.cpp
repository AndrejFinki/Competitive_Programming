#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

int main()
{
    ios::sync_with_stdio( false );

    int N; cin >> N;
    string A[N];
    for( string &i : A ) cin >> i;

    bool flipped = false, isValid = true;
    if( A[0] > A[N-1] ) reverse( A, A+N ), flipped = true; 

    for( int i = 1 ; i < N ; i++ )
    {
        if( A[i-1] >= A[i] ){ isValid = false; break; }
    }

    cout << ( isValid ? ( flipped ? "DECREASING" : "INCREASING" ) : "NEITHER" ) << endl;
}
