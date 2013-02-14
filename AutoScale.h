#ifndef AUTOSCALE_h
#define AUTOSCALE_h

#include <limits.h>
#include <Arduino.h>

class AutoScale
{
  int out_min;
  int out_max;
  int in_min;
  int in_max;
public:
  AutoScale(int min, int max) {
    out_min = min;
    out_max = max;
    reset();
  }
  int operator() (int arg) {
      if (arg < in_min)
	in_min = arg;
      if (arg > in_max)
	in_max = arg;
      if (in_max == in_min)
	return out_min;
      return map(arg, in_min, in_max, out_min, out_max);
  }
  void reset(void) {
    in_min = INT_MAX;
    in_max = INT_MIN;
  }
};

#endif
