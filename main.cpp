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

    // 1) seat musician
    void seatMusician(Musician John);
    // 2) hold equipment
    void placeEquipment(Equipment steinwayPiano);
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
    bool inlineConsole = true;    // stumbled across a special word 'inline' here, change to inlineConsole to prevent Run error
    // 4) price (int)
    int price = 200000;
    // 5) digital or analog (bool)
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

    // 1) turn channel on or off
    bool switchOnOff(int channel); // returns current channel mute state
    // 2) mix channels
    std::string mixChannels(int channelA, int channelB, std::string outputFileName); //returns output file name
    // 3) enable EQ on a channel
    bool enableEqualiser(Equaliser channel); // enables the EQ on a specific channel, returns current state

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

    struct MultiPolarPattern
    {
        int patternChoice; // 0 omni, 1 cardioid, 2 bipolar
        int setPolarPattern(int polarPatternChoice = 0); // returns polar pattern selection as int
    }; 

    // 1) turn on
    bool switchOnOff(); // returns current power state
    // 2) plug in
    void plugInMicrophone();
    // 3) change polar pattern
    int changePolarPattern(int polarPatternChoice = 0); // returns int of polar pattern selection
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
    void recordSound(MixingConsole Neve);
    //     play back sound
    void playBackSound(MixingConsole Neve);
    //     pay musician 
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
