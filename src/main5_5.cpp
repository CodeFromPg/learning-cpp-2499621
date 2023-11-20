#include <iostream>
#include <cstdlib>
#include <ctime>

int benutzerEingabeSpiel(int anzMaxVersuche)
{
  int benutzer_Wahl = 0;
  int anzVersuch = 0;

  while (!(benutzer_Wahl >= 1 && benutzer_Wahl <= 3)) // && anzVersuch < anzMaxVersuche)
  {
    // Verlasse Schleife, wenn maximale Versuche überschritten
    if (anzVersuch > anzMaxVersuche)
    {
      break;
    }

    // Ausgabe ungültige Eingabe
    if (anzVersuch > 0)
    {
      std::cout << "Ungültige Eingabe " << anzVersuch << " von " << anzMaxVersuche << "!" << std::endl;
      std::cout << "Gib dir Mühe und versuche es nochmal!" << std::endl;
      benutzer_Wahl = 0;
    }

    // Ausgabe wähle
    std::cout << "Wähle Schere(1), Stein(2) oder Papier(3) aus!" << std::endl;
    std::cout << "Deine Wahl: ";
    std::cin >> benutzer_Wahl;

    // Versuchszahl erhöhen
    anzVersuch++;
  }

  if (anzVersuch >= anzMaxVersuche)
  {
    std::cout << "Ungültige Eingabe " << anzVersuch << " von " << anzMaxVersuche << "!" << std::endl;
    std::cout << "Eingabe war zu oft falsch! Spiel wird nicht ausgeführt!" << std::endl;
    return -1;
  }
  else
  {
    return benutzer_Wahl;
  }
}

int computerWahlSpiel()
{
  std::srand(std::time(0));
  int computer_Wahl = std::rand() % 3 + 1;

  return computer_Wahl;
}

void ausgabeWahl(bool user, int wahl)
{
  if (user == true) // Benutzer
  {
    switch (wahl)
    {
    case 1:
      std::cout << "Du hast Schere gewählt!" << std::endl;
      break;
    case 2:
      std::cout << "Du hast Stein gewählt!" << std::endl;
      break;
    case 3:
      std::cout << "Du hast Papier gewählt!" << std::endl;
      break;

    default:
      std::cout << "Fehler!" << std::endl;
      break;
    }
  }
  else // Computer
  {
    switch (wahl)
    {
    case 1:
      std::cout << "Der Computer hat Schere gewählt!" << std::endl;
      break;
    case 2:
      std::cout << "Der Computer hat Stein gewählt!" << std::endl;
      break;
    case 3:
      std::cout << "Der Computer hat Papier gewählt!" << std::endl;
      break;

    default:
      std::cout << "Fehler!" << std::endl;
      break;
    }
  }
}

void auswertungSpiel(int benutzer, int computer)
{
  if (benutzer == computer)
  {
    std::cout << "Unentschieden!" << std::endl;
  }
  else if (benutzer == (computer + 1) || (benutzer + 2) == computer)
  {
    std::cout << "Du gewinnst!" << std::endl;
  }
  else
  {
    std::cout << "Du verlierst!" << std::endl;
  }
}

int main()
{
  // Variablen
  int benutzerWahl = 0;
  int computerWahl = 0;

  // Spiel so lange spielen, bis Spieler abbricht
  while (true)
  {
    // Spielablauf
    std::cout << "Herzlich Willkommen zum Schere/Stein/Papier Spiel gegen deinen Computer." << std::endl;
    benutzerWahl = benutzerEingabeSpiel(3);

    if (benutzerWahl != -1)
    {
      computerWahl = computerWahlSpiel();
      ausgabeWahl(true, benutzerWahl);
      ausgabeWahl(false, computerWahl);
      auswertungSpiel(benutzerWahl, computerWahl);
    }

    std::cout << "Nochmal spielen? Mit 2+ENTER beenden" << std::endl;
    std::cout << "Deine Wahl: ";
    std::cin >> benutzerWahl;

    if (benutzerWahl == 2)
    {
      break;
    }
  }

  std::cout << "Spiel beendet. Vielen Dank!" << std::endl;

  return 0;
}