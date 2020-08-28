// See this for reference: https://www.instructables.com/id/Arduino-Self-Balancing-Robot-1/

#include "Wire.h"
#include "MPU6050.h"
#include "math.h"

#define HIST_BITS 4
#define HIST_SIZE 1<<HIST_BITS
#define PREV_ERR (errorHistory[errorHistoryLast & (HIST_SIZE-1)])

#define PID_P 0.001
#define PID_I 0.0001
#define PID_D 0.0001

float errorHistory[HIST_SIZE];
int errorHistoryLast;
MPU6050 imu; // Intertial measurement unit

void setup() {
  // initialization and calibration of all systems
  for (int i=0; i<HIST_SIZE; ++i) {
    errorHistory[i] = 0.0;
  }
  errorHistoryLast = 0;
}

float getError() {
  return 0.0;
}

void applyOutput(float output) {
  
}

void loop() {
  float errorPrev = errorHistory[errorHistoryLast];
  errorHistoryLast = (errorHistoryLast + 1) & (HIST_SIZE - 1);
  float errorCurrent = getError();
  errorHistory[errorHistoryLast] = errorCurrent;
  float errorSum = 0.0;
  for (int i=0; i<HIST_SIZE; ++i) {
    errorSum += errorHistory[i];
  }
  float output = (PID_P * error) + (PID_I * errorSum) + (PID_D * errorPrev);
  applyOutput(output);
}
