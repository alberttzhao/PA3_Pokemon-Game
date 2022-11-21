#include <iostream>
#include <string> 
#include <math.h>

#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "Trainer.h"

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

    /*
    Test Checkpoint 1 material above^
    */
    cout << endl << endl << endl;
    cout << "**************************************************" << endl;
    cout << "Test checkpoint 2: " << endl << endl << endl;


    Building building1; //should print out building default constructed
    Building building2('C', 7, position1);  //passing in some values to use the paramatized constructor

    cout << endl << endl << "Testing ShowStatus() and AddOneTrainer(): " << endl;
    //right now the trainer count should be 0. Use update to see
    //C7 at 3 4
    building2.ShowStatus();

    building2.AddOneTrainer();
    building2.AddOneTrainer();
    building2.AddOneTrainer();
    building2.ShowStatus();  //trainer count should be 3 now

    cout << endl << "Testing RemoveOneTrainer(): " << endl;
    building2.RemoveOneTrainer();
    building2.ShowStatus();  //trainer count should be 2 now


    cout << endl << endl << "Testing PokemonGym Class: " << endl << endl;

    //initializing: 
    PokemonGym gym1; 

    cout << endl << "Initiazing a parameterized PokemonGym constructor: " << endl;
    PokemonGym gym2(77, 5, 5, 10, 1, position2); 
    
    cout << endl << "Show initial status of G1: " << endl;
    //right now: 
    //77 max_battle, 5 health_loss, 5 PokeDollar_cost,10 exp_per_battle, 1 in_id, (10,15) in_loc
    gym2.ShowStatus();

    cout << endl << "Now we are adding 5 trainers to this G1 gym: " << endl;
    gym2.AddOneTrainer();
    gym2.AddOneTrainer();
    gym2.AddOneTrainer();
    gym2.AddOneTrainer();
    gym2.AddOneTrainer();
    gym2.ShowStatus();
    //now there should be 5 trainers in gym2 G1 

    //now testing for GetPokeDollarCost function:
    cout << endl << "Testing for GetPokeDollarCost() *assuming I have 7 battles:" << endl;
    int getcost_calculation = gym2.GetPokeDollarCost(7);
    cout << "7 battles * 5 pokedollar cost per battle = " << getcost_calculation << endl;

    //testing for GetHealthCost() function:
    cout << endl << "Testing for GetHealthCost() *assuming I have 10 battles: " << endl;
    int gethealth_calculation = gym2.GetHealthCost(10);
    cout << "10 battles * 5 health per battle = " << gethealth_calculation << endl;

    //testing GetNumBattlesRemaining()
    cout << endl << "Testing for GetNumBattlesRemaining(): " << endl;
    int num_battles_remaining = gym2.GetNumBattlesRemaining();
    cout << "The amount of battles remaining in gym2 is: " << num_battles_remaining << endl;

    //testing IsAbleToBattle() function:
    cout << endl << "Testing for IsAbleToBattle(): " << endl;
    int IsAbleToBattle_test = gym2.IsAbleToBattle(7, 50, 50); 
    //so I am taking 7 battles. cost for each battle is 5 and health lose for each battle is 5
    //should return true (1) since 5*7 = 35 < 50  
    cout << "Do I have enough budget and health to battle?: " << IsAbleToBattle_test << endl;
    
    //testing for TrainPokemon() function:
    cout << endl << "Testing for TrainPokemon(): " << endl;
    int TrainPokemon_experienced_gained_test_1 = gym2.TrainPokemon(80); //assuming I am taking 80 battles
    //should return 77 * 10 because 80 > 77 max battle cap  
    cout << "Experienced gained from taking battles *requested 80 : " << TrainPokemon_experienced_gained_test_1 << endl;
    int TrainPokemon_experienced_gained_test_2 = gym2.TrainPokemon(50);
    //should return 50 * 10 because 50 < 77 max battle cap: 
    cout << "Experienced gained from taking battles *requested 50 : " << TrainPokemon_experienced_gained_test_2 << endl;
    
    //testing for GetExperiencePerBattle() function:
    cout << endl << "Testing for GetExperiencePerBattle(): " << endl;
    int GetExperiencePerBattle_test = gym2.GetExperiencePerBattle(); //should return 10
    cout << "Experienced per battle in gym2 G1 is: " << GetExperiencePerBattle_test << endl;

    //testing for Update() function:
    cout << endl << "Testing for Update(): " << endl;
    int Update_test = gym2.Update(); //should return false 0;
    cout << "Are there more battles left in G1? : " << Update_test << endl;

    //testing for passed():
    cout << endl << "Testing for passed(): " << endl;
    int passed_test = gym2.passed(); //should return false 0
    cout << "Battles remaining? : " << passed_test << endl;


    cout << endl << endl << endl << "Testing PokemonCenter Class: " << endl << endl << endl;

    //initializing:
    PokemonCenter center1;

    cout << endl << "Initiazing a parameterized PokemonCenter constructor: " << endl;
    PokemonCenter center2(1, 7, 20, position1); 
    //^ ID:1 , cost 7 per potion, cap at 20 potions, center location is at 3 4
    
    cout << endl << "Show initial status of center2 C1: " << endl;
    center2.ShowStatus();

    cout << endl << "Now we are adding 5 trainers to this C1 center: " << endl;
    center2.AddOneTrainer();
    center2.AddOneTrainer();
    center2.AddOneTrainer();
    center2.AddOneTrainer();
    center2.AddOneTrainer();
    center2.ShowStatus();
    //now there should be 5 trainers in center2 C1 


    /*
    Test Checkpoint 2 material above^
    */
    cout << endl << endl << endl;
    cout << "*************************************************" << endl;
    cout << "Test checkpoint 3: " << endl << endl << endl;
    

    //initizing trainer using a default constructor:
    Trainer trainer1;

    //showing trainer1 status:
    cout << endl<< endl<< "Default Trainer Constructor: " << endl;
    trainer1.ShowStatus();

    //showing parametrized constructor:
    Trainer trainer2('T');

    cout << endl<< "parametrized Trainer Constructor: *with only char: " << endl;
    trainer2.ShowStatus();

    //overloaded parametrized constructor:
    //name: Albert, T2, speed: 2, position: 3 4
    Trainer trainer3("Albert", 2, 'T', 2, position1); 

    cout << endl << "parametrized Trainer Constructor: *with all: " << endl;
    trainer3.ShowStatus();

    //testing StartMoving(Point2D dest) function:
    //define a destination location first: 
    Point2D destination_setup;
    destination_setup.x = 50;
    destination_setup.y = 50;

    cout << endl << "testing StartMoving(Point2D dest): *not at the same place:  " << endl;
    trainer3.StartMoving(destination_setup); 
    //should print out On my way because position is 3 4 but destination is 50 50

    cout << endl << "testing StartMoving(Point2D dest): *at the same place:  " << endl;
    Trainer trainer4("Coke", 2, 'T', 2, destination_setup);
    trainer4.StartMoving(destination_setup);
    //should print out I'm already there because position is 50 50 but destination is also 50 50


    //testing StartMovingToGym(PokemonGym* gym) function:
    cout << endl << "testing StartMovingToGym(PokemonGym* gym): " << endl;
    trainer4.StartMovingToGym(&gym2); //gym 2: g1, position: 10 15

    //testing StartMovingToCenter(PokemonCenter* center) function: 
    cout << endl << "StartMovingToCenter(PokemonCenter* center): " << endl;
    trainer3.StartMovingToCenter(&center2); //center 2: c1, position: 3 4
    //trainer 3 is at position 1: 3 4  should print I am already at the center 

    //testing StartBattling(unsigned int num_battles) function:
    cout << endl << "testing StartBattling(unsigned int num_battles): " << endl;
    trainer4.StartBattling(7);

    //testing to see if ShowStatus works:
    cout << endl << "Testing ShowStatus: " << endl;
    trainer3.ShowStatus(); //should correspond to 3 AT CENTER

    //testing StartRecoveringHealth(unsigned int num_potions) function:
    cout << endl << "testing StartRecoveringHealth(unsigned int num_potions): " << endl;
    //using trainer3 since it is inside the center
    trainer3.StartRecoveringHealth(7); //using 7 potions

    //testin

    cout << endl << endl;


    return 0;
}