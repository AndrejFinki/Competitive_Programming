#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double
#define INF 1e9+7

const int maxN = 40;
int N, M;
int C[maxN]; 
vector < vector<int> > food(maxN);

int main()
{
    ios::sync_with_stdio( false );

    int t; cin >> t;
    while( t-- ){

        for( int i = 0 ; i < maxN ; i++ ) food[i].clear();

        cin >> N >> M;

        for( int i = 0 ; i < N ; i++ ){

            int k, x;
            cin >> k;

            for( int j = 0 ; j < k+1 ; j++ ){
                cin >> x;
                food[i].push_back(x);
            }

        }

        for( int i = 1 ; i <= M ; i++ ) cin >> C[i];

        int CASH = 0;

        for( int i = 0 ; i < N ; i++ ){

            int maxCap = INF, prize = food[i][food[i].size()-1];
            for( int j = 0 ; j < food[i].size()-1 ; j++ ) maxCap = min( maxCap, C[food[i][j]] );

            CASH += prize * maxCap;

        }

        cout << CASH << endl;

    }  
}
