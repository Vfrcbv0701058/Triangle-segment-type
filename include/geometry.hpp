#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP
#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    float x, y;
};

void TakeCoordinates(std::vector <Point> &points, int &numPoints);

void Calculate(vector <Point> &points, float &AB, float &BC, float & CA, float &AD, float &BD, float &CD);


#endif //GEOMETRY_HPP
