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

void getInputArray();
void solve();

const int maxN = 100005;
string I;
int N;
int A[maxN];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t; cin.ignore();
    while( t-- ){

        getline( cin, I );
        cin >> N; cin.ignore();
        getInputArray();

        solve();

    }

}



void getInputArray(){

    string line; getline( cin, line );
    for( char &c : line ) if( c == '[' || c == ',' || c == ']' ) c = ' ';
    
    stringstream SS(line); int idx = 0;
    while( SS >> A[idx] ) idx++; 
 
}

void solve(){

    deque <int> dq;

    for( int i = 0 ; i < N ; i++ ) dq.push_back(A[i]);

    bool inFront = true;
    for( char c : I ){
        if( c == 'R' ){ inFront = !inFront; continue; }
        if( dq.empty() ){ cout << "error" << endl; return; }
        if( inFront ) dq.pop_front();
        else dq.pop_back();
    }

    bool firstElement = true;
    cout << '[';
    while( !dq.empty() ){
        if( firstElement ) firstElement = false; else cout << ',';
        if( inFront ){ cout << dq.front(); dq.pop_front(); }
        else { cout << dq.back(); dq.pop_back(); }
    } cout << ']' << endl;

}
