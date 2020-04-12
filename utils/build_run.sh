filename=$1

if [ "${filename}" == "" ]
then
    echo "please enter filename..."
    exit 0
fi

g++ $filename src/*.cc -std=c++11 -I./include/ 

if [ ! -f "a.out" ];
then
    echo "compiler failed..."
    exit 0
else
    ./a.out
fi