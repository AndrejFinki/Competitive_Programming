#include <bits/stdc++.h>
using namespace std;

char soundex[256] = {};

void init();

int main()
{
	init();

	string S;
	while( cin >> S )
	{
		string sdx = "0";
		for( char &c : S ) {
			if( soundex[c] && soundex[c] != sdx[ sdx.length()-1 ] )
				sdx += soundex[c];
		}
		for( char &c : sdx )
			if( c != '0' ) cout << c;
		cout << endl;
	}
}

void init()
{
	for( char c = 'A' ; c <= 'Z' ; c++ ) soundex[c] = '0';
	for( const char &c : {'B', 'F', 'P', 'V'} ) soundex[c] = '1';
	for( const char &c : {'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'} ) soundex[c] = '2';
	for( const char &c : {'D', 'T'} ) soundex[c] = '3';
	for( const char &c : {'L'} ) soundex[c] = '4';
	for( const char &c : {'M', 'N'} ) soundex[c] = '5';
	for( const char &c : {'R'} ) soundex[c] = '6';
}
