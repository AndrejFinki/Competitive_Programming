#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

void init();

int charCost[256] = {};

int main()
{
    ios::sync_with_stdio( false );

    init();

    string line;
    while( getline( cin, line ) ){

        int cost = 0;
        for( char c : line ) cost += charCost[c];
        cout << cost << endl;

    }
}

void init(){

    charCost['!'] =   9;
    charCost['"'] =   6;
    charCost['#'] =  24;
    charCost['$'] =  29;
    charCost['%'] =  22;
    charCost['&'] =  24;
    charCost['\''] =   3;
    charCost['('] =  12;
    charCost[')'] =  12;
    charCost['*'] =  17;
    charCost['+'] =  13;
    charCost[','] =   7;
    charCost['-'] =   7;
    charCost['.'] =   4;
    charCost['/'] =  10;
    charCost['0'] =  22;
    charCost['1'] =  19;
    charCost['2'] =  22;
    charCost['3'] =  23;
    charCost['4'] =  21;
    charCost['5'] =  27;
    charCost['6'] =  26;
    charCost['7'] =  16;
    charCost['8'] =  23;
    charCost['9'] =  26;
    charCost[':'] =   8;
    charCost[';'] =  11;
    charCost['<'] =  10;
    charCost['='] =  14;
    charCost['>'] =  10;
    charCost['?'] =  15;
    charCost['@'] =  32;
    charCost['A'] =  24;
    charCost['B'] =  29;
    charCost['C'] =  20;
    charCost['D'] =  26;
    charCost['E'] =  26;
    charCost['F'] =  20;
    charCost['G'] =  25;
    charCost['H'] =  25;
    charCost['I'] =  18;
    charCost['J'] =  18;
    charCost['K'] =  21;
    charCost['L'] =  16;
    charCost['M'] =  28;
    charCost['N'] =  25;
    charCost['O'] =  26;
    charCost['P'] =  23;
    charCost['Q'] =  31;
    charCost['R'] =  28;
    charCost['S'] =  25;
    charCost['T'] =  16;
    charCost['U'] =  23;
    charCost['V'] =  19;
    charCost['W'] =  26;
    charCost['X'] =  18;
    charCost['Y'] =  14;
    charCost['Z'] =  22;
    charCost['['] =  18;
    charCost['\\'] =  10;
    charCost[']'] =  18;
    charCost['^'] =   7;
    charCost['_'] =   8;
    charCost['`'] =   3;
    charCost['a'] =  23;
    charCost['b'] =  25;
    charCost['c'] =  17;
    charCost['d'] =  25;
    charCost['e'] =  23;
    charCost['f'] =  18;
    charCost['g'] =  30;
    charCost['h'] =  21;
    charCost['i'] =  15;
    charCost['j'] =  20;
    charCost['k'] =  21;
    charCost['l'] =  16;
    charCost['m'] =  22;
    charCost['n'] =  18;
    charCost['o'] =  20;
    charCost['p'] =  25;
    charCost['q'] =  25;
    charCost['r'] =  13;
    charCost['s'] =  21;
    charCost['t'] =  17;
    charCost['u'] =  17;
    charCost['v'] =  13;
    charCost['w'] =  19;
    charCost['x'] =  13;
    charCost['y'] =  24;
    charCost['z'] =  19;
    charCost['{'] =  18;
    charCost['|'] =  12;
    charCost['}'] =  18;
    charCost['~'] =   9;

}
