/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

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

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

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

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


/*
Thing 1)   Piano
5 properties:
    1) height (float)
    2) width (float)
    3) weight (float)
    4) number of keys (int)
    5) number of pedals (int)
3 things it can do:
    1) play keys
    2) press sustain pedal
    3) press soft pedal
 */

struct Piano
{
    // 1) height (float)
    int height = 132;
    // 2) width (float)
    int width = 198;
    // 3) weight (float)
    int weight = 260;
    // 4) number of keys (int)
    int numberOfKeys = 88;
    // 5) number of pedals (int)
    int numberOfPedals = 2;

    // 3 things it can do:
    // 1) play keys
    void playKey(int keyNumber);
    // 2) press sustain pedal
    void pressSustainPedal();
    // 3) press soft pedal
    void pressSoftPedal();
};


/*
Thing 2) tree
5 properties:
    1) height (float)
    2) number of leaves (int)
    3) deciduous or coniferous (bool)
    4) age (int)
    5) dead or alive (bool)
3 things it can do:
    1) grow
    2) sway in the wind
    3) house squirrels
 */

struct Tree
{
    // 1) height (float)
    float height = 10.0f;
    // 2) number of leaves (int)
    int numberOfLeaves = 3000;
    // 3) deciduous or coniferous (bool)
    bool Coniferous = false;
    // 4) age (int)
    int age = 20;
    // 5) dead or alive (bool)
    bool Alive = true;

    // 1) grow
    void grow();
    // 2) sway in the wind
    void swayInTheWind(double windSpeed);
    // 3) house squirrels
    int checkSquirrelResidents(); // returns number of squirrels resident
};


/*
Thing 3) city    
5 properties:
    1) name (std::string)
    2) country (std::string)
    3) population (int)
    4) latitude (float)
    5) longitude (float)
3 things it can do:
    1) expand
    2) make laws
    3) increase population
 */

struct City
{
    // 1) name (std::string)
    std::string name = "Toronto";
    // 2) country (std::string)
    std::string country = "Canada";
    // 3) population (int)
    int population = 5000000;
    // 4) latitude (float)
    float latitude = 43.6532f;    
    // 5) longitude (float)
    float longitude = -79.3470f;  

    // 1) expand
    void expand(float expansionRate = 1.1f);
    // 2) make laws
    std::string createLaw(); // returns new law Name
    // 3) increase population
    int updatePopulation(int immigrants, int emigrants, int births, int deaths);  // returns updated population
};

/*
Thing 4) farm
5 properties:
    1) owner (std::string)
    2) acreage (float)
    3) district (std::string)
    4) annual income (int)
    5) number of employees (int)
3 things it can do:
    1) grow vegetables
    2) raise cattle
    3) pay taxes
 */

struct Farm
{
    // 1) owner (std::string)
    std::string owner = "McDonald";
    // 2) acreage (float)
    float acreage = 250.f;
    // 3) district (std::string)
    std::string district = "Durham";
    // 4) annual income (int)
    int annualIncome = 15000000;
    // 5) number of employees (int)
    int numberEmployees = 5;
    // 1) grow vegetables
    void growVegetable(std::string vegetableType);
    // 2) raise cattle
    void raiseCattle(std::string cattleType);
    // 3) pay taxes
    int payTaxes(int totalProfit); // returns taxes paid

};

/*
Thing 5) Control Room
    5 properties:
    1) length (int)
    2) width (int)
    3) height (int)
    4) monitor brand (std::string)
    5) number of seats (int)

    3 things it can do:
    1) seat engineer
    2) house console
    3) power on or off
 */

struct ControlRoom
{
    // 1) length (int)
    int length = 15;
    // 2) width (int)
    int width = 9;
    // 3) height (int)
    int height = 2;
    // 4) monitor brand (std::string)
    std::string monitorBrand = "ATC";
    // 5) number of seats (int)
    int numberSeats = 3;

    // 1) seat engineer
    void seatEngineer(std::string engineerName);
    // 2) house console
    void houseConsole();
    // 3) power on or off
    bool switchStudioPower(); // returns state of studio power
};

/*
Thing 6) Live Room
    5 properties:
    1) length (int)
    2) width (int)
    3) height (int)
    4) wall material (std::string)
    5) floor material (std::string)

    3 things it can do:
    1) seat musician
    2) hold instruments
    3) provide lighting
 */

struct LiveRoom
{
    // 1) length (int)
    int length = 26;
    // 2) width (int)
    int width = 19;
    // 3) height (int)
    int height = 4;
    // 4) wall material (std::string)
    std::string wallMaterial = "cloth";
    // 5) floor material (std::string)
    std::string floorMaterial = "wood";

    // 1) seat musician
    void seatMusician(std::string musicianName);
    // 2) hold instruments
    void placeInstrument(std::string instrumentName);
    // 3) provide lighting
    bool switchLights(); // returns state of live room lighting
};

/*
Thing 7) Computer
    5 properties:
    1) brand (std::string)
    2) CPU speed (int)
    3) RAM size GB (int)
    4) age (int)
    5) price (int)

    3 things it can do:
    1) turn on or off
    2) run software
    3) crash
 */

struct Computer
{
    // 1) brand (std::string)
    std::string brand = "Apple";
    // 2) CPU speed in MHz (int)
    int CPUspeed = 3200;  
    // 3) RAM size GB (int)
    int RAMsize = 64;
    // 4) age (int)
    int age = 2;
    // 5) price (int)
    int price = 2400;

    // 1) turn on or off
    bool switchOnOff(); // returns current power state
    // 2) run software
    void runSoftware(std::string applicationName);
    // 3) crash
    void crash();
};
/*
Thing 8) Mixing Console
    5 properties:
    1) brand (std::string)
    2) number of channels (int)
    3) inline or split line (bool)
    4) price (int)
    5) digital or analog (bool)

    3 things it can do:
    1) turn on or off
    2) mix channels
    3) provide phantom power
 */

struct MixingConsole
{
    // 1) brand (std::string)
    std::string brand = "Neve";
    // 2) number of channels (int)
    int numberOfChannels = 48;
    // 3) inline or split line console (bool)
    bool inlineConsole = true;    // stumbled across a special word 'inline' here and had to change to inlineConsole to prevent Run error
    // 4) price (int)
    int price = 200000;
    // 5) digital or analog (bool)
    bool digital = false;

    // 1) turn on or off
    bool switchOnOff(); // returns current power state
    // 2) mix channels
    std::string mixChannels(int channelA, int channelB, std::string outputFileName); //returns output file name
    // 3) provide phantom power on any of the channels
    bool switchPhantomPower(int channelNumber); // returns state of phantom power on that channel
};

/*
Thing 9) Microphone
    5 properties:
    1) brand (std::string)
    2) dynamic or condenser (bool)
    3) polar pattern (std::string)
    4) age (int)
    5) price (int)

    3 things it can do:
    1) turn on
    2) plug in
    3) change polar pattern
 */

struct Microphone
{
    // 1) brand (std::string)
    std::string brand = "Schoeps";
    // 2) dynamic or condenser (bool)
    bool condenser = true;
    // 3) polar pattern (std::string)
    std::string polarPattern = "Cardioid";
    // 4) age (int)
    int age = 6;
    // 5) price (int)
    int price = 3600;

    // 1) turn on
    bool switchOnOff(); // returns current power state
    // 2) plug in
    void plugInMicrophone();
    // 3) change polar pattern
    int changePolarPattern(int polarPattern); // returns int of polar pattern selection, if mic is multi pattern
};

/*
Thing 10)
    Recording Studio

    A Recording Studio is built using the following 5 UDTs:
        Control Room
        Live Room
        Computer
        Mixing Console
        Microphone

    A Recording Studio has 3 things it can do:
        record sound
        play back sound
        charge client
*/

struct RecordingStudio
{
    ControlRoom controlRoomA;
    LiveRoom studioA;
    Computer iMac;
    MixingConsole neveDesk;
    Microphone earthworks;

    //     record sound
    void recordSound();
    //     play back sound
    void playBackSound();
    //     charge client
    int chargeClient(int studioHours);  // returns total charge to client
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
