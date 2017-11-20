
/* 
  The circuit of LCD:
 * LCD RS pin to digital pin 2
 * LCD Enable pin to digital pin 3
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3) 
 * 
 * The circuit of Keypad
 * Key ROW 1 pin to digital pin 22
 * Key ROW 2 pin to digital pin 23
 * Key Row 3 pin to digital pin 24
 * Key Row 4 pin to digital pin 25
 * Key Col 1 pin to digital pin 26
 * Key Col 2 pin to digital pin 27
 * Key Col 3 pin to digital pin 28
 */

 // include librares
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
#include <Keypad.h>
//Global Statements
#define NUM_OF_GAMES 7

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {22, 23, 24, 25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {26, 27, 28}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

Adafruit_LiquidCrystal lcd(2,14, 3, 4, 5, 6, 7);
//Functions

//Lcd test Function
void lcd_test(){
  // Print a message to the LCD.
  lcd.print("   hello, world!    ");
  lcd.setCursor(0,1);
  lcd.print("This is the LCD test");
  delay(5000);
  // lcd test
    int i=0;
    int j=0;
    while(i<20){
      while(j<4){
        lcd.setCursor(i,j);
        lcd.print("0");
        delay(50);
        j++;
      }
      lcd.clear();
      i++;
      j=0;
  } 
    i=0;
    j=0;
    while(i<20){
      while(j<4){
        lcd.setCursor(i,j);
        lcd.print("0");        
        j++;
      }      
      i++;
      j=0;
  }
  delay(1000);
  lcd.clear();  
}
void bomb_hello(){
    
    lcd.setCursor(3,0);
    lcd.print("Hello Soldier!");
    lcd.setCursor(1,1);
    lcd.print("Press The Star Key (*) To Continue");
    while(1){
      char key = keypad.getKey();
      if (key){        
        if(key=='*'){
            lcd.clear();
            break;
        }        
      }
    }
  }
  
char* games[]={"(1)Game Of Time", "(2)The Faster", "(3)This is string 3",
"(4)Kolokithi 1", "(5)Patata 24","(6)Tirokeftes","(7)aaaa"," "};

void game_print(){
  int h;
  int i = 0;
  int j = 2;
  char key;
  while(1){

   //BEGIN WHILE 
    h=1;
    lcd.clear();
    Serial.println("hallo");
    for (i; i < j; i++){
        lcd.setCursor(3,0);
        lcd.print("Select One Game!");  
           
        lcd.setCursor(0,3);
        lcd.print("Select(Num)Scroll(#)");
        lcd.setCursor(1,h);
        lcd.print(games[i]);
        delay(500);
        h++;
    }
   // WHILE TO SELECT OR SCROL GAMES
    while(1){
     // Serial.println("a");  
      key = keypad.getKey();      
      if (key){    
            //Serial.println(key); 
        if(key=='#'){//SCROLL GAMES
          if(j>NUM_OF_GAMES){
                j=2;
                i=0;
                break;
            }
          j+=2; 
          Serial.println(i); 
          Serial.println(j);          
          break;
        }
        
        else if(key=='1'){//SELECT GAME 1
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Select Game 1");
          lcd.setCursor(0,2);
          lcd.print("Yes(*)No(#)");
          while(1){ //WHILE TO SELECT YES OR NO FOR GAME 1
              
              char key = keypad.getKey();
              if (key){   
                Serial.print(key);     
                if(key=='*'){
                 // Serial.print(key);
                  game1();
                } 
              else if(key=='#'){
                //Serial.print("aaa");
               // Serial.print(key);           
                break;
              }
             }
         }
         j=2;
         i=0;
         break;              
        }
       else if(key=='2'){
       lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Select Game 2");
          lcd.setCursor(0,2);
          lcd.print("Yes(*)No(#)");
          while(1){ //WHILE TO SELECT YES OR NO FOR GAME 2
              
              char key = keypad.getKey();
              if (key){   
                Serial.print(key);     
                if(key=='*'){
                 // Serial.print(key);
                  game2();
                } 
              else if(key=='#'){
                //Serial.print("aaa");
               // Serial.print(key);           
                break;
              }
             }
         }
         j=2;
         i=0;
         break;        
        }
        else if(key=='3'){
       lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Select Game 3");
          lcd.setCursor(0,2);
          lcd.print("Yes(*)No(#)");
          while(1){ //WHILE TO SELECT YES OR NO FOR GAME 3
              
              char key = keypad.getKey();
              if (key){   
                Serial.print(key);     
                if(key=='*'){
                 // Serial.print(key);
                  game3();
                } 
              else if(key=='#'){
                //Serial.print("aaa");
               // Serial.print(key);           
                break;
              }
             }
         }
         j=2;
         i=0;
         break;        
        }
       else if(key=='4'){
         lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Select Game 4");
          lcd.setCursor(0,2);
          lcd.print("Yes(*)No(#)");
          while(1){ //WHILE TO SELECT YES OR NO FOR GAME 4
              
              char key = keypad.getKey();
              if (key){   
                Serial.print(key);     
                if(key=='*'){
                 // Serial.print(key);
                  game4();
                } 
              else if(key=='#'){
                //Serial.print("aaa");
               // Serial.print(key);           
                break;
              }
             }
         }
         j=2;
         i=0;
         break;
        }
       else if(key=='5'){
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Select Game 5");
          lcd.setCursor(0,2);
          lcd.print("Yes(*)No(#)");
          while(1){ //WHILE TO SELECT YES OR NO FOR GAME 5
              
              char key = keypad.getKey();
              if (key){   
                Serial.print(key);     
                if(key=='*'){
                 // Serial.print(key);
                  game5();
                } 
              else if(key=='#'){
                //Serial.print("aaa");
               // Serial.print(key);           
                break;
              }
             }
         }
         j=2;
         i=0;
         break; 
        }
       else if(key=='6'){
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Select Game 6");
          lcd.setCursor(0,2);
          lcd.print("Yes(*)No(#)");
          while(1){ //WHILE TO SELECT YES OR NO FOR GAME 6
              
              char key = keypad.getKey();
              if (key){   
                Serial.print(key);     
                if(key=='*'){
                 // Serial.print(key);
                  game6();
                } 
              else if(key=='#'){
                //Serial.print("aaa");
               // Serial.print(key);           
                break;
              }
             }
         }
         j=2;
         i=0;
         break; 
        }
       else if(key=='7'){
         lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Select Game 7");
          lcd.setCursor(0,2);
          lcd.print("Yes(*)No(#)");
          while(1){ //WHILE TO SELECT YES OR NO FOR GAME 7
              
              char key = keypad.getKey();
              if (key){   
                Serial.print(key);     
                if(key=='*'){
                 // Serial.print(key);
                  game7();
                } 
              else if(key=='#'){
                //Serial.print("aaa");
               // Serial.print(key);           
                break;
              }
             }
         }
         j=2;
         i=0;
         break;       
        } 
         Serial.print("aa");    
      }
       Serial.print("bb");
            
    }
    Serial.print("cc");
  } 
  Serial.print("dd");  
 }
 
void game1(){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Game1");
      while(1){
      char key = keypad.getKey();
      if (key){        
        if(key=='*'){
            lcd.clear();
            break;
        }        
      }
    }
}  
 
void game2(){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Game2");
      while(1){
      char key = keypad.getKey();
      if (key){        
        if(key=='*'){
            lcd.clear();
            break;
        }        
      }
    }
}  
 
void game3(){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Game3");
      while(1){
      char key = keypad.getKey();
      if (key){        
        if(key=='*'){
            lcd.clear();
            break;
        }        
      }
    }
}  
 
void game4(){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Game4");
      while(1){
      char key = keypad.getKey();
      if (key){        
        if(key=='*'){
            lcd.clear();
            break;
        }        
      }
    }
}  
 
void game5(){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Game5");
      while(1){
      char key = keypad.getKey();
      if (key){        
        if(key=='*'){
            lcd.clear();
            break;
        }        
      }
    }
}  
 
void game6(){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Game6");
      while(1){
      char key = keypad.getKey();
      if (key){        
        if(key=='*'){
            lcd.clear();
            break;
        }        
      }
    }
}  

 
void game7(){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Game7");
      while(1){
      char key = keypad.getKey();
      if (key){        
        if(key=='*'){
            lcd.clear();
            break;
        }        
      }
    }
}  

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of rows and columns: 
  lcd.begin(20, 4);
  //lcd_test();
  bomb_hello();
}

void loop() {  
  game_print();
  }
