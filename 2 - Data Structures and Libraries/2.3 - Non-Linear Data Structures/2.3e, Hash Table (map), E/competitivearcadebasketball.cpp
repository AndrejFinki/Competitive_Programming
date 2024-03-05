#include<bits/stdc++.h>
using namespace std;
#define INF (1<<30)

int N, P, M;
map <string, int> points;
vector <string> winners;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> P >> M;
    
    for( int i = 0 ; i < N ; i++ ){
        string S; cin >> S; points[S] = 0;
    }

    for( int i = 0 ; i < M ; i++ ){
        string player; int score;
        cin >> player >> score;
        points[player] += score;
        if( points[player] < P ) continue;
        winners.push_back( player );
        points[player] = -INF; 
    }

    if( winners.empty() ){ cout << "No winner!" << endl; return 0; }

    for( string win : winners ){
        cout << win << " wins!" << endl;
    }

}
