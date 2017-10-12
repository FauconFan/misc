
if [[ $# != "1" ]]; then
	exit 1
fi
echo "...." > $1
echo "..##" >> $1
echo "..##" >> $1
echo "...." >> $1
echo "" >> $1
echo "...." >> $1
echo "..##" >> $1
echo "..##" >> $1
echo "...." >> $1
echo "" >> $1
/home/fauconfan/Documents/Tetriminos-generator/tetri-gen -v -f 4
cat sample.fillit >> $1
rm -f sample.fillit
../fillit $1
