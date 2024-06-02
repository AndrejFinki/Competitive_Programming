#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF (((1LL<<61)+(1LL<<30)-1)/2)
#define LD long double
#define endl '\n'
#define print(x) "[ " << #x << ": " << x << " ]" << flush
#define printW(x,y) "[ " << #x << ": " << setw(y) << x << " ]" << flush
#define printE(a,x) "[ " << #a << "[" << x << "]: " << a[x] << " ]" << flush
#define printV(v)   if(1){cout << "[ " << #v << ": "; for(auto _i : v) cout << _i << ' '; cout << "]" << flush << endl;}
#define printA(a,n) if(1){cout << "[ " << #a << ": "; for(int i=0;i<n;i++) cout << a[i] << ' '; cout << "]" << flush << endl;}
#pragma GCC target ("avx2")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
const LD ERR = 1e-7; const int MOD = 1e9 + 7; bool areEqual( LD _n1, LD _n2 ){ return fabs( _n1 - _n2 ) < ERR; } bool smallerEqual( LD _n1, LD _n2 ){ return _n1 < _n2 || areEqual( _n1, _n2 ); }
int modSum( LL _n1, LL _n2 ){ return ( _n1 + _n2 ) % MOD; } int modProd( LL _n1, LL _n2 ){ return ( _n1 * _n2 ) % MOD; }
#ifdef debug
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

bool isJolly();

const int maxN = 3005;
int N;
int A[maxN];
bool appears[maxN];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while( cin >> N ){

        memset( appears, 0, sizeof appears );

        for( int i = 0 ; i < N ; i++ ) cin >> A[i];

        cout << ( isJolly() ? "Jolly" : "Not jolly" ) << endl;

    }

}

bool isJolly(){

    for( int i = 1 ; i < N ; i++ ){
        appears[abs(A[i]-A[i-1])] = true;
    }

    for( int i = 1 ; i < N ; i++ ) if( !appears[i] ) return false;
    
    return true;

}
