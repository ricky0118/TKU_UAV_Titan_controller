###########################################################################
## Makefile generated for Simulink model 'px4demo_attitude_system20190504_roll'. 
## 
## Makefile     : px4demo_attitude_system20190504_roll.mk
## Generated on : Mon Jul 29 10:46:16 2019
## MATLAB Coder version: 3.2 (R2016b)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/px4demo_attitude_system20190504_roll.pre.o
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.
# SHARED_OBJS             Shared Object Names

PRODUCT_NAME              = px4demo_attitude_system20190504_roll
MAKEFILE                  = px4demo_attitude_system20190504_roll.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2016b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2016b/bin
MATLAB_ARCH_BIN           = C:/PROGRA~1/MATLAB/R2016b/bin/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = D:/¤å¥ó/tamp/TEST20190504
ARCH                      = win64
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = GCC ARM Cortex-A9
MODELREF_LINK_RSPFILE_NAME = px4demo_attitude_system20190504_roll_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ..
SHARED_SRC_DIR            = ../slprj/ert/_sharedutils
SHARED_SRC                = $(SHARED_SRC_DIR)/*.c
SHARED_BIN_DIR            = ../slprj/ert/_sharedutils
SHARED_LIB                = $(SHARED_BIN_DIR)/rtwshared.lib
SHARED_OBJS               =  \
$(addprefix $(join $(SHARED_BIN_DIR),/), $(addsuffix .o, $(basename $(notdir $(wildcard $(SHARED_SRC_DIR)/*.c)))))

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Pixhawk Toolchain v4.6.2 | gmake (64-bit Windows)
# Supported Version(s):    
# ToolchainInfo Version:   R2016b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_LOAD_CMD
# PX4_BASE

#-----------
# MACROS
#-----------

Q                                   = $(if $(V),,@)
PX4_SIMULINK_APP                    = px4_simulink_app
CPFLAGS                             = -O binary
ARCHWARNINGS                        = -Wall \
-Wextra \
-Wdouble-promotion \
-Wshadow \
-Wfloat-equal \
-Wframe-larger-than=1024 \
-Wpointer-arith \
-Wlogical-op \
-Wmissing-declarations \
-Wpacked \
-Wno-unused-parameter \
-Werror=format-security \
-Werror=array-bounds \
-Wfatal-errors \
-Wformat=1
ARCHCWARNINGS                       = $(ARCHWARNINGS) \
-Wbad-function-cast \
-Wstrict-prototypes \
-Wold-style-declaration \
-Wmissing-parameter-type \
-Wmissing-prototypes \
-Wnested-externs
ARCHOPTIMIZATION                    = -O3 \
-fno-strict-aliasing \
-fno-strength-reduce \
-fomit-frame-pointer \
-funsafe-math-optimizations \
-fno-builtin-printf \
-ffunction-sections \
-fdata-sections
ARCHCPUFLAGS_CORTEXM3               = -mcpu=cortex-m4 \
-mthumb \
-march=armv7e-m \
-mfpu=fpv4-sp-d16 \
-ffixed-r10 \
-mfloat-abi=hard
.SHELLFLAGS                         = --init-file $(PX4_ROOT)/Firmware/.slprofile
SHELL                               = $(PX4_ROOT)/toolchain/bin/sh.exe
ARCHCPUFLAGS                        = $(ARCHCPUFLAGS_CORTEXM3)
INSTRUMENTATIONDEFINES              = $(ARCHINSTRUMENTATIONDEFINES_CORTEXM3)
ARCHDEFINES                         = -DCONFIG_ARCH_BOARD_PX4FMU_V2
LIBGCC                              = $(shell $(CC) $(ARCHCPUFLAGS) -print-libgcc-file-name)
LIBM                                = $(shell $(CC) $(ARCHCPUFLAGS) -print-file-name=libm.a)
MAKEROOT                            = /bin
MAKEROOTWIN                         = %PX4_ROOT%\toolchain\bin

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Pixhawk Toolchain C Compiler
CC = arm-none-eabi-gcc

# Linker: Pixhawk ToolchainC Pre-Linker
LD = arm-none-eabi-ld

# Archiver: Pixhawk Toolchain Archiver
AR = arm-none-eabi-ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD =

# Invoke Make: Invoke Make
INVOKE = $(call CALLPX4MK)

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = $(MAKEROOTWIN)
MAKE = $(MAKE_PATH)/make


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
ENDGRP              = --end-group
OUTPUT_FLAG         = -o
STARTGRP            = --start-group
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /f/q
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -MD \
                       -c \
                       -std=gnu99 \
                       $(ARCHCWARNINGS) \
                       $(ARCHCPUFLAGS) \
                       $(ARCHINCLUDES) \
                       $(INSTRUMENTATIONDEFINES) \
                       $(ARCHDEFINES) \
                       -fno-common \
                       -nodefaultlibs \
                       -nostdlib \
                       -Wframe-larger-than=2000 \
                       -fvisibility=hidden \
                       -include visibility.h \
                       -O0 \
                       -fno-builtin-printf
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
MAKEFILENAME         =
LDFLAGS              = -Ur \
                       -Map $(PRODUCT_NAME).pre.o.map
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE) postdownload_preexecute
SHAREDLIB_LDFLAGS    =

#--------------------
# File extensions
#--------------------

H_EXT               = .h
OBJ_EXT             = .o
C_EXT               = .c
EXE_EXT             = .pre.o
SHAREDLIB_EXT       = .so
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/px4demo_attitude_system20190504_roll.pre.o
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I./referenced_model_includes -I$(MATLAB_ROOT)/toolbox/psp/pixhawk/+codertarget/+pixhawk/+blocks -I$(MATLAB_ROOT)/toolbox/psp/pixhawk/include -I$(MATLAB_ROOT)/simulink/include/sf_runtime -I$(START_DIR)/px4demo_attitude_system20190504_roll_ert_rtw -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(START_DIR)/slprj/ert/_sharedutils -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/serial -I$(PX4_ROOT)/src/lib/mathlib/CMSIS/Include -I$(PX4_ROOT)/lib/gcc/wingw32/4.6.2.include -I$(PX4_ROOT)/Firmware/src -I$(PX4_ROOT)/Firmware/build_$(PX4PSP_CMAKE_CONFIG) -I$(PX4_ROOT)/Firmware/build_$(PX4PSP_CMAKE_CONFIG)/src -I$(PX4_ROOT)/Firmware/src/modules -I$(PX4_ROOT)/Firmware/src/include -I$(PX4_ROOT)/Firmware/src/lib -I$(PX4_ROOT)/Firmware/src/platforms -I$(PX4_ROOT)/Firmware/src/drivers/boards/px4fmu-v2 -I$(PX4_ROOT)/Firmware/build_$(PX4PSP_CMAKE_CONFIG)/src/modules/px4_messages -I$(PX4_ROOT)/Firmware/build_$(PX4PSP_CMAKE_CONFIG)/src/modules -I$(PX4_ROOT)/Firmware/mavlink/include/mavlink -I$(PX4_ROOT)/Firmware/src/lib/DriverFramework/framework/include -I$(PX4_ROOT)/Firmware/src/lib/matrix -I$(PX4PSP_MODULE_BUILD_OUTPUT)/px4fmu-v2/NuttX/nuttx-export/include -I$(PX4PSP_MODULE_BUILD_OUTPUT)/px4fmu-v2/NuttX/nuttx-export/include/cxx -I$(PX4PSP_MODULE_BUILD_OUTPUT)/px4fmu-v2/NuttX/nuttx-export/arch/chip -I$(PX4PSP_MODULE_BUILD_OUTPUT)/px4fmu-v2/NuttX/nuttx-export/arch/common -I$(PX4PSP_MODULE_BUILD_OUTPUT)/external/Install/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DMODEL=px4demo_attitude_system20190504_roll -DNUMST=5 -DNCSTATES=0 -DHAVESTDIO -DONESTEPFCN=1 -DTERMFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DUSE_STDPERIPH_DRIVER -DPX4 -DCONFIG_ARCH_BOARD_PX4FMU_V2 -DGIT_VERSION=d3398270e101359de9687c2d077d991c9892f573 -D__DF_NUTTX -D__PX4_NUTTX -DARM_MATH_CM4=1 -D__FPU_PRESENT=1 -D__FPU_USED=1 -DHSE_VALUE=8000000 -DNULL=0 -DEXIT_FAILURE=1 -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLEPRINTF -DRT -DSTACK_SIZE=64
DEFINES_BUILD_ARGS = -DONESTEPFCN=1 -DTERMFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0
DEFINES_IMPLIED = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DUSE_STDPERIPH_DRIVER -DPX4 -DCONFIG_ARCH_BOARD_PX4FMU_V2 -DGIT_VERSION=d3398270e101359de9687c2d077d991c9892f573 -D__DF_NUTTX -D__PX4_NUTTX -DARM_MATH_CM4=1 -D__FPU_PRESENT=1 -D__FPU_USED=1 -DHSE_VALUE=8000000 -DNULL=0 -DEXIT_FAILURE=1 -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLEPRINTF -DRT -DSTACK_SIZE=64
DEFINES_STANDARD = -DMODEL=px4demo_attitude_system20190504_roll -DNUMST=5 -DNCSTATES=0 -DHAVESTDIO

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_ROOT)/toolbox/psp/pixhawk/src/PX4_sysobj_serial.c $(START_DIR)/px4demo_attitude_system20190504_roll_ert_rtw/px4demo_attitude_system20190504_roll.c $(START_DIR)/px4demo_attitude_system20190504_roll_ert_rtw/px4demo_attitude_system20190504_roll_data.c $(MATLAB_ROOT)/toolbox/psp/pixhawk/src/nuttxinitialize.c

MAIN_SRC = $(START_DIR)/px4demo_attitude_system20190504_roll_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = PX4_sysobj_serial.o px4demo_attitude_system20190504_roll.o px4demo_attitude_system20190504_roll_data.o nuttxinitialize.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

MODELREF_LIBS = ./px4demo_attitude_control20190311roll_rtwlib.lib

LIBS = $(SHARED_LIB)

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


define CALLPX4MK 
	@echo "Making Firmware $2"
	@(cd $(PX4_BASE) && $(PX4_ROOT)/toolchain/bin/make $(PX4PSP_CMAKE_CONFIG) $(PX4PSP_UPLOAD_OPTION) )
	@echo "### End of Simulink Build ###"
endef


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download postdownload_preexecute execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(MODELREF_LIBS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : build


postdownload_preexecute : download
	@echo "### Invoking postbuild tool "Invoke Make" ..."
	$(INVOKE) $(MAKEFILENAME)
	@echo "### Done invoking postbuild tool."


execute : postdownload_preexecute
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MODELREF_LIBS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) --start-group $(MODELREF_LIBS) --end-group $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/psp/pixhawk/+codertarget/+pixhawk/+blocks/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/psp/pixhawk/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/px4demo_attitude_system20190504_roll_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : ../%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


$(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.c
	@echo "### Compiling "$<" ..."
	$(CC) $(CFLAGS) -o "$@" "$<"


#---------------------------
# SHARED UTILITY LIBRARY
#---------------------------

$(SHARED_LIB) : $(SHARED_OBJS)
	@echo "### Creating shared utilities library "$(SHARED_LIB)" ..."
	$(AR) $(ARFLAGS)  $(SHARED_LIB) $(SHARED_OBJS)
	@echo "### Created: $(SHARED_LIB)"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKEFILENAME = $(MAKEFILENAME)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


