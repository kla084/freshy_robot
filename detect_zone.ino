float distance;
int reduce_speed = 0.5;
void detect_zone(int spl ,int spr){
      
        if( (analogRead(A0)>= white) && (analogRead(A4)>= white) )                                                            // light_zone_ตรงไป
        {
            digitalWrite(led_pin,LOW); 
            if(park_counter == 2){                                                                                            // ผ่านจุดจอดที่ 2 เจอทางเบี่ยง
              avoid_obstacle(spl,spr);
            }
            else if (section_counter == 12){                                                                                  // ผ่านแยกที่ 10 เจอเขตอันตราย
              avoid_obstacle(spl,spr);
            }
            else{
              run_pid(spl,spr,kp,ki,kd);
            }
        }
     else if( (analogRead(A0)>= gray && analogRead(A0) < white) && (analogRead(A4)>= gray && analogRead(A4) < white ) )     // gray_zone_ตรงไป
        {
          digitalWrite(led_pin,LOW); 
          run_pid(spl * reduce_speed,spr * reduce_speed,kp,ki,kd);
        }
     else if( (analogRead(A0)< gray) && (analogRead(A2) >= white) && (analogRead(A4) < gray) )                              // dark_zone_ตรงไป
        {
          digitalWrite(led_pin,HIGH);                                                                                       //เปิด led
          run_pid(spl,spr,kp,ki,kd);
        }

     else if( (analogRead(A0)>= white) && (analogRead(A4)< gray) )                                                          // light_zone_เลี้ยวขวา
        {
          digitalWrite(led_pin,LOW);
          run_pid(spl,spr,kp,ki,kd);
        }

     else if( (analogRead(A0)>= gray && analogRead(A0) < white) && (analogRead(A4)< gray) )                                 // gray_zone_เลี้ยวขวา
        {
          digitalWrite(led_pin,LOW);
          run_pid(spl,spr,kp,ki,kd);
        }
     else if( (analogRead(A0) < gray) && (analogRead(A2) <gray) && (analogRead(A4)>= white) )                               // dark_zone_เลี้ยวขวา
        {
          digitalWrite(led_pin,HIGH);                                                                                       //เปิด led
          run_pid(spl,spr,kp,ki,kd);
        }

     else if( (analogRead(A0)< gray) && (analogRead(A4)>= white ))                                                          // light_zone_เลี้ยวซ้าย
        {
          digitalWrite(led_pin,LOW);
          run_pid(spl,spr,kp,ki,kd);
        }
     else if( (analogRead(A0) < gray) && (analogRead(A4)>= gray && analogRead(A4) < white) )                                 // gray_zone_เลี้ยวซ้าย
        {
          digitalWrite(led_pin,LOW);
          run_pid(spl* reduce_speed,spr* reduce_speed,kp,ki,kd);
        }
     else if( (analogRead(A0) >=white) && (analogRead(A2) <gray) && (analogRead(A4) < gray) )                               // dark_zone_เลี้ยวซ้าย
        {
          digitalWrite(led_pin,HIGH);                                                                                       //เปิด led
          run_pid(spl,spr,kp,ki,kd);
        }

     else if( (analogRead(A0)>= white) && (analogRead(A1)>= white) && (analogRead(A2)>= white) && (analogRead(A3)>= white) && (analogRead(A4)>= white)  ) // ขาวหมด -> หยุด
        {
          digitalWrite(led_pin,LOW);
          Motor(0,0);
          digitalWrite(buzzer_pin,HIGH);
          delay(1000);
          digitalWrite(buzzer_pin,LOW);
          delay(1000);
        }     

      else if ((analogRead(A0) < gray) && (analogRead(A1) <gray) && (analogRead(A2) < gray)){                                // light_zone_จุดจอด_ซ้าย
        digitalWrite(led_pin,LOW);
        parking(spl,spr);
      }

      else if ((analogRead(A0) >= white) && (analogRead(A1) >= white) && (analogRead(A2) >= white)){                         // dark_zone_จุดจอด_ซ้าย
        digitalWrite(led_pin,HIGH);
        parking(spl,spr);
      }

      else if ((analogRead(A2) < gray) && (analogRead(A3) <gray) && (analogRead(A4) < gray)){                                // light_zone_จุดจอด_ขวา
        digitalWrite(led_pin,LOW);
        parking(spl,spr);

      }

      else if ((analogRead(A2) >= white) && (analogRead(A3) >= white) && (analogRead(A4) >= white)){                         // dark_zone_จุดจอด_ขวา
        digitalWrite(led_pin,HIGH);
        parking(spl,spr);
      }

}