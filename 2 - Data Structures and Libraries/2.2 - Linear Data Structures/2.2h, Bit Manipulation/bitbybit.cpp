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

void CLEAR(int);
void SET(int);
void OR(int,int);
void AND(int,int);

const int N = 32;
int M;
int A[N];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while( cin >> M && M ){

        memset( A, -1, sizeof A );

        string c; int x, y;
        while( M-- ){
            cin >> c;
            if( c == "CLEAR" ){ cin >> x; CLEAR(x); }
            if( c == "SET" ){ cin >> x; SET(x); }
            if( c == "OR" ){ cin >> x >> y; OR(x,y); }
            if( c == "AND" ){ cin >> x >> y; AND(x,y); }
        }

        for( int i = N-1 ; i >= 0 ; i-- ){
            if( A[i] == -1 ) cout << '?';
            else cout << A[i];
        } cout << endl;

    }

}



void CLEAR( int i ){
    A[i] = 0;
}

void SET( int i ){
    A[i] = 1;
}

void OR( int i, int j ){
    if( A[i] == 1 || A[j] == 1 ) A[i] = 1;
    else if( A[i] == -1 || A[j] == -1 ) A[i] = -1;
    else A[i] = 0;
}

void AND( int i, int j ){
    if( A[i] == 0 || A[j] == 0 ) A[i] = 0;
    else if( A[i] == -1 || A[j] == -1 ) A[i] = -1;
    else A[i] = 1;
}
