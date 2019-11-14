#include <iostream>
#include <string.h>
#include "Media.h"
#include "Movies.h"
#include "Games.h"
#include "Music.h"
#include <vector>

//Ryan Thammakhoune. Classes. Allows user to input 3 types of media into a database. Can also search and delete inputs.

using namespace std;

//Functions

void add(vector<Media*>* medList);
void search(vector<Media*>* medList);
void del(vector<Media*>* medList);
void print(vector<Media*>* medList);

int main() {
  vector<Media*> List;
  vector<Media*>* medList = &List;
  bool start = true;
  while (start == true) {
    char input[10];
    cout<<"Enter a command" << endl; //Ask for commands
    cin >> input;
    cin.clear();
    cin.ignore(999, '\n');
    if (strcmp(input, "ADD") == 0) {
      add(medList);
    }
    if (strcmp(input, "SEARCH") == 0) {
      search(medList);
    }
    if (strcmp(input, "DELETE") == 0) {
      del(medList);
    }
    if (strcmp(input, "QUIT") == 0) {
      start = false;
    }
  }
}

//Adds a media to the list
void add(vector<Media*>* medList) {
  cout << "Enter media type" << endl;
  char media[99];
  cin >> media;
  cin.clear();
  cin.ignore(999, '\n');
  if (strcmp(media, "GAME") == 0) { //For games
    Games* game = new Games(); //Enter info
    cout << "Enter the title" << endl;
    cin.get(game -> getTitle(),99);
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Enter the year" << endl;
    cin >> *game -> getYear();
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Enter the publisher" << endl;
    cin.get(game->getPublisher(), 99);
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Enter the rating" << endl;
    cin.get(game->getRating(),99);
    cin.clear();
    cin.ignore(999, '\n');
    medList->push_back(game);
  }
  if (strcmp(media, "MUSIC") == 0) { //For music
    Music* music = new Music();//Enter info
    cout << "Enter title" << endl;
    cin.get(music->getTitle(),99);
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Enter artist" << endl;
    cin.get(music->getArtist(),99);
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Enter year" << endl;
    cin >> *music -> getYear();
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Enter duration" << endl;
    cin >> *music->getDuration();
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Enter publisher" << endl;
    cin.get(music->getPublisher(),99);
    cin.clear();
    cin.ignore(999, '\n');
    medList->push_back(music);
  }
  if (strcmp(media, "MOVIE") == 0) { //For movies
    Movies* movie = new Movies();
    cout << "Enter title" << endl;
    cin.get(movie->getTitle(),99);
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Enter director" << endl;
    cin.get(movie->getDirector(), 99);
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Enter year" << endl;
    cin >> *movie->getYear();
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Enter duration" << endl;
    cin >> *movie->getDuration();
    cin.clear();
    cin.ignore(999, '\n');
    cout << "Enter rating" << endl;
    cin.get(movie->getRating(), 99);
    cin.clear();
    cin.ignore(999, '\n');
    medList->push_back(movie);
  }
}

void search(vector<Media*>* medList) {
  char in[99];
  cout << "Search by year or title?" << endl;
  cin >> in;
  cin.clear();
  cin.ignore(999, '\n');
  vector<Media*>::iterator it;
  if (strcmp(in, "YEAR")==0) { //For search by year
    int year;
    cout << "Enter year" << endl;
    cin >> year;
    cin.clear();
    cin.ignore(999, '\n');
    for(it = medList->begin(); it != medList ->end(); ++it) {//Creates iterator that checks each component in list
      if ((year == *(*it) -> getYear()) && ((*it) -> getType() ==0)) {
	cout << "\n Title: " << (*it) -> getTitle() << endl;
	cout << "Year: " << *(*it) ->getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Games*>(*it) -> getPublisher() <<endl;
	cout << "Rating: " << *dynamic_cast<Games*>(*it) -> getRating() << endl;
      }
      else if ((year == *(*it) -> getYear()) && ((*it) -> getType() == 1)) {
	cout << "\n Title: " << (*it) -> getTitle() << endl;
	cout << "Year: " << *(*it) -> getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*it) -> getDuration() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*it) -> getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*it) -> getPublisher() << endl;
      }
      else if ((year == *(*it) -> getYear()) && ((*it) -> getType() == 2)) {
	cout << "\n Title: " << (*it) -> getTitle() << endl;
	cout << "Year: " << *(*it) -> getYear() << endl;
	cout << "Director: " << dynamic_cast<Movies*>(*it) -> getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movies*>(*it) -> getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movies*>(*it) -> getRating() << endl;

      }
    }
  }
  else if (strcmp(in, "TITLE") == 0) { //For search by title
    char title[99];
    cout << "Enter title" << endl;
    cin >> title;
    cin.clear();
    cin.ignore(999, '\n');
    for(it = medList->begin(); it != medList ->end(); ++it) {
      if ((strcmp(title, (*it) -> getTitle()) == 0) && ((*it) -> getType() ==0)) {
	cout << "\n Title: " << (*it) -> getTitle() << endl;
	cout << "Year: " << *(*it) ->getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Games*>(*it) -> getPublisher() <<endl;
	cout << "Rating: " << *dynamic_cast<Games*>(*it) -> getRating() << endl;
      }
      else if ((strcmp(title, (*it) -> getTitle()) == 0) && ((*it) -> getType() == 1)) {
	cout << "\n Title: " << (*it) -> getTitle() << endl;
	cout << "Year: " << *(*it) -> getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*it) -> getDuration() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*it) -> getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*it) -> getPublisher() << endl;
      }
      else if ((strcmp(title, (*it) -> getTitle()) == 0) && ((*it) -> getType() == 2)) {
	cout << "\n Title: " << (*it) -> getTitle() << endl;
	cout << "Year: " << *(*it) -> getYear() << endl;
	cout << "Director: " << dynamic_cast<Movies*>(*it) -> getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movies*>(*it) -> getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movies*>(*it) -> getRating() << endl;

      }
    }    
  }
}

void del(vector<Media*>* medList) { //Delete function
  char in[99];
  char del[99];
  cout << "Search by year or title?" << endl; //Searches first
  cin >> in;
  cin.clear();
  cin.ignore(999, '\n');
  vector<Media*>::iterator it;
  if (strcmp(in, "YEAR")==0) {
    int year;
    cout << "Enter year" << endl;
    cin >> year;
    cin.clear();
    cin.ignore(999, '\n');
    for(it = medList->begin(); it != medList ->end(); ++it) {
      if ((year == *(*it) -> getYear()) && ((*it) -> getType() ==0)) {
	cout << "\n Title: " << (*it) -> getTitle() << endl;
	cout << "Year: " << *(*it) ->getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Games*>(*it) -> getPublisher() <<endl;
	cout << "Rating: " << *dynamic_cast<Games*>(*it) -> getRating() << endl;
      }
      else if ((year == *(*it) -> getYear()) && ((*it) -> getType() == 1)) {
	cout << "\n Title: " << (*it) -> getTitle() << endl;
	cout << "Year: " << *(*it) -> getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*it) -> getDuration() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*it) -> getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*it) -> getPublisher() << endl;
      }
      else if ((year == *(*it) -> getYear()) && ((*it) -> getType() == 2)) {
	cout << "\n Title: " << (*it) -> getTitle() << endl;
	cout << "Year: " << *(*it) -> getYear() << endl;
	cout << "Director: " << dynamic_cast<Movies*>(*it) -> getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movies*>(*it) -> getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movies*>(*it) -> getRating() << endl;

      }
      cout << "Delete? (Y/N)" << endl; //Ask for delete
      cin >> del;
      cin.clear();
      cin.ignore(999, '\n');
      if (strcmp(del, "Y") == 0) { //Delete
	delete *it;
	it = medList -> erase(it);
	return;
      }
      else {

      }
    }
  }
  else if (strcmp(in, "TITLE") == 0) {
    char title[99];
    cout << "Enter title" << endl;
    cin >> title;
    cin.clear();
    cin.ignore(999, '\n');
    for(it = medList->begin(); it != medList ->end(); ++it) {
      if ((strcmp(title, (*it) -> getTitle()) == 0) && ((*it) -> getType() ==0)) {
	cout << "\n Title: " << (*it) -> getTitle() << endl;
	cout << "Year: " << *(*it) ->getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Games*>(*it) -> getPublisher() <<endl;
	cout << "Rating: " << *dynamic_cast<Games*>(*it) -> getRating() << endl;
      }
      else if ((strcmp(title, (*it) -> getTitle()) == 0) && ((*it) -> getType() == 1)) {
	cout << "\n Title: " << (*it) -> getTitle() << endl;
	cout << "Year: " << *(*it) -> getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*it) -> getDuration() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*it) -> getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*it) -> getPublisher() << endl;
      }
      else if ((strcmp(title, (*it) -> getTitle()) == 0) && ((*it) -> getType() == 2)) {
	cout << "\n Title: " << (*it) -> getTitle() << endl;
	cout << "Year: " << *(*it) -> getYear() << endl;
	cout << "Director: " << dynamic_cast<Movies*>(*it) -> getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movies*>(*it) -> getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movies*>(*it) -> getRating() << endl;

      }
      cout << "Delete? (Y/N)" << endl;
      cin >> del;
      cin.clear();
      cin.ignore(999, '\n');
      if (strcmp(del, "Y") == 0) {
	delete *it;
	it = medList -> erase(it);
	return;
      }
      else {

      }
    }    
  }
}

