#include "./include/geometry.hpp"

int main() {
    int numPoints = 4;
    vector<Point> points(numPoints);
    points.reserve(numPoints);
    bool satisfied = false;
    do {
        TakeCoordinates(points, numPoints);
        cout << "Are you satisfied with the data? (1 - Yes, 0 - No): ";
        cin >> satisfied;
    } while (!satisfied);
    float AB, BC, CA, AD, BD, CD;
    Calculate(points, AB, BC, CA, AD, BD, CD);
}
