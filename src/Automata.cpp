// Copyright 2022 GHA Test Team
#include "Automata.h"
Automata::Automata() {
  count_menu = 3;
  menu = new string[count_menu]{"Чай", "Кофе с молоком", "Какао"};
  prices = new int[count_menu]{30, 50, 45};
  state = OFF;
  cash = 0;
}
void Automata::on() {
  if (state == OFF) state = WAIT;
}
void Automata::off() {
  if (state == WAIT) state = OFF;
}
void Automata::coin(int sum) {
  if (state == WAIT || state == ACCEPT) {
    state = ACCEPT;
    cash = cash + sum;
  }
}
void Automata::getMenu() {
  for (int i = 0; i < count_menu; i++) {
    cout << i + 1 << "  " << menu[i] << " " << prices[i] << "\n";
  }
}
Automata::State Automata::getState() { return state; }
void Automata::choice(int num) {
  if (state == ACCEPT) {
    if (num < 1 || num > count_menu) {
      cout << "Неправильно выбран напиток\n";
    } else {
      state = CHECK;
      check(num);
    }
  }
}
void Automata::check(int num) {
  state = CHECK;
  if (cash < prices[num - 1]) {
    cout << "Недостаточно денег\n";
    state = WAIT;
  } else {
    cook(num);
  }
}
void Automata::cancel() {
  if (state == ACCEPT || state == CHECK) state = WAIT;
}
void Automata::cook(int num) {
  state = COOK;
  cout << "Приготовление напитка...\n";
  switch (num) {
    case 1:
      Sleep(5000);
    case 2:
      Sleep(8000);
    case 3:
      Sleep(10000);
  }
  finish(cash - prices[num - 1]);
}
void Automata::finish(int s) {
  cout << "Напиток готов\n";
  if (s > 0) cout << "Сдача: " << s << "\n";
  state = WAIT;
}
