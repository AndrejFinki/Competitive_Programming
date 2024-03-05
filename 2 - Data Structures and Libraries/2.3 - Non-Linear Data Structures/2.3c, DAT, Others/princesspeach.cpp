#include<bits/stdc++.h>
using namespace std;

const int maxN = 105;
int N, R;
bool found[maxN] = {};
int found_count = 0;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> R;

    for( int i = 0 ; i < R ; i++ ){
        int x; cin >> x;
        found[x] = true;
    }

    for( int i = 0 ; i < N ; i++ ){
        if( found[i] ){ found_count++; continue; }
        cout << i << endl;
    }

    cout << "Mario got " << found_count << " of the dangerous obstacles." << endl;

}
