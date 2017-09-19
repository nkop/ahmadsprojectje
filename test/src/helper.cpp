//
// Created by Ahmad Rahimi on 9/6/17.
//

#include <cmath>
#include "../headers/helper.h"

const double PI = 3.14;

float Helper::degreesToRadians(double degrees) {
    return degrees / 180*PI;
}

float Helper::radiansToDegrees(double radians) {
    return radians * 180/PI;
}

std::string Helper::getCurrentWorkingDir( void ) {
    char buff[FILENAME_MAX];
    GetCurrentDir( buff, FILENAME_MAX );
    std::string current_working_dir(buff);
    return current_working_dir;
}

double Helper::correctTheAngle(double angle) {
    if (angle > 90){
        return (angle - 90);
    }else {
        return angle + 270;
    }
}