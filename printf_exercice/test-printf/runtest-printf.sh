GREEN='\033[0;32m'
DARK_BLUE='\e[1;34m'
RED='\x1B[31m'
BLUE='\e[96m'
NC='\033[0m'
i=0
success=0
error=0

# $1 = text, $2 = test number
test()
{
	printf "$1" >> test-printf/result.log
	test-printf/test.out $2 > test-printf/original_output
	echo $? >> test-printf/original_output
	sh test-printf/timeout.sh 1 test-printf/test.out $2 user > test-printf/user_output 2> /dev/null
	ret=$(echo $?)
	echo $ret >> test-printf/user_output
	if diff "test-printf/original_output" "test-printf/user_output" >> /dev/null
	then
		if [ $error -eq 1 ]
		then
			printf "\n"
		fi
    	printf "${GREEN}OK ${NC}"
    	printf "${GREEN}OK ${NC}\n" >> test-printf/result.log
		((success++))
		error=0
	else
    	printf "\n${RED}$1"
		if [ $ret -eq 142 ] #timeout
		then
			printf "${RED}TIMEOUT${NC}"
			printf "${RED}TIMEOUT${NC}\n" >> test-printf/result.log
		else
			printf "${RED}FAILED${NC}"
			printf "${RED}FAILED${NC}\n" >> test-printf/result.log
		fi
		error=1
	fi
	((i++))
}

rm test-printf/result.log
make all
make bonus
gcc -Wall -Wextra -Werror -Wformat=0 test-printf/test-main.c libftprintf.a -o test-printf/test.out
printf "\n${BLUE}[H - Tests with minimum field width, flag 0 and .]${NC}\n"
test "$i - (\"%%01.0i\", 0) : ${NC}" $i 
test "$i - (\"%%01.1i\", 0) : ${NC}" $i 
test "$i - (\"%%01.2i\", 0) : ${NC}" $i 
test "$i - (\"%%01.10i\", 0) : ${NC}" $i 
test "$i - (\"%%02.0i\", 0) : ${NC}" $i 
test "$i - (\"%%02.1i\", 0) : ${NC}" $i 
test "$i - (\"%%02.2i\", 0) : ${NC}" $i 
test "$i - (\"%%02.10i\", 0) : ${NC}" $i 
test "$i - (\"%%010.0i\", 0) : ${NC}" $i 
test "$i - (\"%%010.1i\", 0) : ${NC}" $i 
test "$i - (\"%%010.2i\", 0) : ${NC}" $i 
test "$i - (\"%%010.10i\", 0) : ${NC}" $i 
test "$i - (\"%%01.0i\", -1) : ${NC}" $i 
test "$i - (\"%%01.1i\", -1) : ${NC}" $i 
test "$i - (\"%%01.2i\", -1) : ${NC}" $i 
test "$i - (\"%%01.10i\", -1) : ${NC}" $i 
test "$i - (\"%%02.0i\", -1) : ${NC}" $i 
test "$i - (\"%%02.1i\", -1) : ${NC}" $i 
test "$i - (\"%%02.2i\", -1) : ${NC}" $i 
test "$i - (\"%%02.10i\", -1) : ${NC}" $i 
test "$i - (\"%%03.0i\", -1) : ${NC}" $i 
test "$i - (\"%%03.1i\", -1) : ${NC}" $i 
test "$i - (\"%%03.2i\", -1) : ${NC}" $i 
test "$i - (\"%%03.10i\", -1) : ${NC}" $i 
test "$i - (\"%%09.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%09.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%09.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%09.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%01.0d\", 0) : ${NC}" $i 
test "$i - (\"%%01.1d\", 0) : ${NC}" $i 
test "$i - (\"%%01.2d\", 0) : ${NC}" $i 
test "$i - (\"%%01.10d\", 0) : ${NC}" $i 
test "$i - (\"%%02.0d\", 0) : ${NC}" $i 
test "$i - (\"%%02.1d\", 0) : ${NC}" $i 
test "$i - (\"%%02.2d\", 0) : ${NC}" $i 
test "$i - (\"%%02.10d\", 0) : ${NC}" $i 
test "$i - (\"%%010.0d\", 0) : ${NC}" $i 
test "$i - (\"%%010.1d\", 0) : ${NC}" $i 
test "$i - (\"%%010.2d\", 0) : ${NC}" $i 
test "$i - (\"%%010.10d\", 0) : ${NC}" $i 
test "$i - (\"%%01.0d\", -1) : ${NC}" $i 
test "$i - (\"%%01.1d\", -1) : ${NC}" $i 
test "$i - (\"%%01.2d\", -1) : ${NC}" $i 
test "$i - (\"%%01.10d\", -1) : ${NC}" $i 
test "$i - (\"%%02.0d\", -1) : ${NC}" $i 
test "$i - (\"%%02.1d\", -1) : ${NC}" $i 
test "$i - (\"%%02.2d\", -1) : ${NC}" $i 
test "$i - (\"%%02.10d\", -1) : ${NC}" $i 
test "$i - (\"%%03.0d\", -1) : ${NC}" $i 
test "$i - (\"%%03.1d\", -1) : ${NC}" $i 
test "$i - (\"%%03.2d\", -1) : ${NC}" $i 
test "$i - (\"%%03.10d\", -1) : ${NC}" $i 
test "$i - (\"%%09.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%09.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%09.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%09.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%01.0u\", 0) : ${NC}" $i 
test "$i - (\"%%01.1u\", 0) : ${NC}" $i 
test "$i - (\"%%01.2u\", 0) : ${NC}" $i 
test "$i - (\"%%01.10u\", 0) : ${NC}" $i 
test "$i - (\"%%02.0u\", 0) : ${NC}" $i 
test "$i - (\"%%02.1u\", 0) : ${NC}" $i 
test "$i - (\"%%02.2u\", 0) : ${NC}" $i 
test "$i - (\"%%02.10u\", 0) : ${NC}" $i 
test "$i - (\"%%010.0u\", 0) : ${NC}" $i 
test "$i - (\"%%010.1u\", 0) : ${NC}" $i 
test "$i - (\"%%010.2u\", 0) : ${NC}" $i 
test "$i - (\"%%010.10u\", 0) : ${NC}" $i 
test "$i - (\"%%01.0u\", -1) : ${NC}" $i 
test "$i - (\"%%01.1u\", -1) : ${NC}" $i 
test "$i - (\"%%01.2u\", -1) : ${NC}" $i 
test "$i - (\"%%01.10u\", -1) : ${NC}" $i 
test "$i - (\"%%02.0u\", -1) : ${NC}" $i 
test "$i - (\"%%02.1u\", -1) : ${NC}" $i 
test "$i - (\"%%02.2u\", -1) : ${NC}" $i 
test "$i - (\"%%02.10u\", -1) : ${NC}" $i 
test "$i - (\"%%03.0u\", -1) : ${NC}" $i 
test "$i - (\"%%03.1u\", -1) : ${NC}" $i 
test "$i - (\"%%03.2u\", -1) : ${NC}" $i 
test "$i - (\"%%03.10u\", -1) : ${NC}" $i 
test "$i - (\"%%09.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%01.0x\", 0) : ${NC}" $i 
test "$i - (\"%%01.1x\", 0) : ${NC}" $i 
test "$i - (\"%%01.2x\", 0) : ${NC}" $i 
test "$i - (\"%%01.10x\", 0) : ${NC}" $i 
test "$i - (\"%%02.0x\", 0) : ${NC}" $i 
test "$i - (\"%%02.1x\", 0) : ${NC}" $i 
test "$i - (\"%%02.2x\", 0) : ${NC}" $i 
test "$i - (\"%%02.10x\", 0) : ${NC}" $i 
test "$i - (\"%%010.0x\", 0) : ${NC}" $i 
test "$i - (\"%%010.1x\", 0) : ${NC}" $i 
test "$i - (\"%%010.2x\", 0) : ${NC}" $i 
test "$i - (\"%%010.10x\", 0) : ${NC}" $i 
test "$i - (\"%%01.0x\", -1) : ${NC}" $i 
test "$i - (\"%%01.1x\", -1) : ${NC}" $i 
test "$i - (\"%%01.2x\", -1) : ${NC}" $i 
test "$i - (\"%%01.10x\", -1) : ${NC}" $i 
test "$i - (\"%%02.0x\", -1) : ${NC}" $i 
test "$i - (\"%%02.1x\", -1) : ${NC}" $i 
test "$i - (\"%%02.2x\", -1) : ${NC}" $i 
test "$i - (\"%%02.10x\", -1) : ${NC}" $i 
test "$i - (\"%%03.0x\", -1) : ${NC}" $i 
test "$i - (\"%%03.1x\", -1) : ${NC}" $i 
test "$i - (\"%%03.2x\", -1) : ${NC}" $i 
test "$i - (\"%%03.10x\", -1) : ${NC}" $i 
test "$i - (\"%%09.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%01.0X\", 0) : ${NC}" $i 
test "$i - (\"%%01.1X\", 0) : ${NC}" $i 
test "$i - (\"%%01.2X\", 0) : ${NC}" $i 
test "$i - (\"%%01.10X\", 0) : ${NC}" $i 
test "$i - (\"%%02.0X\", 0) : ${NC}" $i 
test "$i - (\"%%02.1X\", 0) : ${NC}" $i 
test "$i - (\"%%02.2X\", 0) : ${NC}" $i 
test "$i - (\"%%02.10X\", 0) : ${NC}" $i 
test "$i - (\"%%010.0X\", 0) : ${NC}" $i 
test "$i - (\"%%010.1X\", 0) : ${NC}" $i 
test "$i - (\"%%010.2X\", 0) : ${NC}" $i 
test "$i - (\"%%010.10X\", 0) : ${NC}" $i 
test "$i - (\"%%01.0X\", -1) : ${NC}" $i 
test "$i - (\"%%01.1X\", -1) : ${NC}" $i 
test "$i - (\"%%01.2X\", -1) : ${NC}" $i 
test "$i - (\"%%01.10X\", -1) : ${NC}" $i 
test "$i - (\"%%02.0X\", -1) : ${NC}" $i 
test "$i - (\"%%02.1X\", -1) : ${NC}" $i 
test "$i - (\"%%02.2X\", -1) : ${NC}" $i 
test "$i - (\"%%02.10X\", -1) : ${NC}" $i 
test "$i - (\"%%03.0X\", -1) : ${NC}" $i 
test "$i - (\"%%03.1X\", -1) : ${NC}" $i 
test "$i - (\"%%03.2X\", -1) : ${NC}" $i 
test "$i - (\"%%03.10X\", -1) : ${NC}" $i 
test "$i - (\"%%09.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.10X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.10X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.10X\", UINT_MAX) : ${NC}" $i 
printf "\n\n${DARK_BLUE}Result [$success/$i]${NC}"
