#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define endl '\n'

map <string,string> alt;

void init();

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    string A, B; int TC = 0;
    while( cin >> A >> B ){ TC++;

        cout << "Case " << TC << ": ";
        cout << ( A.length() == 1 ? "UNIQUE" : alt[A] + " " + B ) << endl;

    }

}

void init(){
    alt["A#"] = "Bb";
    alt["Bb"] = "A#";
    alt["C#"] = "Db";
    alt["Db"] = "C#";
    alt["D#"] = "Eb";
    alt["Eb"] = "D#";
    alt["F#"] = "Gb";
    alt["Gb"] = "F#";
    alt["G#"] = "Ab";
    alt["Ab"] = "G#";
}
