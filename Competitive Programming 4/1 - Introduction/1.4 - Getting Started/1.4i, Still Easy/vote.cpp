#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

int main()
{
    ios::sync_with_stdio( false );

    int t; cin >> t;
    while( t-- ){

        int N; cin >> N;
        int A[N]; for( int &i : A ) cin >> i;

        int maxVotes = 0, winner, totalVotes = 0; bool uniqueMaxVotes = false;
        for( int i = 0 ; i < N ; i++ ){
            totalVotes += A[i];
            if( A[i] == maxVotes ) uniqueMaxVotes = false;
            else if( A[i] > maxVotes ){
                maxVotes = A[i];
                uniqueMaxVotes = true;
                winner = i+1;
            }
        }

        if( !uniqueMaxVotes ) cout << "no winner" << endl;
        else{
            int HALF = totalVotes / 2;
            cout << ( maxVotes > HALF ? "majority" : "minority" ) << " winner " << winner << endl;
        }

    }
}
