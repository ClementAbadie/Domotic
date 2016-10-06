################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/user/ServerSocket.cpp \
../src/user/ServerTCP.cpp \
../src/user/Socket.cpp \
../src/user/User.cpp \
../src/user/pushbullet.cpp 

OBJS += \
./src/user/ServerSocket.o \
./src/user/ServerTCP.o \
./src/user/Socket.o \
./src/user/User.o \
./src/user/pushbullet.o 

CPP_DEPS += \
./src/user/ServerSocket.d \
./src/user/ServerTCP.d \
./src/user/Socket.d \
./src/user/User.d \
./src/user/pushbullet.d 


# Each subdirectory must supply rules for building sources it contributes
src/user/%.o: ../src/user/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I"D:\Dev\Tools\SysGCC\include" -I"D:\Dev\CPP\libraries\mysql\include" -I"D:\Dev\CPP\libraries\SQLAPI\include" -I"D:\Dev\CPP\libraries\wiringPi\include" -I"D:\Dev\CPP\libraries\curl-master\include" -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


