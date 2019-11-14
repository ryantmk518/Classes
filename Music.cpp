#include <iostream>
#include <cstring>
#include "Media.h"
#include "Music.h"

//Music code

using namespace std;

Music::Music() {

}

int Music::getType() {
  return 1;
}

char* Music::getArtist() {
  return artist;
}

int* Music::getDuration(){
  return &duration;
}

char* Music::getPublisher(){
  return publisher;
}
