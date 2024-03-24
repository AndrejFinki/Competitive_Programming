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
struct pos{ int x, y; pos(){} pos( int _x, int _y ) : x(_x), y(_y) {} } const dir[] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
#ifdef debug
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

const int maxN = 25;
int H, W, N, M;
int G[maxN][maxN], K[maxN][maxN], _G[maxN][maxN] = {};

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> H >> W >> N >> M;

    for( int i = 0 ; i < H ; i++ ) for( int j = 0 ; j < W ; j++ ) cin >> G[i][j];
    for( int i = N-1 ; i >= 0 ; i-- ) for( int j = M-1 ; j >= 0 ; j-- ) cin >> K[i][j];

    for( int i = 0 ; i <= H-N ; i++ ) for( int j = 0 ; j <= W-M ; j++ ){

        int &sum = _G[i][j] = 0;
        for( int _i = i ; _i < i + N ; _i++ ) for( int _j = j ; _j < j + M ; _j++ ) sum += K[_i-i][_j-j] * G[_i][_j];

    }

    for( int i = 0 ; i <= H-N ; i++ ){ 
        for( int j = 0 ; j <= W-M ; j++ ){
            cout << _G[i][j] << ' ';
        } cout << endl;
    }

}
