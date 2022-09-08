// Mario's ideas
// Displaying cat image on 8x8 LED Matrix (Multiplexing)

// R0ws
#define R1 2
#define R2 3
#define R3 4
#define R4 5
#define R5 6
#define R6 7
#define R7 8
#define R8 9
//Columns
#define C1 10
#define C2 11
#define C3 12
#define C4 13
#define C5 A0
#define C6 A1
#define C7 A2
#define C8 A3
int pause = 2000; //in micros
int Matrix [8] [8] = {
  {0, 0, 0, 0, 1, 1, 1, 1},
  {0, 0, 0, 0, 1, 1, 1, 1},
  {0, 0, 0, 0, 1, 1, 1, 1},
  {0, 0, 0, 0, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0, 0},
};
//________________________________classes________________________________
class Button {
  private:
    bool buttonFlag; //0 when clicked, 1 when unpressed
    bool Reverse;// reverse read value
    int ReadValue;
    int Pin;
  public:
    bool CButton() {
      ReadValue = analogRead(Pin);
      if (Reverse) ReadValue = 1023 - ReadValue;
      if (buttonFlag && ReadValue < 5) {
        buttonFlag = 0;
        return 1;
      } else {
        if (ReadValue > 100) {
          buttonFlag = 1;
        }
        return 0;
      }
    }
    Button(int pin, bool reverse) {
      Pin = pin;
      Reverse = reverse;
    }
};
Button UpStick(18, 0);
Button DownStick(18, 1);
Button RightStick(19, 0);
Button LeftStick(19, 1);
void setup() {
  pinMode(1, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(R5, OUTPUT);
  pinMode(R6, OUTPUT);
  pinMode(R7, OUTPUT);
  pinMode(R8, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(C5, OUTPUT);
  pinMode(C6, OUTPUT);
  pinMode(C7, OUTPUT);
  pinMode(C8, OUTPUT);

  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, HIGH);
  digitalWrite(R5, HIGH);
  digitalWrite(R6, HIGH);
  digitalWrite(R7, HIGH);
  digitalWrite(R8, HIGH);
  digitalWrite(C1, LOW);
  digitalWrite(C2, LOW);
  digitalWrite(C3, LOW);
  digitalWrite(C4, LOW);
  digitalWrite(C5, LOW);
  digitalWrite(C6, LOW);
  digitalWrite(C7, LOW);
  digitalWrite(C8, LOW);
}



void SelectRow(int row) {
  if (row == 1) digitalWrite(R1, HIGH); else digitalWrite(R1, LOW);
  if (row == 2) digitalWrite(R2, HIGH); else digitalWrite(R2, LOW);
  if (row == 3) digitalWrite(R3, HIGH); else digitalWrite(R3, LOW);
  if (row == 4) digitalWrite(R4, HIGH); else digitalWrite(R4, LOW);
  if (row == 5) digitalWrite(R5, HIGH); else digitalWrite(R5, LOW);
  if (row == 6) digitalWrite(R6, HIGH); else digitalWrite(R6, LOW);
  if (row == 7) digitalWrite(R7, HIGH); else digitalWrite(R7, LOW);
  if (row == 8) digitalWrite(R8, HIGH); else digitalWrite(R8, LOW);
}

void Set_LED_in_Active_Row(int column, int state) {
  if (column == 1) digitalWrite(C1, !state);
  if (column == 2) digitalWrite(C2, !state);
  if (column == 3) digitalWrite(C3, !state);
  if (column == 4) digitalWrite(C4, !state);
  if (column == 5) digitalWrite(C5, !state);
  if (column == 6) digitalWrite(C6, !state);
  if (column == 7) digitalWrite(C7, !state);
  if (column == 8) digitalWrite(C8, !state);
}

void loop() {
  static int Cat1 [8] [8] = {
    {0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0},
  };
  static int Cat2 [8] [8] = {
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1},
  };
  static int Cat3 [8] [8] = {
    {0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 1, 0},
    {1, 0, 0, 0, 0, 0, 1, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0},
  };
  static int Cat4 [8] [8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
  };
  static int Cat5 [8] [8] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
  };
  if (UpStick.CButton())for (int i = 0; i < 8; i++)for (int j = 0; j < 8; j++)Matrix[i][j] = Cat1[i][j]; else if (DownStick.CButton()) for (int i = 0; i < 8; i++)for (int j = 0; j < 8; j++)Matrix[i][j] = Cat2[i][j]; else if (RightStick.CButton()) for (int i = 0; i < 8; i++)for (int j = 0; j < 8; j++)Matrix[i][j] = Cat4[i][j]; else if (LeftStick.CButton()) for (int i = 0; i < 8; i++)for (int j = 0; j < 8; j++)Matrix[i][j] = Cat5[i][j]; else for (int i = 0; i < 8; i++)for (int j = 0; j < 8; j++)Matrix[i][j] = Cat3[i][j];
  for (int j = 0; j < 8; j++) {
    SelectRow(j + 1);
    for (int i = 0; i < 8; i++) {
      Set_LED_in_Active_Row(i + 1 , Matrix[j][i]);

    }
    delayMicroseconds(pause);
  }
}
