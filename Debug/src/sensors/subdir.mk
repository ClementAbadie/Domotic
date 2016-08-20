################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/sensors/i2c.cpp 

OBJS += \
./src/sensors/i2c.o 

CPP_DEPS += \
./src/sensors/i2c.d 


# Each subdirectory must supply rules for building sources it contributes
src/sensors/%.o: ../src/sensors/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I"D:\SysGCC\Raspberry\wiringPi\include" -I"D:\SysGCC\Raspberry\include" -I"D:\libraries\include" -I"D:\libraries\curl-master\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


