#include <iostream>
#include <cstring>
#include "Media.h"

//Movies header

using namespace std;

class Movies:public Media {
 public:
  Movies();
  virtual int getType();
  char* getDirector();
  int* getDuration();
  char* getRating();

 private:
  char director[99];
  int duration;
  char rating[99];

};
