################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/user/ServerSocket.cpp \
../src/user/Socket.cpp \
../src/user/User.cpp \
../src/user/pushbullet.cpp \
../src/user/simple_server_main.cpp 

OBJS += \
./src/user/ServerSocket.o \
./src/user/Socket.o \
./src/user/User.o \
./src/user/pushbullet.o \
./src/user/simple_server_main.o 

CPP_DEPS += \
./src/user/ServerSocket.d \
./src/user/Socket.d \
./src/user/User.d \
./src/user/pushbullet.d \
./src/user/simple_server_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/user/%.o: ../src/user/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I"C:\SysGCC\Raspberry\wiringPi\include" -I"C:\SysGCC\Raspberry\include" -I"C:\Compilation\Eclipse\libraries\include" -I"C:\Compilation\Eclipse\libraries\curl-master\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


