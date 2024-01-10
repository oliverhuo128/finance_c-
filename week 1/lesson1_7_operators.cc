int main(){
  {
    // int variable  
    int j = 4 + 3; // 7, addition
    j = 4 - 3; // 1, subtraction
    j = 4 * 3; // 12, multiplication
    j = 4 / 3; // 1, division
    j = 4 % 3; // 1, modulus (division remainder)
  }

  {
    int j = 10; // assignment
  
    j += 4; // j = j+4; 
    j -= 4; // j = j-4; 
    j *= 4; // j = j*4; 
    j /= 4; // j = j/4; 
    j %= 4; // j = j%4;
	
	//increment operators
    j++;    // j = j+1;
    j--;    // j = j-1;
	
    // these can be used either before or after a variable.
    j++;    // post-increment
    j--;    // post-decrement
    ++j;    // pre-increment
    --j;    // pre-decrement	
  }

  return 0;
}
