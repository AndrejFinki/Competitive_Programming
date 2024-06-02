#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF (((1LL<<61)+(1LL<<30)-1)/2)
#define LD long double
#define endl '\n'
#define Print(x) "[ " << #x << ": " << x << " ]" << flush
#define PrintW(x,y) "[ " << #x << ": " << setw(y) << x << " ]" << flush
#define PrintE(a,x) "[ " << #a << "[" << x << "]: " << a[x] << " ]" << flush
#define PrintV(v)   if(1){cout << "[ " << #v << ": "; for(auto _i : v) cout << _i << ' '; cout << "]" << flush << endl;}
#define PrintA(a,n) if(1){cout << "[ " << #a << ": "; for(int i=0;i<n;i++) cout << a[i] << ' '; cout << "]" << flush << endl;}
#pragma GCC target ("avx2")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
const LD ERR = 1e-7; const int MOD = 1e9 + 7; bool areEqual( LD _n1, LD _n2 ){ return fabs( _n1 - _n2 ) < ERR; } bool smallerEqual( LD _n1, LD _n2 ){ return _n1 < _n2 || areEqual( _n1, _n2 ); }
int modSum( LL _n1, LL _n2 ){ return ( _n1 + _n2 ) % MOD; } int modProd( LL _n1, LL _n2 ){ return ( _n1 * _n2 ) % MOD; } int sign( int x ){ return x < 0 ? -1 : ( x > 0 ? 1 : 0 ); }
struct pos{ int x, y; pos(){} pos( int _x, int _y ) : x(_x), y(_y) {} const bool operator < ( const pos &o ) const { if( x != o.x ) return x < o.x; return y < o.y; } } const dir[] = { {-1,0}, {0,1}, {1,0}, {0,-1} }; enum DIRECTION{ UP, RIGHT, DOWN, LEFT };
#ifdef debug
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

void drop( int );
void take( int );

int N;
int sA, sB;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    bool first = true;
    while( cin >> N && N ){

        if( !first ) cout << endl; else first = false;

        sA = sB = 0;

        string S; int V;
        for( int i = 0 ; i < N ; i++ ){
            cin >> S >> V;
            if( S == "DROP" ) drop(V);
            else              take(V);
        }

    }

}



void drop( int V ){
    sA += V;
    cout << "DROP 1 " << V << endl;
}

void take( int V ){

    if( sB ){
        int K = min( sB, V );
        sB -= K; V -= K;
        cout << "TAKE 2 " << K << endl;
        if( !V ) return;
    }

    swap( sA, sB );
    cout << "MOVE 1->2 " << sB << endl;

    sB -= V;
    cout << "TAKE 2 " << V << endl;

}
