#include <iostream>

int main()
{
  // Variable
  int meinArray[7] = {};

  std::cout << "Array[3] " << meinArray[3] << std::endl;

  meinArray[4] = -9;

  std::cout << "Array[3] " << meinArray[3] << " -- Array[4] " << meinArray[4] << std::endl;

  return 0;
}