################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/actuators/RCSwitch.cpp \
../src/actuators/send.cpp 

OBJS += \
./src/actuators/RCSwitch.o \
./src/actuators/send.o 

CPP_DEPS += \
./src/actuators/RCSwitch.d \
./src/actuators/send.d 


# Each subdirectory must supply rules for building sources it contributes
src/actuators/%.o: ../src/actuators/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I"C:\SysGCC\Raspberry\wiringPi\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


