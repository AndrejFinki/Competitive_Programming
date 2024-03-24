#include<bits/stdc++.h>
using namespace std;

map <string, int> votes;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string line;
    while( getline( cin, line ) && line != "***" ){
        votes[line]++;
    }

    int max_votes = 0;
    string winner;
    for( auto p : votes ){
        if( p.second < max_votes ) continue;
        if( p.second == max_votes ) winner = "Runoff!";
        else { max_votes = p.second; winner = p.first; }
    }

    cout << winner << endl;

}
