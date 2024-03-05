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

struct Person{
    string name, socialClass;
    Person(){}
    Person( string _name, string _socialClass ) : name(_name), socialClass(_socialClass) {}
    const bool operator < ( const Person &o ) const{ if( socialClass != o.socialClass ) return socialClass > o.socialClass; return name < o.name; }
    void input();
    friend ostream &operator << ( ostream &output, const Person &o ){ if( DEBUG ) return output << printW(o.name,15) << print(o.socialClass); return output << o.name; } 
};

void normalizePeople();

const int maxN = 105;
int N;
Person people[maxN];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while( t-- ){

        cin >> N; cin.ignore();

        for( int i = 0 ; i < N ; i++ ) people[i].input();

        normalizePeople();

        sort( people, people+N );

        for( int i = 0 ; i < N ; i++ ) cout << people[i] << endl;

        cout << "==============================" << endl;

    }

}



void Person::input(){

    string line, S; getline( cin, line );
    for( char &c : line ) if( c == ':' || c == '-' ) c = ' ';

    stringstream SS(line);

    SS >> name;
    socialClass = "";

    while( SS >> S && S != "class" ){
        socialClass += tolower(S[0]);
    }

}

void normalizePeople(){

    int maxLen = 0;
    for( int i = 0 ; i < N ; i++ ) maxLen = max( maxLen, int(people[i].socialClass.length()) );

    for( int i = 0 ; i < N ; i++ ){
        string &sc = people[i].socialClass;
        reverse( sc.begin(), sc.end() );
        while( sc.length() < maxLen ) sc += "m";        
    }

}
