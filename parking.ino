void parking(int spl, int spr){
  switch (parking_route[park_counter]){
          case 0:
            Motor(spl,spr);                                                             // เข้าเขตส่ง
            delay(1000);
            Motor(0,0);                                                                 //  รอ
            delay(3000);
            Motor(spl,spr);                                                             //  ออกเขตส่ง
            delay(1000);
            break;
          case 1:
            Motor(spl,spr);
            delay(2000);
            break;
        }
        park_counter +=1;
}