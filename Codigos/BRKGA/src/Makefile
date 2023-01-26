# Macros:
CPP= g++
CFLAGS= -O3 -fopenmp
OBJECTS= samplecode.cpp

# Targets:
all: samplecode

samplecode: $(OBJECTS)
	$(CPP) $(CFLAGS) $(OBJECTS) -o samplecode.exe
        
#SampleDecoder.o:
#	$(CPP) $(CFLAGS) -c -o SampleDecoder.cpp sampleDecoder.exe

# Remove:
clean:
	rm -f sampledecode $(OBJECTS)
