make re >/dev/null
make clean >/dev/null
./ft > mine 2>&1
./std > real 2>&1
diff mine real > result
if [ -s result ]
then
    echo "❌ Error"
	cat result
else
    echo "✅ No difference between ft and std !"
fi
make fclean >/dev/null
rm mine real result