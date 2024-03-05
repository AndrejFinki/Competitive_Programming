#include<bits/stdc++.h>
using namespace std;

int N, Q;
map <string, vector<int>> visits;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for( int i = 0 ; i < N ; i++ ){
        string place; int year;
        cin >> place >> year;
        visits[place].push_back(year);
    }

    for( auto p : visits ){
        sort( visits[p.first].begin(), visits[p.first].end() );
    }

    cin >> Q;
    for( int i = 0 ; i < Q ; i++ ){
        string place; int k;
        cin >> place >> k;
        cout << visits[place][k-1] << endl;
    }

}
