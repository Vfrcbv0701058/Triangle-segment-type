#include "../include/geometry.hpp"

void TakeCoordinates(std::vector<Point> &points, int &numPoints) {
    char namePoint[] = {'A', 'B', 'C', 'D'};
    for (int i = 0; i < numPoints; i++) {
        cout << namePoint[i] << " is: X: ";
        cin >> points[i].x;
        cout << "Y: ";
        cin >> points[i].y;
        if (points[i].x > 10000 || points[i].y > 10000) {
            cout << "Error: Input numbers cannot exceed 10^4." << endl;
            return;
        }
    }
}

void Calculate(vector <Point> &points, float &AB, float &BC, float & CA, float &AD, float &BD, float &CD) {
    // Calculate the distance between points A and B
    AB = sqrt(pow(points[0].x/*A.x*/ - points[1].x /*B.x*/, 2) + pow(points[0].y/*A->y*/ - points[1].y/*B->y*/, 2));

    // Calculate the distance between points B and C
    BC = sqrt(pow(points[1].x/*B.x*/ - points[2].x /*C.x*/, 2) + pow(points[1].x/*B->y*/ - points[2].y/*C->y*/, 2));

    // Calculate the distance between points C and A
    CA = sqrt(pow(points[2].x/*B.x*/ - points[0].x /*A.x*/, 2) + pow(points[2].x/*C->y*/ - points[0].y/*A->y*/, 2));

    // Calculate the distance between points A and D
    AD = sqrt(pow(points[0].x/*B.x*/ - points[3].x /*D.x*/, 2) + pow(points[0].x/*A->y*/ - points[3].y/*D->y*/, 2));

    // Calculate the distance between points B and D
    BD = sqrt(pow(points[1].x/*B.x*/ - points[3].x /*D.x*/, 2) + pow(points[1].x/*B->y*/ - points[3].y/*D->y*/, 2));

    // Calculate the distance between points C and D
    CD = sqrt(pow(points[2].x/*B.x*/ - points[3].x /*D.x*/, 2) + pow(points[2].x/*C->y*/ - points[3].y/*D->y*/, 2));

    if (AD == BD || BD == CD || AD == CD && AB / BC == AD / CD || AB / CA == CD / BD ||
        CA / BC == AD / BD && pow(AD, 2) == pow(AB, 2) + pow(BD, 2) || pow(BD, 2) == pow(AB, 2) + pow(AD, 2) ||
        pow(CD, 2) == pow(BC, 2) + pow(BD, 2)) {
        cout << "Cevian" << endl;
        return;
    } else if (AD == BD || BD == CD || AD == CD) {
        cout << "Median" << endl;
        return;
    } else if (AB / BC == AD / CD || AB / CA == CD / BD || CA / BC == AD / BD) {
        cout << "Bisector" << endl;
        return;
    } else if (pow(AD, 2) == pow(AB, 2) + pow(BD, 2) || pow(BD, 2) == pow(AB, 2) + pow(AD, 2) ||
               pow(CD, 2) == pow(BC, 2) + pow(BD, 2)) {
        cout << "Altitude" << endl;
        return;
    } else {
        cout << "Unknown segment" << endl;
    }
}
