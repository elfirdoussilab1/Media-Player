
//
#define OLD_VERSION
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Database.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"
const int PORT = 3331;
using namespace std;


int main(int argc, char* argv[])
{
  DatabasePtr database = make_shared<Database>(); 
  PhotoPtr photo1 = database->createPhoto("Photo1", "/Users/aelfirdo/Desktop/Linkedin.jpeg", 10, 20);
  PhotoPtr photo2 = database->createPhoto("Photo2", "/Users/aelfirdo/Desktop/5518082.jpg", 10, 20);
  VideoPtr video = database->createVideo("Video1", "/Users/aelfirdo/Desktop/video.mp4", 98);
  GroupPtr group = database->createGroup("Group1");
  group->addMultimedia(photo1);
  group->addMultimedia(photo2);
  group ->addMultimedia(video);
  // cree le TCPServer
  auto* server =
  new TCPServer( [&](std::string const& request, std::string& response) {
    // The structure of the request will be the following : function argument1 argument2 ...
    std::stringstream ss1 ;
    std::stringstream ss2(request);
    string s2, name;
    ss2 >> s2;
    // the request sent by the client to the server
    // Les if on va les remplacer par un map
    if( s2 == "displayAllMultimedias"){
      database->displayAllMultimedias(ss1);
      response = ss1.str();
      
    }
    if(s2 == "displayGroup") {
      ss2 >> s2 >> name;
      database->displayGroup(name, ss1);
      response = ss1.str();
      
    }
    if(s2 == "displayMltimedia") {
      ss2 >> s2 >> name;
      database->displayMultimedia(name, ss1);
      response = ss1.str();
      
    }


    if (s2 == "playMultimedia"){
      ss2 >> s2 >> name;
      database->playMultimedia(name);
      response = "Done";
    }
    else {
      response = "Invalid " + request; 
    }

    // return false would close the connecytion with the client
    return true;
  });


  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }





  #ifndef OLD_VERSION

  // cree le TCPServer
  auto* server =
  new TCPServer( [&](std::string const& request, std::string& response) {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;

    // the response that the server sends back to the client
    response = "RECEIVED: " + request;

    // return false would close the connecytion with the client
    return true;
  });


  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  #endif
  return 0;
}

