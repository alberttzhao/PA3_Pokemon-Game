#include <iostream>
#include <string> 
#include <math.h>

#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"

using namespace std;

int main()
{

    Point2D position1;
    position1.x = 3.0;
    position1.y = 4.0;

    Point2D position2;
    position2.x = 10.0;
    position2.y = 15.0;

    Vector2D vector1;
    vector1.x = 2.0;
    vector1.y = 2.0;

    Vector2D vector2;
    vector2.x = 4.0;
    vector2.y = 4.0;


    //get distance between two points: 
    double dist = GetDistanceBetween(position1 , position2);
    cout << "distance between two points: " << endl;
    cout << dist << endl << endl;

    //print position of two points using outstream operator
    cout << "position of point 1: " << endl;
    cout << position1 << endl; //should print out (3,4) checking for outstream operator 
    cout << "position of point 2: " << endl;
    cout << position2 << endl << endl;

    //print vector of two vectors:
    //checking outstream operator in class Vector2D
    cout << "vector 1: " << endl;
    cout << vector1 << endl;
    cout << "vector 2: " << endl;
    cout << vector2 << endl << endl;

    //checking point2D additional operator: 
    //adding position1 and vector1
    cout << "additional operator for position1 and vector 1" << endl;
    Point2D position_new;
    position_new = position1 + vector1;
    cout << position_new << endl << endl;

    //checking point2D subtraction operator:
    cout << "subtraction operator for position1 and position2...from two points to vector:" << endl;
    Vector2D vector_new;
    vector_new = position1 - position2;
    cout << vector_new << endl << endl;

    //checking multiplication operator in class Vector2D:
    //multiple vector1 by 7
    Vector2D vector_mul_new = vector1 * 7.0;
    cout << "multiple vector1 by 7: " << endl;
    cout << vector_mul_new << endl << endl;

    //checking division operator in class Vector2D:
    Vector2D vector_div_new = vector2 / 2.0;
    cout << "divide vector2 by 2: " << endl;
    cout << vector_div_new << endl << endl;

    //Setting GameObject:
    GameObject setting1('a'); //should print out game object constructed 
    cout << endl << endl;
    
    //Setting another GameObject with position1:
    GameObject setting2(position1, 7, 'c'); //should print out game object constructed as well
    cout << endl << endl;

    //testing setting2:
    Point2D getLoc = setting2.GetLocation();
    int id = setting2.GetId();
    char state = setting2.GetState();
    cout << "The position of setting2 is: " << endl;
    cout << getLoc << endl; 
    cout << "The ID of setting2 is: " << endl;
    cout << id << endl;
    cout << "The state of setting 2 is: " << endl;
    cout << state << endl;
    cout << "The entire status of setting 2 is: " << endl;
    setting2.ShowStatus(); //print out the status of setting2;

 
    return 0;
}