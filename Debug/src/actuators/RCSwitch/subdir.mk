################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/actuators/RCSwitch/RCSwitch.cpp \
../src/actuators/RCSwitch/send.cpp 

OBJS += \
./src/actuators/RCSwitch/RCSwitch.o \
./src/actuators/RCSwitch/send.o 

CPP_DEPS += \
./src/actuators/RCSwitch/RCSwitch.d \
./src/actuators/RCSwitch/send.d 


# Each subdirectory must supply rules for building sources it contributes
src/actuators/RCSwitch/%.o: ../src/actuators/RCSwitch/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I"D:\Dev\Tools\SysGCC\include" -I"D:\Dev\CPP\libraries\mysql\include" -I"D:\Dev\CPP\libraries\SQLAPI\include" -I"D:\Dev\CPP\libraries\wiringPi\include" -I"D:\Dev\CPP\libraries\curl-master\include" -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


