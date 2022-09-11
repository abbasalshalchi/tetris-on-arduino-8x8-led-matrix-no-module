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
//____________________________________________variables____________________________________________
int FrameFlag;
/*const*/ int FrameFlagLimit = 5;
int pause = 2000; //in micros
bool Matrix [8] [8] = {
  {0, 0, 0, 0, 1, 1, 1, 1},
  {0, 0, 0, 0, 1, 1, 1, 1},
  {0, 0, 0, 0, 1, 1, 1, 1},
  {0, 0, 0, 0, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0, 0},
};
bool blockmapout[4][4] = {
  {1, 1, 1, 1},
  {1, 1, 1, 1},
  {1, 1, 1, 1},
  {1, 1, 1, 1},
};
void Clear() {               //clearer
  for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) Matrix[i][j] = 0; //clearer for pixels
}
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
      if (buttonFlag && ReadValue < 40) {
        buttonFlag = 0;
        return 1;
      } else {
        if (ReadValue > 30) {
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
class Block {
  private:
    bool BlockMap[4][4];
    unsigned short Px;
    unsigned short Py;
  public:
    void SetBlockMap(bool blockMap[4][4]) {
      for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++)BlockMap[i][j] = blockMap[i][j];
    }
    void DownShow() {

    }
    void LeftShow() {
      if(Px > 0)Px--;
      StillShow();
    }
    void RightShow() {
      if(Px < 4)Px++;
      StillShow();
    }
    void SpinShow() {

    }
    void StillShow() {
      for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++)Matrix[i + Py][j + Px] = BlockMap[i][j];
    }
    Block(bool blockMap[4][4]) {
      for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++)BlockMap[i][j] = blockMap[i][j];
    }
};
Button UpStick(18, 0);
Button DownStick(18, 1);
Button RightStick(19, 1);
Button LeftStick(19, 0);
Block block(blockmapout);
void setup() {
  FrameFlag = 0;
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
//    3
//  2    1
//    4
void loop() {
  static short BHolder = 0;
  Clear();
  if (FrameFlag < FrameFlagLimit) {
    //__________________________________________________still shows__________________________________________________
    FrameFlag++;
    block.StillShow();
    if (BHolder == 0) {
      if (RightStick.CButton())BHolder = 1; else if (LeftStick.CButton())BHolder = 2;
    }
  } else {
    FrameFlag = 0;
    //frame show
    if (RightStick.CButton() || BHolder == 1) {
      block.RightShow();
      BHolder = 0;
    }else if (LeftStick.CButton() || BHolder == 2) {
      block.LeftShow();
      BHolder = 0;
    }
    //frame show
  }
  for (int j = 0; j < 8; j++) {
    SelectRow(j + 1);
    for (int i = 0; i < 8; i++) {
      Set_LED_in_Active_Row(i + 1 , Matrix[j][i]);

    }
    delayMicroseconds(pause);
  }
}
