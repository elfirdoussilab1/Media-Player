
#ifndef Database_h
#define Database_h
#include <map>
#include "Photo.h"
#include "Film.h"
#include "Group.h"
#include <memory>

using namespace std;

class Database{
    private :
        map<string, GroupPtr> groups;
        map<string, MultimediaPtr> multimedias;
    public :
        
        /// @brief Default constructor
        Database(){}
    
        /// @brief Constructor of 
        /// @param groups 
        /// @param multimedias 
        Database(map<string, GroupPtr> const & groups, map<string, MultimediaPtr> const & multimedias):
        groups(groups), multimedias(multimedias){}
    
        
        /// @brief Destructor of the Database
        ~Database(){cout << "Bye Data Base \n";}
    

        /// @brief Creates a Photo and add it to the map multimedias
        /// @param name 
        /// @param path 
        /// @param length 
        /// @param height 
        /// @return a shared pointer of Photo object
        PhotoPtr createPhoto(string const & name, string const & path, int length, int height){
            PhotoPtr p = make_shared<Photo>(name, path, length, height);
            multimedias[name] = p;
            return p;
        }
    
        
        /// @brief Creates a Video and add it to multimedias
        /// @param name 
        /// @param path 
        /// @param duration 
        /// @return a shared pointer of Video object
        VideoPtr createVideo(string const & name, string const & path, int duration){
            VideoPtr v = make_shared<Video>(name, path, duration);
            multimedias[name] = v;
            return v;
        }
    
    
        /// @brief Creates a Film and add it to multimedias
        /// @param name 
        /// @param path 
        /// @param duration 
        /// @param n_chapters 
        /// @param chapters 
        /// @return a shared pointer of Film object
        FilmPtr createFilm(string const & name, string const & path, int duration, int n_chapters, int * chapters){
            FilmPtr f = make_shared<Film>(name, path, duration, n_chapters, chapters);
            multimedias[name] = f;
            return f;
        }
        
        /// @brief Creates a Group and add it to the map groups
        /// @param name 
        /// @return shared pointer of Group object
        GroupPtr createGroup(string const & name){
            GroupPtr g = make_shared<Group>(name);
            groups[name] = g;
            return g;
        }


        /// @brief Displays the values of a Multimedia object in multimedias
        /// @param name 
        /// @param s 
        void displayMultimedia(string const & name, ostream & s)const {
            auto it = multimedias.find(name);
            if(it != multimedias.end()){
                it->second->printValues(s); 
            }
            else{
                cout << "Multimedia not found, please check if the entered name is correct \n";
            }
            
        }

        void displayAllMultimedias(ostream & s) const {
            for(auto it = multimedias.begin(); it != multimedias.end(); ++it){
                it->second->printValues(s);
            }
        }
        
        /// @brief Displays the elements of a Group contained in groups
        /// @param name 
        /// @param s 
        void displayGroup(string const & name, ostream & s) const {
            auto it = groups.find(name);
            if(it != groups.end()){
                it->second->display(s);
            }
            else{
                cout << "Group not found, please check if the entered name is correct \n";
            }
            
        }
        
        
        /// @brief Plays a Multimedia object in multimedias
        /// @param name 
        void playMultimedia(string const & name) const {
            auto it = multimedias.find(name);
            if(it != multimedias.end()){
                it->second->playMedia();
            }
            else{
                cout << "Group not found, please check if the entered name is correct \n";
            }
            
        };
        

        
        /// @brief Deletes a group from groups
        /// @param name 
        void deleteGroup(string const & name){
            auto it = groups.find(name);
            if(it != groups.end()){
                groups.erase(it);
            }
            else{
                cout << "Group not found, please check if you entered the correct group name \n";
            }
            
        };
        
    
        /// @brief Deletes a Multimedia object from multimedias and groups
        /// @param name_ 
        void deleteMultimedia(string const & name_){
            // Removing the Multimedia object from every group
            map<string, GroupPtr>::iterator it2 ;
            string name = name_;
            for (it2 = groups.begin(); it2 != groups.end(); ++it2){
                GroupPtr current = it2->second;
                current->remove_if([=](MultimediaPtr m){return m->getName() == name ;});
            }

            // removing the element from the map multimedias
            auto it = multimedias.find(name_);
            if(it != multimedias.end()){
                multimedias.erase(it);
            }
            else{
                cout << "Multimedia object not found, please check if you entered the correct name \n";
            };
            
        }
        
};

typedef shared_ptr<Database> DatabasePtr;
#endif /* Group_h */
