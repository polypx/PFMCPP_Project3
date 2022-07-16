/*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Foot
    {
        int numSteps = 0;
        int footLength = 20;
        int stepLength = 60;

        void stepForward();
        int stepSize();
    };

    Foot leftFoot;
    Foot rightFoot;
    
    void run(int howFast, bool startWithLeftFoot);
};

void Person::Foot::stepForward()
{
    ++numSteps;
}

int Person::Foot::stepSize()
{
    return footLength + stepLength;
}

void Person::run(int howFast, bool startWithLeftFoot)
{
    if ( startWithLeftFoot == true )
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }

    distanceTraveled += (leftFoot.stepSize() + rightFoot.stepSize()) * howFast;
}



 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */




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
    std::cout << "good to go!" << std::endl;
}
