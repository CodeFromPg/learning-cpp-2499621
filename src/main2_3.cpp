#include <iostream>

int main()
{
  // Variablen anlegen
  float meineErsteFloatVariable = 4.3;
  float meineZweiteFloatVariable = -2.8;
  float meinFloatErgebnis = meineErsteFloatVariable + meineZweiteFloatVariable;
  double meineErsteDoubleVariable = 4.3;
  double meineZweiteDoubleVariable = -2.8;
  double meinDoubleErgebnis = meineErsteDoubleVariable + meineZweiteDoubleVariable;

  // Ausgabe
  std::cout << "Float Ergebnis: " << meinFloatErgebnis << std::endl;
  std::cout << "Double Ergebnis: " << meinDoubleErgebnis << std::endl;

  return 0;
}