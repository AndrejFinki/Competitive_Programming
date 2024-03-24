#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

void init();

string charMap[256];

int main()
{
    ios::sync_with_stdio( false );

    init();

    string line;
    getline( cin, line );
    transform( line.begin(), line.end(), line.begin(), ::tolower );

    for( char c : line ) if( charMap[c] == "" ) cout << c; else cout << charMap[c];
    cout << endl;
}

void init(){

    for( string &s : charMap ) s = "";

    charMap['a'] = "@";
    charMap['b'] = "8";
    charMap['c'] = "(";
    charMap['d'] = "|)";
    charMap['e'] = "3";
    charMap['f'] = "#";
    charMap['g'] = "6";
    charMap['h'] = "[-]";
    charMap['i'] = "|";
    charMap['j'] = "_|";
    charMap['k'] = "|<";
    charMap['l'] = "1";
    charMap['m'] = "[]\\/[]";
    charMap['n'] = "[]\\[]";
    charMap['o'] = "0";
    charMap['p'] = "|D";
    charMap['q'] = "(,)";
    charMap['r'] = "|Z";
    charMap['s'] = "$";
    charMap['t'] = "']['";
    charMap['u'] = "|_|";
    charMap['v'] = "\\/";
    charMap['w'] = "\\/\\/";
    charMap['x'] = "}{";
    charMap['y'] = "`/";
    charMap['z'] = "2";

}
