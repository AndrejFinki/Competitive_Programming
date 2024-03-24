#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

void processLane( const int, int, const int, const int );
bool froggerWins( const int, const string );

const int maxR = 15, maxC = 25;
int R, C;
vector <string> globalLaneList[maxR];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;

    for( int i = 0 ; i < R ; i++ ){

        int O, I, S; cin >> O >> I >> S;
        processLane( i, O, I, S );

    }

    int P; string MOVES;
    cin >> P >> MOVES;

    cout << ( froggerWins(P,MOVES) ? "safe" : "squish" ) << endl;

}

void processLane( const int idx, int O, const int I, const int S ){

    bitset <maxC> usedOffset = 0;
    string currentLane;
    vector <string> laneList;

    while( true ){

        if( usedOffset[O] ) break;
        usedOffset[O] = true;

        currentLane = "";
        for( int i = 0 ; i < C ; i++ ) currentLane += ".";

        for( int i = O ; i < C+S ; i += I ){
            if( i < C ) currentLane[i] = '>';
            for( int j = i-1 ; i-j < S && j >= 0 ; j-- ){ if( j < C ) currentLane[j] = '-'; }
        }

        laneList.push_back(currentLane);

        O += S;
        while( O - I >= 0 ) O -= I;

    }

    if( idx & 1 ) for( string &s : laneList ) {reverse( s.begin(), s.end() ); for( char &c : s ) if( c == '>' ) c = '<'; }
    
    globalLaneList[idx] = laneList;

}

bool froggerWins( const int P, const string M ){

    function <bool( int, int, int )> froggieDead = []( int T, int x, int y ) -> bool {
        if( x < 0 || x >= R ) return false;
        int REM = T % (int)( globalLaneList[x].size() );
        return !( globalLaneList[x][REM][y] == '.' );
    };

    int x = R, y = P, T = 0;

    for( char c : M ){ T++;

        if( c == 'U' ) x--;
        if( c == 'D' ) x++;
        if( c == 'L' ) y--;
        if( c == 'R' ) y++;

        if( froggieDead( T, x, y ) ) return false;
        if( x == -1 ) return true; 

    }

    return false;

}