################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/user/TCP/subdir.mk
-include src/user/subdir.mk
-include src/tools/subdir.mk
-include src/sensors/htu21/subdir.mk
-include src/sensors/bmp180/subdir.mk
-include src/sensors/subdir.mk
-include src/home/subdir.mk
-include src/conf/subdir.mk
-include src/actuators/RCSwitch/subdir.mk
-include src/actuators/subdir.mk
-include src/AI/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Domotic

# Tool invocations
Domotic: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	arm-linux-gnueabihf-g++ -L"D:\Dev\Tools\SysGCC\lib" -L"D:\Dev\CPP\libraries\wiringPi\lib" -L"D:\Dev\CPP\libraries\curl-master\lib" -L"D:\Dev\CPP\libraries\curl-master\lib\.libs" -L"D:\Dev\CPP\libraries\SQLAPI\lib" -L"D:\Dev\CPP\libraries\mysql\lib" -o "Domotic" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(C_DEPS)$(CPP_DEPS) Domotic
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
