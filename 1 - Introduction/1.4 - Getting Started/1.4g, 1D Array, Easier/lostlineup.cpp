#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

int main()
{
    ios::sync_with_stdio( false );

    int N; cin >> N;
    int A[N];
    A[0] = 1;

    for( int i = 1 ; i < N ; i++ )
    {
        int x; cin >> x;
        A[x+1] = i+1;
    }

    for( int i : A ) cout << i << ' '; cout << endl;
}
