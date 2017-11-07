
if [[ $# != "1" ]]; then
	exit 1
fi
/home/fauconfan/Documents/Tetriminos-generator/tetri-gen -i -f 15
cat sample.fillit > $1.txt
rm -f sample.fillit
../fillit $1.txt > $1.ans.txt
cat $1.ans.txt
