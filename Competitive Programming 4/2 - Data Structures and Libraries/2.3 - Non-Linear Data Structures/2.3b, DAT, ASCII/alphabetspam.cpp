#include<bits/stdc++.h>
using namespace std;
#define LD long double

void print_ratio( int, int );

int freq[256] = {};
string line;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    getline( cin, line );

    for( const char &c : line ) freq[c]++;

    int total = line.length();
    int whitespace = 0, lowercase = 0, uppercase = 0, symbols = 0;

    whitespace = freq['_'];

    for( char c = 'a' ; c <= 'z' ; c++ ) lowercase += freq[c];

    for( char c = 'A' ; c <= 'Z' ; c++ ) uppercase += freq[c];

    symbols = total - whitespace - lowercase - uppercase;

    for( const int &i : { whitespace, lowercase, uppercase, symbols } ) print_ratio( total, i );

}

void print_ratio( int total, int i ){
    LD r = i;
    r /= total;
    cout << fixed << setprecision(16) << r << endl;
}
