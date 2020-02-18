filename=$1

if [ "${filename}" == "" ]
then
    echo "please enter filename..."
    exit 0
fi

g++ $filename -std=c++11 -I./

if [ ! -f "a.out" ];
then
    echo "compiler failed..."
    exit 0
else
    ./a.out
fi