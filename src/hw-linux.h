#ifndef _HWLINUX_
#define _HWLINUX_

#include <unordered_map>
#include <string>
#include <vector>

#include "hw-ihardware.h"
#include "sysclock.h"
#include "constants.h"

class HwLinux : IHardware {

    private:

        SysClock * clock_;
        AlsaSoundcard * soundcard_;
        DefaultCpu * cpu_;

    public:
        HwLinux();
        ~HwLinux();

        IClock * Clock() { return (IClock *)this->clock_; }
        ISoundcard * Soundcard() { return (ISoundcard *)this->soundcard_; }
        ICpu * Cpu() { return (ICpu *)this->cpu_; }

        bool getTVOutStatus();
        std::string getTVOutMode();
        void setTVOutMode(std::string mode);

        void ledOn(int flashSpeed = 250);
        void ledOff();

        int getBatteryLevel();

        int getBacklightLevel();
        int setBacklightLevel(int val);

        bool getKeepAspectRatio();
        bool setKeepAspectRatio(bool val);

        std::string getDeviceType();

        void powerOff();
        void reboot();

        int defaultScreenWidth();
        int defaultScreenHeight();

        bool setScreenState(const bool &enable);

        std::string inputFile() { return "linux.input.conf"; };
};

#endif