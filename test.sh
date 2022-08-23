make re >/dev/null
make clean >/dev/null
./std > real 2>&1
./ft > mine 2>&1
diff mine real > result
if [ -s result ]
then
    echo "❌ \e[1;31mError\e[0m"
	cat result
else
    echo "✅ \e[1;32mNo difference between ft and std !\e[0m\n"
    echo "⏱️  \e[1;37mTesting performance...\e[0m"
	echo "\e[0;33mSTD :\e[0m"
	time -p ./std >/dev/null
	echo "\e[0;33mFT :\e[0m"
	time -p ./ft >/dev/null
fi
#make fclean >/dev/null
rm mine real result