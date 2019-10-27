#ifndef BD37033FV_H
#define BD37033FV_H

#define BD37033FV_address 0b1000000 

#define INITIAL_SETUP        0x01
#define LPF_SETUP            0x02
#define MIXING_SETUP         0x03
#define INPUT_SELECT         0x05
#define INPUT_GAIN           0x06
#define VOLUME_GAIN          0x20
#define FADER_1_FRONT        0x28
#define FADER_2_FRONT        0x29
#define FADER_1_REAR         0x2A
#define FADER_2_REAR         0x2B
#define FADER_SUB_1          0x2C
#define FADER_SUB_2          0x30
#define BASS_SETUP           0x41
#define MIDDLE_SETUP         0x44
#define TREBLE_SETUP         0x47
#define BASS_GAIN            0x51
#define MIDDLE_GAIN          0x54
#define TREBLE_GAIN          0x57
#define LOUDNESS_GAIN        0x75

#include <Arduino.h>
class BD37033FV
{
  public:
    BD37033FV();
    void setInitial();
        void setSub_setup(int sub_f,int sub_out, int faza); // off 55hz 85hz 120hz 160hz pass = int sub_f(0...5) || LPF front rear sub = int sub_out(0...3) 0 - default || 0 180 = int faza(0...1)
        void setLoud_f(int mix_in, int loud_f, int mix_ch1, int mix_ch2); // MIX_IN 0...3 3=off || 400hz 800hz 2400hz Prohibition = int loud_f(0...3) || MIXING 1ch 2ch -- on off = mix_ch1(0...1) mix_ch2(0..1)
        void setIn(int in); // in1 in2 in3 = int in(0...2)
        void setIn_gain(int in_gain, int mute); // 0...16 dB = int in_gain(0...16) || off on = int mute(0...1)
        void setVol(int vol); // -79...+15 dB = int vol(-79...15)
        void setFront_1(int front_1); // -79...+15 dB = int -79...15
        void setFront_2(int front_2); // -79...+15 dB = int -79...15
        void setRear_1(int rear_1); // -79...+15 dB = int -79...15
        void setRear_2(int rear_2); // -79...+15 dB = int -79...15
        void setSub1(int sub1); // -79...+15 dB = int -79...15
        void setSub2(int sub2); // -79...+15 dB = int -79...15
        void setBass_setup(int bass_q, int bass_f); // 0.5 1.0 1.5 2.0 --- int 0...3, 60Hz 80Hz 100Hz 120Hz --- int 0...3
        void setMiddle_setup(int mid_q, int mid_f); // 0.75 1.0 1.25 1.5 --- int 0...3, 500Hz 1kHz 1.5kHz 2.5kHz --- int 0...3
        void setTreble_setup(int treb_q, int treb_f); // 0.75 1.25  --- int 0...1, 7.5kHz 10kHz 12.5kHz 15kHz --- int 0...3
        void setBass_gain(int bass_gain); // --15 ... +15 dB = int -15 ... 15    
        void setMiddle_gain(int mid_gain); // --15 ... +15 dB = int -15 ... 15
        void setTreble_gain(int treb_gain); // --15 ... +20 dB = int -15 ... 15
        void setLoudness_gain(int loud_gain); // 0 ... 15 dB = int 0 ... 15    

  private:
    void writeWire(char a, char b);
};
    
#endif //BD37033FV_H
