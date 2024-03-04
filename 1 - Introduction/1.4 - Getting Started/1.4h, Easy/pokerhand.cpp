#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

int freq[128] = {};

int main()
{
    ios::sync_with_stdio( false );

    string S;
    int maxFreq = 0;
    for( int i = 0 ; i < 5 ; i++ )
    {
        cin >> S;
        freq[ S[0] ]++;
        maxFreq = max( maxFreq, freq[ S[0] ] );
    } 

    cout << maxFreq << endl;
}
