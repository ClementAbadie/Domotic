################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AI/AI.cpp \
../src/AI/DB.cpp 

OBJS += \
./src/AI/AI.o \
./src/AI/DB.o 

CPP_DEPS += \
./src/AI/AI.d \
./src/AI/DB.d 


# Each subdirectory must supply rules for building sources it contributes
src/AI/%.o: ../src/AI/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I"C:\SysGCC\Raspberry\wiringPi\include" -I"C:\SysGCC\Raspberry\include" -I"C:\Compilation\Eclipse\libraries\include" -I"C:\Compilation\Eclipse\libraries\curl-master\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


