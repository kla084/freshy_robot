


// int button_pin = A6;
int buzzer_pin = 8;
int led_pin = 9;

int LeftMotor_pin =3; //pwmL
int RightMotor_pin = 5; //pwmR
int direction_1_leftmotor = 2;
int direction_2_leftmotor = 4;
int direction_1_rightmotor = 6;
int direction_2_rightmotor = 7;

int spl = 50;
int spr = 50;

// int Trig = 11;
// int Echo = 12;

float kp = 0.08;
float ki = 0.001;
float kd = 2;



int black = 0;   //(0-339)
int gray = 340;  //(340-779)
int white = 780; //(780-1024)

int section_route[] = {1,3,1,1,1,1,1,1,2,3,3,2,1,3,3,1,3,2,1,1,3}; // 1 =forward ,2 = left ,3 = right
int parking_route[] = {0,1,1,0,0,0,1,1,0,1}; // 0 =stop ,1= park
int obstacle_route[] = {1,2,3}; //1 = เบี่ยงซ้าย , 2 =หันหลัง , 3 =รอ 5 วินาที

int section_counter =0;  //นับจุดตัด
int park_counter=0;       //นับจุดจอด
int obstacle_counter=0;   //นับจุดอุปสรรค

void setup() 
   { 
      Serial.begin(9600); 
      // pinMode(button_pin,INPUT);
      pinMode(buzzer_pin,OUTPUT);
      pinMode(led_pin ,OUTPUT);

      digitalWrite(buzzer_pin,HIGH);
      delay(500);
      digitalWrite(buzzer_pin,LOW);
      delay(500);
      digitalWrite(buzzer_pin,HIGH);
      delay(500);
      digitalWrite(buzzer_pin,LOW);
      delay(500);
      digitalWrite(buzzer_pin,HIGH);
      delay(500);
      digitalWrite(buzzer_pin,LOW);
      delay(500);

      for(int j=0;  j < (sizeof(section_route) / sizeof(int)); j++)  {
        switch(section_route[j] ){
          case 1:
            FF(spl,spr);
            break;
            
            case 2:
            FL(spl,spr);
            break;
            
            case 3:
            FR(spl,spr);
            break;
        }
        if(park_counter == 1){           
          delay(1000);                      //หลังจุดจอดที่ 1 มีทางม้าลาย
          nokia_sound();

        }
      }
          
   }
void loop() 
   {
     
   }
