#include <iostream>

int main(){

    int i = 0;
	std::cout << " i at start:" << i << "\n";
	{
	    std::cout << " inside braces"<<"\n";
        int i = 7, j = 12;                            // this i hides the outer one
                                                      // i and j local to inside the braces		
	    std::cout << "inside braces i:" << i << "\n"; //using local i
		std::cout << "inside braces j:" << j << "\n";
	}	

	std::cout << "outside braces i:" << i << "\n";    // here we are using the original inside
	                                                  // j no longer exists
    return 0;
}