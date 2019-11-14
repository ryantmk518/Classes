#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <string.h>

//Media header

using namespace std;

class Media {
 public:
  Media();
  char* getTitle();
  int* getYear();
  virtual int getType();
 private:
  char title[99];
  int year;
};

#endif
