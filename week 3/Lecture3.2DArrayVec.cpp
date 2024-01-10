#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

void print(Matrix& m){
   int M=m.size();
   int N=m[0].size();
   for(int i=0; i<M; i++) {
      for(int j=0; j<N; j++)
         cout << m[i][j] << " ";
      cout << endl;
   }
   cout << endl;
}


int main(){

    Matrix m = {  {  1,  2,  3,  4,  5 },   /*  initializers for row indexed by 0 */
                  {  6,  7,  8,  9, 10 },   /*  initializers for row indexed by 1 */
                  { 11, 12, 13, 14, 15 },   /*  initializers for row indexed by 2 */
                  { 16, 17, 18, 19, 20 },   /*  initializers for row indexed by 3 */
                  { 21, 22, 23, 24, 25 } }; /*  initializers for row indexed by 4 */
    print(m);

    //To initialize a 3 x 4 matrix with 0:
    Matrix n( 3,vector<int>(4,0));
	for (auto i = n.
    print(n);
    return 0;
}