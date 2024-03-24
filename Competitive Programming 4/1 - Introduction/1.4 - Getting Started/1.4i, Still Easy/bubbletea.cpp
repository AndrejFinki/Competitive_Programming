#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF ((1LL<<61)+(1LL<<30)-1)
#define LD long double
#define endl '\n'

const int maxN = 1005;
int N, M;
int BP[maxN], TP[maxN];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for( int i = 0 ; i < N ; i++ ) cin >> BP[i];

    cin >> M;
    for( int i = 0 ; i < M ; i++ ) cin >> TP[i];

    int minPrice = INF;
    for( int i = 0 ; i < N ; i++ ){

        int t; cin >> t;
        while( t-- ){
            int x; cin >> x;
            minPrice = min( minPrice, BP[i] + TP[x-1] );
        }

    }

    int MONEY; cin >> MONEY;

    cout << max( 0, ( MONEY / minPrice ) - 1 ) << endl;

}
