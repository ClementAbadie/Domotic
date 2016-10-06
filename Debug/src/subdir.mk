################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Domotic.cpp \
../src/Test.cpp \
../src/admin.cpp 

OBJS += \
./src/Domotic.o \
./src/Test.o \
./src/admin.o 

CPP_DEPS += \
./src/Domotic.d \
./src/Test.d \
./src/admin.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I"D:\Dev\Tools\SysGCC\include" -I"D:\Dev\CPP\libraries\mysql\include" -I"D:\Dev\CPP\libraries\SQLAPI\include" -I"D:\Dev\CPP\libraries\wiringPi\include" -I"D:\Dev\CPP\libraries\curl-master\include" -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


