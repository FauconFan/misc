#!/bin/sh

G_VM="./filler_vm"
G_MINE="../jpriou.filler"
G_LIST_PLAYERS="abanlin.filler carli.filler champely.filler grati.filler hcao.filler superjeannot.filler"
G_MAP="map00 map01 map02"

G_DEFAULT_NB=5
if [[ $# = 1 ]]; then
	G_DEFAULT_NB=$(($1))
fi

fc_match()
{
	var1=0
	var2=0
	isfirst=0
	MAP_FP="maps/"$2
	PLAYER_FP="players/"$1
	ret=`$G_VM -q -f $MAP_FP -p1 $G_MINE -p2 $PLAYER_FP | tail -n 2 | tr ' ' '-'`
	for j in $ret; do
		data=`echo $j | cut -f4 -d-`
		if [ $isfirst = 0 ]; then
			var1=$data
			isfirst=1
		else
			var2=$data
		fi
	done
	is_winner=`echo "$var1 - $var2" | bc`
	echo "$var1/$var2"
	echo $is_winner
}

fc_match5()
{
	player_test=$1
	map=$2
	nb_win=0
	echo "Match versus $player_test on map $map"
	for (( nb = 0; nb < $G_DEFAULT_NB; nb++ )); do
		isfirst=0
		ret=`fc_match $player_test $map`
		for str in $ret; do
			if [[ $isfirst = 0 ]]; then
				echo $str
				isfirst=1
			else
				if [[ $str -gt 0 ]]; then
					nb_win=$((nb_win + 1))
				fi
			fi
		done
	done
	echo "Score Final "$nb_win" / $G_DEFAULT_NB"
}

for map in $G_MAP; do
	for p in $G_LIST_PLAYERS; do
		fc_match5 $p $map
	done
done
