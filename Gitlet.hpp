/*************************************************************************
	> File Name: Gitlet.h
	> Author: Melon
	> Mail:xiaosong.plus@foxmail.com 
	> Created Time: Sun 13 Aug 2017 06:38:04 PM CST
 ************************************************************************/

#ifndef __GITLET_H__
#define __GITLET_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;

class Gitlet{
    public:
        void main(std::vector<string> args);

        void init(){
            string GitFolder = ".gitlet";

            ifstream infile;
            infile.open(GitFolder.c_str());
            if(!infile){
                mkdir(GitFolder.c_str(), 0744);  //error check?
            }else{
                cout << "A gitlet visioo control system \
                         already exists in the current directory." 
                     << endl;
            }        
        }
};


#endif
