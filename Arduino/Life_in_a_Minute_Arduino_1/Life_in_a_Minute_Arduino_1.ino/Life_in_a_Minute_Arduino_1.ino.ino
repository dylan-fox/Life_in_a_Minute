/*------------------------------------------------------------------------
Prints a receipt following a user's participation in the 'Life in a Minute' penny-throwing experience.

SETUP:
1. Add 'Adafruit_Thermal' folder to Documents/Arduino/Libraries
2. Open Serial Monitor and set to 19200 baud.

Attendant weighs jars of pennies one by one, entering their weights in grams via the serial monitor in the following order:
1. Career
2. Community
3. Education
4. Family
5. Play


To translate weight into years spent on each area:
1. Subtracts the weight of the jar
2. Divides by the weight of a penny to get # of pennies
3. Divides by 10 pennies/year to get # of years per category

Finally, it should print a receipt with the years spent on each category and 'other'.

  ------------------------------------------------------------------------*/

#include "Adafruit_Thermal.h"
#include "adalogo.h"
#include "adaqrcode.h"

// Here's the new syntax when using SoftwareSerial (e.g. Arduino Uno) ----
// If using hardware serial instead, comment out or remove these lines:

#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor
// Then see setup() function regarding serial & printer begin() calls.

// Here's the syntax for hardware serial (e.g. Arduino Due) --------------
// Un-comment the following line if using hardware serial:

//Adafruit_Thermal printer(&Serial3);      // Or Serial2, Serial3, etc.

// -----------------------------------------------------------------------

//KEY VARIABLES

float jarWeight = 559;
int numJars = 5;
float pennyWeight = 2.5;
float penniesPerYear = 10;

float careerWeight = 0; //weights in grams, INCLUDING JARS
float communityWeight = 0;
float educationWeight = 0;
float familyWeight = 0;
float playWeight = 0;

float careerYears = 0; //converted to years of life
float communityYears = 0;
float educationYears = 0;
float familyYears = 0;
float playYears = 0;
float wastedYears = 0;
//float allYears[] = {0,0,0,0,0};

//char serInString[100];
String inString = "";
float measurement = 0;  //user measurement
int phase = 1; //     //1 - enter Career weight; prompt for community
                      //2 - enter Community weight; prompt for education
                      //3 - enter Education weight; prompt for Family
                      //4 - enter Family weight; prompt for play
                      //5 - enter Play weight
                      //6 - print receipt

void setup() {

  // This line is for compatibility with the Adafruit IotP project pack,
  // which uses pin 7 as a spare grounding point.  You only need this if
  // wired up the same way (w/3-pin header into pins 5/6/7):
  pinMode(7, OUTPUT); digitalWrite(7, LOW);

  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
  mySerial.begin(19200);  // Initialize SoftwareSerial
  Serial.begin(19200); // Use this instead if using hardware serial
  printer.begin();        // Init printer (same regardless of serial type)
  Serial.println("Ready to begin.");
  Serial.println("Enter the weight of the Career jar in grams.");


/*
  // The following calls are in setup(), but don't *need* to be.  Use them
  // anywhere!  They're just here so they run one time and are not printed
  // over and over (which would happen if they were in loop() instead).
  // Some functions will feed a line when called, this is normal.

  // Test inverse on & off
  printer.inverseOn();
  printer.println(F("Inverse ON"));
  printer.inverseOff();

  // Test character double-height on & off
  printer.doubleHeightOn();
  printer.println(F("Double Height ON"));
  printer.doubleHeightOff();

  // Set text justification (right, center, left) -- accepts 'L', 'C', 'R'
  printer.justify('R');
  printer.println(F("Right justified"));
  printer.justify('C');
  printer.println(F("Center justified"));
  printer.justify('L');
  printer.println(F("Left justified"));

  // Test more styles
  printer.boldOn();
  printer.println(F("Bold text"));
  printer.boldOff();

  printer.underlineOn();
  printer.println(F("Underlined text"));
  printer.underlineOff();

  printer.setSize('L');        // Set type size, accepts 'S', 'M', 'L'
  printer.println(F("Large"));
  printer.setSize('M');
  printer.println(F("Medium"));
  printer.setSize('S');
  printer.println(F("Small"));

  printer.justify('C');
  printer.println(F("normal\nline\nspacing"));
  printer.setLineHeight(50);
  printer.println(F("Taller\nline\nspacing"));
  printer.setLineHeight(); // Reset to default
  printer.justify('L');

  // Barcode examples:
  // CODE39 is the most common alphanumeric barcode:
  printer.printBarcode("ADAFRUT", CODE39);
  printer.setBarcodeHeight(100);
  // Print UPC line on product barcodes:
  printer.printBarcode("123456789123", UPC_A);

  // Print the 75x75 pixel logo in adalogo.h:
  printer.printBitmap(adalogo_width, adalogo_height, adalogo_data);

  // Print the 135x135 pixel QR code in adaqrcode.h:
  printer.printBitmap(adaqrcode_width, adaqrcode_height, adaqrcode_data);
  printer.println(F("Adafruit!"));
  printer.feed(2);

  printer.sleep();      // Tell printer to sleep
  delay(3000L);         // Sleep for 3 seconds
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults
  */

  
}

void loop() {
  //Serial.println("Beginning of loop.");
  //Serial.println(phase);
  //while (Serial.available() == null) {
  //  measurement = Serial.parseFloat();
  //}
  
  // clear the string
  //memset(serInString, 0, 100);
  //read the serial port and create a string out of what you read
  //readSerialString(serInString);
  //measurement = serInString[0].toFloat();

  //Take in code
  //while (Serial.available() > 0 || measurement == 0) {
  while(Serial.available() > 0) {
    
    char inChar = Serial.read();

    if (isDigit(inChar) || inChar == '.') {
      inString += inChar;
      //Serial.println(inString);
    }
    /*
    else if (isWhitespace(inChar)) {
      measurement = inString.toFloat();
      //Serial.print("Measurement entered: ");
      //Serial.println(measurement);
      //Serial.print("Phase: ");
      //Serial.println(phase);
      //Serial.print("Serial.available: ");
      //Serial.println(Serial.available());
      inString = "";
    }
    */
  }
  measurement = inString.toFloat();
  inString = "";
  
  if (measurement != 0) {
  if (phase == 1) {
    careerWeight = measurement;
    Serial.print("Career weight set to: ");
    Serial.println(careerWeight);
    Serial.println();
    Serial.println("Enter the weight of the Community jar in grams.");
  }

  else if (phase == 2) {
    communityWeight = measurement;
    Serial.print("Community weight set to: ");
    Serial.println(communityWeight);
    Serial.println();
    Serial.println("Enter the weight of the Education jar in grams.");
  }
  
  else if (phase == 3) {
    educationWeight = measurement;
    Serial.print("Education weight set to: ");
    Serial.println(educationWeight);
    Serial.println();
    Serial.println("Enter the weight of the Family jar in grams.");
  }
  
  else if (phase == 4) {
    familyWeight = measurement;
    Serial.print("Family weight set to: ");
    Serial.println(familyWeight);
    Serial.println();
    Serial.println("Enter the weight of the Play jar in grams.");
  }
  
  else if (phase == 5) {
    playWeight = measurement;
    Serial.print("Play weight set to: ");
    Serial.println(playWeight);
    Serial.println();

    //Final activities
    Serial.println("Years spent per category: ");
    careerYears = weightToYears (careerWeight, jarWeight, pennyWeight, penniesPerYear);
    communityYears = weightToYears (communityWeight, jarWeight, pennyWeight, penniesPerYear);
    educationYears = weightToYears (educationWeight, jarWeight, pennyWeight, penniesPerYear);
    familyYears = weightToYears (familyWeight, jarWeight, pennyWeight, penniesPerYear);
    playYears = weightToYears (playWeight, jarWeight, pennyWeight, penniesPerYear);

    wastedYears = 71.5 - careerYears - communityYears - educationYears - familyYears - playYears;

    Serial.print("Career: ");
    Serial.println(careerYears);
    Serial.print("Community: ");
    Serial.println(communityYears);
    Serial.print("Education: ");
    Serial.println(educationYears);
    Serial.print("Family: ");
    Serial.println(familyYears);
    Serial.print("Play: ");
    Serial.println(playYears);
    Serial.print("Wasted: ");
    Serial.println(wastedYears);
    Serial.println();
    


    //Sort by time spent
    /*
    float allYears[] = {careerYears, communityYears, educationYears, familyYears, playYears};

    Serial.println("Sorted largest to smallest: ");
    sortArray(allYears, numJars);
    int i;
    for (i = 0; i < numJars; i = i + 1) {
      Serial.println(allYears[i]);
    }
    */
    Serial.println("Print receipt? Enter 1 for yes or 2 for no.");
  }

  else if (phase == 6) {
    if (measurement == 1) {
      Serial.println("Printing receipt.");
      printReceipt(careerYears, communityYears, educationYears, familyYears, playYears, wastedYears);
    }
    else {
      Serial.println("Receipt printing cancelled.");
    }
    
    phase = 0;
    Serial.println("\n\nEnter the weight of the Career jar in grams.");
  }

  phase +=1;
  measurement = 0;
  }
  delay(100); 
  
}

float weightToYears (float measuredWeight, float jarWeight, float pennyWeight, float penniesPerYear) {
  float weightSansJar = measuredWeight - jarWeight;
  float numPennies = weightSansJar / pennyWeight;
  float years = numPennies / penniesPerYear;
  return years;
}

void printReceipt (float careerYears, float communityYears, float educationYears, float familyYears, float playYears, float wastedYears) {
  Serial.println("Printing...");
  printer.setDefault(); 

  //Title
  printer.inverseOn();
  printer.setSize('M');
  printer.println(F("--Life In A Minute--"));
  printer.inverseOff();
  printer.println(F(""));

  //Header
  printer.setSize('L');
  printer.println(F("Your Life"));
  printer.setSize('S');
  printer.println(F(""));


  //Career
  printer.justify('L');
  printer.println(F("Career"));
  printer.justify('R');
  printer.print(careerYears);
  printer.println(F(" years"));
  printer.println(F(""));

  //Community
  printer.justify('L');
  printer.println(F("Community"));
  printer.justify('R');
  printer.print(communityYears);
  printer.println(F(" years"));
  printer.println(F(""));

  //Education
  printer.justify('L');
  printer.println(F("Education"));
  printer.justify('R');
  printer.print(educationYears);
  printer.println(F(" years"));
  printer.println(F(""));

  //Family
  printer.justify('L');
  printer.println(F("Family"));
  printer.justify('R');
  printer.print(familyYears);
  printer.println(F(" years"));  
  printer.println(F(""));

  //Play
  printer.justify('L');
  printer.println(F("Play"));
  printer.justify('R');
  printer.print(playYears);
  printer.println(F(" years"));
  printer.println(F(""));
  

  //Wasted
  printer.justify('L');
  printer.println(F("Other"));
  printer.justify('R');
  printer.print(wastedYears);
  printer.println(F(" years"));
  printer.println(F(""));

  float totalYears = careerYears + communityYears + educationYears + familyYears + playYears + wastedYears;
  printer.println(F(""));
  //Total
  printer.setSize('M');
  printer.justify('L');
  printer.println(F("Total"));
  printer.justify('R');
  printer.print(totalYears);
  printer.println(F(" years"));


  //Farewell
  printer.println(F(""));
  printer.setSize('S');
  printer.inverseOn();
  printer.justify('L');
  printer.println(F("-Have a good afterlife!-"));
  printer.inverseOff();
  printer.feed(4);
  Serial.println("Done printing.");
}

void sortArray (float inArray[], int arraySize) {
  //Sorts an array of numbers from largest to smallest.
  int i, j;
  for (i = 0; i < arraySize - 1; i = i + 1) {
    //Serial.println(inArray[i]);
    for (j = 0; j < arraySize - 1 - i;  j = j + 1) {
      if (inArray[j] < inArray[j + 1]) {
        swap(inArray[j], inArray[j + 1]);
      }
    }
  }
}

void swap(float a, float b) {
  float temp = a; 
  a = b;
  b = temp;
}

