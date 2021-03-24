paths=$(find $1 -type f -name "*.$2")
mkdir $3
for path in $paths
do
	cp --parent $path $3
done
tar -czf $4 $3
echo done
