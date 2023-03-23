// Copyright 2022 GHA Test Team
#pragma once
#include <iostream>
#include <string>
#include "windows.h"
using namespace std;

class Automata {
 public:
  enum State {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK

  };

 private:
  double cash;
  string *menu;
  int *prices;
  State state;
  int count_menu;

 public:
  Automata();
  void on();
  void off();
  void coin(int);
  void getMenu();
  State getState();
  void choice(int);
  void cancel();

 private:
  void check(int);
  void cook(int);
  void finish(int);
};
