#ifndef SECONDDEGREE_INCLUDED
#define SECONDDEGREE_INCLUDED

#include "ResoEquation.h"

/**
 * A simple class for 2nd degree resolution equation.
 *
 *
 */

template <typename T> class SecondDegree : public ResoEquation<T> {
private:
  float a, b, c; // real coef. of the equation

public:
  std::vector<std::complex<float>> sol;

  SecondDegree() = default;
  ~SecondDegree() = default;

  inline T getSolution() { return solve(a, b, c); };

  inline std::vector<std::complex<float>> solve(float a, float b, float c) {
    float delta = b * b - 4.f * a * c;
    float solution1 = -b / (2.f * a);

    if (delta < 0) {
      float solutionPartielle = sqrt(-delta) / (2.f * a);
      return {{solution1, solutionPartielle}, {solution1, -solutionPartielle}};
    } else if (delta == 0) {
      return {{solution1}};
    } else {
      float solutionPartielle = sqrt(delta) / (2.f * a);
      return {{solution1 - solutionPartielle}, {solution1 + solutionPartielle}};
    }
  }

  inline void initialize() {
    std::cout << "Finding solutions of a second degree equation ";
    std::cout << std::endl;
    std::cout << "Equation is: ax**2 + bx + c = 0, with a,b and c reals."
              << std::endl;
    std::cout << std::endl;
    std::cout << "a= ";
    std::cin >> a;
    std::cout << "b= ";
    std::cin >> b;
    std::cout << "c= ";
    std::cin >> c;
  };

  inline void run() {
    sol = solve(a, b, c);
    printSolution();
  };

  inline void printSolution() {
    std::cout << "Equation: " << a << "x^2+" << b << "x+" << c << "=0  has ";

    if (sol[0].imag()) {
      std::cout << "two imaginary complex solutions: " << sol.front().real()
                << "-" << sol.front().imag() << "i and " << sol.front().real()
                << "+" << sol.front().imag() << "i" << std::endl;
    }

    else if (sol.size() == 1) {
      std::cout << "one real solution: " << sol.front().real() << std::endl;
    }

    else {
      std::cout << "two real solutions: " << sol.front().real() << " and "
                << sol.back().real() << std::endl;
    }

    //    if (a == 0)  std::cout << "Erreur ! Votre equation n'est pas du second
    //    degre." <<  std::endl; else
    //    {
    //        delta = b*b - 4*a*c;
    //        if (delta < 0){
    //            std::cout << "No real solution:" <<  std::endl;
    //            x0 = -b/(2*a);
    //            std::complex<double> z1(x0, sqrt(-delta)/(2*a));
    //            std::complex<double> z2(x0, -sqrt(-delta)/(2*a));
    //
    //             std::cout << "Two imaginary solutions." <<  std::endl;
    //             std::cout << "First solution : " << z1 <<  std::endl;
    //             std::cout << "Second solution : " << z2 <<  std::endl;
    //        }
    //        else if (delta == 0)
    //        {
    //            x0 = -b/(2*a);
    //             std::cout << "One real solution : " << x0 <<  std::endl;
    //        }
    //        else // Case where delta > 0
    //        {
    //            x1 = (-b+ sqrt(delta))/(2*a);
    //            x2 = (-b- sqrt(delta))/(2*a);
    //
    //             std::cout << "Two real solutions." <<  std::endl;
    //             std::cout << "First real solution : " << x1 <<  std::endl;
    //             std::cout << "Second real solution : " << x2 <<  std::endl;
    //        }
    //    }
  }
};

#endif
