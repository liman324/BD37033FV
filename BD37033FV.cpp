#include <Arduino.h>
#include <Wire.h>
#include "BD37033FV.h"

BD37033FV::BD37033FV(){
	Wire.begin();
}

void BD37033FV::setInitial(){
             int initial = 0b00100100;
           writeWire(INITIAL_SETUP, initial); 
   }

void BD37033FV::setSub_setup(int sub_f,int sub_out, int faza){
          switch(sub_f){
             case 0: sub_f = 0b00000000;break;  
             case 1: sub_f = 0b00000001;break; 
             case 2: sub_f = 0b00000010;break; 
             case 3: sub_f = 0b00000011;break; 
             case 4: sub_f = 0b00000100;break; 
             case 5: sub_f = 0b00000101;break;        
   }   
          switch(sub_out){
             case 0: sub_out = 0b00000000;break;  
             case 1: sub_out = 0b00010000;break; 
             case 2: sub_out = 0b00100000;break; 
             case 3: sub_out = 0b00110000;break;
   } 
          switch(faza){
             case 0: faza = 0b00000000;break;
             case 1: faza = 0b10000000;break;
   }
             int sub_set_sum = sub_f + sub_out + faza;
             writeWire(LPF_SETUP, sub_set_sum); 
   }

void BD37033FV::setLoud_f(int mix_in, int loud_f, int mix_ch1, int mix_ch2){
             switch(mix_in){
             case 0: mix_in = 0b00000000;break;  
             case 1: mix_in = 0b01000000;break; 
             case 2: mix_in = 0b10000000;break; 
             case 3: mix_in = 0b11000000;break; 
   }
             switch(loud_f){
             case 0: loud_f = 0b00000000;break;  
             case 1: loud_f = 0b00001000;break; 
             case 2: loud_f = 0b00010000;break; 
             case 3: loud_f = 0b00011000;break;      
   }   
             switch(mix_ch1){
             case 0: mix_ch1 = 0b00000000;break;  
             case 1: mix_ch1 = 0b00000010;break; 
   }
             switch(mix_ch2){
             case 0: mix_ch2 = 0b00000000;break;  
             case 1: mix_ch2 = 0b00000100;break; 
   }     
             int loun_sum = 0b00000001 + loud_f + mix_ch1 + mix_ch2 + mix_in;
             writeWire(MIXING_SETUP, loun_sum); 
   }

void BD37033FV::setIn(int in){
             switch(in){
             case 0: in = 0b00000000;break;  
             case 1: in = 0b00000001;break; 
             case 2: in = 0b00000010;break;      
   }   
             writeWire(INPUT_SELECT, in); 
   }

void BD37033FV::setIn_gain(int in_gain, int mute){
            switch(mute){
               case 0: mute = 0b00000000;break;
               case 1: mute = 0b10000000;break;
   }
            int sum_in_gain = in_gain + mute;
            writeWire(INPUT_GAIN, sum_in_gain); 
   }

void BD37033FV::setVol(int vol){
            if(vol > 0){vol = 128 - vol;}
            if(vol <= 0){vol = abs(vol) + 128;}
            writeWire(VOLUME_GAIN, vol); 
   }

void BD37033FV::setFront_1(int front_1){
            if(front_1 > 0){front_1 = 128 - front_1;}
            if(front_1 <= 0){front_1 = abs(front_1) + 128;}
            
            writeWire(FADER_1_FRONT, front_1); 
   }

void BD37033FV::setFront_2(int front_2){
            if(front_2 > 0){front_2 = 128 - front_2;}
            if(front_2 <= 0){front_2 = abs(front_2) + 128;}
            
            writeWire(FADER_2_FRONT, front_2); 
   }

void BD37033FV::setRear_1(int rear_1){
            if(rear_1 > 0){rear_1 = 128 - rear_1;}
            if(rear_1 <= 0){rear_1 = abs(rear_1) + 128;}
            
            writeWire(FADER_1_REAR, rear_1); 
   }

void BD37033FV::setRear_2(int rear_2){
            if(rear_2 > 0){rear_2 = 128 - rear_2;}
            if(rear_2 <= 0){rear_2 = abs(rear_2) + 128;}
            
            writeWire(FADER_2_REAR, rear_2); 
   }

void BD37033FV::setSub1(int sub1){
            if(sub1 > 0){sub1 = 128 - sub1;}
            if(sub1 <= 0){sub1 = abs(sub1) + 128;}
            
            writeWire(FADER_SUB_1, sub1); 
   }

void BD37033FV::setSub2(int sub2){
            if(sub2 > 0){sub2 = 128 - sub2;}
            if(sub2 <= 0){sub2 = abs(sub2) + 128;}
            
            writeWire(FADER_SUB_2, sub2); 
   }

void BD37033FV::setBass_setup(int bass_q, int bass_f){
            switch(bass_q){
               case 0: bass_q = 0b00000000;break;
               case 1: bass_q = 0b00000001;break;
               case 2: bass_q = 0b00000010;break;
               case 3: bass_q = 0b00000011;break;  
   }
            switch(bass_f){
               case 0: bass_f = 0b00000000;break;
               case 1: bass_f = 0b00010000;break;
               case 2: bass_f = 0b00100000;break;
               case 3: bass_f = 0b00110000;break;  
   }
            int bass_s_sum = bass_q + bass_f;
            writeWire(BASS_SETUP, bass_s_sum); 
   }

void BD37033FV::setMiddle_setup(int mid_q, int mid_f){
            switch(mid_q){
               case 0: mid_q = 0b00000000;break;
               case 1: mid_q = 0b00000001;break;
               case 2: mid_q = 0b00000010;break;
               case 3: mid_q = 0b00000011;break;  
   }
            switch(mid_f){
               case 0: mid_f = 0b00000000;break;
               case 1: mid_f = 0b00010000;break;
               case 2: mid_f = 0b00100000;break;
               case 3: mid_f = 0b00110000;break;  
   }
            int mid_s_sum = mid_q + mid_f;
            writeWire(MIDDLE_SETUP, mid_s_sum); 
   }

void BD37033FV::setTreble_setup(int treb_q, int treb_f){
            switch(treb_q){
               case 0: treb_q = 0b00000000;break;
               case 1: treb_q = 0b00000001;break; 
   }
            switch(treb_f){
               case 0: treb_f = 0b00000000;break;
               case 1: treb_f = 0b00010000;break;
               case 2: treb_f = 0b00100000;break;
               case 3: treb_f = 0b00110000;break;  
   }
            int treb_s_sum = treb_q + treb_f;
            writeWire(TREBLE_SETUP, treb_s_sum); 
   }

void BD37033FV::setBass_gain(int bass_gain){
                 if(bass_gain>0){bass_gain = bass_gain + 0b00000000;}                     
                 if(bass_gain<=0){bass_gain = abs(bass_gain) + 0b10000000;}  
               writeWire(BASS_GAIN, bass_gain);   
   }

void BD37033FV::setMiddle_gain(int mid_gain){
                 if(mid_gain>0){mid_gain = mid_gain + 0b00000000;}                     
                 if(mid_gain<=0){mid_gain = abs(mid_gain) + 0b10000000;}  
               writeWire(MIDDLE_GAIN, mid_gain);   
   }

void BD37033FV::setTreble_gain(int treb_gain){
                 if(treb_gain>0){treb_gain = treb_gain + 0b00000000;}                     
                 if(treb_gain<=0){treb_gain = abs(treb_gain) + 0b10000000;}  
               writeWire(TREBLE_GAIN, treb_gain);   
   }

void BD37033FV::setLoudness_gain(int loud_gain){
               writeWire(LOUDNESS_GAIN, loud_gain);  
   }



void BD37033FV::writeWire(char a, char b){
  Wire.beginTransmission(BD37033FV_address);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
