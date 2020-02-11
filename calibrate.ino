void calibrate () {
  run(150, 150);
  delay(20);
  fr1 = analogRead(0);
  fr2 = analogRead(1);
  fr3 = analogRead(2);
  fr4 = analogRead(3);
  fr5 = analogRead(4);
  fr6 = analogRead(5);
  delay(20);
  er1 = analogRead(0);
  er2 = analogRead(1);
  er3 = analogRead(2);
  er4 = analogRead(3);
  er5 = analogRead(4);
  er6 = analogRead(5);

  dif1 = abs(fr1 - er1);
  dif2 = abs(fr2 - er2);
  dif3 = abs(fr3 - er3);
  dif4 = abs(fr4 - er4);
  dif5 = abs(fr5 - er5);
  dif6 = abs(fr6 - er6);


  while (true) {
    er1 = analogRead(0);
    er2 = analogRead(1);
    er3 = analogRead(2);
    er4 = analogRead(3);
    er5 = analogRead(4);
    er6 = analogRead(5);

    dif1 = abs(fr1 - er1);
    dif2 = abs(fr2 - er2);
    dif3 = abs(fr3 - er3);
    dif4 = abs(fr4 - er4);
    dif5 = abs(fr5 - er5);
    dif6 = abs(fr6 - er6);

    if (dif1 > dif_const && dif2 > dif_const && dif3 > dif_const && dif4 > dif_const && dif5 > dif_const && dif6 > dif_const) {
      sums1 = (fr1 + er1) / 2;
      sums2 = (fr2 + er2) / 2;
      sums3 = (fr3 + er3) / 2;
      sums4 = (fr4 + er4) / 2;
      sums5 = (fr5 + er5) / 2;
      sums6 = (fr6 + er6) / 2;
      run(0, 0);
      break;
    }
    else {
      run(150, 150);
    }
  }
  if (fr1 < sums1) {
    surface = 0; //white
  } else {
    surface = 1; //black;
  }
  Serial.print("Calibration=");
  Serial.println(surface);
  run(0, 0);
}
