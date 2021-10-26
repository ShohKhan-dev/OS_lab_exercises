touch week01/file.txt
link week01/file.txt week10/_ex2.txt
INUM=$(ls -i week10/_ex2.txt | cut -d ' ' -f 1)
find .. -inum "$INUM"
find .. -inum "$INUM" -exec rm {} \;
