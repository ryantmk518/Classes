#include <iostream>
#include <string.h>
#include <cstring>
#include "Media.h"

//Media code

using namespace std;

Media::Media() {

}

int* Media::getYear(){
  return &year;
}

char* Media::getTitle() {
  return title;
}

int Media::getType() {
  return 0;
}
