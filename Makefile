SUBDIRS := $(shell find . -type d -d 1 -name '[0-9]*' -print)

default: all

$(SUBDIRS)::
	@$(MAKE) -C $@ $(MAKECMDGOALS)

all clean : $(SUBDIRS)
