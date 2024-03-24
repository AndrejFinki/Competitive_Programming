#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long

const int maxV = 4005;

struct Graph {
    bool adj[maxV][maxV] = {};
};

const int MOD = 1e9+7;
int mod_sum( int p1, int p2 ){
    return ((LL)(p1) + p2) % MOD;
}
int mod_prod( int p1, int p2 ){
    return ((LL)(p1) * p2) % MOD;
}
int mod_pow( int p, int e ){
    if( !e ) return 1;
    if( e & 1 ) return mod_prod( p, mod_pow( p, e-1 ) );
    return mod_pow( mod_prod( p, p ), e/2 );
}

void print_results();
void init_graphs();

void run_query( int );
void add_new_node();
void add_new_edge( int, int );
void delete_all_edges_from( int );
void remove_edge( int, int );
void transpose_graph();
void complement_graph();


int V, E, Q;
Graph g1, g2, g3, g4;
Graph *current, *transpose, *inverse, *transpose_inverse;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E >> Q;

    init_graphs();

    int p, q;
    for( int i = 0 ; i < E ; i++ ){
        cin >> p >> q;
        add_new_edge( p, q );
    }

    for( int i = 0 ; i < Q ; i++ ){
        int query; cin >> query;
        run_query( query );
    }

    print_results();

}

void init_graphs(){

    current = &g1;
    transpose = &g2;
    inverse = &g3;
    transpose_inverse = &g4;

    for( int i = 0 ; i < V ; i++ ) for( int j = 0 ; j < V ; j++ ){
        current->adj[i][j] = 0;
        transpose->adj[i][j] = 0;
        inverse->adj[i][j] = 1;
        transpose_inverse->adj[i][j] = 1;
    }

}

void print_results(){

    function <int(int)> out_degree = []( int x ) -> int {
        int rv = 0;
        for( int i = 0 ; i < V ; i++ ) if( i != x ) rv += current->adj[x][i];
        return rv;
    };

    function <int(int)> hash = []( int x ) -> int {
        int rv = 0, idx = 0;

        for( int i = 0 ; i < V ; i++ ){
            if( !current->adj[x][i] || i == x ) continue;
            rv = mod_sum( rv, mod_prod( mod_pow( 7, idx++ ), i ) );
        }

        return rv;
    };

    cout << V << endl;
    for( int i = 0 ; i < V ; i++ ){
        cout << out_degree(i) << ' ' << hash(i) << endl;
    }

}

void run_query( int query ){

    if( query == 1 ){
        add_new_node();
    }

    if( query == 2 ){
        int x, y; cin >> x >> y;
        add_new_edge( x, y );
    }

    if( query == 3 ){
        int x; cin >> x;
        delete_all_edges_from( x );
    }

    if( query == 4 ){
        int x, y; cin >> x >> y;
        remove_edge( x, y );
    }

    if( query == 5 ){
        transpose_graph();
    }

    if( query == 6 ){
        complement_graph();
    }

}

void add_new_node(){
    for( int i = 0 ; i < V ; i++ ){
        current->adj[i][V]           = current->adj[V][i]           = false;
        transpose->adj[i][V]         = transpose->adj[V][i]         = false;
        inverse->adj[i][V]           = inverse->adj[V][i]           = true;
        transpose_inverse->adj[i][V] = transpose_inverse->adj[V][i] = true;
    }
    V++;
}

void add_new_edge( int x, int y ){
    current->adj[x][y] = true;
    transpose->adj[y][x] = true;
    inverse->adj[x][y] = false;
    transpose_inverse->adj[y][x] = false;
}

void delete_all_edges_from( int x ){
    for( int i = 0 ; i < V ; i++ ){
        current->adj[i][x]          = current->adj[x][i]          = false;
        transpose->adj[i][x]        = transpose->adj[x][i]        = false;
        inverse->adj[i][x]          = inverse->adj[x][i]          = true;
        transpose_inverse->adj[i][x] = transpose_inverse->adj[x][i] = true;
    }
}

void remove_edge( int x, int y ){
    current->adj[x][y] = false;
    transpose->adj[y][x] = false;
    inverse->adj[x][y] = true;
    transpose_inverse->adj[y][x] = true;
}

void transpose_graph(){
    swap( current, transpose );
    swap( inverse, transpose_inverse );
}

void complement_graph(){
    swap( current, inverse );
    swap( transpose, transpose_inverse );
}
