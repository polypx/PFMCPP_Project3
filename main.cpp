/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()


struct Piano
{
    int height, width, weight, numberOfKeys, numberOfPedals;
    std::string brand;
    
    Piano() : height(132), width(198), weight(260), numberOfKeys(88), numberOfPedals(2), brand("x")  { }

    int  countBbnotes(int totalKeys);
    void playKey(int keyNumber);
    void pressSustainPedal();
    void pressSoftPedal();
};

int Piano::countBbnotes(int totalKeys)
{
    int counter = 0;
    int i = 0;
    while(i < totalKeys)
    {
        if(i % 12 == 1)
        {
        counter += 1;
        }
        i += 1;
    }
    std::cout << "This piano has " << counter << " Bb octaves." << std::endl;
    return counter; 
}

void Piano::playKey(int keyNumber)
{
    if (keyNumber > numberOfKeys)
    {
       std::cout << "that note is too high" << std::endl; 
    }    
    else
    {
        std::cout << "The " << brand << " piano is playing key " <<  keyNumber << std::endl;
    }    
}

void Piano::pressSustainPedal()
{
    std::cout << "The " << brand << " sustain pedal is pressed. " << std::endl;
}

void Piano::pressSoftPedal()
{
    std::cout << "The " << brand << " soft pedal is pressed. " << std::endl;
}



struct Tree
{
    int numberOfLeaves, age, numberOfSquirrels;
    float height;
    bool Coniferous, Alive;

    Tree() : numberOfLeaves(3000), age(20), numberOfSquirrels(0), height(10.f), Coniferous(false), Alive(true) {}

    void grow();
    void swayInTheWind(double windSpeed);
    void setSquirrelResidents(int number);
    int checkSquirrelResidents(); // returns number of squirrels resident
    int squirrelPopulationGrowth(int initialPopulation, int numberMonths); // find squirrel population in so many Months
};


void Tree::grow()
{
    std::cout << "Tree is " << age << " years old" << std::endl; //3) 
}

void Tree::swayInTheWind(double windSpeed)
{
    if(windSpeed < 0)
    {
        std::cout << "negative wind speed not allowed" << std::endl;       
    } 
    else
    {
        std::cout << "Wind speed is " << windSpeed << std::endl;   
    }    
}

void Tree::setSquirrelResidents(int number)
{
    numberOfSquirrels = number;
}


int Tree::checkSquirrelResidents()
{
    return numberOfSquirrels;
}

int Tree::squirrelPopulationGrowth(int initialPopulation, int numberMonths)
{
    numberOfSquirrels = initialPopulation;
    for (int i = 0; i < numberMonths; i = i+3 ) 
    {
        numberOfSquirrels = numberOfSquirrels + numberOfSquirrels*2; // population doubles every three months
        numberOfSquirrels = numberOfSquirrels - 14; // 14 die every two months from random causes    
    }
    std::cout << "Squirrel count will be " << numberOfSquirrels << " in " << numberMonths << " months." << std::endl;
    return numberOfSquirrels;
}



struct City
{
    std::string name = "Toronto";                   // in CLASS initialisation
    std::string country = "Canada";
    std::string newLawName = "Friday's Off";
    int population = 5000000;
    float latitude = 43.6532f;    
    float longitude = -79.3470f;  

    City();

    void expand(float expansionRate = 1.1f);
    std::string createLaw(); // returns new law Name
    int updatePopulation(int immigrantsYear, int emigrantsYear, int birthsYear, int deathsYear, int years);  
};

City::City()
{
    std::cout << "City being constructed." << std::endl;
}

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

int City::updatePopulation(int immigrantsYear, int emigrantsYear, int birthsYear, int deathsYear, int years)
{
    for(int i = 0; i <= years; ++i)
    {
    population = population + immigrantsYear - emigrantsYear + birthsYear - deathsYear;
    }    
    return population;
}




struct Farm
{
    
    int annualIncome, numberEmployees, chickensTotal, acreage;
    std::string owner;

    Farm() : annualIncome(1500000), numberEmployees(5), chickensTotal(50), acreage(4), owner("Dan") {}

    void growVegetable(std::string vegetableType);
    void raiseCattle(std::string cattleType);
    int payTaxes(int totalProfit); // returns taxes owed

    int chickenMaximum(int chickens, float percentageIncreaseWeek ); // calculate maximum chickens we can fit on the farm
};


void Farm::growVegetable(std::string vegetableType)
{
    std::cout << "We're growing " << vegetableType << std::endl;      
}

void Farm::raiseCattle(std::string cattleType)
{
    std::cout << "We're raising " << cattleType << std::endl;      
}

int Farm::payTaxes(int totalProfit)
{ 
    return totalProfit / 2 ;
}

int Farm::chickenMaximum(int chickens, float percentageIncreaseWeek )
{ 
    int weeks = 1;
    int maximumChickens = acreage*50; // this is the maximum chickens we can fit
    float x;
    x = static_cast<float>(chickens);
    while (chickens < maximumChickens)
    { 
    x = x + x*percentageIncreaseWeek;
    chickens = static_cast<int>(x);    
    ++ weeks; 
    }
    std::cout << "Farm will be full of chickens in " << weeks << " weeks." << std::endl;    
    return weeks;
}



struct ControlRoom
{
    ControlRoom();

    int length, width, height, numberSeats;
    bool studioPowerState; 
    std::string monitorBrand;

    void seatEngineer(std::string engineerName);
    void houseConsole();
    bool switchStudioPower(); // returns state of studio power
};

ControlRoom::ControlRoom():                 // in constructor LIST initialisation 
length(15),
width(9),
height(2),
numberSeats(3),
studioPowerState(false),
monitorBrand("ATC")
{
    std::cout << "ControlRoom being constructed." << std::endl;
}

void ControlRoom::seatEngineer(std::string engineerName)
{
    std::cout << "Today we're enjoying the mixing skills of " << engineerName << std::endl;      
}

void ControlRoom::houseConsole()
{
}

bool ControlRoom::switchStudioPower()
{
    studioPowerState = !studioPowerState;
    if (studioPowerState)
    {
        std::cout << "Studio power is ON. "  << std::endl;       
    }
    else
    {
        std::cout << "Studio power is OFF. "  << std::endl; 
    }    
    return studioPowerState;
}



struct LiveRoom
{
    LiveRoom();                                // in  CLASS initialisation 

    int length = 26;
    int width = 19;
    int height = 4;
    std::string wallMaterial = "cloth";
    std::string floorMaterial = "wood";
    bool lightsCurrentState = false; 
    std::string studioName = "Studio A";

    struct Musician
    {
        Musician();

        std::string name, mainInstrument;
        int yearsExperience, hourlyRate;

        void callMusician();
        bool createContract(); // returns contract created or not
        int totalHoursUnpaid(); // returns total hours not yet paid
    };


    struct Equipment
    {
        Equipment();

        std::string instrument1, instrument2, instrument3;

        void tunePiano(); 
        bool switchHammond(); // returns power state of Hammond organ
        bool enableSnaresOnSnareDrum(); // returns snare wires state on snare drum, on/off

    };



    void seatMusician(Musician musicianName, std::string thisName);
    void placeEquipment(Equipment steinwayPiano);
    bool switchLights(); // returns state of live room lighting
};

LiveRoom::LiveRoom()
{
    std::cout << "LiveRoom being constructed." << std::endl;
}

LiveRoom::Musician::Musician()
{
    name = "John";                         // in constructor BODY initialise 
    mainInstrument = "Piano";
    yearsExperience = 10;
    hourlyRate = 75;
    
    std::cout << "Musician being constructed." << std::endl;
}

LiveRoom::Equipment::Equipment() :         // in constructor LIST initialise 
instrument1("Piano"),
instrument2("Guitar"),
instrument3("Drums")
{
    std::cout << "Equipment being constructed." << std::endl;
}


void LiveRoom::seatMusician(Musician musicianName, std::string thisName)
{
    musicianName.name = thisName;
    std::cout << "Today we're enjoying the dulcet tones of " << musicianName.name  << std::endl;    
}


void LiveRoom::placeEquipment(Equipment instrumentType)
{
    std::cout << "We have taken delivery of a " << instrumentType.instrument1  << std::endl;     
}

bool LiveRoom::switchLights()
{
    lightsCurrentState = !lightsCurrentState;
    if (lightsCurrentState)
    {
        std::cout << "The lights are currently on."  << std::endl; 
    } 
    else
    {
        std::cout << "The lights are currently off."  << std::endl; 
    }
    
    return lightsCurrentState;
    
}


struct Computer
{
    Computer();

    std::string brand = "Apple";                // in CLASS initialisation
    int CPUspeed = 3200;  
    int RAMsize = 64;
    int age = 2;
    int price = 2400;
    bool powerState = false; 

    bool switchOnOff(); // returns current power state
    std::string runSoftware(std::string applicationName); // return app name
    void crash();
};

Computer::Computer()
{
    std::cout << "Computer being constructed." << std::endl;
}

bool Computer::switchOnOff()
{
    powerState = !powerState;
    if (powerState)
    {
        std::cout << "The computer is currently on."  << std::endl; 
    } 
    else
    {
        std::cout << "The computer is currently off."  << std::endl; 
    }    
    return powerState;
}

std::string Computer::runSoftware(std::string programName)
{
    return programName;
}

void Computer::crash()
{
}


struct MixingConsole
{
    MixingConsole();

    std::string brand;
    int numberOfChannels;
    bool inlineConsole; //special word 'inline' here, change to inlineConsole to prevent Run error
    int price;
    bool digital;
    bool powerState; 
    int channelMix;

    struct Equaliser
    {
        Equaliser();

        bool switchEqualiser = false; 
        float highPassFilter, lowPassFilter, midBandFreq, midBandGain, midBandQ;


        void setMidBand(float frequency = 1000.f, float gain = 0.f, float quality = 1.f);
        void setHighPassFilter(float frequency = 20.f);
        void setLowPassFilter(float frequency = 20.f);
    }; 

    bool switchOnOff(); // returns current power state
    int mixChannels(int channelA, int channelB); //returns mixed output
    bool enableEqualiser(Equaliser thisEQ); // enables or disables the Equaliser

};

MixingConsole::MixingConsole()
{
    brand = "Neve";                     // in constructory BODY initialisation 
    numberOfChannels = 48;
    inlineConsole = true; //special word 'inline' here, change to inlineConsole to prevent Run error
    price = 200000;
    digital = false;
    powerState = false; 
    channelMix = 0;
    
    std::cout << "MixingConsole being constructed." << std::endl;
}

MixingConsole::Equaliser::Equaliser() :           // in constructor LIST initialise 
switchEqualiser(false),
highPassFilter(20.f),
lowPassFilter(20000.f),
midBandFreq(1000.f),
midBandGain(0.f),
midBandQ(1.f) 
{
    std::cout << "Equaliser being constructed." << std::endl;
} 

void MixingConsole::Equaliser::setMidBand(float frequency, float gain, float quality)
{
    midBandFreq = frequency;
    midBandGain = gain;
    midBandQ = quality;
}

bool MixingConsole::switchOnOff()
{
    powerState = !powerState;
    return powerState;
}

int MixingConsole::mixChannels(int channelA, int channelB)
{
    channelMix = channelA + channelB;
    return channelMix;
}

bool MixingConsole::enableEqualiser(Equaliser exampleEQ)
{
    exampleEQ.switchEqualiser = !exampleEQ.switchEqualiser;
    return exampleEQ.switchEqualiser;
}




struct Microphone
{
    Microphone();

    std::string brand = "B&K";                 // in CLASS initialisation
    bool condenser = true;
    std::string polarPattern = "Cardioid";
    int age = 6;
    int price = 3600;
    bool switchState = false; 

    bool switchOnOff(); // returns current power state
    void plugInMicrophone();
    int changePolarPattern(int polarPatternChoice = 0); // returns int of polar pattern selection
};

Microphone::Microphone()
{
    std::cout << brand << " " << polarPattern << " microphone being constructed." << std::endl;
}

bool Microphone::switchOnOff()
{
    switchState = !switchState;
    return switchState;
}

void Microphone::plugInMicrophone()
{
}

int Microphone::changePolarPattern(int polarPatternChoice)
{
    switch (polarPatternChoice)
    {
        case 0:
            polarPattern = "Omni";
            break;
        case 1:
            polarPattern = "Cardioid";
            break;
        case 2:
            polarPattern = "Figure 8";
            break;
    }
    return polarPatternChoice;
}

struct RecordingStudio
{
    RecordingStudio();

    std::string name = "Olympic";
    ControlRoom defaultControlRoom;
    LiveRoom defaultLiveRoom;
    Computer iMac;
    MixingConsole neveDesk;
    Microphone condenserMic;
    
    void recordSound(MixingConsole Neve);
    void playBackSound(MixingConsole Neve);
    int bookStudio(LiveRoom John, int hours = 5);  // returns number of hours booked
};

RecordingStudio::RecordingStudio()
{
    
    std::cout << "RecordingStudio being constructed." << std::endl;
}

void RecordingStudio::recordSound(MixingConsole chosenConsole)
{
    std::cout << "Recording on " << chosenConsole.brand  << std::endl;   
}

void RecordingStudio::playBackSound(MixingConsole chosenConsole)
{
    std::cout << "Playing back on  " << chosenConsole.brand  << std::endl;   
}

int RecordingStudio::bookStudio(LiveRoom studioChoice, int time )
{
    std::cout << "Booking studio  " << studioChoice.studioName  << std::endl;   
    return time;
}



#include <iostream>
int main()
{
    Example::main();
    
    Piano steinway;         
    steinway.brand = "Steinway";
    steinway.playKey(60);   
    steinway.pressSustainPedal(); 
    steinway.pressSoftPedal(); 
    steinway.countBbnotes(steinway.numberOfKeys);
    
    
    Tree maple;          
    maple.swayInTheWind(11);
    maple.grow();
    maple.setSquirrelResidents(17);  
    std::cout << "This tree currently has " << maple.checkSquirrelResidents() << " squirrels living in it." << std::endl;
    maple.squirrelPopulationGrowth(maple.numberOfSquirrels, 6); // estimate the squirrel count in 6 months
    
    
    City toronto;         
    toronto.expand();
    toronto.createLaw();
    std::cout << "This population of the city will be " <<  toronto.updatePopulation(4000, 1500, 18000, 17000, 5)  << " in 5 years." << std::endl;

    
    Farm oldmcdonalds;   
    oldmcdonalds.growVegetable("potatoes");
    oldmcdonalds.raiseCattle("chickens");
    oldmcdonalds.payTaxes(100000);
    std::cout << "This farm owes $" <<  oldmcdonalds.payTaxes(150000) << " in taxes." << std::endl;
    oldmcdonalds.chickenMaximum(oldmcdonalds.chickensTotal, 0.3f); // how many weeks till farm is full of chickens????

    
    RecordingStudio factory; 
    factory.name = "Factory";
    std::cout << factory.name << " studio has a " << factory.neveDesk.numberOfChannels << " channel " << factory.neveDesk.brand << " desk." << std::endl;

    factory.condenserMic.brand = "Schoeps";
    std::cout << "We'll be recording with the " << factory.condenserMic.brand  << std::endl;
    factory.defaultControlRoom.seatEngineer("Bobby V");
    
    LiveRoom::Musician tony;
    factory.defaultLiveRoom.seatMusician(tony, "Tony");
    factory.defaultLiveRoom.switchLights();



    
    std::cout << "good to go!" << std::endl;
}
