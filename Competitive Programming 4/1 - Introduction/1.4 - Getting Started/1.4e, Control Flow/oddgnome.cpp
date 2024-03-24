#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio( false );

    int t; cin >> t;
    while( t-- ){

        int N;
        cin >> N;

        int A[N];
        for( int i = 0 ; i < N ; i++ ) cin >> A[i];

        for( int i = 1 ; i < N-1 ; i++ )
        {
            if( A[i-1] < A[i+1] && ( A[i] <= A[i-1] || A[i] >= A[i+1] ) ) {
                cout << i+1 << endl;
                continue;
            }
        } 

    }
}