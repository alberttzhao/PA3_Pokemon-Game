
#include "GameCommand.h"

/*
void DoMoveCommand(Model& model, int trainer_id, Point2D p1);
void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id);
void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id);
void DoStopCommand(Model& model, int trainer_id);
void DoBattleCommand(Model& model, int trainer_id, unsigned int battles);
void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed);
void DoAdvanceCommand(Model& model, View& view);
void DoRunCommand(Model& model, View& view);
*/

// void GetInformationFromPlayer()
// {
//     string line;
//     char command;
//     int id1;
//     int id2;
//     int position_x;
//     int position_y;

//     cout << "Enter the game command: ", cin >> line;
//     command = line[0];

//     switch(command)
//     {
//         case 'm':
//             id1 = line[2];
//             position_x = line[4];
//             position_y = line[6];
//             break;
//         case 'c':
//             id1 = line[2];
//             id2 = line[4];
//         default:
//             cout << "Invalid Command!" << endl;
//             break;
//     }

// }


void DoMoveCommand(Model& model, int trainer_id, Point2D p1)
{
    if(model.GetTrainerPtr(trainer_id) == 0)
    {
        cout << "Error: Please enter a valid command! " << endl;
        return;
    }
    else
    {
        model.GetTrainerPtr(trainer_id)->StartMoving(p1);

        cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetName() << " to " << p1 << endl;
        return;
    }
}


void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id)
{
    if((model.GetTrainerPtr(trainer_id) == 0) || (model.GetPokemonCenterPtr(center_id) == 0))
    {
        cout << "Error: Please enter a valid command! " << endl;
        return;
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->StartMovingToCenter(model.GetPokemonCenterPtr(center_id));

        cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetName() << " to Pokemon Center " << center_id << endl; 

        return;
    }
}

void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id)
{
    if(model.GetTrainerPtr(trainer_id) == 0 || model.GetPokemonGymPtr(gym_id) == 0)
    {
        cout << "Error: Please enter a valid command! " << endl;
        return;
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->StartMovingToGym(model.GetPokemonGymPtr(gym_id));

        cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetName() << " to gym " << gym_id << endl;

        return;
    }
}

void DoStopCommand(Model& model, int trainer_id)
{
    if(model.GetTrainerPtr(trainer_id) == 0)
    {
        cout << "Error: Please enter a valid command! " << endl;
        return;
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->Stop();

        cout << "Stopping " << model.GetTrainerPtr(trainer_id)->GetName() << endl;

        return;
    }
}


void DoBattleCommand(Model& model, int trainer_id, unsigned int battles)
{
    if(model.GetTrainerPtr(trainer_id) == 0)
    {
        cout << "Error: Please enter a valid command! " << endl;
        return;
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->StartBattling(battles);

        cout << model.GetTrainerPtr(trainer_id)->GetName() << " is battling. " << endl; 
        
        return;
    }
}

 void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed)
 {
    if(model.GetTrainerPtr(trainer_id) == 0)
    {
        cout << "Error: Please enter a valid command! " << endl;
        return;
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->StartRecoveringHealth(potions_needed);

        cout << "Recovering " << model.GetTrainerPtr(trainer_id)->GetName() << "'s Pokemon's health. " << endl;

        return;
    }
 }



