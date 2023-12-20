#include <CAN_setup>
int available()
{
  return (_rxLength - _rxIndex);
}

int Cread()
{
  if (!available()) {
    return -1;
  }

  return _rxData[_rxIndex++];
}