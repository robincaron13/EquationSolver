#include <chrono>
#include <thread>

#include "FirstDegree.h"
#include "ResoEquation.h"
#include "SecondDegree.h"
#include "ThirdDegree.h"

using namespace std;

int main() {
  FirstDegree<float> eq1;
  eq1.ResoEquation::checkAccess();
  eq1.initialize();
  eq1.run();

  SecondDegree<std::vector<std::complex<float>>> eq2;
  eq2.initialize();
  eq2.run();

  ThirdDegree<std::vector<std::complex<float>>> eq3;
  eq3.initialize();
  eq3.run();

  return 0;
}
