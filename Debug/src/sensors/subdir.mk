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
	arm-linux-gnueabihf-g++ -I"D:\Dev\Tools\SysGCC\include" -I"D:\Dev\CPP\libraries\mysql\include" -I"D:\Dev\CPP\libraries\SQLAPI\include" -I"D:\Dev\CPP\libraries\wiringPi\include" -I"D:\Dev\CPP\libraries\curl-master\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


