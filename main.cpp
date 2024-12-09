/*
The main goal of this repository is to simplify the process of data collection
We're going to start with opening mp4 files in C++
-> We might sidetrack into files as drone videos may not be in mp4 (We'll make a file convertor)
We will be using openCV for this project
We will open the file
(Once AI is setup we can also integrate this into our program)
We want a start and end time.
We can use this calcualte frames
We also want an intial position, end position and a width x length (of the piece of trash)
These width x length can change given time but for now we assume that the drone is at a steady height
Using the start and end time we can calculate how many frames are in between these two images

Now we can begin taking screenshots beginning at the initial position.
[Side note from now I'll be calling our center as C]
The distance from C,Start and C,End can be expressed as a vector <i,j> with C,start being the origin (we simply allign for it when taking screenshots)
Thus at the next frame we know that the width x height should be moved by <i/t, j/t> [starting at <0,0>]
Here t is a constant that encapsulates the FPS and the total time taken

Now all that is left to do is find a way to capture screenshots and write them to a repository
We will use OpenCV's ROI (region of interst) functionality
(This will be explained as we move along this file)


Of course to avoid overfitting/memorization all of the pieces of trash processed through this method
should be under the influence of some sort of change in enviornemnt (i.e wind, different lighting, rain, etc.)
*/
//Importing OpenCV and bits/stdc++.h (because I'm lazy :D)
//mac initally:
#include <opencv2/opencv.hpp>
#include <glob.h>
#include <unistd.h>

int videos;

std::wstring Path(){
    char buffer[PATH_MAX];
    if(getcwd(buffer, sizeof(buffer)) != nullptr){
        std::cout<<"Testing Directory is: "<< buffer<<std::endl;
    }

}
void helper(){
    Path();
}
//main function
int main(){
    //We start by taking input from the user
    std::cout<<"Hey, EcoDrones Member! To simplify your expierence start by telling me how many videos we are processing!"<<std::endl;
    std::cin>>videos;
    for(int i = 0; i<videos; i++){
        std::cout<<"That's great!, Now Paste your videos into the current directory"<<std::endl;
        helper();
    }

      
}

//To run on macos, run: g++ -std=c++17 -o main main.cpp $(pkg-config --cflags --libs opencv4)
//followed by: ./main
