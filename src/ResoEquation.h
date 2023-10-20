#ifndef RESOEQUATION_INCLUDED
#define RESOEQUATION_INCLUDED

#define _USE_MATH_DEFINES

#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <vector>

/**
 * A simple class for resolution equation.
 *
 *
 */

template <typename T> class ResoEquation {
private:
  int _max_size;
  int _max_time;

protected:
  std::string name;
  int nparameters;
  T solution;

public:
  ResoEquation() {
    // std::cout << "ResoEquation class constructor called." << std::endl;
  }
  ~ResoEquation() {
    // std::cout << "ResoEquation class destructor called." << std::endl;
  }

  void setMaxParSize(int size) { _max_size = size; };
  void setMaxTime(int time) { _max_time = time; };

  inline void checkAccess() {
    std::cout << "Dear, how old are you?" << std::endl;
    try {
      int age;
      std::cin >> age;
      if (age >= 18) {
        std::cout << "Access granted - you are old enough." << std::endl;
      } else {
        throw(age);
      }
    } catch (int myNum) {
      std::cout << "Access denied - You must be at least 18 years old.\n"
                << std::endl;
      std::cout << "Age is: " << myNum;
    }
  };
};

#endif
