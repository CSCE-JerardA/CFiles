flags = -std=c++17 -Wall

style1 : program2functions.h
	cpplint program2functions.h

style2 : program2functions.cc
	cpplint program2functions.cc

program2functions.o : program2functions.cc program2functions.h
	g++ $(flags) -c $<

compile : program2functions.o
	

testRange : testRange.cc program2functions.o
	g++ $(flags) $^ -o $@
	./$@

testDigitInPosition : testDigitInPosition.cc program2functions.o
	g++ -$(flags) $^ -o $@
	./$@

testIsSquare : testIsSquare.cc program2functions.o
	g++ $(flags) $^ -o $@
	./$@

testIsPerfect : testIsPerfect.cc program2functions.o
	g++ $(flags) $^ -o $@
	./$@

testToDigit : testToDigit.cc program2functions.o
	g++ $(flags) $^ -o $@
	./$@

testIsConsonant : testIsConsonant.cc program2functions.o
	g++ $(flags) $^ -o $@
	./$@

testIsVowel : testIsVowel.cc program2functions.o
	g++ $(flags) $^ -o $@
	./$@

clean :
	rm checkit program2*.o testLeapYear testLastDayOfMonth testValidDate testNextDate testPreviousDate

