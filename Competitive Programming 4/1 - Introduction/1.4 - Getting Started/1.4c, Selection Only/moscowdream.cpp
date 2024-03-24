#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio( false );

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    cout << ( !a || !b || !c || a + b + c < n || n < 3 ? "NO" : "YES" ) << endl;
}