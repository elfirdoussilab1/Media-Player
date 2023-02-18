#ifndef Media_Film
#define Media_Film

#include "Video.h"
using namespace std;

class Film:public Video{
    private:

        int n_chapters{};
        int * chapters;

    public :

    /// @brief Default Constructor of Film
    Film() : Video(){};

    
    /// @brief Constructor of Film object
    /// @param name 
    /// @param path 
    /// @param duration 
    /// @param n_chapters 
    /// @param chapters_ 
    Film(string const & name, string const & path, int duration, int n_chapters, int * chapters_): Video(name,path, duration), n_chapters(n_chapters){
        chapters = new int[n_chapters];
        for (int i=0; i<n_chapters; i++){
            chapters[i] = chapters_[i];
        }
    };

    /// @brief Copy constructor (to perform deep copy)
    /// @param from (Film const reference)
    Film(const Film & from) : Video(from){
        n_chapters = from.n_chapters;
        if (from.chapters){
            chapters = new int[n_chapters];
            for (int i=0; i<n_chapters; i++){
                chapters[i] = from.chapters[i];
            }
        } else{ chapters = nullptr;}

    }

    /// @brief Redefining operator = to perform deep copy
    /// @param from 
    /// @return Film &
    Film & operator=(const Film & from){
        Video::operator=(from);
        n_chapters = from.n_chapters;
        if (from.chapters){
            chapters = new int[n_chapters];
            for (int i=0; i<n_chapters; i++){
                chapters[i] = from.chapters[i];
            }
        } 
        else{ chapters = nullptr;}
        return *this;
    }
    
    /// @brief The destructor of a Film object displays "Good Bye Film" when it's called
    ~Film(){
        delete[] chapters;
        cout << "Good bye Film \n";
    }

    /// @brief Getter for the array chapters
    /// @return a const value of the array, so that it can be accessed only in reading
    const int * getChapters() const { // this array should not be changed by the user exept by the function setChapters
        return chapters;
    };

    /// @brief Getter for the number of chapters in the Film
    /// @return number of chapters
    int getNumberOfChapters() const{
        return n_chapters;
    };

    /// @brief Setter of array chapters of Film
    /// @param new_n_chapters 
    /// @param new_chapters 
    void setChapters(int new_n_chapters, int * new_chapters){
        // verify if one of the parameters are null
        if ((new_n_chapters ==0) || (new_chapters == nullptr)){
            n_chapters = 0;
            delete[] chapters;
            chapters = nullptr;
        }
        // If parameters are not null
        if ((new_n_chapters !=0) && (new_chapters != nullptr)){
            
                // the new number of chapters is not 0
                n_chapters = new_n_chapters;
                chapters = new int[n_chapters];
                for (int i=0; i<n_chapters; i++){
                    chapters[i] = new_chapters[i];
                
            }
        }
    };

    /// @brief The function is final since we will not refedine this function in another subclass of Film
    /// @param s 
    void printValues(ostream & s) const final {
        Video::printValues(s);
        for (int i=0; i<n_chapters; i++){
            s << " Duration of Chapter " << i+1 << " : " << chapters[i] << std::endl;
        }
    }

};

typedef shared_ptr<Film> FilmPtr;
#endif
