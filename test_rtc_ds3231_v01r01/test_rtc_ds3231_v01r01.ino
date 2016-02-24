/* ---------------------------------------------------------
Package     :  wsn v.1
Module      :  main
Copyright   :  (c) 2016 by Antonio Curci 

Copyright 2014-2016 by Antonio Curci. All rights reserved.
Redistribution and use in source and binary forms,
with or without modification, are not permitted.


-------------------------------------------------------- */
// ******************** DEFINES
#define sersetup()  Serial.begin(9600)
#define pr(x)  Serial.print(x)
#define prln(x)  Serial.println(x)
#define prf(x)  Serial.print(F(x))
#define prfln(x)  Serial.println(F(x))

// ******************** WARNINGS


// ******************** CONSTANTS
// ******************** VARIABLES
// ******************** FUNCTIONS

// ******************** ARDUINO
void setup() {
  sersetup();
  rtcsetup();
  prf("\r\ntest RTC DS3231 v.01.01 (C) Copyright 2016 by Antonio Curci\r\n");

  rtcoutYY(16);
  rtcoutMM(2);
  rtcoutDD(24);
  rtcoutDW(4);
  rtcouthh(22);
  rtcoutmm(33);
  rtcoutss(00);
  rtcwrite();
}

void loop() {
  rtcread();
  //rtcpr();
  rtcprdate(); pr(' '); rtcprtime();
  /*
  prf("Hour: ");   prln(rtcinhh());
  prf("Minute: "); prln(rtcinmm());
  prf("Second: "); prln(rtcinss());
  prf("Year: ");   prln(rtcinYY());
  prf("Month: ");  prln(rtcinMM());
  prf("Day: ");    prln(rtcinDD());
  */
  prf("  Dow: ");    pr(rtcinDW());
  prf("  Temp: ");   prln(rtcintemp());

  prln();
  delay(3000);
}
