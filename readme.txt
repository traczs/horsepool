**********************************************
Samuel Tracz
0927451
CIS 3490 Assignment 3
March 13, 2017
**********************************************

*************************
Compilation
*************************
make

*****************************
running the program
*****************************
./p11 data_4.txt
./p12 data_4.txt
./p21 data_5.txt
./p22 data_5.txt
./p23 data_5.txt

***************************
Notes
***************************
-p11 and p12 have a lot of repetetive code because of my parsing and me not feeling like doing a function
-p23 seg faults on 2 & 8 character strings
-either my horsepool or my b-m sometimes do not give the correct answer for the amount of occurences.(The search for "not" gave me different results, but other words seem fine)

*****************************
Question 2.4
*****************************
pattern|time ratios(horsepool:b-m)(milliseconds)|shift ratio
"a" | 46:25 | 3296591:1591939
"not"|16:15|1151746:834232
"stop"|12:11|880509:687874
"hello"|10:10|688373:552977
"jumped"|10:9|589109:491125
"welcome"|10:9|511374:426036
"hatchback"|6:8|393864:349283
"maximization"|8:6|317684:272892
"characteristics"|7:7|269061:242788
"verylongwordthatisverylong"|5:5|182104:168165

Average time ratio: 1.13.
Average shift ratio: 1.43

Observations: -the longer the word, the shorter it takes timewise and it requires less shifts for both algorithms
-Boyer-Moore algorithm is useful for short patterns, but once it hits a certain point, it is pretty much just as fast as horsepool
