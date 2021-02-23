paths=$(find $1 -type f -name "*.$2")
mkdir $3
for path in $paths
do
	mkdir -p $3/$path
	cp $path $3/$path
done
tar -czf $3/$4 $3/$1
echo done
