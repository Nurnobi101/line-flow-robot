
int enb = 9, inc = 7, ind = 6; //right motor
int ena = 10, ina = 5, inb = 4; //left motor



int c_s1, c_s2, c_s3, c_s4, c_s5, c_s6;

int button = 11;
int buttonstate = 0;

//calibration
int dif_const = 350;
int dif1, dif2, dif3, dif4, dif5, dif6;
int fr1, fr2, fr3, fr4, fr5, fr6;
int er1, er2, er3, er4, er5, er6;
int sums1, sums2, sums3, sums4, sums5, sums6;
int surface;
int pid_flg = 0;

//PID
int set_value = 3500, error_value, posi, last_position, proposition, s_sum, s_avg, derivative;
int left_max_spd, right_max_spd, max_spd = 240;
double kp = .090 , kd = .35;

int led1 = 22, led2 = 23, led3 = 24, led4 = 25, led5 = 26, led6 = 27;




void setup() {
  Serial.begin(9600);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
  pinMode(inc, OUTPUT);
  pinMode(ind, OUTPUT);

  pinMode(button, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

}

void loop() {
  //run(0,-250);
  //test_analog_value();
  int buttonstate = digitalRead(button);
  //Serial.println(buttonstate);
  if (buttonstate == 1 && pid_flg == 0) {
    pid_flg = 1;
    sensor_read();
    calibrate ();
  }

  else if (buttonstate == 1 && pid_flg == 1) {
    while (1) {
      sensor_read();
       if ((c_s1 == 1 && c_s2 == 1 && c_s3 == 1 && c_s4 == 1 && c_s5 == 1 && c_s6 == 0) || (c_s1 == 0 && c_s2 == 1 && c_s3 == 1 && c_s4 == 1 && c_s5 == 1 && c_s6 == 1) || (c_s1 == 1 && c_s2 == 1 && c_s3 == 1 && c_s4 == 1 && c_s5 == 1 && c_s6 == 1)) {
        run(100,100);
        delay(40);
        sensor_read();
        if (c_s1 == 1 && c_s2 == 1 && c_s3 == 1 && c_s4 == 1 && c_s5 == 1 && c_s6 == 1) {
          run(-250,-250);
          delay(30);
          run(0, 0);
          delay(10000);
        }
      }
      sensor_read();
      //--------------L Shape--------------------
      if (c_s3 == 1 && c_s2 == 1 && c_s1 == 1 && c_s6 == 0) {

        while (c_s3 != 0 && c_s1 != 0) {
          sensor_read();
          run(100, 100);
        }
        run(-250, -250);
        delay(70);
        sensor_read();
        if (c_s3 == 1 || c_s4 == 1)
        {
          //plus
        }
        else
        {
          sensor_read();
          while (c_s1 != 1) {
            sensor_read();
            run(-100, 250);
          }
        }
      }

      //------------Right T-----------------
      else if (c_s6 == 1 && c_s5 == 1 && c_s4 == 1 && c_s1 == 0) {

        while (c_s6 != 0 && c_s4 != 0) {
          sensor_read();
          run(100, 100);
        }
        run(-250, -250);
        delay(70);
        sensor_read();
        if (c_s3 == 1 || c_s4 == 1)
        {
          //plus
        }
        else
        {
          sensor_read();
          while (c_s6 != 1) {
            sensor_read();
            run(250, -100);
          }
        }

      }

      else if (c_s6 == 1 && c_s1 == 1 && c_s3 == 1 && c_s4 == 1) {
        sensor_read();
        while (c_s6 != 0 && c_s1 != 0) {
          sensor_read();
          run(100, 100);
        }
        //run(-250,-250);
        //delay(30);
        //run(0,0);
        sensor_read();
        if (c_s3 == 1 || c_s4 == 1)
        {
          //plus
        }

        sensor_read();
      }
      //------------------hexagonal-----------------------------------------
      else if ((c_s1 == 1 || c_s2 == 1) && (c_s6 == 1 || c_s5 == 1) && (c_s4 == 0 || c_s3 == 0)) {
        sensor_read();
        run(-250, -250);
        delay(30);
        run(0, 0);
        while (c_s4 != 1) {
          run(-100, 100);
          sensor_read();
        }
        sensor_read();
      } else if ((c_s1 == 1 && c_s6 == 1) && (c_s2 == 0 ||  c_s3 == 0 || c_s4 == 0 || c_s5 == 0)) {
        sensor_read();
        run(-250, -250);
        delay(30);
        run(0, 0);
        delay(2000);
        while (c_s6 != 0) {
          run(-100, 100);
          sensor_read();
        }
        sensor_read();
        while (c_s4 != 1) {
          run(-100, 100);
          sensor_read();
        }
        sensor_read();
      } 

      ///-------pid------
      else {
        sensor_read();
        pid();
      }

    }
  }


}
