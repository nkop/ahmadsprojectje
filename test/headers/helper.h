//
// Created by Ahmad Rahimi on 9/6/17.
//

#ifndef HELPER_H
#define HELPER_H
#include <io.h>  /* defines FILENAME_MAX */
#define WINDOWS  /* uncomment this line to use it for windows.*/
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <io.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>
class Helper {
public:
    static float radiansToDegrees(double radians);
    static float degreesToRadians(double degrees);
    static std::string getCurrentWorkingDir();
    static double correctTheAngle(double angle);
};

#endif //SHOOTER_HELPER_H
