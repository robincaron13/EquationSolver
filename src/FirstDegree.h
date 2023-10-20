#ifndef FIRSTDEGREE_INCLUDED
#define FIRSTDEGREE_INCLUDED

#include "ResoEquation.h"

/**
 * A simple class for 1st degree resolution equation.
 *
 *
 */

template <typename T> class FirstDegree : public ResoEquation<T> {
private:
  float a, b; // real coef. of the equation
  float x0;   // unique solution of y=0

public:
  FirstDegree() = default;
  ~FirstDegree() = default;

  inline float solve(float a, float b) { return -b / a; }

  T getSolution() { return solve(a, b); };

  inline void initialize() {
    std::cout << "Finding solutions of a first degree equation ";
    std::cout << std::endl;
    std::cout << "Equation is: ax + b = 0, with a,b reals." << std::endl;
    std::cout << std::endl;
    std::cout << "Enter the value of a: ";
    std::cin >> a;
    std::cout << "Enter the value of b: ";
    std::cin >> b;
  };

  inline void run() {
    x0 = solve(a, b);
    printSolution();
  };

  inline void printSolution() {
    std::cout << "Equation: " << a << "x+" << b << "=0  has ";

    if (a != 0) {
      std::cout << "one real solution: " << x0 << std::endl;
    } else {
      std::cout << "Function is constant, y=" << b << std::endl;
    }
  }
};

#endif
