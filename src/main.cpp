// Copyright 2022 GHA Test Team
#include <iostream>
#include <string>
#include "Automata.h"
int main() {
  setlocale(LC_ALL, "Russian");
  Automata p;
  p.getMenu();
  p.on();
  p.coin(200);
  p.choice(2);
}
