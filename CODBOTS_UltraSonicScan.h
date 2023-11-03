
#ifndef CODBOTS_UltraSonicScan_h
#define CODBOTS_UltraSonicScan_h

#include <Arduino.h>
#include <ESP32Servo.h>
#include <UltrasonicDistance.h>


class CODBOTS_UltraSonicScan
{
    public:
        CODBOTS_UltraSonicScan(int pin_trig_,int pin_echo_);
        void begin(int avg_samples);
        void begin(int start,int end,int partitions_count,int avg_samples);
        float readSensor();
        

        void read();
        void readIndex(int index);
        void read(int angle);

        float getDistance();
        float getDistanceIndex(int index);
        float getDistance(int angle);

        void reset();
        bool scan(bool shift);

        int nextScanIndex();

        bool isInIndexRange(int index);
        bool isInAngleRange(int angle);

        int getAngle();

    private:
        int pin_trig;
        int pin_echo;

        int start;
        int end;

        float duration_us, distance_cm;

        UltrasonicDistance* partitions;

        int partition_size;//single partition length
        int partitions_count;//count is this

        int scanindex = 0;
        int scandir = true;
};


#endif