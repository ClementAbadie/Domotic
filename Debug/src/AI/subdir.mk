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
	arm-linux-gnueabihf-g++ -I"D:\Dev\Tools\SysGCC\include" -I"D:\Dev\CPP\libraries\mysql\include" -I"D:\Dev\CPP\libraries\SQLAPI\include" -I"D:\Dev\CPP\libraries\wiringPi\include" -I"D:\Dev\CPP\libraries\curl-master\include" -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


