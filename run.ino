void run(int left , int right) {
  if (left < 0) {
    digitalWrite(inc, LOW);
    digitalWrite(ind, HIGH);
    left = left * -1;
  } else {
    digitalWrite(inc, HIGH);
    digitalWrite(ind, LOW);
  }
  if (right < 0) {
    digitalWrite(ina, LOW);
    digitalWrite(inb, HIGH);
    right = right * -1;
  } else {
    digitalWrite(ina, HIGH);
    digitalWrite(inb, LOW);
  }
  analogWrite(enb, left);
  analogWrite(ena, right);
}




void dead_end()
{
  delay(50);
  run(-200, -200);
  delay(100);
  run(-150, 150);
  while (c_s1 != 1)
  {
    run(-200, 200);
    sensor_read();
  }
  run(200, -200);
  delay(30);
  run(0, 0);
}
//void left()
//{
//  while (c_s3 == 1 || c_s4 == 1)
//  {
//    run(-150, 150);
//    sensor_read();
//  }
//  run(0, 0);
//  while (c_s3 != 1)
//  {
//    run(-150, 150);
//    sensor_read();
//  }
//  run(150, -150);
//  delay(30);
//  run(0, 0);
//}
//void right()
//{
//  while (c_s3 == 1 || c_s4 == 1)
//  {
//    run(150, -150);
//    sensor_read();
//  }
//  run(0, 0);
//  while (c_s4 != 1)
//  {
//    run(150, -150);
//    sensor_read();
//  }
//  run(-150, 150);
//  delay(30);
//  run(0, 0);
//}
void straight()
{
  sensor_read();
  pid();
}


//void halt()
//{
//  run(250,250);
//  delay(80);
//  run(-250,-250);
//  delay(30);
//  run(0,0);
//  run(-250,250);
//  delay(420);
//  run(250,-250);
//  delay(20);
//  run(0,0);
//  run(250,250);
//  delay(200);
//  run(0,0);
//  lhr();
//  go_bot();
//  //while(1) run(0,0);
//  
//}
