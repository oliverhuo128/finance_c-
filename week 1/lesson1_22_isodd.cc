#include <iostream>
// function name: "isodd"
// parameter list one parameter, with name "n" and type int
// return type is bool
bool isodd(int n)
{                      // the body of the function begins
    return n % 2;
}  
                    // the body of the function ends
void func1() {    
   static int i=0; //static variable    
   int j=0; //local variable    
   i++;    
   j++;    
   cout<<"i=" << i<<" and j=" <<j<<endl;    

}
  
int main(){
    for(int arg : {-3, -2, -1, 0, 1, 2, 3})
        std::cout << isodd(arg) << ' '; // isodd called 7 times, each
                                        // time n is copy-initialized from arg
    func1();
	func1();
	func1();
}