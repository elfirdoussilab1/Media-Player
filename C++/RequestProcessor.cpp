#include "RequestProcessor.h"
#include <iostream>
#include <sstream>
#include <functional>

using namespace std;

string create(vector<string> request, DatabasePtr database){
    string response;
    // here we have request[0] = "create"
    // We test if create is for a Photo, or a Video or a Group or a Film
    if(request[1].compare("Photo") == 0){ // we create a Photo
        // request = {"create", "Photo", "name", "path", "length", "height","groupename"}
        PhotoPtr p = database->createPhoto(request.at(2), request.at(3), stoi(request.at(4)), stoi(request.at(5)));
        if (p == nullptr){
            response = "The Photo couldn't be created, please check that the length and height given are positive and that no other Multimedia has the same name";
            return response;
        }
        int res = database->addMultimediaToGroup(request.at(2), request.at(6));
        if (res){response = "Done";}
        else{
            response = "The Photo couldn't be added to the group named " + request.at(6);
        }
    }

    else if(request.at(1).compare("Video") == 0) {
        // request = {"create", "Video", "name", "path", "duration", "groupename"}
        VideoPtr v = database->createVideo(request.at(2), request.at(3), stoi(request.at(4)));
        if (v == nullptr){
            response = "The Video couldn't be created, please check that the given duration is positive and that no other Multimedia has the same name";
            return response;
        }
        int res = database->addMultimediaToGroup(request.at(2), request.at(5));
        if (res){response = "Done";}
        else{
            response = "The Video couldn't be added to the group named " + request.at(6);
        }
    }
    else if(request.at(1).compare("Group") == 0){
        // request = {"create", "Group", "name"}
        GroupPtr g = database->createGroup(request.at(2));
        if (g == nullptr){
            response = "The Group couldn't be created, please check that no other Group has the same name";
            return response;
        }
        response = "Done";
        
    }
    return response;
};

string play(vector<string> request, DatabasePtr database){
    // request[0] = {"play", "name"}
    string response;
    int i = database->playMultimedia(request.at(1));
    if (i){
        response = "Multimedia " + request.at(1) + " is played successfully";
    }
    else{
        response = "Couldn't play Multimedia, please check if this name " + request.at(1) + " is valid !";
    }

    return response;

};

string deleteM(vector<string> request, DatabasePtr database){
    //request = {"delete", "Multimedia","name"} or request = {"delete", "Group", "name"}
    string response;
    if (request.at(1).compare("Multimedia") == 0){
        int i = database->deleteMultimedia(request.at(2));
        if(i){response = "Multimedia " + request.at(2) + " was deleted successfuly !";}
        else{response = "Multimedia "+ request.at(2) + " doesn't even exist";}
    }
    else {
        int res = database->deleteGroup(request.at(2));
        if (res){response = "Group " + request.at(2) + " was deleted successfully !";}
        else{response = "Group " + request.at(2) + " doesn't even exist !";}
        
    }

    return response;
};

string display(vector<string> request, DatabasePtr database){
    // request = {"display", "Multimedia", "name"} or request = {"display", "Group", "name"}
    string response;
    stringstream ss;
    int res;
    if (request.at(1).compare("Multimedia") == 0){
        res = database->displayMultimedia(request.at(2), ss);
        if(res == 0){   
            response = "Multimedia "+request.at(2) + " doesn't exist !";
            return response;
        }
        string line;
        while(getline(ss,line)){
          response = response + "  |  " + line;
        }
    }
    else {
        res = database->displayGroup(request.at(2), ss);
        if(res == 0){   
            response = "Group "+request.at(2) + " doesn't exist !";
            return response;
        }
        string line;
        while(getline(ss,line)){
          response = response + "  |  " + line;
        }

    }
    return response;
};

string displayAll(vector<string> request, DatabasePtr database){
    string response, line;
    stringstream ss;
    database->displayAllMultimedias(ss);
    while(getline(ss,line)){
        response = response + "  |  " + line;
    }
    return response;
};

map<string, function< string(vector<string>, DatabasePtr) >> my_functions = {
    {"create", create},
    {"play", play}, 
    {"delete", deleteM}, 
    {"display", display}, 
    {"displayAll", displayAll} };
    
