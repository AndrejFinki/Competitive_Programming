#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

struct pos{
    int x, y;
    pos(){}
    pos( int _x, int _y ) : x(_x), y(_y) {}
};

pair <int, string> findCorrectInstruction();
bool simulate();

const int maxN = 55;
int N, Gx, Gy;
string instructionList[maxN];
pos dir[] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main()
{
    ios::sync_with_stdio( false );

    cin >> Gx >> Gy >> N;

    for( int i = 0 ; i < N ; i++ ){
        cin >> instructionList[i];
    }

    pair <int, string> correctInstruction = findCorrectInstruction();

    cout << correctInstruction.first << ' ' << correctInstruction.second << endl;
}

pair <int, string> findCorrectInstruction(){

    for( int i = 0 ; i < N ; i++ ){

        string original = instructionList[i];

        for( string in : { "Forward", "Left", "Right" } ){
            instructionList[i] = in;
            if( simulate() ) return { i+1, in };
        }

        instructionList[i] = original;

    }

    return {-1, "none"};

}

bool simulate(){

    int x = 0, y = 0, cd = 0;
    for( int i = 0 ; i < N ; i++ ){
        string in = instructionList[i];

        if( in == "Forward" ){ x += dir[cd].x; y += dir[cd].y; }
        if( in == "Left" ){ cd = ( cd - 1 + 4 ) % 4; }
        if( in == "Right" ){ cd = ( cd + 1 ) % 4; }

    }

    return x == Gx && y == Gy;

}
