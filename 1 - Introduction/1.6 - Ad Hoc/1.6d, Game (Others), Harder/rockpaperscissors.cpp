#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF ((1LL<<61)+(1LL<<30)-1)
#define LD long double
#define endl '\n'

const int maxN = 105;
int N, K;
int W[maxN], L[maxN];

pair <int, int> playGame( int, int, string, string );

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cout << fixed << setprecision(3);
    while( cin >> N >> K && N ){

        memset( W, 0, sizeof W );
        memset( L, 0, sizeof L );

        int ROUNDS = K * N * ( N-1 ) / 2;
        while( ROUNDS-- ){

            int p1, p2; string m1, m2;
            cin >> p1 >> m1 >> p2 >> m2;

            // pair < winner, loser >
            pair <int, int> result = playGame( p1, p2, m1, m2 );
            if( result.first == -1 ) continue;
            W[result.first]++;
            L[result.second]++;

        }

        for( int i = 1 ; i <= N ; i++ ){
            if( W[i] + L[i] == 0 ) cout << '-' << endl;
            else cout << (LD)( W[i] ) / ( W[i] + L[i] ) << endl;
        } cout << endl;

    }

}

pair <int, int> playGame( int p1, int p2, string m1, string m2 ){

    if( m1 == m2 ) return { -1, -1 };
    if( m1 == "paper" ) return ( m2 == "scissors" ? pair<int,int>(p2, p1) : pair<int,int>(p1, p2) );
    if( m1 == "rock" ) return ( m2 == "paper" ? pair<int,int>(p2, p1) : pair<int,int>(p1, p2) );
    if( m1 == "scissors" ) return ( m2 == "rock" ? pair<int,int>(p2, p1) : pair<int,int>(p1, p2) );
    return { -1, -1 };

}
