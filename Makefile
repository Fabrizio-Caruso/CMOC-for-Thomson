INCLUDES ?= mo5_lib.c

OPTS ?= -O2 -Wno-const 

BUILD_PATH ?= ./build

TOOLS_PATH ?= ./tools



mo5_ex1: 
	cmoc -c -nodefaultlibs $(OPTS) $(INCLUDES) ./mo5_ex1.c
	cmoc -o $(BUILD_PATH)/mo5_ex1.bin -nodefaultlibs $(OPTS) $(INCLUDES)  ./mo5_ex1.o
	rm ./mo5_ex1.o
	$(TOOLS_PATH)/mo5/f2k5.exe $(BUILD_PATH)/mo5_ex1.bin
	mv $(BUILD_PATH)/mo5_ex1.bin .
	$(TOOLS_PATH)/mo5/sapfs.exe -c mo5_ex1.sap
	$(TOOLS_PATH)/mo5/sapfs.exe --add mo5_ex1.sap mo5_ex1.bin
	mv ./mo5_ex1.bin $(BUILD_PATH)
	mv ./mo5_ex1.sap $(BUILD_PATH)
	mv ./FILE.k5 $(BUILD_PATH)/mo5_ex1.k5