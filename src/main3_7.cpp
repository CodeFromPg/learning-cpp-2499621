#include <iostream>

int main()
{
  // Challenge 1
  std::cout << "- Challenge 1 -" << std::endl;

  // Variablen
  int intArray[5] = {};
  int AnzGroesser6 = 0;

  // Aufgabe: Array[x] = x*3; Zähle wie viele Array-Indexe >= 6
  for (int i = 0; i < 5; i++) 
  {
    intArray[i] = i * 3;

    if (intArray[i] >= 6) {
      AnzGroesser6++;
    }

    // Ausgabe Array-Index-Wert
    std::cout << "Array[" << i << "] hat den Wert: " << intArray[i] << std::endl;
  }

  // Ausgabe Ergebnis
  std::cout << "Es sind " << AnzGroesser6 << " >= dem Wert 6" << std::endl;

  // Challenge 2
  std::cout << "- Challenge 2 -" << std::endl;

  // Variablen
  int var1 = 10;
  int var2 = 2;

  // Aufgabe: var1 um 1 erhöhen, var2 um 2 erhöhen, solange bis var2 > var1 ist
  while (var1 >= var2)
  {
    var1++;
    var2 = var2 + 2;
  }

  // Ausgabe
  std::cout << "Variabel 2 mit dem Wert " << var2 << " hat die Variable 1 mit dem Wert " << var1 << " überholt" << std::endl;

  return 0;
}