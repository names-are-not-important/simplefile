//#define FILEPATH "" //one way to define the path looks cool but you cant have two SimpleFile classes with diffrent paths
#include <iostream>
#include <string>
#include "simplefile.h"


int main(){
    SimpleFile file; //makes a new SimpleFile object called file
    file.pathtofile = "./src/path.txt"; //sets the path as path.txt P.S ./ means the current directory
    file.startup(); //starts




    file.Save(23);
    file.Save("hello line");
    std::cout << file.LoadLine(1) << std::endl;
}