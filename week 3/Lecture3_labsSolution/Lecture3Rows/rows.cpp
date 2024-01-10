//----------------------------------------------------------------------------------------------
/*! \file row.cpp
    \brief A Implentation files for classes in row

    \details
*/
//-----------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include files
#include "rows.h"

using namespace OOP;

//------
// constructor
row::row(const int length, const string& name): len(length),  label(name){
  ptr = new int[length]; 
}

//------
// Copy constructor
row::row(const row& r){
  
  if (r.len > -1) {
    len = r.len;
    // ptr = r.ptr
    ptr = new int[len];
    for (int i = 0; i < len; ++i) {
      set_at(i, r.at(i));
    }
  }

   label = r.label; 
}

//------
// destructor
row::~row() {
  if (len != -1) {
    delete[] ptr;
  }
}

//------------------------------------------------------------------------------
/*! \fn operator =(const row &r)
*   \brief  copy assignment operator
*/
row& row::operator =(const row& r) {
  if (&r != this) {
    if (r.len != -1) {
      delete[] ptr;  
      len = r.len; 
      ptr = new int[len];
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
const int row::at(const int i)const {
  if (i < len) {
    return ptr[i];
  }
  else {
    throw ("Array not initized!");
  }
}

//------------------------------------------------------------------------------
/*! \fn double printrow(void)
*   \brief  print the row class to cout
*/
void row::set_at(const int i, const int val) {
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
void row::set_label(const std::string& str){
  label = str;
}


//------------------------------------------------------------------------------
/*! \fn double printrow(void)
*   \brief  print the row class to cout
*/
void row::printrow(void)const {
  cout << label << endl;
  cout << "{ ";
  if (len>-1) {
    for (int i = 0; i < len; ++i) {
      cout<< this->at(i);
      if (i!=len)
        cout<< ", ";
     }
    cout << "}\n";
  }  else {
      throw ("Array not initized!");
  }
}
