#ifndef THIRDDEGREE_INCLUDED
#define THIRDDEGREE_INCLUDED

#include "ResoEquation.h"

/**
 * A simple class for 3rd degree resolution equation.
 *
 *
 */

template <typename T> class ThirdDegree : public ResoEquation<T> {
private:
  float a, b, c, d; // real coef. of the equation

public:
  std::vector<std::complex<float>> sol;

  ThirdDegree() {
    // std::cout << "ThirdDegree class constructor called." << std::endl;
  }
  ~ThirdDegree() {
    // std::cout << "ThirdDegree class destructor called." << std::endl;
  }

  inline T getSolution() { return solve(a, b, c, d); };

  inline std::vector<std::complex<float>> solve(float a, float b, float c,
                                                float d) {
    float zToX = -b / (3.f * a); // x = z - b/3a

    // resolution of: z^3 + p.z + q == 0
    float p = -b * b / (3.f * a * a) + c / a;
    float q = b / (27.f * a) * (2.f * b * b / (a * a) - 9.f * c / a) + d / a;

    // z = u+v  with  u^3+v^3=-q  and  u^3.v^3 = -p^3/27
    float delta2 = q * q + 4.f / 27.f * p * p * p;

    if (delta2 < 0) {
      float k1 = 2.f * std::sqrt(-p / 3.f);
      float ac =
          1.f / 3.f * std::acos(-q / 2.f * std::sqrt(27.f / (-p * p * p)));
      return {k1 * std::cos(ac) + zToX,
              k1 * std::cos(ac + float(2 * M_PI / 3)) + zToX,
              k1 * std::cos(ac + float(4 * M_PI / 3)) + zToX};
    }

    else if (delta2 > 0) { //  delta<0
      float u = std::cbrt(-q / 2.f - std::sqrt(delta2) / 2.f);
      float v = std::cbrt(-q / 2.f + std::sqrt(delta2) / 2.f);
      const std::complex<float> j = {-1.f / 2.f, std::sqrt(3.f) / 2.f};
      const std::complex<float> j2 = {-1.f / 2.f, -std::sqrt(3.f) / 2.f};

      return {u + v + zToX, u * j + v * j2 + zToX, u * j2 + v * j + zToX};
    }

    else if (p == 0 && q == 0) {
      return {zToX}; // triple solution
    }

    else {
      return {3.f * q / p + zToX, -3.f / 2.f * q / p + zToX};
    }
  };

  inline void initialize() {
    std::cout << "ax^3 + bx^2 + cx + d = 0" << std::endl;
    std::cout << ("a=") << std::endl;
    std::cin >> a;
    std::cout << ("b=") << std::endl;
    std::cin >> b;
    std::cout << ("c=") << std::endl;
    std::cin >> c;
    std::cout << ("d=") << std::endl;
    std::cin >> d;
  };

  inline void run() {
    sol = solve(a, b, c, d);
    printSolution();
  };

  inline void printSolution() {

    std::cout << "Equation: (" << a << ")x^3+(" << b << ")x^2+(" << c << ")x+("
              << d << ")=0 ";

    if (sol.size() == 1) {
      std::cout << "triple solution: " << sol[0].real() << std::endl;
    }

    else if (sol.size() == 3 && sol[2].imag() == 0) {
      std::cout << "three real solutions: " << sol[0].real() << " ; "
                << sol[1].real() << " et " << sol[2].real() << std::endl;
    }

    else if (sol.size() == 3) {
      std::cout << "two imaginary solutions: " << sol[1].real()
                << (sol[1].imag() < 0 ? "-" : "+") << std::abs(sol[1].imag())
                << "i and " << sol[2].real() << (sol[2].imag() < 0 ? "-" : "+")
                << std::abs(sol[2].imag())
                << "i, and one real solution: " << sol[0].real() << std::endl;
    }

    else if (sol.size() == 2) {
      std::cout << "two real solution, with one double: " << sol[1].real()
                << " et " << sol[0].real() << std::endl;
    }
  }
};

#endif
