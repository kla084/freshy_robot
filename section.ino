// void FST(int spl, int spr)   //  เดินตามเส้น ถึงแยกให้หยุด
//   {
//    while(1)
//      {
//       hcsr04 ()
//       detect_zone(spl ,spr);

//       if(analogRead(A1) < gray && analogRead(A3) < gray ){
//         break;
//       }
     
//      Motor(0,0);
//      delay(10);
//   }

void FF(int spl, int spr)   //  เดินตามเส้น ถึงแยกให้ข้ามเส้น
  {
   while(1)
     {
      
       detect_zone(spl ,spr);
      
     if( (analogRead(A1)< gray) && (analogRead(A2)< gray) && (analogRead(A3)< gray) )    // light zone 4-แยกตั้งฉาก , 3-แยกตั้งฉาก
        {
          do
            {
              Motor(spl,spr);
            }
           while  ( analogRead(A4)< gray );
           
          break;
        }        

     else if( (analogRead(A0)< gray) && (analogRead(A1) > white ) && (analogRead(A2)< gray) )    // light zone 3-แยกมุมแหลมไปทางซ้าย
        {
          do
            {
              Motor(spl,spr);
            }
           while  ( analogRead(A0)< gray ); //เดี๋ยวแก้
           
          break;
        }        
     
      else if( (analogRead(A0) >= white ) && (analogRead(A1) < gray) && (analogRead(A2)>= white) )    // dark zone 3-แยกมุมแหลมไปทางซ้าย
        {
          do
            {
              Motor(spl,spr);
            }
           while  ( analogRead(A0) >= white );
           
          break;
        }        
      else if( (analogRead(A2)< gray) && (analogRead(A3)>= white) && (analogRead(A4) < gray) )    // light zone 3-แยกมุมแหลมไปทางขวา
        {
          do
            {
              Motor(spl,spr);
            }
           while  ( analogRead(A4) < gray );
           
          break;
        } 
      else if( (analogRead(A2) >= white) && (analogRead(A3) < gray) && (analogRead(A4)>= white) )    // dark zone 3-แยกมุมแหลมไปทางขวา
        {
          do
            {
              Motor(spl,spr);
            }
           while  ( analogRead(A4) >= white );
           
          break;
        }        
     }
     //Motor(0,0);
    //  delay(10);
  }

void FL(int spl, int spr)   //  เดินตามเส้น ถึงแยกให้เลี้ยวซ้าย ถ้าเจอแยกขวาไม่จำเป็นต้องเลี้ยวซ้าย
  {
  while(1)
     {

      
       detect_zone(spl ,spr);
      
     if( (analogRead(A1)< gray) && (analogRead(A2)< gray) && (analogRead(A3)< gray) )    // light zone 4-แยกตั้งฉาก , 3-แยกตั้งฉาก
        {
          Motor(40,40);
          delay(700);
          Motor(0,0);
          delay(200);
          
          do
            {
              Motor(-40,40);
            }
          while  ( analogRead(A1) > white );
             
          break;
        }        

     else if( (analogRead(A0) < gray) && (analogRead(A1) >= white) && (analogRead(A2)< gray) )    // light zone 3-แยกมุมแหลมไปทางซ้าย
        {
          Motor(40,40);
          delay(700);
          Motor(0,0);
          delay(200);
          
          do
            {
              Motor(-40,40);
            }
          while  ( analogRead(A0) >= white );
             
          break;
        }        
     
      else if( (analogRead(A0) >= white) && (analogRead(A1) < gray) && (analogRead(A2)>= white) )    // dark zone 3-แยกมุมแหลมไปทางซ้าย
        {
          Motor(40,40);
          delay(700);
          Motor(0,0);
          delay(200);
          
          do
            {
              Motor(-40,40);
            }
          while  ( analogRead(A0)< gray );
             
          break;
        }        
      
              
     }
    //  delay(200);
    //  Motor(0,0);
    //  delay(10);
  }
void FR(int spl, int spr)   //  เดินตามเส้น ถึงแยกให้เลี้ยวขวา ถ้าเจอแยกซ้ายไม่จำเป็นต้องเลี้ยวขวา
  {
     while(1)
     {

      
       detect_zone(spl ,spr);
      
     if( (analogRead(A1)< gray) && (analogRead(A2)< gray) && (analogRead(A3)< gray) )    // light zone 4-แยกตั้งฉาก , 3-แยกตั้งฉาก
        {
          Motor(40,40);
          delay(700);
          Motor(0,0);
          delay(200);
          
          do
            {
              Motor(40,-40);
            }
          while  ( analogRead(A3)>=white );
           
          break;
        }        
      else if( (analogRead(A2)< gray) && (analogRead(A3)>= white) && (analogRead(A4) < gray) )    // light zone 3-แยกมุมแหลมไปทางขวา
         {
          do
            {
              Motor(40,-40);
            }
          while  ( analogRead(A4) >=white );
           
          break;
        } 
      else if( (analogRead(A2) >= white) && (analogRead(A3)>= gray) && (analogRead(A4)>= white) )    // dark zone 3-แยกมุมแหลมไปทางขวา
        {
          do
            {
              Motor(40,-40);
            }
          while  ( analogRead(A4) < gray );
           
          break;
        }         
     }
    //  delay(200);
    //  Motor(0,0);
    //  delay(10);
  } 
