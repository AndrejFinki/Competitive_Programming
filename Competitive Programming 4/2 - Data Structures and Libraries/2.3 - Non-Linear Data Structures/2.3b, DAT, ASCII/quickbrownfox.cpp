#include<bits/stdc++.h>
using namespace std;

int freq[256] = {};

void solve(string);

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string line; int t; cin >> t; cin.ignore();
    while( t-- ){
        getline( cin, line );
        solve(line);
    }

}

void solve( string line ){

    memset( freq, 0, sizeof freq );

    transform( line.begin(), line.end(), line.begin(), ::tolower );

    for( const char &c : line ) freq[c]++;

    string missing = "";

    for( char c = 'a' ; c <= 'z' ; c++ ) if( !freq[c] ) missing += c;

    cout << ( missing.empty() ? "pangram" : "missing " + missing ) << endl;

}
