#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

string GAME;
int starsPerRank[] = { (int)INF, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2 };
bool reachedLegend = false;
int currentRank = 25, currentStars = 0, consecutiveWins = 0;

int main()
{
    ios::sync_with_stdio( false );

    cin >> GAME;

    for( char c : GAME ){

        if( c == 'W' ){
            consecutiveWins++;
            currentStars += 1 + bool( consecutiveWins >= 3 && currentRank >= 6 );
            while( currentStars > starsPerRank[currentRank] ){
                currentStars -= starsPerRank[currentRank];
                currentRank--;
            }
            if( currentRank == 0 ) reachedLegend = true;
        }else{
            consecutiveWins = 0;
            if( currentRank <= 20 ) currentStars--;
            if( currentStars == -1 ){
                if( currentRank < 20 ){
                    currentRank++;
                    currentStars = starsPerRank[currentRank] - 1;
                } else currentStars = 0;
            }
        }

    }

    cout << ( reachedLegend ? "Legend" : to_string( currentRank ) ) << endl;
}
