//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include"Gestion.h"
using namespace std;

int main(int argc, const char* argv[])
{
    // Creating a table containing phtos and videos
    // to do so, we can use the following method:
    // Creating a table of pointers to Multimedia objects
    // Example for length of array equals to 3
    
    Video * v = new Video("iliass", "/Users/aelfirdo/Desktop/video.mp4",3);
    v->printValues(cout);
    v->playMedia();
    Photo * p = new Photo("iliass akil","/Users/aelfirdo/Desktop/Linkedin.jpeg",12,300);
    p->printValues(cout);
    p->playMedia();
    delete p;
    delete v;
    
    /*MultimediaPtr p = make_shared<Photo>("/Users/aelfirdo/Desktop/5518082.jpg",10,10);
    
    Group * g1 = new Group("MonGroupe");
    
    g1->push_back(p);
    g1->display(std::cout);
    Group * g2 = new Group("MonSecondGroup");
    g2->push_back(p);
    g2->display(std::cout);
    cout << g2->size() << std::endl;
    p.reset();
    g1->remove(p);
    g2->remove(p);
    cout << "coucou \n";
    multimedias(name] = (MultimediaPtr) video;
    Gestion * G = new Gestion();
    G->displayMultimedia("photo1");
    G->displayGroup("group1");*/
    //Multimedia * f = new Film();
    //delete f;
    return 0;
}

// links : "/Users/aelfirdo/Desktop/video.mp4"
// "/Users/aelfirdo/Desktop/5518082.jpg"
// "/Users/aelfirdo/Desktop/Linkedin.jpeg"
