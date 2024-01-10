#include "BinomialTreeOption.h"

#include <sstream>     // 
#include <iostream>    // cout
#include <cmath>       // pow  

using namespace std;
using namespace OOP;

BinomialTreeOption::BinomialTreeOption(
  double sharePrice,
  double expiryTime,
  double strike,
  double volatility,
  double interestRate,
  int TreeLevel
) :
  mySharePrice(sharePrice),
  myExpiryTime(expiryTime),
  myStrike(strike),
  myVolatility(volatility),
  myInterestRate(interestRate),
  _n(TreeLevel) {
  mytstep = _n / myExpiryTime;
  _tree.reserve(_n);
  int level{ 0 };
  int num{ 0 };
  // initialization--------------------------------------------
  for (int i = 0; i < _n; i++) {
    // construct a vector of doubles with the given mySharePrice
    std::vector<Node> v;
    int sz = static_cast<int>(pow(2, i));
    v.reserve(sz);
    for (int j = 0; j < sz; j++) {
      Node a;
      a.num = num++; 
      a.t = static_cast<double>(i);
      a.optionvalue = 0.0;
      v.push_back(a);
    }
    // push back above one-dimensional vector
    _tree.push_back(v);
  }

  //end of initialization--------------------------------------------

   

  double A = 0.5 * ((exp(2 * myInterestRate + myVolatility * myVolatility) * mytstep) + exp(-myInterestRate * mytstep));
  double up = A + sqrt(A * A - 1);
  double down = A - sqrt(A * A - 1);
  double probability = (exp(myInterestRate * mytstep) - down) / (up - down);
  for (int j = _n; j >= 0; --j) {
      //int numLvl = static_cast<int>(_tree[j].size());
      for (int i = 0; i <= j; ++i) {
          _tree[j][i].Si = mySharePrice * pow(up, i) * pow(down, j - i);
      }
  }



}







BinomialTreeOption::~BinomialTreeOption() {

}

void BinomialTreeOption::print() const{
  int lvl = 0;
  int numtabs = static_cast<int>(pow(2, _n+2));

  for (const auto& i : _tree) {
    
    stringstream treeStream;
    for (const auto& j : i) { 
      treeStream << "["<< j.t << ":" << j.optionvalue<< "]";
    }
    vector<string> tabs_list;
    string tab = " ";
    for (int k = 0; k < static_cast<int>( (numtabs - (2 * lvl)-(treeStream.str().length()/2))); ++k) {
      tabs_list.push_back(tab);     //middle 
    }
    //middle 
    for (auto t : tabs_list)
      std::cout << t;

    std::cout << treeStream.str()<< std::endl;
    lvl++;
  }
}

double BinomialTreeOption::Result(){
  double discfactor = exp(-myInterestRate * mytstep);
  return _tree[0][0].optionvalue;
}
