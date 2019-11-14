#include <iostream>
#include <cstring>
#include "Media.h"
#include "Games.h"

//Games code

using namespace std;

Games::Games(){

}

int Games::getType(){
  return 0;
}

char* Games::getPublisher(){
  return publisher;
}

char* Games::getRating(){
  return rating;
}
