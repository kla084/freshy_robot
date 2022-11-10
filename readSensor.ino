 int a0,a1,a2,a3,a4;
 void read_sensor()
    {
       //Serial.println(error);
       a0 = analogRead(A0);
       a1 = analogRead(A1);
       a2 = analogRead(A2);
       a3 = analogRead(A3);
       a4 = analogRead(A4);

           if((a0< gray)&&(a1>= white)&&(a2 > white)&&(a3>= white)&&(a4>= white))   error=-4;     //(ดำ,ขาว,ขาว,ขาว,ขาว)  // light zone
      else if((a0< gray)&&(a1< gray)&&(a2 > white)&&(a3>= white)&&(a4>= white))     error=-3;     //(ดำ,ดำ,ขาว,ขาว,ขาว)
      else if((a0>= white)&&(a1< gray)&&(a2 > white)&&(a3>= white)&&(a4>= white))   error=-2;     //(ขาว,ดำ,ขาว,ขาว,ขาว)
      else if((a0>= white)&&(a1< gray)&&(a2< gray)&&(a3>= white)&&(a4>= white))     error=-1;     //(ขาว,ดำ,ดำ,ขาว,ขาว)
      else if((a0>= white)&&(a1>= white)&&(a2< gray)&&(a3>= white)&&(a4>= white))   error=0;      //(ขาว,ขาว,ดำ,ขาว,ขาว)
      else if((a0>= white)&&(a1>= white)&&(a2< gray)&&(a3< gray)&&(a4>= white))     error=1;      //(ขาว,ขาว,ดำ,ดำ,ขาว)
      else if((a0>= white)&&(a1>= white)&&(a2>= white)&&(a3< gray)&&(a4>= white))   error=2;      //(ขาว,ขาว,ขาว,ดำ,ขาว)
      else if((a0>= white)&&(a1>= white)&&(a2>= white)&&(a3< gray)&&(a4< gray))     error=3;      //(ขาว,ขาว,ขาว,ดำ,ดำ)
      else if((a0>= white)&&(a1>= white)&&(a2>= white)&&(a3>= white)&&(a4< gray))   error=4;      //(ขาว,ขาว,ขาว,ขาว,ดำ)
      
      else if((a0>=white)&&(a1< gray)&&(a2< gray)&&(a3< gray)&&(a4< gray))          error=-4;     //(ขาว,ดำ,ดำ,ดำ,ดำ)     // dark zone
      else if((a0>=white)&&(a1>=white)&&(a2 > white)&&(a3< gray)&&(a4< gray))       error=-3;     //(ขาว,ขาว,ดำ,ดำ,ดำ)
      else if((a0< gray)&&(a1>=white)&&(a2 > white)&&(a3< gray)&&(a4< gray))        error=-2;     //(ดำ,ขาว,ดำ,ดำ,ดำ)
      else if((a0< gray)&&(a1>=white)&&(a2>=white)&&(a3< gray)&&(a4< gray))         error=-1;     //(ดำ,ขาว,ขาว,ดำ,ดำ)
      else if((a0< gray)&&(a1< gray)&&(a2>=white)&&(a3< gray)&&(a4< gray))          error=0;      //(ดำ,ดำ,ขาว,ดำ,ดำ)
      else if((a0< gray)&&(a1< gray)&&(a2>=white)&&(a3>=white)&&(a4< gray))         error=1;      //(ดำ,ดำ,ขาว,ขาว,ดำ)
      else if((a0< gray)&&(a1< gray)&&(a2< gray)&&(a3>=white)&&(a4< gray))          error=2;      //(ดำ,ดำ,ดำ,ขาว,ดำ)
      else if((a0< gray)&&(a1< gray)&&(a2< gray)&&(a3>=white)&&(a4>=white))         error=3;      //(ดำ,ดำ,ดำ,ขาว,ขาว)
      else if((a0< gray)&&(a1< gray)&&(a2< gray)&&(a3< gray)&&(a4>=white))          error=4;      //(ดำ,ดำ,ดำ,ดำ,ขาว)

      else if((a0< gray)&&(a1>= gray)&&(a2 > gray)&&(a3>= gray)&&(a4>= gray))       error=-4;     //(ดำ,เทา,เทา,เทา,เทา)  // gray zone
      else if((a0< gray)&&(a1< gray)&&(a2 > gray)&&(a3>= gray)&&(a4>= gray))        error=-3;     //(ดำ,ดำ,เทา,เทา,เทา)
      else if((a0>= gray)&&(a1< gray)&&(a2 > gray)&&(a3>= gray)&&(a4>= gray))       error=-2;     //(เทา,ดำ,เทา,เทา,เทา)
      else if((a0>= gray)&&(a1< gray)&&(a2< gray)&&(a3>= gray)&&(a4>= gray))        error=-1;     //(เทา,ดำ,ดำ,เทา,เทา)
      else if((a0>= gray)&&(a1>= gray)&&(a2< gray)&&(a3>= gray)&&(a4>= gray))       error=0;      //(เทา,เทา,ดำ,เทา,เทา)
      else if((a0>= gray)&&(a1>= gray)&&(a2< gray)&&(a3< gray)&&(a4>= gray))        error=1;      //(เทา,เทา,ดำ,ดำ,เทา)
      else if((a0>= gray)&&(a1>= gray)&&(a2>= gray)&&(a3< gray)&&(a4>= gray))       error=2;      //(เทา,เทา,เทา,ดำ,เทา)
      else if((a0>= gray)&&(a1>= gray)&&(a2>= gray)&&(a3< gray)&&(a4< gray))        error=3;      //(เทา,เทา,เทา,ดำ,ดำ)
      else if((a0>= gray)&&(a1>= gray)&&(a2>= gray)&&(a3>= gray)&&(a4< gray))       error=4;      //(เทา,เทา,เทา,เทา,ดำ)
      
    }