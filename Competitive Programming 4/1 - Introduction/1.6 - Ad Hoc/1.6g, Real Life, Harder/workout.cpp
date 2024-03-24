#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int N = 10;
int U[N], R[N];
int u[N], r[N], t[N];

void machineTime( int, int& );

int main()
{
    ios::sync_with_stdio( false );

    for( int i = 0 ; i < N ; i++ ) cin >> U[i] >> R[i];
    for( int i = 0 ; i < N ; i++ ) cin >> u[i] >> r[i] >> t[i];

    int TIME = 0;
    for( int rep = 0 ; rep < 3 ; rep++ ){
        for( int i = 0 ; i < N ; i++ ){
            machineTime( i, TIME );
        }   
    }

    cout << TIME - R[N-1] << endl;
}

void machineTime( int i, int &T ){
        
    /* 1) - Finish using machine before pi even gets on it
       2) - Start using machine before pi gets on, but pi arrives during usage
       3) - Pi has already started the cycle */

    if( T + U[i] <= t[i] ){ T += U[i] + R[i]; return; }

    if( T < t[i] ){
        T += U[i];
        t[i] = T;
        T += R[i];
        return;
    }

    int cycle = u[i] + r[i];
    int _T = (T - t[i]) % cycle;
    _T = ( _T + cycle ) % cycle;

    if( _T < u[i] ){
        int waitTime = u[i] - _T;
        _T = u[i];
        T += waitTime;
    }


    T += U[i] + R[i];

    int restTimeLeft = cycle - _T;
    if( U[i] > restTimeLeft ) t[i] += U[i] - restTimeLeft;

}
