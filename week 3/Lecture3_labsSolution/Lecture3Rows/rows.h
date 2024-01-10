//------------------------------------------------------------------------------
//
// OOP
// rows.h
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include guard

#ifndef OOP_ROW_H
#define OOP_ROW_H

//------------------------------------------------------------------------------
// include files
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------------------------
// namespace definition
namespace OOP {

	//------------------------------------------------------------------------------
	/*! \class row in row.h
		 * \brief This is the class for a row with a pointer
		 */
	class row {
	  public: 
			row():ptr(nullptr),len(-1),label("array:") {} 	// Default constructor
			row(const int length, const string& name);
			row(const row& r);              // Copy constructor
			~row();           	            // destructor 

			row & operator =(const row& r); // = copy assignment operator

			// Acecssor / Getter
			const int get_ArrayLen()const { return len; }
			const int at(const int i)const;

			// Mutators / Setters
			void set_at(const int i, const int val);
			void set_label(const std::string& str);

			// Utility
			void printrow(void)const;

	  private:
		  int* ptr, len;
			string label;
	};	// class row

} // namespace OOP

#endif	// OOP_ROW_H

//------------------------------------------------------------------------------

