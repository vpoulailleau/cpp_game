CC=g++
DEBUG=yes
EXEC=game.exe

SRC = $(wildcard *.cpp)

LDFLAGS= -Wall
ifeq ($(DEBUG),yes)
	CXXFLAGS=-W -Wall -g
else
	CXXFLAGS=-W -Wall -O3
endif

###############################################
# end of the configuration
###############################################

all: $(EXEC)

obj = $(SRC:.cpp=.o)
dep = $(obj:.o=.d)

$(EXEC): $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(dep)

%.d: %.cpp
	@$(CC) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

%.o: %.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(obj) $(EXEC) $(dep)
