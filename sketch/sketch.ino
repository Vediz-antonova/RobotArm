#include <Servo.h>
#include <StaticSerialCommands.h>

Servo sAlpha;
Servo sBeta;
Servo sBetaUp;
bool penDown;
float alpha;
float beta;

void setServo(Servo &servo, float angle) {
  float microSeconds = 1856.0 * angle / 180 + 544;
  servo.writeMicroseconds(microSeconds);
}

void setAlpha(float angle) {
  setServo(sAlpha, angle);
  alpha = angle;
}

float getPenUpBetaModifier(float angle) {
  if (penDown) {
    return 0;
  }

  if (angle <= 40) {
    return 12.0;
  }

  if (angle <= 50) {
    return 16.0;
  }

  if (angle <= 60) {
    return 20.0;
  }

  return 28.0;
}

void setBeta(float angle) {
  float revAngle = 180.0 - angle;
  float betaModifier = getPenUpBetaModifier(angle);

  setServo(sBeta, revAngle - betaModifier);
  setServo(sBetaUp, revAngle + betaModifier);
  beta = angle;
}

void setPen(bool isDown) {
  penDown = isDown;
  setBeta(beta);
}

void cmd_help(SerialCommands& sender, Args& args) {
  sender.listCommands();
}

void cmd_pen(SerialCommands& sender, Args& args) {
  int isDown = args[0].getInt();
  setPen(isDown);
}

void cmd_alpha(SerialCommands& sender, Args& args) {
  float angle = args[0].getFloat();
  setAlpha(angle);
}

void cmd_beta(SerialCommands& sender, Args& args) {
  float angle = args[0].getFloat();
  setBeta(angle);
}

void cmd_delay(SerialCommands& sender, Args& args) {
  int delay_number = args[0].getInt();
  delay(delay_number);
}

Command commands[] {
  COMMAND(cmd_help, "help", NULL, "list commands"),
  COMMAND(cmd_pen, "p", ARG(ArgType::Int, 0, 1, "isDown"), NULL, "Set pen up or down. 1 for down."),
  COMMAND(cmd_alpha, "a", ARG(ArgType::Float, 60, 120, "angle"), NULL, "Set alpha angle. 60 <= alpha <= 120"),
  COMMAND(cmd_beta, "b", ARG(ArgType::Float, 20, 70, "angle"), NULL, "Set beta angle. 20 <= beta <= 70"),
  COMMAND(cmd_delay, "d", ARG(ArgType::Int, 0, 3000, "delay_number"), NULL, "Set delay. 0 <= delay_number <= 3000"),
};

SerialCommands serialCommands(Serial, commands, sizeof(commands) / sizeof(Command));

void setup() {
  sAlpha.attach(9);
  sBeta.attach(10);
  sBetaUp.attach(11);

  Serial.begin(9600);

  penDown = false;
  setAlpha(90);
  setBeta(70);
  delay(1000);
}

void loop() {
  serialCommands.readSerial();
  return;
}