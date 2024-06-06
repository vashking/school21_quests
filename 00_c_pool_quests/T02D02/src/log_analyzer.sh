#!/bin/bash
echo "Enter File:"
read file
if test -f "$file"; then
    echo 'File is found'
else
    echo 'File not found, exit'
exit 1
fi

amount=$(wc -l $file | awk '{print $1}')
unique=$(cat $file | cut -d " " -f 1 | uniq | wc -l)
hash=$(cat files.log | awk '{print $8}' | uniq | wc -l)

echo $amount $unique $hash