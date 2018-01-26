#!/bin/sh

G_PATH_PATH_UNCRUSTIFY="scripts/path_uncrustify.txt"
G_PATH_CONFIG="scripts/config_uncrustify.cfg"

if [ ! -f $G_PATH_PATH_UNCRUSTIFY ]; then
	echo "The file $G_PATH_PATH_UNCRUSTIFY may not exist."
	echo "You have to create it and add the path to the uncrustify executable"
	echo "Look the repository uncrustify on Github to compile it"
else
	ret=`find ./src/ -name "*.java"`
	path_unc=`cat $G_PATH_PATH_UNCRUSTIFY`
	echo $path_unc
	for elem in $ret; do
		$path_unc -c $G_PATH_CONFIG --replace --no-backup --mtime $elem
	done
	exit 0
fi

exit 1
