echo "STARTING THE PROGRAM..."
sleep 1
echo "..."
sleep 1
echo "..."
sleep 1
echo "..."
sleep 1
echo "**HINT: PRESS CTRL+C to EXIT the PROGRAM"
sleep 2

if [ ! -f  "ex2.txt" ]; then
	echo "WARNING! -> ex2.txt file does not exist!"
	echo "CREATING ex2.txt file..."
	touch ex2.txt
	echo "ex2.txt is created!"
	echo "1" > ex2.txt
	sleep 2
	
fi
last="$(tail -1 ex2.txt)"
integer='^[0-9]+$'

if ! [[ $last =~ $integer ]]; then
	echo "ERROR! -> INVALID INPUT IN 'ex2.txt' FILE"
	echo "'ex2.txt' FILE must contain only INTEGER"
	exit
	
fi

filePath="ex2.txt"
lockPath="ex2.lock"

trap 'rm ${lockPath};exit' exit
echo "LOCKING..."
if ln $filePath $lockPath 2>&-; 
then
    echo "FILE IS LOCKED"
else
    echo $(<$filePath)
    rm $tmpfile
    exit
fi

while  [ true ]
do