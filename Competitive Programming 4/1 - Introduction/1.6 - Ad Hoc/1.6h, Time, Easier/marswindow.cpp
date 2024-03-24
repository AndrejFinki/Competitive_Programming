#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

void init();

const int maxY = 10005;
bool hasLaunch[maxY];

int main()
{
    ios::sync_with_stdio( false );

    init();

    int Y; cin >> Y;
    cout << ( hasLaunch[Y] ? "yes" : "no" ) << endl;
}

void init(){

    memset( hasLaunch, 0, sizeof hasLaunch );

    int M = 4, Y = 2018, T = 0;
    while( Y < maxY ){
        if( !T ){ hasLaunch[Y] = true; T = 26; }
        T--; M++;
        if( M == 13 ){ M = 1; Y++; }
    }

}
