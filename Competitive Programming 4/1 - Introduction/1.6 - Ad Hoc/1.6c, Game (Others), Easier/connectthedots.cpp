#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int maxN = 105;
int N, M;
char G[maxN][maxN];
pair <int,int> pos[maxN];

int toIdx( char );
void verticalLine( int, int, int );
void horizontalLine( int, int, int );

int main()
{
    ios::sync_with_stdio( false );

    string line;
    while( true ){

        for( pair <int,int> &i : pos ) i = {-1,-1};
        N = M = 0;

        while( getline( cin, line ) && line != "" ){
            N++; M = line.length();
            for( int j = 0 ; j < M ; j++ ){
                G[N-1][j] = line[j];
                if( line[j] == '.' ) continue;
                pos[toIdx(line[j])] = { N-1, j };
            }
        }

        if( !N ) break;

        for( int i = 1 ; pos[i].first != -1 ; i++ ){

            pair <int,int> x = pos[i-1], y = pos[i];
            if( x.first == y.first ) verticalLine( x.first, x.second, y.second );
            else                     horizontalLine( x.second, x.first, y.first );

        }

        for( int i = 0 ; i < N ; i++ ){
            for( int j = 0 ; j < M ; j++ ){
                cout << G[i][j];
            } cout << endl;
        } cout << endl;

    }
}

void verticalLine( int x, int y1, int y2 ){
    if( y1 > y2 ) swap( y1, y2 );
    for( int y = y1 ; y <= y2 ; y++ ){
        if( G[x][y] == '.' ) G[x][y] = '-';
        else if( G[x][y] == '|' ) G[x][y] = '+';
    }
}

void horizontalLine( int y, int x1, int x2 ){
    if( x1 > x2 ) swap( x1, x2 );
    for( int x = x1 ; x <= x2 ; x++ ){
        if( G[x][y] == '.' ) G[x][y] = '|';
        else if( G[x][y] == '-' ) G[x][y] = '+';
    }
}

int toIdx( char c ){
    if( '0' <= c && c <= '9' ) return c - '0';
    if( 'a' <= c && c <= 'z' ) return 10 + c - 'a';
    return 10 + 26 + c - 'A';
}
