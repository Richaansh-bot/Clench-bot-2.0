class BTS {
public:
  uint8_t rpwm, lpwm;
  uint8_t ren, len;

  void init(uint8_t rpwm, uint8_t lpwm, uint8_t ren, uint8_t len) {
    this->lpwm = lpwm;
    this->rpwm = rpwm;
    this->ren = ren;
    this->len = len;
    pinMode(rpwm, OUTPUT);
    pinMode(lpwm, OUTPUT);
    pinMode(ren, OUTPUT);
    pinMode(len, OUTPUT);

    digitalWrite(ren, HIGH);
    digitalWrite(len, HIGH);

    delay(500);

    analogWrite(rpwm, 0);
    analogWrite(lpwm, 0);
    
  }

  void rotate(int speed, int dir)
  {


    int pwm_val = map(speed, 950, 2000, -255, 255);
    pwm_val = min(pwm_val, 255);
    pwm_val = max(pwm_val, -255);
    if(dir<0) pwm_val = -pwm_val;
    if(speed>2500 or speed<500)
      pwm_val = 0;
    if(pwm_val > 0){
      analogWrite(rpwm, pwm_val);
      analogWrite(lpwm, 0);
    }
    else{
      analogWrite(rpwm, 0);
      analogWrite(lpwm, -pwm_val);
    }
  }
};

class FS_I6{
public:
  uint8_t channels[6];
  int vals[6];

  void init(uint8_t ch[]) {
    for (int i = 0; i < 6; i++) {
      channels[i] = ch[i];
      pinMode(channels[i], INPUT);
    }
  }

  void read() {
    for (int i = 0; i < 6; i++)
      vals[i] = pulseIn(channels[i], HIGH, 30000);
  }

  void print(int i) {
    Serial.println(vals[i]);
  }
};


BTS left_w, right_w;

FS_I6 remote;


void setup() {
  Serial.begin(9600);
\
  // define left and right bts and remote
  left_w.init(2, 3, 4, 5);
  right_w.init(8, 9, 10, 11);

  uint8_t chpins[] = {12, 13, 6, 7, 20, 21};
  remote.init(chpins);


  // end



}


void loop() {

  remote.read();

  right_w.rotate(remote.vals[0], 1);
  left_w.rotate(remote.vals[1], -1);
  
}
