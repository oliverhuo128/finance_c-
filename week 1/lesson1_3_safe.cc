int main() { 
	// define some variables from basic types
	bool a = true;
	char b = 45; 
	int c = 123; 
	double d = 3.141567; 
	
    // Use implicit ( C-Style) Conversions
    // no loss of data as converting to a type 
    // that supports a wider range of values 
	c = b; 
	d = c; 
	b = a;
} 
