folders=$(find $1 -type f -name *.$2)
mkdir $3
cp $folders $3
cd $3
tar -czf $4 $folders
echo done
