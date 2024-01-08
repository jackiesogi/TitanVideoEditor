#ifndef TEMPFILE_H
#define TEMPFILE_H


#include<map>
#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<string>
#include<cstdlib>
#include<cstdio>


#include<mp4v2/mp4v2.h>

#define CLIPNAME_LENGTH 30

class Clip
{
    public:
    std::string filename;
    size_t filesize;

};



class TempLookupTable
{

    std::map<std::string ,Clip> table;


};


int write_temp_file(char* , size_t, std::map<std::string,Clip>& );
void query_file_info(const std::map<std::string,Clip>&, const std::string&);
void delete_file_info(std::map<std::string,Clip>& , const std::string& );



#endif