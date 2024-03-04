#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

string piglatin( string );

int main()
{
    ios::sync_with_stdio( false );

    string line;
    while( getline( cin, line ) ){

        for( int i = 0 ; i < line.length() ; ){

            if( !isalpha(line[i]) ){ cout << line[i++]; continue; }

            string word = "";
            while( i < line.length() && isalpha(line[i]) ){ word += line[i++]; }

            cout << piglatin(word);

        } cout << endl;

    }
}

string piglatin( string S ){

    function <bool(char)> isVowel = []( char c ) -> bool{
        c = tolower(c);
        for( char _c : { 'a', 'e', 'i', 'o', 'u', 'y' } ) if( c == _c ) return true;
        return false;
    };

    bool vowelStart = isVowel(S[0]);
    while( !isVowel( S[0] ) ) S = S.substr(1,INF) + S[0];
    if( vowelStart ) S += "y";
    return S + "ay";

}
