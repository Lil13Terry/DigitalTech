//18060
//Terry Daniels


// including servo libary to use servos
# include <Servo.h>
# include <LibPrintf.h>

// adding the LibPrintf libary to make outputs look better for easier debugging and terminal use


// setting up constant variables with name to reference for later use
const byte SERVOPIN = 5;
const byte CHOICEPIN = 1;
const byte STARTBTN = 2;
// setting LED variables to seperate anolog pins
const byte LED1 = A1;
const byte LED2 = A2;
const byte LED3 = A3;
const byte LED4 = A4;

// stores data for LED states
// values can be 1-4 because of "blink" method
byte LEDVALUE = 1;


// setting servo variable name to "lock" for later reference
Servo lock;
// creating 2 variables for servo use (open and close)
const byte OPEN_SERVO = 90;
const byte CLOSE_SERVO = 0;
// creating a KEY variable to open the box, for values 1-4 (when key is true, box will open)
const byte KEY = 3;


// creating a boolian with a false value
bool STARTBOOL = false;



void setup() { // setup code runs once when starting up
  // setting our CHOICEBTN and STARTBTN to input pins
  pinMode(CHOICEPIN, INPUT);
  pinMode(STARTBTN, INPUT);
  // setting the anolog pin to output pins, will be used for LEDs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  //attaching servo to our SERVOPIN variable
  lock.attach(SERVOPIN);

  // moving "lock" servo to CLOSE_SERVO (closing box) when starting program
  lock.write(CLOSE_SERVO);


  // used for error compiling/debugging in terminal
  Serial.begin(9600);






}

void loop() { // loop runs until it is terminated

  //if digitalRead of STARTBTN pin is HIGH run code (if STARTBTN is pressed)
  if (digitalRead(STARTBTN) == HIGH) {
    // changes bool STARTBOOL between true and false
    STARTBOOL =! STARTBOOL;

   // writing statement to terminal
    Printf("game is set to %b", STARTBOOL)
    // adding a small delay for functional use
    delay(250);

  }


  if (STARTBOOL) // if STARTBOOL var is true, execute code, else skip
 
  { blink(400); //changing this value will change how long lights will take to turn on in ms

 
  printf(" LEDVALUE is %i and KEY is %i\n", LEDVALUE,KEY)


// if LEDVALUE and KEY variable are the same, AND the user is pressing the CHOICEBTN, the code will run else it will skip
    if (LEDVALUE == KEY && CHOICEPIN == HIGH) {
      lock.write(OPEN_SERVO);
    }
  }
}



  void blink(int length) {
    // turning off all LEDs
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);

    // creating a switch using LEDCOICE variable
    //use 4 cases for each LED pin, changing LEDCHOICE will change outcome of switch
    switch (LEDVALUE) {
      case 1:
        digitalWrite(LED1, HIGH);
        break;
      case 2:
        digitalWrite(LED2, HIGH);
        break;
      case 3:
        digitalWrite(LED3, HIGH);
        break;
      case 4:
        digitalWrite(LED4, HIGH);
        //reset the switch
        LEDVALUE = 1;
    }
    // adds 1 to LEDCHOICE to start next switch case
    LEDVALUE++;


    delay(length);  // temporarily stops code for time in ms

  }