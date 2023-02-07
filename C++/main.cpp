//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>

#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include"Gestion.h"

using namespace std;

int main(int argc, const char* argv[])
{
    int tab[3];
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    GestionPtr database = make_shared<Gestion>();
    PhotoPtr photo = database->createPhoto("Photo 1", "/path/to/photo1", 10, 20);
    VideoPtr video = database->createVideo("Video 1", "/path/to/video1", 98);
    FilmPtr film = database->createFilm("Film 1", "/path/to/film1", 120, 3,tab);
    GroupPtr group = database->createGroup("Group 1");

    group->push_back(photo);
    group->push_back(video);
    group->push_back(film);

    cout << "Display a photo in the database:" << endl;
    database->displayMultimedia("Photo 1", cout);

    cout << "\nDisplay a video in the database:" << endl;
    database->displayMultimedia("Video 1", cout);

    cout << "\nDisplay a film in the database:" << endl;
    database->displayMultimedia("Film 1", cout);

    cout << "\nDisplay a group in the database:" << endl;
    database->displayGroup("Group 1", cout);

    cout << "\nTry to remove \"Photo 1\" from the database:" << endl;
    database->deleteMultimedia("Photo 1");

    cout << "\nDisplay \"Group 1\" a second time to see if \"Photo 1\" was correctly removed from the group:" << endl;
    database->displayGroup("Group 1", cout);

    return 0;
};

// links : "/Users/aelfirdo/Desktop/video.mp4"
// "/Users/aelfirdo/Desktop/5518082.jpg"
// "/Users/aelfirdo/Desktop/Linkedin.jpeg"
