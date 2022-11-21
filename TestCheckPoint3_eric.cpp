#include <iostream>
#include <cmath>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"


using namespace std;

int main()
{
    //making points
    Point2D point1;
    point1.x = 1;
    point1.y = 3;

    Point2D point2;
    point2.x = 7;
    point2.y = 21;


    //PokemonCenter

    PokemonCenter center1(1, 5, 20, point1);
    PokemonCenter center2(10, 5, 20, point2);


    //PokemonGym

    PokemonGym gym1(1, 5, 5, 20, 1, point1);
    PokemonGym gym2(2, 5, 5, 20, 1, point2);



    //TESTING TRAINER

    //testing base case
    Trainer trainer1;
    trainer1.ShowStatus();

    //testing other base case with just an input character
    Trainer trainer2('E');
    trainer2.ShowStatus();

    //testing case where actual values are fed in
    Trainer trainer3("Eric", 1, 'e', 5, point1);
    trainer3.ShowStatus();
    Trainer trainer4 ("Ash", 1, 'a', 5, point2);
    trainer4.ShowStatus();

    //testing moving functions when the location and destination aren't the same
    trainer3.StartMoving(point2);
    trainer3.StartMovingToGym(&gym2);
    trainer3.StartMovingToCenter(&center2);

    //testing moving functions when the location and destination are the same
    trainer3.StartMoving(point1);
    trainer3.StartMovingToGym(&gym1);
    trainer3.StartMovingToCenter(&center1);

    //testing StartBattling
    trainer3.StartBattling(7);
    

    return 0;
}