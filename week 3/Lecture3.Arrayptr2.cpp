
// Array pointers
#include <iostream>
using namespace std;

int main()
{
  int a[5][5] = { {  1,  2,  3,  4,  5 },   /*  initializers for row indexed by 0 */
                  {  6,  7,  8,  9, 10 },   /*  initializers for row indexed by 1 */
                  { 11, 12, 13, 14, 15 },   /*  initializers for row indexed by 2 */
                  { 16, 17, 18, 19, 20 },   /*  initializers for row indexed by 3 */
                  { 21, 22, 23, 24, 25 } }; /*  initializers for row indexed by 4 */
  int(*p)[5] = a;
  p = a;           *(*p) = 10000;                      //  a[0][0]=10000
                   p[1][1] = 20000;                    //  a[1][1]=20000
  p = &a[2];       (*p)[2] = 30000;                    //  a[2][2]=30000 
  p = a + 3;       (*p)[3] = 40000;                    //  a[3][3]=40000
  p = a;  
  *(p[4] + 4) = 50000;                                 //  a[4][4]=50000
  for (int n = 0; n < 5; n++) {
    for (int m = 0; m < 5; m++){
      cout << a[n][m] << ", ";    // output : 10000, 2, 3, 4, 5, ....
    }
    cout << std::endl;
  }
  return 0;
}

