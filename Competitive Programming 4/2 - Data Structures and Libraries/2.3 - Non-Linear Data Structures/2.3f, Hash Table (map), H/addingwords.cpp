#include<bits/stdc++.h>
using namespace std;
#define INF (1<<30)

map <string, int> definitions;

void clear();
void def();
void calc();

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string cmd;
    while( cin >> cmd ){
        if( cmd == "clear" ) clear();
        if( cmd == "def" ) def();
        if( cmd == "calc" ) calc();
    }

}

void calc(){

    function <string(int)> get_word_for_result = [](int v) -> string {
        for( const pair <string, int> &p : definitions ){
            if( p.second == v ) return p.first;
        } return "unknown";
    };

    string line; getline( cin, line ); line = line.substr(1, INF);
    stringstream SS(line);

    bool found_unknown = false;
    bool next_is_negative = false;
    string next;
    int int_value = 0;
    while( SS >> next && next != "=" ){
        if( next == "+" ){ next_is_negative = false; continue; }
        if( next == "-" ){ next_is_negative = true; continue; }
        if( !definitions.count(next) ){ found_unknown = true; continue; }
        int_value += ( next_is_negative ? -1 : 1 ) * definitions[next];
    }

    cout << line << " " << ( found_unknown ? "unknown" : get_word_for_result(int_value) ) << endl;

}

void def(){
    string var; int val;
    cin >> var >> val;
    definitions[var] = val;
}

void clear(){
    definitions.clear();
}
