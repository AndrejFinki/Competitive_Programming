#include<bits/stdc++.h>
using namespace std;

vector <string> word_list;
set <string> word_bank;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string word;
    while( cin >> word ) word_list.push_back(word);

    int N = word_list.size();
    for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ){
        if( i == j ) continue;
        word_bank.insert( word_list[i] + word_list[j] );
    }

    for( const string &S : word_bank ) cout << S << endl;

}
