
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
    
        /// @brief Constructor of Database
        /// @param groups 
        /// @param multimedias 
        Database(map<string, GroupPtr> const & groups, map<string, MultimediaPtr> const & multimedias):
        groups(groups), multimedias(multimedias){}
    
        
        /// @brief Destructor of the Database
        ~Database(){cout << "Bye DataBase \n";}
    

        /// @brief Creates a Photo and add it to the map multimedias
        /// @param name 
        /// @param path 
        /// @param length 
        /// @param height 
        /// @return a shared pointer of Photo object
        PhotoPtr createPhoto(string const & name, string const & path, int length, int height){
            // check if no other Multimedia has the same name
            auto it = multimedias.find(name);
            if (it == multimedias.end()){
                if (length >= 0 && height >= 0) {
                    PhotoPtr p = make_shared<Photo>(name, path, length, height);
                    multimedias[name] = p;
                    return p;
                }
            }
            return nullptr;
        }
        
        /// @brief Creates a Video and add it to multimedias
        /// @param name 
        /// @param path 
        /// @param duration 
        /// @return a shared pointer of Video object
        VideoPtr createVideo(string const & name, string const & path, int duration){
            auto it = multimedias.find(name);
            if (it == multimedias.end()){
                if (duration >= 0){
                    VideoPtr v = make_shared<Video>(name, path, duration);
                    multimedias[name] = v;
                    return v;
                }
            } 
            return nullptr;

        }
    
    
        /// @brief Creates a Film and add it to multimedias
        /// @param name 
        /// @param path 
        /// @param duration 
        /// @param n_chapters 
        /// @param chapters 
        /// @return a shared pointer of Film object
        FilmPtr createFilm(string const & name, string const & path, int duration, int n_chapters, int * chapters){
            auto it = multimedias.find(name);
            if (it == multimedias.end()){
                if(duration >=0 && n_chapters >=0){
                    FilmPtr f = make_shared<Film>(name, path, duration, n_chapters, chapters);
                    multimedias[name] = f;
                    return f;
                }
            }
            return nullptr;
            
        }
        
        /// @brief Creates a Group and add it to the map groups
        /// @param name 
        /// @return shared pointer of Group object
        GroupPtr createGroup(string const & name){
            // See if no other group has the same name
            auto it = groups.find(name);
            if (it == groups.end()){
                GroupPtr g = make_shared<Group>(name);
                groups[name] = g;
                return g;
            }
            return nullptr;
            
        }

        /// @brief Adding a Multimedia object ot a certain group
        /// @param m 
        /// @param name 
        int addMultimediaToGroup(string const & m_name, string const & g_name){
            // First we check if the Multimedia object exists
            auto it = multimedias.find(m_name);
            if (it == multimedias.end()){
                return 0;
            }
            auto it2 = groups.find(g_name);
            if(it2 != groups.end()){
                MultimediaPtr m = multimedias.find(m_name)->second;
                it2->second->push_back(m);
            }
            else{ // we create the group
                GroupPtr new_group = this->createGroup(g_name);
                auto it = multimedias.find(m_name);
                new_group->push_back(it->second);
            }
            return 1;
        }


        /// @brief Displays the values of a Multimedia object in multimedias
        /// @param name 
        /// @param s 
        int displayMultimedia(string const & name, ostream & s)const {
            auto it = multimedias.find(name);
            if(it != multimedias.end()){
                it->second->printValues(s); 
                return 1;
            }
                return 0; // Multimedia not found
            
        }

        void displayAllMultimedias(ostream & s) const {
            for(auto it = multimedias.begin(); it != multimedias.end(); ++it){
                it->second->printValues(s);
            }
        }
        
        /// @brief Displays the elements of a Group contained in groups
        /// @param name 
        /// @param s 
        int displayGroup(string const & name, ostream & s) const {
            auto it = groups.find(name);
            if(it != groups.end()){
                it->second->display(s);
                return 1;
            }
            return 0;
            
        }
        
        
        /// @brief Plays a Multimedia object in multimedias
        /// @param name 
        int playMultimedia(string const & name) const {
            auto it = multimedias.find(name);
            if(it != multimedias.end()){
                it->second->playMedia();
                return  1;
            }
            return 0;
            
        };
        

        
        /// @brief Deletes a group from groups
        /// @param name 
        int deleteGroup(string const & name){
            auto it = groups.find(name);
            if(it != groups.end()){
                groups.erase(it);
                return 1;
            }

            return 0; // Group not found
            
        };
        
    
        /// @brief Deletes a Multimedia object from multimedias and groups
        /// @param name_ 
        int deleteMultimedia(string const & name_){
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
                return 1;
            }
            return 0;
            
            
        }
        
};

typedef shared_ptr<Database> DatabasePtr;
#endif /* Database_h */
