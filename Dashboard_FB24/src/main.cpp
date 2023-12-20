
#include <CAN_setup.cpp>
#include <CAN_func.cpp>

// put function declarations here:
int myFunction(int, int);

void setup()
 {

   can1.begin();
  can1.setBaudRate(10000000);
 }


void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}