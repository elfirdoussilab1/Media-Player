//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <sstream>
#include <typeinfo>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Database.h"

using namespace std;

int main(int argc, const char* argv[])
{
    stringstream ss("Hello World !");
    string s1, s2;
    ss >> s1 >> s2;
    cout << s2 << endl;
    
    /*
    int tab[] = {1,2,3};
    DatabasePtr database = make_shared<Database>();
    PhotoPtr photo = database->createPhoto("Photo 1", "/path/to/photo1", 10, 20);
    VideoPtr video = database->createVideo("Video 1", "/path/to/video1", 98);
    FilmPtr film = database->createFilm("Film 1", "/path/to/film1", 120, 3,tab);
    GroupPtr group = database->createGroup("Group 1");
    group->addMultimedia(photo);
    group ->addMultimedia(video);
    database->displayAllMultimedias(cout);
    */
    return 0;
};

// links : "/Users/aelfirdo/Desktop/video.mp4"
// "/Users/aelfirdo/Desktop/5518082.jpg"
// "/Users/aelfirdo/Desktop/Linkedin.jpeg"
