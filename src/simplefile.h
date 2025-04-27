#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#pragma once
extern std::string definepath;
extern std::ofstream outfile;
#ifdef FILEPATH
    bool path = true;
    std::string definepath = FILEPATH;
#else
    bool path = false;
    std::string definepath = " ";
#endif

class SimpleFile {
    public:
    std::string pathtofile = definepath;

    void startup(){
        if(pathtofile == " "){
            std::cerr << "Please provide a path by passing your file path to the class like file.pathtofile = path or alternatively you could" << std::endl << "add #define FILEPATH path at the TOP of your file" << std::endl;
        }else{
            if(!std::filesystem::exists(pathtofile)){ //if it doesnt exist
                std::ofstream creatfile(pathtofile); //make it exist
                creatfile.close();                   //crazy concept... I know
            }
        }


    }
   
    
    int countLines() {
        std::ifstream filetocount(pathtofile); //open file
        int lineCount = 0;
        std::string line;
      
        if (filetocount.is_open()) {
            while (std::getline(filetocount, line)) {
                ++lineCount; //for each line add one to linecount duh
            }
            filetocount.close();
        } else {
            std::cerr << "Error opening file for counting!\n"; //if its not open
        }
      
        return lineCount;
      }
      template <typename TEXTTOSAVE>
      void Save(TEXTTOSAVE text) {
        std::ofstream outfile(pathtofile, std::ios::app);
      
        if (outfile.is_open()) {
            outfile << text << std::endl;
        } else {
            std::cerr << "Error opening file for writing!\n";
        }
        outfile.close();
      }
      
      std::string LoadLine(int targetLine) {
        std::ifstream inFile(pathtofile);
        std::string line;
        int currentLine = 0;
    
        if (inFile.is_open()) {
            while (std::getline(inFile, line)) {
                ++currentLine;
                if (currentLine == targetLine) {
                    return line; // return the specific line
                }
            }
            inFile.close();
        } else {
            std::cerr << "Error opening file!\n";
        }
    
        return "";
    }
    
    
      
};
