#include<bits/stdc++.h>
using namespace std;

const int maxN = 1005;
int N;
int A[maxN];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for( int i = 0 ; i < N ; i++ ) cin >> A[i];

    sort( A, A+N );

    for( int i = 0 ; i < N ; i++ ){
        int j = i+1;
        while( j < N && A[j]-1 == A[j-1] ) j++;
        j--;
        if( i+1 > j ) cout << A[i] << ' ';
        else if( i+1 == j ) cout << A[i] << ' ' << A[j] << ' ';
        else cout << A[i] << '-' << A[j] << ' ';
        i = j;
    }

}
