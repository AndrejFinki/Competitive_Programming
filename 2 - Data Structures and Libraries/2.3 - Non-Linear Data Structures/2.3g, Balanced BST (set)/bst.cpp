#include<bits/stdc++.h>
using namespace std;
#define LL long long

void insert(int);

set <int> bst;
map <int, int> height;
LL counter = 0;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    while( N-- ){
        int x; cin >> x;
        insert(x);
        counter += height[x];
        cout << counter << endl;
    }

}

void insert( int v ){

    bst.insert(v);

    set <int>::iterator vitr = bst.find(v);

    if( vitr == bst.begin() && vitr == --bst.end() ){ height[v] = 0; return; }

    if( vitr == bst.begin() ){ height[v] = height[*(++vitr)] + 1; return; }

    if( vitr == --bst.end() ){ height[v] = height[*(--vitr)] + 1; return; }

    set <int>::iterator litr = vitr, ritr = vitr;
    litr--; ritr++;

    height[v] = max( height[*litr], height[*ritr] ) + 1;

}
