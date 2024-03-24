#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

int main()
{
    ios::sync_with_stdio( false );

    string A, B;
    cin >> A >> B;
    reverse( A.begin(), A.end() );
    reverse( B.begin(), B.end() );
    cout << ( A > B ? A : B ) << endl;
}
