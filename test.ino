#include <Wire.h> 
#include <BD37033FV.h>
BD37033FV tda; 

void setup(){
   Wire.begin();
   audio();
}

void loop(){}

void audio(){
        tda.setInitial();
        tda.setSub_setup(0,0,0); // off 55hz 85hz 120hz 160hz pass = int sub_f(0...5) || LPF front rear sub = int sub_out(0...3) 0 - default || 0 180 = int faza(0...1)
        tda.setLoud_f(3,0,0,0); // mix_in off || 400hz 800hz 2400hz Prohibition = int loud_f(0...3) || MIXING 1ch 2ch -- on off = mix_ch1(0...1) mix_ch2(0..1)
        tda.setIn(0); // in1 in2 in3 = int in(0...2)
        tda.setIn_gain(0,0); // 0...16 dB = int in_gain(0...16) || off on = int mute(0...1)
        tda.setVol(0); // -79...+15 dB = int vol(-79...15)
        tda.setFront_1(0); // -79...+15 dB = int -79...15
        tda.setFront_2(0); // -79...+15 dB = int -79...15
        tda.setRear_1(0); // -79...+15 dB = int -79...15
        tda.setRear_2(0); // -79...+15 dB = int -79...15
        tda.setSub1(0); // -79...+15 dB = int -79...15
        tda.setSub2(0); // -79...+15 dB = int -79...15
        tda.setBass_setup(0,0); // 0.5 1.0 1.5 2.0 --- int 0...3, 60Hz 80Hz 100Hz 120Hz --- int 0...3
        tda.setMiddle_setup(0,0); // 0.75 1.0 1.25 1.5 --- int 0...3, 500Hz 1kHz 1.5kHz 2.5kHz --- int 0...3
        tda.setTreble_setup(0,0); // 0.75 1.25  --- int 0...1, 7.5kHz 10kHz 12.5kHz 15kHz --- int 0...3
        tda.setBass_gain(0); // --15 ... +15 dB = int -15 ... 15 
        tda.setMiddle_gain(0); // --15 ... +15 dB = int -15 ... 15
        tda.setTreble_gain(0); // --15 ... +20 dB = int -15 ... 15
        tda.setLoudness_gain(0); // 0 ... 15 dB = int 0 ... 15 
  }
