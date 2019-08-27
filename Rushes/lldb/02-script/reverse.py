#!/usr/bin/python

import lldb
import commands

def reverse(debugger, command, result, internal_dict):
	for name in debugger:
		command = "FT_" + str(name)[::-1]
		print >>result, (command)

# And the initialization code to add your commands
def __lldb_init_module(debugger, internal_dict):
	helper = "Reverse the entire target name (text string) and add \'FT_\' as a prefix."
	debugger.HandleCommand('command script add -h "{}" -f reverse.reverse reverse'.format(helper))
