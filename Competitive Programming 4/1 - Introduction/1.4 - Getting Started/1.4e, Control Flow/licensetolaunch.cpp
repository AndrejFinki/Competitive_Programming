#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio( false );

    int N, minJ = 1e9+7, minJIdx = -1, x;
    cin >> N;
    
    for( int i = 0 ; i < N ; i++ )
    {
        cin >> x;
        if( x >= minJ ) continue;
        minJ = x;
        minJIdx = i;
    }

    cout << minJIdx << endl;
}