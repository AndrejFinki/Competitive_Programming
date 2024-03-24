#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

char change[256];

void init();

int main()
{
    ios::sync_with_stdio( false );

    init();

    string line; 
    while( getline( cin, line ) ){
        for( char &c : line ) c = change[c];
        cout << line << endl;
    }
}

void init(){

    change['1'] = '`';
    change['2'] = '1';
    change['3'] = '2';
    change['4'] = '3';
    change['5'] = '4';
    change['6'] = '5';
    change['7'] = '6';
    change['8'] = '7';
    change['9'] = '8';
    change['0'] = '9';
    change['-'] = '0';
    change['='] = '-';

    change['W'] = 'Q';
    change['E'] = 'W';
    change['R'] = 'E';
    change['T'] = 'R';
    change['Y'] = 'T';
    change['U'] = 'Y';
    change['I'] = 'U';
    change['O'] = 'I';
    change['P'] = 'O';
    change['['] = 'P';
    change[']'] = '[';
    change['\\'] = ']';

    change['S'] = 'A';
    change['D'] = 'S';
    change['F'] = 'D';
    change['G'] = 'F';
    change['H'] = 'G';
    change['J'] = 'H';
    change['K'] = 'J';
    change['L'] = 'K';
    change[';'] = 'L';
    change['\''] = ';';

    change['X'] = 'Z';
    change['C'] = 'X';
    change['V'] = 'C';
    change['B'] = 'V';
    change['N'] = 'B';
    change['M'] = 'N';
    change[','] = 'M';
    change['.'] = ',';
    change['/'] = '.';

    change[' '] = ' ';

}
