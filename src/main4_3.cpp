#include <iostream>

void AusgabeMeinArray(int array[], int arrayLaenge)
{
  for (int i = 0; i < arrayLaenge; i++)
  {
    std::cout << "Das Array[" << i << "] hat den Wert " << array[i] << std::endl;
  }
}

float MeineSpezialBerechnung(float var1, float var2)
{
  int var_2 = var2 + 2;
  int resultat = var1 * var_2;

  return resultat;
}

bool CheckVariablen(int var1, int var2, int var3)
{
  bool ergebnis = false;

  if (var1 < var2 && var2 < var3)
  {
    ergebnis = true;
  }

  return ergebnis;
}

int main()
{
  // Challenge 1: Alle Werte eines Arrays ausgeben
  // Variablen
  int array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  // Funktionsaufruf
  AusgabeMeinArray(array, 10);

  // Challenge 2: Multiplikation zweier Variablen (2te Variable wird um 2 erhöht)
  // Variablen
  float var1 = 4.5;
  float var2 = 2.0;

  // Funktionsaufruf
  float resultat = MeineSpezialBerechnung(var1, var2);

  std::cout << "Resultat Challenge 2: " << resultat << std::endl;

  // Challenge 3: Überprüfe ob var1 < var2 und var2 < var3
  // Variablen
  int ch3_var1 = 1;
  int ch3_var2 = 2;
  int ch3_var3 = 3;
  int testvar1 = 0;
  int testvar2 = 0;
  int testvar3 = 0;

  // Funktionsaufruf 1: Ergebnis soll falsch sein
  testvar1 = ch3_var3;
  testvar2 = ch3_var2;
  testvar3 = ch3_var1;

  if (CheckVariablen(testvar1, testvar2, testvar3))
  {
    std::cout << "Variablen Check erfolgreich: " << testvar1 << " < " << testvar2 << " < " << testvar3 << std::endl;
  }
  else
  {
    std::cout << "Variablen Check nicht erfolgreich: " << testvar1 << " < " << testvar2 << " < " << testvar3 << std::endl;
  }

  // Funktionsaufruf 2: Ergebnis soll richtig sein
  testvar1 = ch3_var1;
  testvar2 = ch3_var2;
  testvar3 = ch3_var3;

  if (CheckVariablen(testvar1, testvar2, testvar3))
  {
    std::cout << "Variablen Check erfolgreich: " << testvar1 << " < " << testvar2 << " < " << testvar3 << std::endl;
  }
  else
  {
    std::cout << "Variablen Check nicht erfolgreich: " << testvar1 << " < " << testvar2 << " < " << testvar3 << std::endl;
  }

  return 0;
}