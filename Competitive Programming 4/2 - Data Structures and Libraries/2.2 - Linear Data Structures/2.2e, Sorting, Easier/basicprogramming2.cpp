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

void declareActions();

const int maxN = 200005, maxT = 6;
int N, t;
int A[maxN];
function <void()> action[maxT];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    declareActions();

    cin >> N >> t;
    for( int i = 0 ; i < N ; i++ ) cin >> A[i];

    sort( A, A+N );

    action[t]();

}



void declareActions(){

    // Print “Yes” if there are two integers x∈A and y∈A such that x≠y and x+y=7777, or “No” otherwise
    action[1] = []() -> void{
        for( int i = 0 ; i < N ; i++ ){
            int x = A[i];
            int L = i+1, R = N-1, mid;
            while( L <= R ){
                mid = (L+R) / 2;
                int y = A[mid];
                if( x + y == 7777 ){ cout << "Yes" << endl; return; }
                if( x + y < 7777 ) L = mid+1;
                else               R = mid-1;
            }
        } cout << "No" << endl;
    };

    // Print “Unique” if all integers in A are different; or print “Contains duplicate” otherwise (without the quotes)
    action[2] = []() -> void{
        for( int i = 1 ; i < N ; i++ ){
            if( A[i] == A[i-1] ){ cout << "Contains duplicate" << endl; return; }
        } cout << "Unique" << endl;
    };

    // Find and print the integer that appears > N/2 times in A; or print −1 if such integer cannot be found
    action[3] = []() -> void{
        int half = N/2;
        for( int i = 0 ; i + half < N ; i++ ){
            if( A[i] == A[i+half] ){ cout << A[i] << endl; return; }
        } cout << -1 << endl;
    };

    // Find and print the median integer of A if N is odd; or print both median integers of A if N is even (separate them with a single space)
    action[4] = []() -> void{
        if( N & 1 ) cout << A[N/2] << endl;
        else cout << A[N/2-1] << ' ' << A[N/2] << endl; 
    };

    // Print integers in A that fall between a range [100…999] in sorted order; (print a single space between two integers)
    action[5] = []() -> void{
        bool first = true;
        for( int i = 0 ; i < N && A[i] <= 999 ; i++ ){
            if( A[i] < 100 ) continue;
            if( !first ) cout << ' '; else first = false;
            cout << A[i];
        } cout << endl;
    };

}
