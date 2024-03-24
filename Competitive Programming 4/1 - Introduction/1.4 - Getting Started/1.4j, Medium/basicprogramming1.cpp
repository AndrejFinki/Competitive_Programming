#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

const int maxN = 200005, maxK = 8;
int N, K;
int A[maxN];
bool vis[maxN];
function <string()> doFunction[maxK];

void init();
string command1(), command2(), command3(), command4(), command5(), command6(), command7();

int main()
{
    ios::sync_with_stdio( false );

    init();

    cin >> N >> K;
    for( int i = 0 ; i < N ; i++ ) cin >> A[i];

    cout << doFunction[K]() << endl;
}

string command1(){
    return "7";
}

string command2(){
    if( A[0] > A[1] ) return "Bigger";
    if( A[0] < A[1] ) return "Smaller";
    return "Equal";
}

string command3(){
    int _A[] = { A[0], A[1], A[2] };
    sort( _A, _A + 3 );
    return to_string(_A[1]);
}

string command4(){
    LL SUM = 0;
    for( int i = 0 ; i < N ; i++ ) SUM += A[i];
    return to_string(SUM);
}

string command5(){
    LL SUM = 0;
    for( int i = 0 ; i < N ; i++ ) if( A[i] % 2 == 0 ) SUM += A[i];
    return to_string(SUM);
}

string command6(){
    string rv = "";
    for( int i = 0 ; i < N ; i++ ) rv += char( (A[i] % 26) + 'a' );
    return rv;
}

string command7(){
    memset( vis, 0, sizeof vis );
    int i = 0;
    while( i != N-1 && !vis[i] ){
        vis[i] = true;
        i = A[i];
        if( i >= N || i < 0 ) return "Out";
    }
    return ( i == N-1 ? "Done" : "Cyclic" );
}

void init(){
    doFunction[1] = *command1;
    doFunction[2] = *command2;
    doFunction[3] = *command3;
    doFunction[4] = *command4;
    doFunction[5] = *command5;
    doFunction[6] = *command6;
    doFunction[7] = *command7;
}
