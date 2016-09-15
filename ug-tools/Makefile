include ../buildconf.mk

LIB   	:= -lsyndicate -lsyndicate-ug -lfskit -lprotobuf -lcurl
C_SRCS	:= $(wildcard *.c)
CXSRCS	:= $(wildcard *.cpp)

OBJDIR  := obj/
OBJ		:= $(patsubst %.c,$(BUILD_UG_TOOLS)/%.o,$(C_SRCS)) \
	       $(patsubst %.cpp,$(BUILD_UG_TOOLS)/%.o,$(CXSRCS))

TOOL_NAMES := syndicate-ls syndicate-mkdir syndicate-rmdir syndicate-touch \
  			  syndicate-put syndicate-cat syndicate-vacuum syndicate-unlink \
			  syndicate-trunc syndicate-write syndicate-read syndicate-coord \
			  syndicate-rename syndicate-stat syndicate-listxattr syndicate-getxattr \
			  syndicate-setxattr syndicate-removexattr syndicate-refresh \
			  syndicate-repl

TOOLS := $(patsubst %,$(BUILD_UG_TOOLS)/%,$(TOOL_NAMES))
TOOLS_INSTALL := $(patsubst %,$(BINDIR)/%,$(TOOL_NAMES))

COMMON_SRC := common.cpp
COMMON_OBJ := $(patsubst %.cpp,$(BUILD_UG_TOOLS)/$(OBJDIR)/%.o,$(COMMON_SRC))

all: $(TOOLS)

$(BUILD_UG_TOOLS)/syndicate-% : $(BUILD_UG_TOOLS)/$(OBJDIR)/syndicate-%.o $(COMMON_OBJ)
	@mkdir -p "$(shell dirname "$@")"
	$(CPP) -o "$@" $(INC) "$<" $(UG_COMMON_OBJ) $(COMMON_OBJ) $(LIBINC) $(LIB)

$(BUILD_UG_TOOLS)/$(OBJDIR)/%.o : %.c
	@mkdir -p "$(shell dirname "$@")"
	$(CPP) -o "$@" $(INC) -c "$<" $(DEFS)

$(BUILD_UG_TOOLS)/$(OBJDIR)/%.o : %.cpp
	@mkdir -p "$(shell dirname "$@")"
	$(CPP) -o "$@" $(INC) -c "$<" $(DEFS)

.PHONY: clean
clean:
	rm -f $(OBJ) $(TOOLS)

.PHONY: install 
install: $(TOOLS_INSTALL)

$(BINDIR)/%: $(BUILD_UG_TOOLS)/%
	@mkdir -p "$(shell dirname "$@")"
	@rm -f "$@"
	@cp -a "$<" "$@"

.PHONY: uninstall
uninstall:
	@rm -f $(TOOLS_INSTALL)

print-%: ; @echo $*=$($*)
