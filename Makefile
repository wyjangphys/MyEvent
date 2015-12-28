CXX = g++
CXXFLAGS = -W -Wall -m64
CXX_LDFLAGS += $(shell $(ROOTSYS)/bin/root-config --libs)

INCLUDES = -I${ROOTSYS}/include

all : libEvent.so Event

#6
Event : MainEvent.o Event.o EventDict.o
	$(CXX) $^ $(CXXFLAGS) $(CXX_LDFLAGS) -o $@

#5
MainEvent.o : MainEvent.cxx
	$(CXX) -fPIC $(CXXFLAGS) $(INCLUDES) -c $^

#4
libEvent.so : Event.o EventDict.o
	$(CXX) -shared $(CXXFLAGS) $^ -o $@

#3
EventDict.o : EventDict.cxx
	$(CXX) -fPIC $(CXXFLAGS) $(INCLUDES) -c $^
#2
EventDict.cxx : Event.h EventLinkDef.h
	@echo "Generating dictionary $@..."
	rootcint -f $@ -c $^
#1
Event.o : Event.cxx
	$(CXX) -fPIC $(CXXFLAGS) $(INCLUDES) -c $^
clean :
	rm -rf *.o MainEvent *.so EventDict* Event
