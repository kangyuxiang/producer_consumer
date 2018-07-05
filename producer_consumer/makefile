ROOTDIR := ./
CXXFLAGS := -g -c 
SRCEXTS := .cpp .c .cc
OBJDIR := ./objs/
PROGRAM := ./producer_consumer
CPPFLAGS := -std=c++11 -Wall -fPIC -I$(ROOTDIR) -I/usr/local/include
LDFLAGS := -lgcc_s -lpthread
OBJS := $(foreach d,$(SRCEXTS), $(patsubst %$(d),%.o,$(notdir $(wildcard *$(d) $(ROOTDIR)$(d)))))
FULLOBJS = $(addprefix $(OBJDIR),$(OBJS))

vpath %.cpp $(ROOTDIR)
vpath %.cc $(ROOTDIR)
vpath %.o $(OBJDIR)
#$(PROGRAM) : $(OBJS) 
.PHONY : all objs clean test

all : config $(PROGRAM)

objs : $(OBJS)
	@echo -e "objs:$(OBJS)"

%.o : %.cpp
	@echo -e "building:$(notdir $@) ..."
	$(CXX) -g -c $(CPPFLAGS) $< -o $(OBJDIR)$(notdir $@)

%.o : %.cc
	@echo -e "building:$(notdir $@) ..."
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $(OBJDIR)$(notdir $@)

$(PROGRAM) : $(OBJS)
	@echo -e "building: $(PROGRAM)"
	@echo -e "OBJS: $(OBJS)"
	@echo -e "FULLOBJS: $(FULLOBJS)"
	$(CXX) -g -o $(PROGRAM) $(FULLOBJS) $(LDFLAGS)

test:
	@echo -e "objs:$(OBJS)"

config: dir

dir:
	@echo -e "making dir..."
	mkdir -p $(OBJDIR)
	
clean :
	$(RM) $(FULLOBJS)
