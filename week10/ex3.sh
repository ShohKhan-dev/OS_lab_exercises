touch _ex3.txt				
echo Shohjahon > _ex3.txt
ls -l _ex3.txt

chmod a-x _ex3.txt		# remove execute permissions from everyone 
ls -l _ex3.txt

chmod u+rwx,o+rwx _ex3.txt	# give all permissions to user and others 
ls -l _ex3.txt

chmod g=u _ex3.txt		# give group same permissions as user
ls -l _ex3.txt

rm _ex3.txt
