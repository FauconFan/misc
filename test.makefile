# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.makefile                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 10:29:49 by jpriou            #+#    #+#              #
#    Updated: 2019/06/27 12:17:39 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_NM = ./ft_nm
NAME_OTOOL = ./ft_otool

FIND_PARAMS = -maxdepth 1 -type f -exec bash -c 'if [ ! "`file $$0 | grep ASCII`" -a -r "$$0" ]; then echo $$0; fi' {} \; | sort

BLACK_LISTED = \
			/bin/syslog.py \
			/usr/bin/imptrace \
			/usr/bin/json_pp5.16 \
			/usr/bin/json_pp5.18 \
			/usr/bin/phar.phar \
			/usr/bin/net-snmp-config \
			/usr/bin/net-snmp-cert \
			/usr/bin/krb5-config \
			/usr/bin/systriage \
			/usr/bin/tkpp5.16 \
			/usr/bin/tkpp5.18 \
			/usr/sbin/smbdiagnose \

_FILES_BIN = $(shell find /bin $(FIND_PARAMS))
_FILES_SBIN = $(shell find /sbin $(FIND_PARAMS))
_FILES_USR_BIN = $(shell find /usr/bin $(FIND_PARAMS))
_FILES_USR_SBIN = $(shell find /usr/sbin $(FIND_PARAMS))
_FILES_USR_LIB = $(shell find /usr/lib $(FIND_PARAMS))
_FILES_USR_LIBEXEC = $(shell find /usr/libexec $(FIND_PARAMS))
_FILES_USR_LOCAL_BIN = $(shell find /usr/local/bin $(FIND_PARAMS))
_FILES_USR_LOCAL_LIB = $(shell find /usr/local/lib $(FIND_PARAMS))

FILES_BIN = $(filter-out $(BLACK_LISTED), $(_FILES_BIN))
FILES_SBIN = $(filter-out $(BLACK_LISTED), $(_FILES_SBIN))
FILES_USR_BIN = $(filter-out $(BLACK_LISTED), $(_FILES_USR_BIN))
FILES_USR_SBIN = $(filter-out $(BLACK_LISTED), $(_FILES_USR_SBIN))
FILES_USR_LIB = $(filter-out $(BLACK_LISTED), $(_FILES_USR_LIB))
FILES_USR_LIBEXEC = $(filter-out $(BLACK_LISTED), $(_FILES_USR_LIBEXEC))
FILES_USR_LOCAL_BIN = $(filter-out $(BLACK_LISTED), $(_FILES_USR_LOCAL_BIN))
FILES_USR_LOCAL_LIB = $(filter-out $(BLACK_LISTED), $(_FILES_USR_LOCAL_LIB))

.PHONY: main
main:
	@ make -f test.makefile test_bin
	@ make -f test.makefile test_sbin
	@ make -f test.makefile test_usr_lib
	@ make -f test.makefile test_usr_libexec
	@ make -f test.makefile test_usr_bin
	@ make -f test.makefile test_usr_sbin
	@ make -f test.makefile test_usr_local_lib
	@ make -f test.makefile test_mguillau42_unit_test_nm_otool
	@ make -f test.makefile test_salwan_binary_samples
	@ make -f test.makefile test_mmeisson_tests_nm

.PHONY: rude
rude:
	@ make -f test.makefile test_usr_local_bin

$(NAME_NM):
	make -f Makefile $(NAME_NM)

$(NAME_OTOOL):
	make -f Makefile $(NAME_OTOOL)

################################## SYSTEM #####################################

.PHONY: test_bin
test_bin: 
	@ make -f test.makefile $(FILES_BIN)

.PHONY: test_sbin
test_sbin: 
	@ make -f test.makefile $(FILES_SBIN)

.PHONY: test_usr_bin
test_usr_bin:
	@ make -f test.makefile $(FILES_USR_BIN)

.PHONY: test_usr_sbin
test_usr_sbin:
	@ make -f test.makefile $(FILES_USR_SBIN)

.PHONY: test_usr_lib
test_usr_lib:
	@ make -f test.makefile $(FILES_USR_LIB)

.PHONY: test_usr_libexec
test_usr_libexec:
	@ make -f test.makefile $(FILES_USR_LIBEXEC)

# rude one because of node
.PHONY: test_usr_local_bin
test_usr_local_bin:
	@ make -f test.makefile $(FILES_USR_LOCAL_BIN)

.PHONY: test_usr_local_lib
test_usr_local_lib:
	@ make -f test.makefile $(FILES_USR_LOCAL_LIB)

################################## REMOTE #####################################

TMP_DIR = /tmp/_abcdefghij/

MGUILLAU_GIT = https://github.com/mguillau42/unit_test_nm_otool.git
SALWAN_GIT = https://github.com/JonathanSalwan/binary-samples.git
MMEISSON_GIT = https://github.com/mmeisson/tests_nm.git

MGUILLAU_SUBDIR = \
			custom_tests/32 \
			custom_tests/64 \
			custom_tests/fat \
			custom_tests/fat_lib \
			custom_tests/lib_stat \

MGUILLAU_BLACK_LISTED = \
			$(shell pwd)/tests/mguillau42_unit_test_nm_otool/custom_tests/fat/MachO-OSX-ppc-and-i386-bash \

MGUILLAU_SUBDIR_REAL = $(addprefix $(shell pwd)/tests/mguillau42_unit_test_nm_otool/, $(MGUILLAU_SUBDIR))
MGUILLAU_FILES = $(filter-out $(MGUILLAU_BLACK_LISTED), $(shell find $(MGUILLAU_SUBDIR_REAL) -type f))
MGUILLAU_CORR_FILES = $(shell find tests/mguillau42_unit_test_nm_otool/custom_tests/corrupt)

SALWAN_BLACK_LISTED = \
			$(shell pwd)/tests/salwan_binary_sample/MachO-OSX-ppc-and-i386-bash \

SALWAN_FILES = $(filter-out $(SALWAN_BLACK_LISTED), $(shell find $(shell pwd)/tests/salwan_binary_sample -type f -name "MachO*"))

MMEISSON_CORR_FILES = $(shell find tests/mmeisson_tests_nm/corrupted_binaries -type f)

.PHONY: test_mguillau42_unit_test_nm_otool
test_mguillau42_unit_test_nm_otool: tests/mguillau42_unit_test_nm_otool
	@ make -f test.makefile $(MGUILLAU_FILES)
	@ make -f test.makefile $(MGUILLAU_CORR_FILES)

.PHONY: test_salwan_binary_samples
test_salwan_binary_samples: tests/salwan_binary_sample
	@ make -f test.makefile $(SALWAN_FILES)

.PHONY: test_mmeisson_tests_nm
test_mmeisson_tests_nm: tests/mmeisson_tests_nm
	@ make -f test.makefile $(MMEISSON_CORR_FILES)

tests/mguillau42_unit_test_nm_otool:
	@ mkdir -p tests/
	@ git clone --depth=1 --branch=master $(MGUILLAU_GIT) $(TMP_DIR)a
	@ rm -rf $(TMP_DIR)/a/.git
	@ mv $(TMP_DIR)/a $@

tests/salwan_binary_sample:
	@ mkdir -p tests/
	@ git clone --depth=1 --branch=master $(SALWAN_GIT) $(TMP_DIR)b
	@ rm -rf $(TMP_DIR)/b/.git
	@ mv $(TMP_DIR)/b $@

tests/mmeisson_tests_nm:
	@ mkdir -p tests/
	@ git clone --depth=1 --branch=master $(MMEISSON_GIT) $(TMP_DIR)c
	@ rm -rf $(TMP_DIR)/c/.git
	@ mv $(TMP_DIR)/c $@

##################################### TEST ####################################

## Normal check
/%: $(NAME_NM) $(NAME_OTOOL) FORCE
	@ printf "%s\\n" "$@"
	@ bash -c "diff <(nm $@) <($(NAME_NM) $@)"
	@ bash -c "diff <(otool -t $@) <($(NAME_OTOOL) $@)"

## Check corrupted
tests/%: $(NAME_NM) $(NAME_OTOOL) FORCE
	@ printf "check no abort\\t\\t%s\\n" "$@"
	@ $(NAME_NM) $@ > /dev/null
	@ $(NAME_OTOOL) $@ > /dev/null

.PHONY: FORCE
FORCE:
