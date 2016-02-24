/* ---------------------------------------------------------
Package     :  wsn v.1
Module      :  rtc
Copyright   :  (c) 2016 by Antonio Curci 

Copyright 2014-2016 by Antonio Curci. All rights reserved.
Redistribution and use in source and binary forms,
with or without modification, are not permitted.
-------------------------------------------------------- */

// ******************** WARNINGS
/* 
 Note: 
  1. temperature is updated every 64 seconds by the DS3231
  2. DateTime struct:
     Second: 0-59 
     Minute: 0-59
     Hour:   0-23
     Dow:    1-7  (1=Sunday)
     Day:    1-31
     Month:  1-12
     Year:   0-199

*/

// ******************** LIBRARIES
#include <DS3231_Simple.h>

// ******************** DEFINES

// ******************** CONSTANTS

// ******************** VARIABLES
boolean rtn;    // enabled

DS3231_Simple Clock;
DateTime dt;  

// ******************** FUNCTIONS
void rtcsetup() {Clock.begin();rtcen(true);}
void rtcen(bool f) {rtn=f;}  
bool rtcena()  {return rtn;}  

void rtcread() {dt=Clock.read();}
void rtcwrite() {Clock.write(dt);}

float rtcintemp() {return Clock.getTemperatureFloat();}

// get
byte rtcinYY() {return dt.Year;}
byte rtcinMM() {return dt.Month;}
byte rtcinDD() {return dt.Day;}
byte rtcinDW() {return dt.Dow;}
byte rtcinhh() {return dt.Hour;}
byte rtcinmm() {return dt.Minute;}
byte rtcinss() {return dt.Second;}

// set
void rtcoutYY(byte x) {dt.Year=x;}
void rtcoutMM(byte x) {dt.Month=x;}
void rtcoutDD(byte x) {dt.Day=x;}
void rtcoutDW(byte x) {dt.Dow=x;}
void rtcouthh(byte x) {dt.Hour=x;}
void rtcoutmm(byte x) {dt.Minute=x;}
void rtcoutss(byte x) {dt.Second=x;}

// print
void rtcprdate() {Clock.printDateTo_DMY(Serial,dt);}  
void rtcprdateYMD() {Clock.printDateTo_YMD(Serial,dt);}  

void rtcprtime() {Clock.printTimeTo_HMS(Serial,dt);}  
void rtcprtimeHM() {Clock.printTimeTo_HM(Serial,dt);}  

