#ifndef Utility_H // include guard
// #include
#include<string>

#define Utility_H
#include <dirent.h> 
#include <chrono>
#include <ctime>
 const char* base_dir ="/home/chaudhrytayyab/Host";

std::string get_local_time()
{

     auto timenow =
      chrono::system_clock::to_time_t(chrono::system_clock::now());
return  string( ctime(&timenow));
}




std::string get_file_path(std::string uri)
{
    DIR * directorty;
    dirent* file_path;
    directorty =opendir(base_dir);
    if (directorty)
    {
        while ((file_path=readdir(directorty))!=NULL)
        {
         if(std::string(file_path->d_name)==uri)
         {
            std::string s=base_dir;
             return s+"/"+file_path->d_name;
         }
        }
        closedir(directorty);
    }
    return "" ;
}

#endif