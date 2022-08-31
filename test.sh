# not necessary
if [ "$1" = "x" ] || [ "$2" = "x" ]
then
	clear
fi	
#

make re >/dev/null
make clean >/dev/null

if [ "$1" = "stack" ]
then
	./std stack > real 2>&1
	./ft stack > mine 2>&1
elif [ "$1" = "vector" ]
then
	./std vector > real 2>&1
	./ft vector > mine 2>&1
else
	./std > real 2>&1
	./ft > mine 2>&1
fi

diff real mine > result

if [ -s result ]
then
	echo "❌ \e[1;31mError\e[0m"
	cat result
else
	echo "✅ \e[1;32mNo difference between ft and std !\e[0m\n"
	echo "⏱️  \e[1;37mTesting performance...\e[0m"
	echo "\e[0;33mSTD $1:\e[0m"
	time -p ./std $1 >/dev/null
	echo "\n\e[0;33mFT $1:\e[0m"
	time -p ./ft $1 >/dev/null
fi

# not necessary
if [ "$1" = "c" ] || [ "$2" = "c" ]
then
	make fclean >/dev/null
fi	
#

rm mine real result
