################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/sensors/bmp180/bmp180dev3.cpp 

OBJS += \
./src/sensors/bmp180/bmp180dev3.o 

CPP_DEPS += \
./src/sensors/bmp180/bmp180dev3.d 


# Each subdirectory must supply rules for building sources it contributes
src/sensors/bmp180/%.o: ../src/sensors/bmp180/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I"D:\Dev\Tools\SysGCC\include" -I"D:\Dev\CPP\libraries\mysql\include" -I"D:\Dev\CPP\libraries\SQLAPI\include" -I"D:\Dev\CPP\libraries\wiringPi\include" -I"D:\Dev\CPP\libraries\curl-master\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


