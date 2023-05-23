#include <LibPrintF.h>;

const byte LARM = 5;
const byte RARM = 6;

void setup() {
  pinMode(LARM, OUTPUT);
  pinMode(RARM, OUTPUT);

 Serial.begin(9600);
}

void loop() {
  getIngredients();
makeBurger(digitalRead(1), 1);
makeBurger(3, 0);

 int stars = customerReview();
 if(stars > 3){
   //post to socials
} else {

 }
}

void getIngredients() {
//check ingredients are in the fridge
//or some sort of hopper

//code goes here

printf("all the ingredients are ready");
}

void makeBurger(byte menuItem, bool paid){
 switch (menuItem){
  case 1 :

   break;
  case 2 :

   break;
  case 3

   break;
 }
 if(paid == 1) {
printf("all ready", menuItem);
 }else 
printf("check for cash")
 } 
}

int customerReview(); {
 int rating = -1;
rating = digitalRead(8);

 return rating;
}