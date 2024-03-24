#include<bits/stdc++.h>
using namespace std;

int N;
unordered_map <int, int> last_pos;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int x, awk = N;
    for( int i = 0 ; i < N ; i++ ){
        cin >> x;
        if( last_pos.count(x) ){ awk = min( awk, i - last_pos[x] ); }
        last_pos[x] = i;
    }

    cout << awk << endl;

}
