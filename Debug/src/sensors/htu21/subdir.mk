################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/sensors/htu21/htu21dev4.cpp 

OBJS += \
./src/sensors/htu21/htu21dev4.o 

CPP_DEPS += \
./src/sensors/htu21/htu21dev4.d 


# Each subdirectory must supply rules for building sources it contributes
src/sensors/htu21/%.o: ../src/sensors/htu21/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I"C:\SysGCC\Raspberry\wiringPi\include" -I"C:\SysGCC\Raspberry\include" -I"C:\Compilation\Eclipse\libraries\include" -I"C:\Compilation\Eclipse\libraries\curl-master\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


