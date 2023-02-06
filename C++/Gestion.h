
#ifndef Gestion_h
#define Gestion_h
#include <map>

#include "Photo.h"
#include "Film.h"
#include "Group.h"

using namespace std;

class Gestion{
    private :
        map<string, GroupPtr> groups;
        map<string, MultimediaPtr> all_multimedias;
    public :
        // constructors
        Gestion(){};
    
        Gestion(map<string, GroupPtr> groups, map<string, MultimediaPtr> all_multimedias):
        groups(groups), all_multimedias(all_multimedias){};
    
        // destructor
        ~Gestion(){cout << "Bye gestion \n";};
    
        // Creating a Photo and adding it to the map: all_multimedias

        PhotoPtr createPhoto(string name, string path, int length, int height){
            PhotoPtr p = make_shared<Photo>(name, path, length, height);
            all_multimedias[name] = p;
            return p;
        }
    
        // Creating a Video and adding it to the map: all_multimedias
    
        VideoPtr createVideo(string name, string path, int duration){
            VideoPtr v = make_shared<Video>(name, path, duration);
            all_multimedias[name] = v;
            return v;
        }
    
        // Creating a Film and adding it to the map: all_multimedias
    
        FilmPtr createFilm(string name, string path, int duration, int n_chapters, int* chapters){
            FilmPtr f = make_shared<Film>(name, path, duration, n_chapters, chapters);
            all_multimedias[name] = f;
            return f;
        }
        
        // Creating a Group and adding it to the map: groups
        GroupPtr createGroup(string name){
            GroupPtr g = make_shared<Group>(name);
            groups[name] = g;
            return g;
        }

        // Displaying the values of a multimedia object in all_multimedias
        void displayMultimedia(string name){
            auto it = all_multimedias.find(name);
            if(it != all_multimedias.end()){
                it->second->printValues(cout); // first pour la clé et second pour l'element
            }
            else{
                cout << "Multimedia not found, please check if the entered name is correct \n";
            }
            
        };
    
        // Displaying the elements of a group  in groups
        void displayGroup(string name){
            auto it = groups.find(name);
            if(it != groups.end()){
                it->second->display(cout);
            }
            else{
                cout << "Group not found, please check if the entered name is correct \n";
            }
            
        };
        
        // Displaying a multimedia object in all_multimedias
        void playMultimedia(string name){
            auto it = all_multimedias.find(name);
            if(it != all_multimedias.end()){
                it->second->playMedia();
            }
            else{
                cout << "Group not found, please check if the entered name is correct \n";
            }
            
        };
        
        // Deleting a group from groups
        void deleteGroup(string name){
            auto it = groups.find(name);
            if(it != groups.end()){
                groups.erase(it);
            }
            else{
                cout << "Group not found, please check if you entered the correct group name \n";
            }
            
        };
        
    
        // Deleting a multimedia object from all_multimedias
        void deleteMultimedia(string name){
            auto it = all_multimedias.find(name);
            if(it != all_multimedias.end()){
                all_multimedias.erase(it);
                int n = groups.size();
                for (int i=0; i<n;i++){
                    //auto it2 = i->second;
                }
            }
            else{
                cout << "Multimedia object not found, please check if you entered the correct name \n";
            }
            
        };
        
};
#endif /* Group_h */
