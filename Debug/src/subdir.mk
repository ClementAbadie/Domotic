################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Domotic.cpp \
../src/Test.cpp 

OBJS += \
./src/Domotic.o \
./src/Test.o 

CPP_DEPS += \
./src/Domotic.d \
./src/Test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I"C:\SysGCC\Raspberry\wiringPi\include" -I"C:\SysGCC\Raspberry\include" -I"C:\Compilation\Eclipse\libraries\include" -I"C:\Compilation\Eclipse\libraries\curl-master\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


