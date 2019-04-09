#!/bin/zsh
SEED=(
	/usr/lib/*.dylib
	/etc/*.conf
	/etc/*rc
	/usr/lib/*.dylib
)

FAILURE=()
MINE=~/Projects/Algo/ft_ssl/ft_ssl
ORIG=/sbin/md5
k=0
for i in $SEED; do
	$MINE md5 $i > /tmp/a
	$ORIG $i > /tmp/b

	DIFF=$(diff /tmp/a /tmp/b)
	if [ "$DIFF" != ""  ]
	then
		FAILURE+=($i)
	else
		echo "[$k] Test for $i done."
	fi
	k=$((k + 1));
done

echo ""
for x in $FAILURE; do
	echo "Failed test for: $x";
done
t=$((k - ${#FAILURE[@]}));
echo "\nPassed $t/$k tests."
