if [ $# == 3 ]
then
	perl ~/Desktop/piscine/genmap.perl $1 $2 $3 > $1x$2x$3
	cat $1x$2x$3
else
	echo "Invalid number of arguments.\nUsage : genmap [x] [y] [density]"
fi