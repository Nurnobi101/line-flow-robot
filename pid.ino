void pid() {
  sensor_read();
  s_sum = c_s1 + c_s2 + c_s3 + c_s4 + c_s5 + c_s6; //jug kore total ber kora
  s_avg = ((c_s1 * 1 * 1000) + (  c_s2 * 2 * 1000) + (c_s3 * 3 * 1000) + (c_s4 * 4 * 1000) + (c_s5 * 5 * 1000) + (c_s6 * 6 * 1000));//ekhon
  // protitar  sathe 1000 diye gun kora 6 ta er jonno 1-6 porjonto gun then jug kora
  posi = s_avg / s_sum; // position ber korar jonno total gun kora number ke total value diye bhag
  //Serial.println(s_avg);

  if (posi < 0)// position 0 theke chuto hole
    posi = 0;//declere 0

  proposition = posi - set_value; // error ber korar jonno set value biyug position
  derivative = proposition - last_position; // error update rakhar jonno
  last_position = proposition;

  error_value = int((proposition * kp) + (derivative * kd)); // kp diye pro end kd diye derivative gun
  // Serial.println(error_value);

  if (error_value > 0) {
    right_max_spd = max_spd;
    left_max_spd = max_spd - error_value;
  } else {
    left_max_spd = max_spd;
    right_max_spd = max_spd + error_value;
  }
  
  if(right_max_spd<left_max_spd && right_max_spd<=30)
    right_max_spd-=90;

  if(right_max_spd>left_max_spd && left_max_spd<=30)
    left_max_spd-=90;
  
  
  run(right_max_spd, left_max_spd);
  
  Serial.print(error_value);
  Serial.print("Left: ");
  Serial.print(left_max_spd);
  Serial.print(" Right: ");
  Serial.print(right_max_spd);
  Serial.println(" ");
  /*
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
  */

}
