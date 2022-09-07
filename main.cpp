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




struct Piano
{
    Piano();

    
    int height = 132;
    int width = 198;
    int weight = 260;
    int numberOfKeys = 88;
    int numberOfPedals = 2;
    std::string brand = "Heintzman";

    void playKey(int keyNumber);
    void pressSustainPedal();
    void pressSoftPedal();
};

Piano::Piano()
{
    std::cout << "Piano being constructed" << std::endl; //2) 
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
    Tree();

    float height = 10.0f;
    int numberOfLeaves = 3000;
    bool Coniferous = false;
    int age = 20;
    bool Alive = true;
    int numberOfSquirrels = 0;

    void grow();
    void swayInTheWind(double windSpeed);
    void setSquirrelResidents(int number);
    int checkSquirrelResidents(); // returns number of squirrels resident
};

Tree::Tree()
{
    std::cout << "Tree being constructed" << std::endl; //3) 
}

void Tree::grow()
{
}

void Tree::swayInTheWind(double windSpeed)
{
    if(windSpeed < 0)
    {
        std::cout << "negative wind speed not allowed" << std::endl;       
    } else
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



struct City
{
    City();

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

int City::updatePopulation(int immigrants, int emigrants, int births, int deaths)
{
    population = population + immigrants - emigrants + births - deaths;
    return population;
}




struct Farm
{
    Farm();

    std::string owner = "McDonald";
    float acreage = 250.f;
    std::string district = "Durham";
    int annualIncome = 15000000;
    int numberEmployees = 5;
    void growVegetable(std::string vegetableType);
    void raiseCattle(std::string cattleType);
    int payTaxes(int totalProfit); // returns taxes owed

};

Farm::Farm()
{
    std::cout << "Farm being constructed." << std::endl;
}

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


struct ControlRoom
{
    ControlRoom();

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

ControlRoom::ControlRoom()
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
    return studioPowerState;
}



struct LiveRoom
{
    LiveRoom();

    int length = 26;
    int width = 19;
    int height = 4;
    std::string wallMaterial = "cloth";
    std::string floorMaterial = "wood";
    bool lightsCurrentState;
    std::string studioName = "Studio A";

    struct Musician
    {
        Musician();

        std::string name = "John";
        std::string mainInstrument = "Piano";
        int yearsExperience = 10;
        int hourlyRate = 75;

        void callMusician();
        bool createContract(); // returns contract created or not
        int totalHoursUnpaid(); // returns total hours not yet paid
    };

    struct Equipment
    {
        Equipment();

        std::string instrument1 = "Piano";
        std::string instrument2 = "DrumKit";
        std::string instrument3 = "Hammond Organ";

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
    std::cout << "Musician being constructed." << std::endl;
}

LiveRoom::Equipment::Equipment()
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
    } else
    {
        std::cout << "The lights are currently off."  << std::endl; 
    }
    
    return lightsCurrentState;
    
}


struct Computer
{
    Computer();

    std::string brand = "Apple";
    int CPUspeed = 3200;  
    int RAMsize = 64;
    int age = 2;
    int price = 2400;
    bool powerState;

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
    return powerState;
}

std::string Computer::runSoftware(std::string MSWord)
{
    return MSWord;
}

void Computer::crash()
{
}


struct MixingConsole
{
    MixingConsole();

    std::string brand = "Neve";
    int numberOfChannels = 48;
    bool inlineConsole = true; //special word 'inline' here, change to inlineConsole to prevent Run error
    int price = 200000;
    bool digital = false;
    bool powerState;
    int channelMix;

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

    bool switchOnOff(); // returns current power state
    int mixChannels(int channelA, int channelB); //returns mixed output
    bool enableEqualiser(Equaliser thisEQ); // enables or disables the Equaliser

};

MixingConsole::MixingConsole()
{
    std::cout << "MixingConsole being constructed." << std::endl;
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

    std::string brand = "xxx";
    bool condenser = true;
    std::string polarPattern = "Cardioid";
    int age = 6;
    int price = 3600;
    bool switchState;

    bool switchOnOff(); // returns current power state
    void plugInMicrophone();
    int changePolarPattern(int polarPatternChoice = 0); // returns int of polar pattern selection
};

Microphone::Microphone()
{
    std::cout << "Microphone being constructed." << std::endl;
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
    
    Piano steinway;         // instantiate a piano called "steinway"
    steinway.brand = "Steinway";
    steinway.playKey(60);   //  play middle C on the steinway
    steinway.pressSustainPedal(); // press the sustain pedal on the steinway
    steinway.pressSoftPedal(); // press the sustain pedal on the steinway

    
    Tree maple;             // instantiate a tree called "maple"
    maple.setSquirrelResidents(17);  
    std::cout << "This tree has " << maple.checkSquirrelResidents() << " squirrels living in it." << std::endl;
    maple.swayInTheWind(11);
    maple.grow();

    
    City toronto;           // instantiate a city called "toronto"
    toronto.expand();
    toronto.createLaw();
    std::cout << "This population of the city is now " <<  toronto.updatePopulation(4000, 1500, 18000, 17000) << std::endl;

    
    Farm oldmcdonalds;      // instatiate a farm
    oldmcdonalds.growVegetable("potatoes");
    oldmcdonalds.raiseCattle("chickens");
    oldmcdonalds.payTaxes(100000);
    std::cout << "This farm owes $" <<  oldmcdonalds.payTaxes(150000) << " in taxes." << std::endl;
    
    
    RecordingStudio factorysound;   // the RecordingStudio instatiate constructs all the other UDTs included in it
                                    // but those all set to defaults within their definitions, so... how 
                                    // do we construct an entire RecordingStudio fresh? 
    factorysound.name = "Factory Sound";
    
    std::cout << factorysound.name << " studio has a " << factorysound.neveDesk.numberOfChannels << " channel " << factorysound.neveDesk.brand << " mixing desk." << std::endl;

    factorysound.condenserMic.brand = "Schoeps";
    std::cout << "We'll be recording with the " << factorysound.condenserMic.brand  << std::endl;
    
    factorysound.defaultControlRoom.seatEngineer("Bobby V");
    
    LiveRoom::Musician tony;
    factorysound.defaultLiveRoom.seatMusician(tony, "Tony");

    factorysound.defaultLiveRoom.switchLights();
    
    std::cout << "good to go!" << std::endl;
}
