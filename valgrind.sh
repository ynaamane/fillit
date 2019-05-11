if [[ $1 == "" ]]
 then
 echo "Usage type: sh valgrind.sh map"
 exit 0
fi

#!/bin/sh
valgrind -v --leak-check=full ./fillit $1
#!--show-leak-kinds=all  ./fillit $1
