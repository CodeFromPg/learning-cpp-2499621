#include <iostream>

char zeichenErmittlung(int wert)
{
  if (wert == 0)
  {
    return ' ';
  }
  else if (wert == 1)
  {
    return 'X';
  }
  else if (wert == 2)
  {
    return 'O';
  }
  else
  {
    return '?';
  }
}

void ausgabeSpielfeldHilfe()
{
  std::cout << std::endl;
  std::cout << "7 | 8 | 9" << std::endl;
  std::cout << "--+---+--" << std::endl;
  std::cout << "4 | 5 | 6" << std::endl;
  std::cout << "--+---+--" << std::endl;
  std::cout << "1 | 2 | 3" << std::endl;
  std::cout << std::endl;
}

void ausgabeSpielfeld(int array[])
{
  std::cout << std::endl;
  std::cout << zeichenErmittlung(array[7]) << " | " << zeichenErmittlung(array[8]) << " | " << zeichenErmittlung(array[9]) << std::endl;
  std::cout << "--+---+--" << std::endl;
  std::cout << zeichenErmittlung(array[4]) << " | " << zeichenErmittlung(array[5]) << " | " << zeichenErmittlung(array[6]) << std::endl;
  std::cout << "--+---+--" << std::endl;
  std::cout << zeichenErmittlung(array[1]) << " | " << zeichenErmittlung(array[2]) << " | " << zeichenErmittlung(array[3]) << std::endl;
  std::cout << std::endl;
}

void spielerSpielzug(int spieler, int array[]) // spieler = 1 => Spieler 1
{
  int zugSpieler = 0;
  bool zugAktiv = true;

  while (zugAktiv)
  {
    std::cout << "Spieler " << spieler << " dein Zug!" << std::endl;
    // std::cout << "Gib dein Feld ein, Felder sind nummeriert von 0-8, beginnend links oben!" << std::endl;
    std::cout << "Spieler " << spieler << " was ist dein Zug(1-9)? ";
    std::cin >> zugSpieler;

    // Plausibilitätsabfrage
    if (zugSpieler >= 1 && zugSpieler <= 9)
    {
      if (array[zugSpieler] == 0)
      {
        array[zugSpieler] = spieler;
        zugAktiv = false;
      }
      else
      {
        std::cout << std::endl;
        std::cout << "Spieler " << spieler << " dein Zug ist ungültig! Das Feld wurde schon von deinem Gegenspieler besetzt! Wähle ein anderes!" << std::endl;
        ausgabeSpielfeld(array);
      }
    }
    else
    {
      std::cout << std::endl;
      std::cout << "Spieler " << spieler << " dein Zug ist ungültig! Wähle eine Nummer zwischen 1-9. Siehe das folgende Feld zur Hilfe" << std::endl;
      ausgabeSpielfeldHilfe();
    }
  }
}

int gewinnAbfrage(int array[])
{
  int gewinner = 0; // 0=spiel aktiv, 1=spieler1, 2=spieler2, 100 = unentschieden

  for (int i = 1; i <= 2; i++)
  {
    if ((array[7] == i && array[8] == i && array[9] == i) ||
        (array[4] == i && array[5] == i && array[6] == i) ||
        (array[1] == i && array[2] == i && array[3] == i) ||
        // Abfrage horizontal
        (array[7] == i && array[4] == i && array[1] == i) ||
        (array[8] == i && array[5] == i && array[2] == i) ||
        (array[9] == i && array[6] == i && array[3] == i) ||
        // Abfrage vertikal
        (array[7] == i && array[5] == i && array[3] == i) ||
        (array[9] == i && array[5] == i && array[1] == i))
    {
      gewinner = i;
      break; // Es gibt einen Gewinner
    }
  }

  if (gewinner == 0 &&
      array[1] != 0 &&
      array[2] != 0 &&
      array[3] != 0 &&
      array[4] != 0 &&
      array[5] != 0 &&
      array[6] != 0 &&
      array[7] != 0 &&
      array[8] != 0 &&
      array[9] != 0)
  {
    gewinner = 100;
  }

  return gewinner;
}

// Challenge Tic Tac Toe Spiel
int main()
{
  // Variablen
  int array[10] = {};
  bool gameAktiv = true;
  int spielerAktiv = 0;

  // Spielablauf
  std::cout << "Herzlich Willkommen zu Tic Tac Toe!" << std::endl;
  std::cout << std::endl;
  std::cout << "Spielanleitung: Der aktive Spieler muss ein freies Feld auswählen (1-9). Siehe Spielfeld darunter!" << std::endl;
  ausgabeSpielfeldHilfe();
  std::cout << "Spielanleitung: Hat ein Spieler drei in einer Reihe gewinnt dieser!" << std::endl;
  std::cout << "Viel Spaß!" << std::endl;
  std::cout << std::endl;
  std::cout << "Lasst das Spiel beginnen!" << std::endl;

  // Spieler 1 beginnt immer
  spielerAktiv = 1;

  while (gameAktiv)
  {
    ausgabeSpielfeld(array);
    spielerSpielzug(spielerAktiv, array);
    // std::cout << "\x1B[2J\x1B[H"; // Konsole ablöschen
    int ergebnis = gewinnAbfrage(array);

    if (ergebnis != 0)
    {
      if (ergebnis == 100)
      {
        std::cout << std::endl;
        std::cout << "Unentschieden!" << std::endl;
        ausgabeSpielfeld(array);
        std::cout << "Vielen Dank fürs Spielen!" << std::endl;
        gameAktiv = false;
      }
      else if (ergebnis == 1 || ergebnis == 2)
      {
        std::cout << std::endl;
        std::cout << "Herzlichen Glückwunsch Spieler " << ergebnis << ", du hast gewonnen!" << std::endl;
        ausgabeSpielfeld(array);
        std::cout << "Vielen Dank fürs Spielen!" << std::endl;
        gameAktiv = false;
      }
    }
    else if (spielerAktiv == 1)
    {
      spielerAktiv = 2;
    }
    else
    {
      spielerAktiv = 1;
    }
  }

  return 0;
}