#include "cimp.h"

#define	ARG_NAME_TAG "NAME"
#define	ARG_NUM_TAG  "NUM"
#define	ARG_PATH_TAG "PATH"
#define	ARG_RECT_TAG "RECT"

const char * arg_type_to_string(t_arg_type atype) {
	switch (atype) {
		case ARG_NAME:
			return (ARG_NAME_TAG);

		case ARG_NUM:
			return (ARG_NUM_TAG);

		case ARG_PATH:
			return (ARG_PATH_TAG);

		case ARG_RECT:
			return (ARG_RECT_TAG);
	}
	// Should never happened
	return (NULL);
}
