############################################################
##	MACROS
############################################################


GNU_COMP = /opt/local/bin/g++-mp-4.7
#GNU_COMP = g++
GNU_OPENMP = -fopenmp

CLANG_COMP = clang++ 
CLANG_OPENMP = #-fopenmp

EXECUTABLE_NAME = cc.bin
TEST_EXECUTABLE_NAME = cc_test.bin

ifndef COMP
COMP = $(GNU_COMP)
COMP_OPENMP = $(GNU_OPENMP)
endif

#ADDITIONAL_OPTS = -p -g 
ADDITIONAL_OPTS = -O3 -msse4.2 

ALGLIB_PATH = ../lib/alglib/src/

INCLUDES = -I./ -I../lib/alglib/src/ -I/opt/local/include #Add path to local boost here if needed

LIBS =  -lboost_program_options-mt -lboost_iostreams-mt -L../lib/alglib/src/  -L./ -L/opt/local/lib/

ADDITIONAL_FILES_TO_BE_DELETED = 

############################################################
##	OBJECTS
############################################################

### EXECUTABLE

$(EXECUTABLE_NAME): main.o Point.o Canopy.o CanopyClustering.o Stats.o Log.o 
	$(COMP) -o $@ $(COMP_OPENMP) $(ADDITIONAL_OPTS) $(INCLUDES) $(LIBS) $^

$(TEST_EXECUTABLE_NAME): main_test.o Point.o Canopy.o CanopyClustering.o Stats.o Log.o 
	$(COMP) -o $@ $(COMP_OPENMP) $(ADDITIONAL_OPTS) $(INCLUDES) $(LIBS) $^

main.o:	main.cpp 
	$(COMP) -o$@ $(COMP_OPENMP) -c $(ADDITIONAL_OPTS) $(INCLUDES) $^
	
main_test.o:	main_test.cpp 
	$(COMP) -o$@ $(COMP_OPENMP) -c $(ADDITIONAL_OPTS) $(INCLUDES) $^

Point.o: Point.cpp 
	$(COMP) -o$@ $(COMP_OPENMP) -c $(ADDITIONAL_OPTS) $(INCLUDES) $^

Canopy.o: Canopy.cpp 
	$(COMP) -o$@ $(COMP_OPENMP) -c $(ADDITIONAL_OPTS) $(INCLUDES) $^

CanopyClustering.o: CanopyClustering.cpp 
	$(COMP) -o$@ $(COMP_OPENMP) -c $(ADDITIONAL_OPTS) $(INCLUDES) $^

Stats.o: Stats.cpp 
	$(COMP) -o$@ $(COMP_OPENMP) -c $(ADDITIONAL_OPTS) $(INCLUDES) $^

Log.o: Log.cpp 
	$(COMP) -o$@ $(COMP_OPENMP) -c $(ADDITIONAL_OPTS) $(INCLUDES) $^

#### Targets

all: $(EXECUTABLE_NAME) $(TEST_EXECUTABLE_NAME)

############################################################
##	CLEAN
############################################################

.PHONY: clean

clean:
	-rm -f *.bin *.o *.d $(ADDITIONAL_FILES_TO_BE_DELETED) $(COMMON_DIR)*.o
 