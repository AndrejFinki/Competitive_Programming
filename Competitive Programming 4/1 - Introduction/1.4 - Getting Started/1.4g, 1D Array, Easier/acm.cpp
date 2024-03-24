#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

int penalty[128] = {};

int main()
{
    ios::sync_with_stdio( false );

    int SOLVED = 0, TIME = 0;
    int M; char P; string V;
    while( cin >> M >> P >> V && M != -1 )
    {
        if( V == "wrong" ) penalty[P] += 20;
        else               SOLVED++, TIME += M + penalty[P];
    }

    cout << SOLVED << ' ' << TIME << endl;
}
