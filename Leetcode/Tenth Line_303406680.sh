# Read from the file file.txt and output the tenth line to stdout.

i=1
while read line
do
    if [ $i -eq 10 ]
    then
        echo $line
    fi
    ((i++))
done < file.txt

