/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct Piano
{
    int height = 132;
    int width = 198;
    int weight = 260;
    int numberOfKeys = 88;
    int numberOfPedals = 2;

    void playKey(int keyNumber);
    void pressSustainPedal();
    void pressSoftPedal();
};

void Piano::playKey(int keyNumber)
{
    if (keyNumber > numberOfKeys)
    {
       std::cout << "that note is too high \n"; 
    }    
}
void Piano::pressSustainPedal()
{
}
void Piano::pressSoftPedal()
{
}



struct Tree
{
    float height = 10.0f;
    int numberOfLeaves = 3000;
    bool Coniferous = false;
    int age = 20;
    bool Alive = true;
    int numberOfSquirrels = 0;

    void grow();
    void swayInTheWind(double windSpeed);
    int checkSquirrelResidents(); // returns number of squirrels resident
};

void Tree::grow()
{
}

void Tree::swayInTheWind(double windSpeed)
{
    if(windSpeed < 0)
    {
        std::cout << "negative wind speed not allowed \n";      
    }    
}

int Tree::checkSquirrelResidents()
{
    return numberOfSquirrels;
}



struct City
{
    std::string name = "Toronto";
    std::string country = "Canada";
    std::string newLawName = "Friday's Off";
    int population = 5000000;
    float latitude = 43.6532f;    
    float longitude = -79.3470f;  

    void expand(float expansionRate = 1.1f);
    std::string createLaw(); // returns new law Name
    int updatePopulation(int immigrants, int emigrants, int births, int deaths);  // returns updated population
};

void City::expand(float expansionRate)
{
    if(expansionRate < 0.f)
    {
        std::cout << "we're shrinking! \n";      
    } 
}

std::string City::createLaw()
{
  return newLawName;  
}

int City::updatePopulation(int immigrants, int emigrants, int births, int deaths)
{
    population = population + immigrants - emigrants + births - deaths;
    return population;
}




struct Farm
{
    std::string owner = "McDonald";
    float acreage = 250.f;
    std::string district = "Durham";
    int annualIncome = 15000000;
    int numberEmployees = 5;
    void growVegetable(std::string vegetableType);
    void raiseCattle(std::string cattleType);
    int payTaxes(int totalProfit); // returns taxes owed

};

void Farm::growVegetable(std::string vegetableType)
{
        std::cout << "we're growing  " << vegetableType;      
}

void Farm::raiseCattle(std::string cattleType)
{
        std::cout << "we're raising  " << cattleType;      
}

int Farm::payTaxes(int totalProfit)
{ 
    return totalProfit / 2 ;
}


struct ControlRoom
{
    int length = 15;
    int width = 9;
    int height = 2;
    std::string monitorBrand = "ATC";
    int numberSeats = 3;
    bool studioPowerState;

    void seatEngineer(std::string engineerName);
    void houseConsole();
    bool switchStudioPower(); // returns state of studio power
};

void ControlRoom::seatEngineer(std::string engineerName)
{
        std::cout << "Today we're enjoying the mixing skills of  " << engineerName;      
}

void ControlRoom::houseConsole()
{
}

bool ControlRoom::switchStudioPower()
{
    studioPowerState = !studioPowerState;
    return studioPowerState;
}



struct LiveRoom
{
    int length = 26;
    int width = 19;
    int height = 4;
    std::string wallMaterial = "cloth";
    std::string floorMaterial = "wood";
    bool lightsCurrentState;

    struct Musician
    {
        std::string name = "John";
        std::string mainInstrument = "Piano";
        int yearsExperience = 1;
        int hourlyRate = 75;

        void callMusician();
        bool createContract(); // returns contract created or not
        int totalHoursUnpaid(); // returns total hours not yet paid
    };

    struct Equipment
    {
        std::string instrument1 = "Piano";
        std::string instrument2 = "DrumKit";
        std::string instrument3 = "Hammond Organ";

        void tunePiano(); 
        bool switchHammond(); // returns power state of Hammond organ
        bool enableSnaresOnSnareDrum(); // returns snare wires state on snare drum, on/off

    };

    void seatMusician(Musician John);
    void placeEquipment(Equipment steinwayPiano);
    bool switchLights(); // returns state of live room lighting
};

void LiveRoom::seatMusician(Musician John)
{
    std::cout << "Today we're enjoying the dulcet tones of  " << John.name;     
}

void LiveRoom::placeEquipment(Equipment instrumentType)
{
    std::cout << "We have taken delivery of a " << instrumentType.instrument1;     
}

bool LiveRoom::switchLights()
{
    lightsCurrentState = !lightsCurrentState;
    return lightsCurrentState;
}


struct Computer
{
    std::string brand = "Apple";
    int CPUspeed = 3200;  
    int RAMsize = 64;
    int age = 2;
    int price = 2400;

    bool switchOnOff(); // returns current power state
    void runSoftware(std::string applicationName);
    void crash();
};


struct MixingConsole
{
    std::string brand = "Neve";
    int numberOfChannels = 48;
    bool inlineConsole = true;    // stumbled across a special word 'inline' here, change to inlineConsole to prevent Run error
    int price = 200000;
    bool digital = false;

    struct Equaliser
    {
        bool switchEqualiser;
        float highPassFilter = 20.0f;
        float lowPassFilter = 20000.0f;
        float midBandFreq = 1000.0f;
        float midBandGain = 0.f;
        float midBandQ = 1.0f;

        void setMidBand(float frequency = 1000.f, float gain = 0.f, float quality = 1.f);
        void setHighPassFilter(float frequency = 20.f);
        void setLowPassFilter(float frequency = 20.f);
    }; 

    bool switchOnOff(int channel); // returns current channel mute state
    std::string mixChannels(int channelA, int channelB, std::string outputFileName); //returns output file name
    bool enableEqualiser(Equaliser channel); // enables the EQ on a specific channel, returns current state

};



struct Microphone
{
    std::string brand = "Schoeps";
    bool condenser = true;
    std::string polarPattern = "Cardioid";
    int age = 6;
    int price = 3600;

    struct MultiPolarPattern
    {
        int patternChoice; // 0 omni, 1 cardioid, 2 bipolar
        int setPolarPattern(int polarPatternChoice = 0); // returns polar pattern selection as int
    }; 

    bool switchOnOff(); // returns current power state
    void plugInMicrophone();
    int changePolarPattern(int polarPatternChoice = 0); // returns int of polar pattern selection
};



struct RecordingStudio
{
    ControlRoom controlRoomA;
    LiveRoom studioA;
    Computer iMac;
    MixingConsole neveDesk;
    Microphone earthworks;

    void recordSound(MixingConsole Neve);
    void playBackSound(MixingConsole Neve);
    int payMusician(LiveRoom John);  // pays musician for hours he was playing
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Example::main();
    
    std::cout << "good to go!" << std::endl;
}
