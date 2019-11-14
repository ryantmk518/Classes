#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <string.h>
#include <cstring>
#include "Media.h"

//Music header

using namespace std;

class Music:public Media{
 public:
  Music();
  virtual int getType();
  char* getArtist();
  int* getDuration();
  char* getPublisher();

 private:
  char artist[99];
  int duration;
  char publisher[99];
};

#endif
