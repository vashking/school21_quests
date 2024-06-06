#!/bin/bash
echo "Enter File:"
read file
if test -f "$file"; then
    echo 'File is found'
else
    echo 'File not found'
exit 1
fi

echo "Введите строку которую меняете, ENTER, после чего строку на которую поменяете"
read string1

if [ "string1" == "" ];then
    echo "Empty string is not allowed"
    exit 1
fi

read string2
sed -i '' "s/$string1/$string2/g" "$file" 

size="$(ls -la $file | awk '{print $5}')"
data=$(date -r $file +'%F %H:%M')
sha=$(shasum $file | awk '{print $1}')
echo "src/$file - $size - $data - $sha - sha256" >> files.log