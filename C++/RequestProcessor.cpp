#include "RequestProcessor.h"

string const & RequestProcessor::create(vector<string> const & request, DatabasePtr database){
    string response;
    // here we have request[0] = "create"
    // We test if create is for a Photo, or a Video or a Group or a Film
    if(request[1].compare("Photo") == 0){ // we create a Photo
        // request = {"create", "Photo", "name", "path", "length", "height","groupename"}
        PhotoPtr p = database->createPhoto(request.at(2), request.at(3), stoi(request.at(4)), stoi(request.at(5)));
        database->addMultimediaToGroup(request.at(2), request.at(6));
        response = "The Photo " + request.at(2) + " was created successfully";
        return response;
    }

    else if(request.at(1).compare("Video") == 0) {
        // request = {"create", "Video", "name", "path", "duration", "groupename"}
        VideoPtr v = database->createVideo(request.at(2), request.at(3), stoi(request.at(4)));
        database->addMultimediaToGroup(request.at(2), request.at(5));
        response = "The Video " + request.at(2) + " was created successfully";
        return response;
    }
    else if(request.at(1).compare("Group") == 0){
        // request = {"create", "Group", "name"}
        GroupPtr g = database->createGroup(request.at(2));
        response = "The Group " + request.at(2) + " was created successfully";
        return response;
    }
};

string const & RequestProcessor::play(vector<string> const & request, DatabasePtr database){
    // request[0] = {"play", "name"}
    string response;
    int i = database->playMultimedia(request.at(1));
    if (i){
        response = "Multimedia " + request.at(1) + " is played successfully";
    }
    else{
        response = "Couldn't play Multimedia, please check if this name " + request.at(1) + " is valid !"
    }
    return response;

}

string const & RequestProcessor::deleteM(vector<string> const & request, DatabasePtr database){
    //request = {"delete", "Multimedia","name"} or request = {"delete", "Group", "name"}
    string response;
    if (request.at(1).compare("Multimedia") == 0){
        database->deleteMultimedia(request.at(2));
        response = "Multimedia " + request.at(2) + " was deleted successfuly !";
    }
    else {
        database->deleteGroup(request.at(2));
        response = "Group " + request.at(2) + " was deleted successfully !";
    }

    return response;
}

string const & RequestProcessor::display(vector<string> const & request, DatabasePtr database){
    // request = {"display", "Multimedia", "name"} or request = {"display", "Group", "name"}
    string response;
    stringstream ss;
    if (request.at(1).compare("Multimedia") == 0){
        database->displayMultimedia(req[1], ss);
        string line;
        while(getline(ss,line)){
          response = response + "  |  " + line;
        }
    }
    else {
        database->displayGroup(request.at(2), ss);
        string line;
        while(getline(ss,line)){
          response = response + "  |  " + line;
        }

    }
    return response;
}

string const & RequestProcessor::displayAll(vector<string> const & request, DatabasePtr database){
    string response, line;
    stringstream ss;
    database->displayAllMultimedias(ss);
    while(getline(ss,line)){
        response = response + "  |  " + line;
    }
    return response;
}
my_functions["create"] = create;
my_functions["play"] = play;
my_functions["delete"] = deleteM;
my_functions["display"] = display;
my_functions["displayAll"] = displayAll;