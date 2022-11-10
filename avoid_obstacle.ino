void avoid_obstacle(int spl,int spr){
        switch (obstacle_route[obstacle_counter]){
          case 1:
            Motor(-spl,spr);                                                                                                   // หมุนซ้าย
            delay(1000);
            Motor(spl,spr);                                                                                                       // ไปข้างหน้า
            delay(1000); 
            Motor(spl,-spr);                                                                                                   // หมุนขวา
            delay(1000);                                                                                                     
            Motor(spl,spr);                                                                                                   // ไปข้างหน้า
            delay(1000);
            Motor(spl,-spr);                                                                                                   // หมุนขวา
            delay(1000);                                                                                                     
            Motor(spl,spr);                                                                                                   // ไปข้างหน้า
            delay(1000);
            Motor(-spl,spr);                                                                                                   // หมุนซ้าย
            delay(1000);
            break;
          case 2:
            Motor(-spl,-spr);                                                                                                 //ถอยหลัง
            delay(2000);
            Motor(spl,-spr);                                                                                                  // หมุนขวา
            delay(1000);
            break;
          case 3:
            Motor(0,0);
            delay(5000);
            break;
        }
        obstacle_counter +=1;
}