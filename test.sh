make re >/dev/null
make clean >/dev/null
./ft > mine
./std > real
diff mine real > result
if [ -s result ]
then
    echo "❌ Error"
else
    echo "✅ No difference between ft and std !"
fi
make fclean >/dev/null
rm mine real result