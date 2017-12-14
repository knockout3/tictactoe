int turn = 0;
int tictactoe[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int x;
int play;
int b;
int r;

void setup() {
  Serial.begin(9600);
  for (int i = 22; i < 41; i += 2) {
    pinMode(i, OUTPUT);
  }
  for (int j = 23; j < 42; j += 2) {
    pinMode(j, OUTPUT);
  }
}

void loop() {
  if (turn == 0) {
    redTurn();
    checkWin();
    turn = 1;
  }

  if (turn == 1) {
    blueTurn();
    checkWin();
    turn = 0;
  }
}

void redTurn() {
  digitalWrite(41, 0);
  digitalWrite(40, 1);
  Serial.println("It is red's turn");
  x = 0;
  while (x == 0) {
    while (Serial.available() == 0);
    int play = Serial.read() - 48;
    if (tictactoe[play - 1] == 0) {
      tictactoe[play - 1] = 1;
      digitalWrite((20 + 2 * play), 1);
      x = 1;
    } else {
      Serial.println("Choose a different spot to play");
    }
  }
}

void blueTurn() {
  digitalWrite(40, 0);
  digitalWrite(41, 1);
  Serial.println("It is blue's turn");
  x = 0;
  while (x == 0) {
    while (Serial.available() == 0);
    int play = Serial.read() - 48;
    if (tictactoe[play - 1] == 0) {
      tictactoe[play - 1] = 2;
      digitalWrite((21 + 2 * play), 1);
      x = 1;
    } else {
      Serial.println("Choose a different spot to play");
    }
  }
}

void checkWin() {
  if ((tictactoe[0] == 1 && tictactoe[1] == 1 && tictactoe[2] == 1) ||
      (tictactoe[3] == 1 && tictactoe[4] == 1 && tictactoe[5] == 1) ||
      (tictactoe[6] == 1 && tictactoe[7] == 1 && tictactoe[8] == 1) ||
      (tictactoe[0] == 1 && tictactoe[3] == 1 && tictactoe[6] == 1) ||
      (tictactoe[1] == 1 && tictactoe[4] == 1 && tictactoe[7] == 1) ||
      (tictactoe[2] == 1 && tictactoe[5] == 1 && tictactoe[8] == 1) ||
      (tictactoe[0] == 1 && tictactoe[4] == 1 && tictactoe[8] == 1) ||
      (tictactoe[2] == 1 && tictactoe[4] == 1 && tictactoe[6] == 1)) {
    redWin();
  }
  else if ((tictactoe[0] == 2 && tictactoe[1] == 2 && tictactoe[2] == 2) ||
           (tictactoe[3] == 2 && tictactoe[4] == 2 && tictactoe[5] == 2) ||
           (tictactoe[6] == 2 && tictactoe[7] == 2 && tictactoe[8] == 2) ||
           (tictactoe[0] == 2 && tictactoe[3] == 2 && tictactoe[6] == 2) ||
           (tictactoe[1] == 2 && tictactoe[4] == 2 && tictactoe[7] == 2) ||
           (tictactoe[2] == 2 && tictactoe[5] == 2 && tictactoe[8] == 2) ||
           (tictactoe[0] == 2 && tictactoe[4] == 2 && tictactoe[8] == 2) ||
           (tictactoe[2] == 2 && tictactoe[4] == 2 && tictactoe[6] == 2)) {
    blueWin();
  } else if (tictactoe[0] != 0 && tictactoe[1] != 0 && tictactoe[2] != 0 &&
             tictactoe[3] != 0 && tictactoe[4] != 0 && tictactoe[5] != 0 &&
             tictactoe[6] != 0 && tictactoe[7] != 0 && tictactoe[8] != 0) {
    noWinner();
  }
}

void redWin() {
  Serial.println("Red wins!");
  delay(2000);
  for (b = 23; b < 40; b += 2) {
    digitalWrite(b, 0);
  }
  for (x = 0; x < 3; x++) {
    for (int r = 22; r < 39; r += 2) {
      digitalWrite(r, 1);
    }
    delay (500);
    for (r = 22; r < 39; r += 2) {
      digitalWrite(r, 0);
    }
    delay(500);
  }
  resetAll();
}

void blueWin() {
  Serial.println("Blue wins!");
  delay(2000);
  for (r = 22; r < 39; r += 2) {
    digitalWrite(r, 0);
  }
  for (x = 0; x < 3; x++) {
    for (int b = 23; b < 40; b += 2) {
      digitalWrite(b, 1);
    }
    delay (500);
    for (b = 23; b < 40; b += 2) {
      digitalWrite(b, 0);
    }
    delay(500);
  }
  resetAll();
}

void noWinner() {
  Serial.println("No winner");
  delay(2000);
  for (x = 0; x < 3; x++) {
    for (r = 22; r < 40; r++) {
      digitalWrite(r, 0);
    }
    delay(500);
    for (r = 22; r < 40; r++) {
      digitalWrite(r, 1);
    }
    delay(500);
  }
  resetAll();
}

void resetAll() {
  for (r = 22; r < 40; r++) {
    digitalWrite(r, 0);
  }
  for (int i = 0; i < 9; i++) {
    tictactoe[i] = 0;
  }
}
