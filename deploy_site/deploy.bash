#!/bin/bash
set -eu

SERVER="ssh.cluster021.hosting.ovh.net"
USER="jprioufrvu"
PATH_ON_SERVER="www/"

# just enable no host key checking
sshpass -p 'dbMyV4bS94tWF5yLXD5Kvs7vt4j7' ssh -o "StrictHostKeyChecking no" "$USER@$SERVER" echo "Adding in known hosts"

PATH_FILE=""

if [ -f "./kde.php" ]; then
	PATH_FILE="./kde.php"
elif [ -f "deploy_site/kde.php" ]; then
	PATH_FILE="deploy_site/kde.php"
else
	echo "You are in a wrong directory"
	exit 1
fi

php "${PATH_FILE}"

echo ""
echo "Check your data"
echo "type 'enter' if you agree, Ctrl+C to abort"
read -r LINE

if [ ! "$LINE" == "enter" ]; then
	echo "Wrong word, type litteraly 'enter'"
	exit 1
fi

sshpass -p 'dbMyV4bS94tWF5yLXD5Kvs7vt4j7' scp "${PATH_FILE}" "$USER@$SERVER:$PATH_ON_SERVER/kde.php"
echo "The file has been updated"
