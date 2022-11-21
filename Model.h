#pragma once

#include <iostream>
#include "GameObject.h"
#include "Trainer.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Point2D.h"

using namespace std;

class Model
{

private:

    int time;
    GameObject* object_ptrs[10];
    int num_objects;
    Trainer* trainer_ptrs[10];
    int num_trainers;
    PokemonCenter* center_ptrs[10];
    int num_centers;
    PokemonGym* gym_ptrs[10];
    int num_gyms;

public:

    //default constructor:
    Model();
    
    //destructor:
    ~Model();

    //functions:
    Trainer* GetTrainerPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);

    bool Update();
    //void Display(View& view);
    void ShowStatus();
    
};