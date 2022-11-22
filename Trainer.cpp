
#include "Trainer.h"

//destructor:
Trainer::~Trainer()
{
    cout << "Trainer destructed" << endl;
}


//default constructor:

Trainer::Trainer() : GameObject('B') //verify this later 
{
    speed = 5;
    cout << "Trainer default constructed. " << endl;

    //initialize other variables:
    is_at_center = false;
    is_IN_GYM = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    //name
    current_center = NULL;
    current_gym = NULL;
    //destination;
    //delta;
}

Trainer::Trainer(char in_code) : GameObject(in_code)
{
    speed = 5;
    cout << "Trainer constructed." << endl;

    //initialize other variables:
    is_at_center = false;
    is_IN_GYM = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    //name
    current_center = NULL;
    current_gym = NULL;
    //destination;
    //delta;
}

Trainer::Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc, in_id, in_code)
{
    speed = in_speed;
    name = in_name;
    cout << "Trainer constructed." << endl;

    //initialize other variables:
    is_at_center = false;
    is_IN_GYM = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    //name
    current_center = NULL;
    current_gym = NULL;
    //destination;
    //delta;
}


void Trainer::SetupDestination(Point2D dest)
//delta = (destination – location) * (speed / GetDistanceBetween(destination, location))
{
    destination = dest;
    delta = (dest - location) * (speed / GetDistanceBetween(dest , location));
}

void Trainer::StartMoving(Point2D dest)
{
    SetupDestination(dest);
    if(GetDistanceBetween(location, destination) == 0) //apparently this would not work
    {
        cout << display_code << id_num << ": I'm already there. See?" << endl;
    }
    else if(state == FAINTED)
    {
       cout << display_code << id_num << ": My pokemon have fainted. I may move but you cannot see me." << endl;
    }
    else
    {
        state = MOVING;
        cout << display_code << id_num << ": On my way." << endl;
    }
}

void Trainer::StartMovingToGym(PokemonGym* gym)
{
    SetupDestination(gym->GetLocation());
    current_gym = gym;
    if(state == FAINTED)
    {
        cout << display_code << id_num << ": My Pokemon have fainted so I can't move to gym... " << endl;
    }
    else if(GetDistanceBetween(location, destination) == 0)
    {
        state = IN_GYM;
        current_gym = gym;
        cout << display_code << id_num << ": I am already at the PokemonGym! " << endl;
    }
    else
    {
        state = MOVING_TO_GYM;
        cout << display_code << id_num << ": on my way to gym " <<  gym->GetId() << endl;
    }
}

void Trainer::StartMovingToCenter(PokemonCenter* center)
{
    SetupDestination(center->GetLocation());
    current_center = center;
    if(state == FAINTED)
    {
        cout << display_code << id_num << ": My pokemon have fainted so I should have gone to the center.." << endl;
    }
    else if(GetDistanceBetween(location, destination) == 0)
    {
        state = AT_CENTER;
        current_center = center;
        cout << display_code << id_num << ": I am already at the Center! " << endl;
    }
    else
    {
        state = MOVING_TO_CENTER;
        cout << display_code << id_num << ": On my way to Center " << center->GetId() << endl;
    }
}


void Trainer::StartBattling(unsigned int num_battles)
{
    if(state == FAINTED)
    {
        cout << display_code << id_num << ": My Pokemon have fainted so no more battles for me... " << endl;
    }
    else if(state != IN_GYM)
    {
        cout << display_code << id_num << ": I can only battle in a PokemonGym!" << endl;
    }
    else if(PokeDollars < current_gym->GetPokeDollarCost(num_battles)) //?
    {
        cout << display_code << id_num << ": Not enough money for battles" << endl;
    }
    else if(current_gym->GetNumBattlesRemaining() < num_battles) //?
    {
        cout << display_code << id_num << ": Cannot battle! This PokemonGym has no more trainers to battle" << endl;
    }
    else
    {
        state = BATTLING_IN_GYM;
        battles_to_buy = num_battles; //?
        //need to add: update the remaining battles in the gym . This will be used when its Update() function is called.
    }
}

void Trainer::StartRecoveringHealth(unsigned int num_potions)
{

    if(current_center->CanAffordPotion(num_potions , PokeDollars) == false)
    {
        cout << display_code << id_num << ": Not enough money to recover health. " << endl;
    }
    else if(current_center->HasPotions() == false)
    {
        cout << display_code << id_num << ": Cannot recover! No potion remaining in this Pokemon Center " << endl;
    }
    else if(state != AT_CENTER)
    {
        cout << display_code << id_num << ": I can only recover health at a Pokemon Center! " << endl;
    }
    else
    {
        //the trainer can start recovering health
        //potions_to_buy = num_potions;
        //need to add: update the remaining potions in the center. This will be used when its Update() function is called
        
        //add 5 health for every potion used:
        unsigned int potions_to_buy = current_center->DistributePotion(num_potions);
        health = health + (5 * potions_to_buy); //?
    }
}

void Trainer::Stop()
{
    state = STOPPED;
    cout << display_code << id_num << ": Stopping..." << endl;
}


bool Trainer::HasFainted()
{
    if(health == 0)
        return true;
    else
        return false;
}

bool Trainer::ShouldBeVisible()
{
    if(state == FAINTED)
        return false;
    else
        return true;
}

/*
    STOPPED = 0,
    MOVING = 1,
    FAINTED = 2,
    AT_CENTER = 3,
    IN_GYM = 4,
    MOVING_TO_CENTER = 5,
    MOVING_TO_GYM = 6,
    BATTLING_IN_GYM = 7,
    RECOVERING_HEALTH = 8
*/

void Trainer::ShowStatus()
{
    cout << name << " status: ";
    GameObject::ShowStatus();
    switch(state)
    {
        case 0:
            cout << "stopped" << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 1:
            cout << "moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 6:
            cout << "heading to PokemonGym " << current_gym->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 5:
            cout << "heading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 4:
            cout << "inside PokemonGym " << current_gym->GetId() << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 3:
            cout << "inside PokemonCenter " << current_center->GetId() << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 7:
            cout << "battling in PokemonGym " << current_gym->GetId() << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 8:
            cout << "recovering health in Pokemon Center " << current_center->GetId() << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
    }
}


bool Trainer::Update()
{
    switch(state)
    {
        case 0: //stopped
            return false;
            break;
        case 1: //moving
            if(UpdateLocation() == true) //? 
            {
                state = STOPPED;
                return true;
                break;
            }
            else
            {
                state = MOVING; //is this necessary?
                return false; 
                break;
            }
        case 6: //moving_to_gym
            if(UpdateLocation() == true)
            {
                state = IN_GYM;
                return true;
                break;
            }
            else
            {
                state = MOVING_TO_GYM;
                return false;
                break;
            }
        case 5: //moving to center
            if(UpdateLocation() == true)
            {
                state = AT_CENTER;
                return true;
                break;
            }
            else
            {
                state = MOVING_TO_CENTER;
                return false;
                break;
            }
        case 4: //in gymn
            return false;
            break;
        case 3: //at center
            return false;
            break;
        case 7: //battling in gym
        {
            unsigned int current_health_cost =  current_gym->GetHealthCost(battles_to_buy);
            health = health - current_health_cost;//? reduce Trainer health based on total health cost for the current gym request

            unsigned int current_dollar_cost = current_gym->GetPokeDollarCost(battles_to_buy);
            PokeDollars = PokeDollars - current_dollar_cost;

            unsigned int current_experience_gain = current_gym->TrainPokemon(battles_to_buy);
            experience = experience - current_experience_gain;

            if(battles_to_buy <= 1)
                cout << "** " << name << " completed " << battles_to_buy << " battle! **" << endl;
            else 
                cout << "** " << name << " completed " << battles_to_buy << " battles! **" << endl;

            cout << "** " << name << " gained " << current_experience_gain << " experiences! **" << endl;

            state = IN_GYM;
            return true;
            break;
        }

        case 8: //recovering_health
        {
            unsigned int healthpoints_recovered = potions_to_buy * 5;
            

            unsigned int current_dollar_cost = current_center->GetPokeDollarCost(potions_to_buy);
            PokeDollars = PokeDollars - current_dollar_cost;

            cout << "** " << name << " recovered " << healthpoints_recovered << " experiences! **" << endl;
            if(potions_to_buy <= 1)
                cout << "** " << name << " bought " << potions_to_buy << " potion! **" << endl;
            else 
                cout << "** " << name << " bought " << potions_to_buy << " potions! **" << endl;

            state = AT_CENTER;
            return true;
            break;  
        }
        default:
            return false;
    }
}



//protected members:

bool Trainer::UpdateLocation()
//update the location while the object is moving
{
    if((fabs(destination.x - location.x) < delta.x) && (fabs(destination.y - location.y) < delta.y))
    {
        cout << display_code << id_num << ": I'm there!" << endl;
        location = destination; //? don't know if I have to do location.x = destination.x or not
        return true;
    }
    else
    {
        location = location + delta;
        PokeDollars = PokeDollars + GetRandomAmountOfPokeDollars(); //should be right? get random dollar everytime the trainer takes a step
        health = health - 1; //lose one health everytime you move
        cout << display_code << id_num << ": step..." << endl;
        return false;
    }
}

string Trainer::GetName()
{
    return name;
}


//get random amount of PokeDollar everytime the trainer takes a step:
//non-member function:
double GetRandomAmountOfPokeDollars()
{
    srand(time(NULL));
    float rando = static_cast<float>(rand()) / static_cast<float>(RAND_MAX/2.0);
    return rando;
}
