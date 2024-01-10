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
	template <class T>
	class templatedRow {
	public: 
    
    templatedRow():ptr(nullptr), len(-1), label("templatedRow") {
    }
  
    //------
    // constructor
    templatedRow(const int length, const string& name) : len(length), label(name) {
      ptr = new T[length];
    }

    //------
    // Copy constructor  	
    templatedRow(const templatedRow& r) {
      if (r.len > -1) {
        len = r.len;
        // ptr = r.ptr
        ptr = new T[len];
        for (int i = 0; i < len; ++i) {
          set_at(i, r.at(i));
        }
      }

      label = r.label;
    }

    //------
    // destructor 
    ~templatedRow() {
      if (len != -1) {
        delete[] ptr;
      }
    }

    //------------------------------------------------------------------------------
    /*! \fn operator =(const templatedRow &r)
    *   \brief  copy assignment operator
    */
    templatedRow<T>& operator =(const templatedRow& r) {
      if (&r != this) {
        if (r.len != -1) {
          delete[] ptr;
          len = r.len;
          ptr = new T[len];
          for (int i = 0; i < len; ++i) {
            set_at(i, r.at(i));
          }

        }
        label = r.label;

      }

      return *this;

    }

    //------------------------------------------------------------------------------
    /*! \fn double printrow(void)
    *   \brief  print the row class to cout
    */ 
    const T& at(const int i)const {
      if (i < len) {
        return ptr[i];
      }
      else {
        throw ("Array not initized!");
      }
    }

    //------------------------------------------------------------------------------
    /*! \fn set_at(const int i, const T& val) 
    *   \brief  set the value at index i
    */ 
    void set_at(const int i, const T& val) {
      if (i < len) {
        ptr[i] = val;
      }
      else {
        throw ("Array not initized!");
      }
    }

    //------------------------------------------------------------------------------
    /*! \fn double set_label(void)
    *   \brief  print the row class to cout
    */ 
    void  set_label(const std::string& str) {
      label = str;
    }


    //------------------------------------------------------------------------------
    /*! \fn double printrow(void)
    *   \brief  print the row class to cout
    */ 
    void  printrow(void)const {
      cout << label << endl;
      cout << "{ ";
      if (len > -1) {
        for (int i = 0; i < len; ++i) {
          cout << this->at(i);
          if (i != len)
            cout << ", ";
        }
        cout << "}\n";
      }
      else {
        throw ("Array not initized!");
      }
    }


	private:
    T* ptr;
    int len;
		string label;
	};	// class row

} // namespace OOP

#endif	// OOP_ROW_H

//------------------------------------------------------------------------------

