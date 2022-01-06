
SHELL := /bin/bash
MAKEFLAGS += --no-print-directory

##### PARAMETERS

N            ?= 5

COUNTER      ?= $(wordlist 2,$(words $(NN)),$(NN))
LINE         ?= $(foreach i,$(NNM1),0) 1

#####

empty        :=
space        := $(empty) $(empty)

range         = $(if $(filter $(1),$(words $(2))),$(strip $(2)),$(call range,$(1),x $(2)))
display_bit   = $(if $(filter 0,$(1)),\\x20,\\x2A)

NN           := $(call range,$(N),)
NNM1         := $(wordlist 2,$(words $(NN)),$(NN))
NM1          := $(words $(NNM1))

COUNTER_M1   := $(wordlist 2,$(words $(COUNTER)),$(COUNTER))

LINE_SHOW    := $(subst $(space),, $(foreach bit,$(LINE),$(call display_bit,$(bit))))

TRIPLETS     := \
				$(join $(join \
				$(foreach bit1,0 $(wordlist 1,$(NM1),$(LINE)),$(bit1)), \
				$(foreach bit2,$(LINE),$(bit2))), \
				$(foreach bit3,$(wordlist 2,$(N),$(LINE)) 0,$(bit3)))

NEXT_LINE    := \
				$(subst 7,1, \
				$(subst 8,0, \
					$(subst 111,8, \
					$(subst 110,7, \
					$(subst 101,7, \
					$(subst 100,8, \
					$(subst 011,7, \
					$(subst 010,7, \
					$(subst 001,7, \
					$(subst 000,8, \
						$(TRIPLETS) \
					)))))))) \
				))

.PHONY: all
all:
	@ echo -e $(LINE_SHOW)
ifneq ($(COUNTER),)
	@ $(MAKE) -f $(lastword $(MAKEFILE_LIST)) \
		LINE="$(NEXT_LINE)" \
		COUNTER="$(COUNTER_M1)"
endif
