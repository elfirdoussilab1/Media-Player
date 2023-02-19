#include <iostream>
#include <sstream>
#include <memory>
#include <map>
#include <vector>
#include "tcpserver.h"
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Database.h"
#include "RequestProcessor.h"

#define OLD_VERSION
const int PORT = 3331;
using namespace std;

/// @brief We define a function that extract every string of a stringstream
///        And store the result in a map
/// @param ss 
/// @return 
vector<string> extract(stringstream & ss){
    vector<string> v;
    int i = 0;
    string s;
    while (ss >> s ){
        v.push_back(s);
        i++;
    }
    return v;
}

int main(int argc, const char* argv[])
{
    // define a database to test our methods with
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
    new TCPServer( [&](std::string const & request, std::string & response) {
        stringstream ss2(request);
        vector<string> req = extract(ss2);
        if (req.size() == 0){
            response = "You need to specify the function and the arguments"; 
        }

        else {
            response = my_functions[req[0]](req, database);
        } // size of the vector

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
};
