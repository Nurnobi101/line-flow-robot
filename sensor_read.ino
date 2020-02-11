void sensor_read() {
  if (surface == 0) {
    int s1 = analogRead(A0);
    if (s1 >= sums1) {
      c_s1 = 1;
     digitalWrite(led1, 1);

    } else {
      c_s1 = 0;
      digitalWrite(led1, 0);
    }


    int s2 = analogRead(A1);
    if (s2 >= sums2) {
      c_s2 = 1;
      digitalWrite(led2, 1);
    } else {
      c_s2 = 0;
      digitalWrite(led2, 0);
    }


    int s3 = analogRead(A2);
    if (s3 >= sums3) {
      c_s3 = 1;
      digitalWrite(led3, 1);
    } else {
      c_s3 = 0;
      digitalWrite(led3, 0);
    }


    int s4 = analogRead(A3);
    if (s4 >= sums4) {
      c_s4 = 1;
      digitalWrite(led4, 1);
    } else {
      c_s4 = 0;
      digitalWrite(led4, 0);
    }


    int s5 = analogRead(A4);
    if (s5 >= sums5) {
      c_s5 = 1;
      digitalWrite(led5, 1);
    } else {
      c_s5 = 0;
      digitalWrite(led5, 0);
    }


    int s6 = analogRead(A5);
    if (s6 >= sums6) {
      c_s6 = 1;
      digitalWrite(led6, 1);
    } else {
      c_s6 = 0;
      digitalWrite(led6, 0);
    }




  } else {

    int s1 = analogRead(A0);
    if (s1 < sums1) {
      c_s1 = 1;
      digitalWrite(led1, 1);

    } else {
      c_s1 = 0;
      digitalWrite(led1, 0);

    }


    int s2 = analogRead(A1);
    if (s2 < sums2) {
      c_s2 = 1;
      digitalWrite(led2, 1);
    } else {
      c_s2 = 0;
      digitalWrite(led2, 0);
    }


    int s3 = analogRead(A2);
    if (s3 < sums3) {
      c_s3 = 1;
      digitalWrite(led3, 1);
    } else {
      c_s3 = 0;
      digitalWrite(led3, 0);
    }


    int s4 = analogRead(A3);
    if (s4 < sums4) {
      c_s4 = 1;
      digitalWrite(led4, 1);
    } else {
      c_s4 = 0;
      digitalWrite(led4, 0);
    }


    int s5 = analogRead(A4);
    if (s5 < sums5) {
      c_s5 = 1;
      digitalWrite(led5, 1);
    } else {
      c_s5 = 0;
      digitalWrite(led5, 0);
    }


    int s6 = analogRead(A5);
    if (s6 < sums6) {
      c_s6 = 1;
      digitalWrite(led6, 1);
    } else {
      c_s6 = 0;
      digitalWrite(led6, 0);
    }
  }
}


void test_digital_value() {
  sensor_read();
  Serial.print(c_s1);
  Serial.print(" ");
  Serial.print(c_s2);
  Serial.print(" ");
  Serial.print(c_s3);
  Serial.print(" ");
  Serial.print(c_s4);
  Serial.print(" ");
  Serial.print(c_s5);
  Serial.print(" ");
  Serial.print(c_s6);
  Serial.println();
}

void test_analog_value() {
  int s1 = analogRead(A0);
  Serial.print(s1);
  Serial.print(" ");
  int s2 = analogRead(A1);
  Serial.print(s2);
  Serial.print(" ");
  int s3 = analogRead(A2);
  Serial.print(s3);
  Serial.print(" ");
  int s4 = analogRead(A3);
  Serial.print(s4);
  Serial.print(" ");
  int s5 = analogRead(A4);
  Serial.print(s5);
  Serial.print(" ");
  int s6 = analogRead(A5);
  Serial.print(s6);
  Serial.println();
}
