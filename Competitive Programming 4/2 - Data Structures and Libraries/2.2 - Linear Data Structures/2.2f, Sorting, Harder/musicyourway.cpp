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
int modSum( LL _n1, LL _n2 ){ return ( _n1 + _n2 ) % MOD; } int modProd( LL _n1, LL _n2 ){ return ( _n1 * _n2 ) % MOD; } int sign( int x ){ return x < 0 ? -1 : ( x > 0 ? 1 : 0 ); }
struct pos{ int x, y; pos(){} pos( int _x, int _y ) : x(_x), y(_y) {} const bool operator < ( const pos &o ) const { if( x != o.x ) return x < o.x; return y < o.y; } } const dir[] = { {-1,0}, {0,1}, {1,0}, {0,-1} }; enum DIRECTION{ UP, RIGHT, DOWN, LEFT };
#ifdef debug
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

const int maxN = 105, maxA = 25;

struct Song{
    string attributes[maxA];
    int currentSortingAttribute = 0;
    Song(){ for( string &s : attributes ) s = ""; }
    string &operator [] ( int i ){ return attributes[i]; }
    const bool operator < ( const Song &o ) const{ return attributes[currentSortingAttribute] < o.attributes[currentSortingAttribute]; }
};

void getAttributeList();
void sortBy(int);
void printPlaylist();

int N, M, A = 0;
string attributeList[maxA];
map <string, int> attributeIdx;
Song playlist[maxN];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    getAttributeList();

    cin >> N;

    for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < A ; j++ ) cin >> playlist[i][j];

    cin >> M;

    for( int i = 0 ; i < M ; i++ ){
        if(i) cout << endl;
        string att; cin >> att;
        sortBy(attributeIdx[att]);
        printPlaylist();
    }

}



void getAttributeList(){

    string line, S; getline( cin, line );
    stringstream SS(line);

    while( SS >> S ){ attributeList[A] = S; attributeIdx[S] = A++; }

}

void sortBy( int a ){

    for( int i = 0 ; i < N ; i++ ) playlist[i].currentSortingAttribute = a;

    stable_sort( playlist, playlist+N );

}

void printPlaylist(){

    for( int i = 0 ; i < A ; i++ ){ cout << attributeList[i] << ' '; } cout << endl;

    for( int i = 0 ; i < N ; i++ ){
        Song &s = playlist[i];
        for( int j = 0 ; j < A ; j++ ) cout << s[j] << ' ';
        cout << endl;
    }  

}
