################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
nonHalCoGen/interrupt_handlers.obj: ../nonHalCoGen/interrupt_handlers.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7R4 -g --include_path="C:/Hercules/IAR/rm48x" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --include_path="" --diag_warning=225 -me --enum_type=packed --abi=eabi --code_state=32 --float_support=VFPv3D16 --preproc_with_compile --preproc_dependency="nonHalCoGen/interrupt_handlers.pp" --obj_directory="nonHalCoGen" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

nonHalCoGen/leds_control.obj: ../nonHalCoGen/leds_control.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7R4 -g --include_path="C:/Hercules/IAR/rm48x" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --include_path="" --diag_warning=225 -me --enum_type=packed --abi=eabi --code_state=32 --float_support=VFPv3D16 --preproc_with_compile --preproc_dependency="nonHalCoGen/leds_control.pp" --obj_directory="nonHalCoGen" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

nonHalCoGen/user_main.obj: ../nonHalCoGen/user_main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7R4 -g --include_path="C:/Hercules/IAR/rm48x" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --include_path="" --diag_warning=225 -me --enum_type=packed --abi=eabi --code_state=32 --float_support=VFPv3D16 --preproc_with_compile --preproc_dependency="nonHalCoGen/user_main.pp" --obj_directory="nonHalCoGen" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


