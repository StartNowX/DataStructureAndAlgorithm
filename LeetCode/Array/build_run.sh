filename=$1

if [ "${filename}" == "" ]
then
    echo "please enter filename..."
    exit
fi

g++ $filename -std=c++11 -I./../

./a.out