float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0,previous_I=0;  
void run_pid(int spl, int spr, int kp ,int ki ,int kd)
    {
     while(1)
       {
          read_sensor();
        
          P = error;              //  error  หามาให้ได้
          I = I + previous_I;
          D = error - previous_error;  
          previous_I=I;
          previous_error=error; 
      
          PID_value = (kp*P) + (ki*I) + (kd*D);  //  kp=20, p=-1,  10x(-1) = -20

          Motor( spl+PID_value,   spr - PID_value ); // (50+(-20), 50-(-20)) = (30, 70);
       }
    }