#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

string S, T;

int countCharacter( string, char );

int main()
{
    ios::sync_with_stdio( false );

    int t; cin >> t;
    for( int TC = 1 ; TC <= t ; TC++ ){

        cout << "Case " << TC << ": ";

        cin >> S >> T;

        // IF S has more 1's than T, then there is no way to turn those 1's into 0's, therefore there isn't a possible solution. 
        // In any other case, a solution is possible
        if( countCharacter(S,'1') > countCharacter(T,'1') ){ cout << -1 << endl; continue; }
        
        int RES = 0, N = S.length();
        int questionMark0 = 0, questionMark1 = 0; // questionMarkX -> question mark positions that should become X to match with the same number in T
        int mismatch0 = 0, mismatch1 = 0;         // digits that are '0' in S and are '1' in T give mismatch0

        for( int i = 0 ; i < N ; i++ ){
            if( S[i] == T[i] ) continue;
            if( S[i] == '?' ) ( T[i] == '0' ? questionMark0++ : questionMark1++ );
            else              ( S[i] == '0' ? mismatch0++     : mismatch1++     );
        } 

        // Every quesion mark has to become a digit
        RES += questionMark0 + questionMark1;

        // We swap every '0' and '1' we can, and we're left with either only mismatching 0s or mismatching 1s
        int possibleSwaps = min( mismatch0, mismatch1 );
        RES += possibleSwaps; mismatch0 -= possibleSwaps; mismatch1 -= possibleSwaps;

        if( mismatch0 ){
            // Very simple, we turn all of the 0s into 1s with one action
            RES += mismatch0;
        }else{
            // We need to place these leftover 1s into positions with a question mark that have a 1 underneath them
            // When the question mark is swapped with the 1, the one is satisfied and then we just turn the question mark into a 0
            // Since we've already done all of the question mark transformations, all that is needed is to sum up the number of swaps
            // made from this step, which is equal to mismatch1
            RES += mismatch1;
        }

        cout << RES << endl;

    }
}

int countCharacter( string x, char c ){
    int rv = 0;
    for( char _c : x ) rv += _c == c;
    return rv;
}
