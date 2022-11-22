
#include "Model.h"

Model::Model()
{
    time = 0;

    //objects:

    //C1 is a PokemonCenter:
    Point2D C1_initial_location;
    C1_initial_location.x = 1;
    C1_initial_location.y = 20;
    PokemonCenter* center1_ptr = new PokemonCenter(1, 1, 100, C1_initial_location);
    object_ptrs[2] = center1_ptr;
    center_ptrs[0] = center1_ptr;

    //C2 is a PokemonCenter:
    Point2D C2_initial_location;
    C2_initial_location.x = 10;
    C2_initial_location.y = 20;
    PokemonCenter* center2_ptr = new PokemonCenter(2, 2, 200, C2_initial_location);
    object_ptrs[3] = center2_ptr;
    center_ptrs[1] = center2_ptr;

    //T1 is a Trainer:
    Point2D T1_initial_location;
    T1_initial_location.x = 5;
    T1_initial_location.y = 1;
    Trainer* trainer1_ptr = new Trainer("Ash", 1, 'T', 1, T1_initial_location);
    object_ptrs[0] = trainer1_ptr;
    trainer_ptrs[0] = trainer1_ptr; 
    
    //T2 is a trainer:
    Point2D T2_initial_location;
    T2_initial_location.x = 10;
    T2_initial_location.y = 1;
    Trainer* trainer2_ptr = new Trainer("Misty", 2, 'T', 2, T2_initial_location);
    object_ptrs[1] = trainer2_ptr;
    trainer_ptrs[1] = trainer2_ptr;

    //G1 is a PokemonGym:
    Point2D G1_initial_location;
    G1_initial_location.x = 0;
    G1_initial_location.y = 0;
    PokemonGym* gym1_ptr = new PokemonGym(10, 1, 2, 3, 1, G1_initial_location);
    object_ptrs[4] = gym1_ptr;
    gym_ptrs[0] = gym1_ptr;

    //G2 is a PokemonGym:
    Point2D G2_initial_location;
    G2_initial_location.x = 5;
    G2_initial_location.y = 5;
    PokemonGym* gym2_ptr = new PokemonGym(20, 5, 7.5, 4, 2, G2_initial_location);
    object_ptrs[5] = gym2_ptr;
    gym_ptrs[1] = gym2_ptr;

    //others:
    num_objects = 6;
    num_trainers = 2;
    num_centers = 2;
    num_gyms = 2;

    cout << "Model default constructed" << endl;

}

Model::~Model()
{
    cout << "Model destructed" << endl;
}


Trainer* Model::GetTrainerPtr(int id)
{
    if(trainer_ptrs[id] != NULL)
    {
        //return if pointer is found:
        return trainer_ptrs[id];
    }
    else
    {
        //return 0 if pointer is not found:
        return 0;
    }
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
    if(center_ptrs[id] != NULL)
    {
        return center_ptrs[id];
    }
    else
    {
        return 0;
    }
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
    if(gym_ptrs[id] != NULL)
    {
        return gym_ptrs[id];
    }
    else
    {
        return 0;
    }
}

bool Model::Update()
{
    //increment time:
    time = time + 1;

    for(int i = 0; i < sizeof(object_ptrs); i++)
    {
        if(object_ptrs[i]->Update() == true)
        {
            return true;
        }
    }
    return false;
}



// void Model::Display(View& view)
// {

// }


void Model::ShowStatus(){

    cout << "Time: " << time << endl; 

    for (int i = 0; i < num_objects; i++){
        object_ptrs[i]->ShowStatus();
    }
}



