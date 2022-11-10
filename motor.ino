
void Motor(int spl, int spr)   //  ค่าในตัวแปรไม่เกิน 100 
    {
      pinMode(3,OUTPUT);  //pwmL
      pinMode(2,OUTPUT); 
      pinMode(4,OUTPUT);
      
      pinMode(5,OUTPUT);  //pwmR
      pinMode(6,OUTPUT);
      pinMode(7,OUTPUT);

      if(spl>0)
         {
            analogWrite(3,(spl*255)/100);
            digitalWrite(2,LOW);
            digitalWrite(4,HIGH); 
         }
      else if(spl<0)
         {
            analogWrite(3,-(spl*255)/100);
            digitalWrite(2,HIGH);
            digitalWrite(4,LOW); 
         }
      else
         {
            analogWrite(3,255);
            digitalWrite(2,LOW);
            digitalWrite(4,LOW); 
         }

      if(spr>0)
         {
            analogWrite(5,(spr*255)/100);
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW); 
         }
      else if(spr<0)
         {
            analogWrite(5,-(spr*255)/100);
            digitalWrite(6,LOW);
            digitalWrite(7,HIGH); 
         }
      else
         {
            analogWrite(5,255);
            digitalWrite(6,LOW);
            digitalWrite(7,LOW); 
         }

       if(spl>100)
         {
          spl = 100;
         }
       else if(spl<-100)
         {
          spl = -100;
         }

       if(spr>100)
         {
          spr = 100;
         }
       else if(spr<-100)
         {
          spr = -100;
         }
    }
