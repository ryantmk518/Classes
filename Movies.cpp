#include <iostream>
#include <cstring>
#include "Movies.h"
#include "Media.h"

//Movies code

Movies::Movies() {

}

int Movies::getType() {
  return 2;
}

char* Movies::getDirector(){
  return director;
}

int* Movies::getDuration() {
  return &duration;
}

char* Movies::getRating(){
  return rating;
}
