#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio( false );

    int N, TC = 0;
    while( cin >> N )
    {
        TC++;
        int minV = 1e9+7, maxV = -1e9+7, x;
        while( N-- ) cin >> x, minV = min( minV, x ), maxV = max( maxV, x );
        cout << "Case " << TC << ": " << minV << ' ' << maxV << ' ' << maxV - minV << endl;
    }
}