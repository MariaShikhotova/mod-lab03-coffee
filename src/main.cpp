#include <iostream>
#include <string>
#include "windows.h"
#include "Automata.h"
using namespace std;
int main() {
  setlocale(LC_ALL, "Russian");
  Automata p;
  p.getMenu();
  p.on();
  p.coin(200);
  p.choice(2);
}
