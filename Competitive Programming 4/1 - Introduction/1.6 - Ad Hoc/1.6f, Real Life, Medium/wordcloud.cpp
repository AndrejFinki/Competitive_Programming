#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int maxN = 105;
int totalWidth, N, maxWidth;
pair <string,int> wordList[maxN];

int findPtSize( int, int );
int findWidth( int, int );

int main()
{
    ios::sync_with_stdio( false );

    int TC = 0;
    while( cin >> totalWidth >> N && totalWidth ){ TC++;

        maxWidth = -1;
        for( int i = 0 ; i < N ; i++ ) { cin >> wordList[i].first >> wordList[i].second; maxWidth = max( maxWidth, wordList[i].second ); }

        int totalH = 0, currentH = 0, currentW = 0; bool first = true;
        for( int i = 0 ; i < N ; i++ ){

            int P = findPtSize( wordList[i].second, maxWidth );
            int W = findWidth( P, wordList[i].first.length() );

            int effectiveW = W + ( first ? 0 : 10 );

            if( currentW + effectiveW > totalWidth ){
                totalH += currentH;
                currentH = 0;
                first = true;
                effectiveW -= 10;
                currentW = 0;
            }

            currentH = max( currentH, P );
            currentW += effectiveW;
            first = false;

        }

        totalH += currentH;

        cout << "CLOUD " << TC << ": " << totalH << endl;

    }
}

int findWidth( int P, int t ){
    return ceil( 9.0*t*P/16.0 );
}

int findPtSize( int Cw, int Cmax ){
    return 8 + ceil( 40.0*(Cw-4)/(Cmax-4) );
}
