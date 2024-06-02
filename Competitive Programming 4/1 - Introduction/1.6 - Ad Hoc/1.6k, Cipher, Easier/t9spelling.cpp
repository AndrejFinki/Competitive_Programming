#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

void init();

string charToString[256];

int main()
{
    ios::sync_with_stdio( false );

    init();

    int t; cin >> t; cin.ignore();
    for( int TC = 1 ; TC <= t ; TC++ ) {

        string line;
        getline( cin, line );

        string rv = "";
        char lastDigit = '~';
        for( char c : line ){
            if( lastDigit == charToString[c][0] ) rv += ' ';
            rv += charToString[c];
            lastDigit = charToString[c][charToString[c].length()-1];
        }

        cout << "Case #" << TC << ": " << rv << endl;

    }
}

void init(){

    charToString['a'] = "2";
    charToString['b'] = "22";
    charToString['c'] = "222";
    charToString['d'] = "3";
    charToString['e'] = "33";
    charToString['f'] = "333";
    charToString['g'] = "4";
    charToString['h'] = "44";
    charToString['i'] = "444";
    charToString['j'] = "5";
    charToString['k'] = "55";
    charToString['l'] = "555";
    charToString['m'] = "6";
    charToString['n'] = "66";
    charToString['o'] = "666";
    charToString['p'] = "7";
    charToString['q'] = "77";
    charToString['r'] = "777";
    charToString['s'] = "7777";
    charToString['t'] = "8";
    charToString['u'] = "88";
    charToString['v'] = "888";
    charToString['w'] = "9";
    charToString['x'] = "99";
    charToString['y'] = "999";
    charToString['z'] = "9999";
    charToString[' '] = "0";

}