# CS 3050 Programming Assignment #3.		

You are in a skyscraper and you are currently in floor s, where you see an elevator. Upon entering the elevator, you learn that it has only two buttons, marked "UP *u*" and "DOWN *d*". The UP-button takes the elevator *u* floors up (if there aren't enough floors, pressing the UP-botton does nothing), whereas the DOWN-button takes you d stories down (or none if there aren't enough). If you want to go to floor *g*, and that there are only f floors in the building, write a program that gives you the amount of button pushes you need to perform. If you simply cannot reach the correct floor, your program halts with the message "use the stairs".

Given input *f, s, g, u* and *d* (floors, start, goal, up, down), find the shortest sequence of button presses you must press in order to get from *s* to *g*, given a building of floors, or output "use the stairs" if you cannot get from *s* to *g* by the given elevator.

**Input**
The input will consist of one line, namely f s g u d, where 1 <= s, g <= f <= 100 and 0 <= u, d <= 100. The floors are one-indexed, i.e. if there are 10 stories, s and g be in [1; 10].

**Output**
Write the sequence with the minimum number of pushes you must make in order to get from s to g, or output "use the stairs" if it is impossible given the configuration of the elevator.

## Instructions:
To compile, run:
g++ *.cpp -o Prog3 -Wall -Werror

Then, run:
Prog3

## Example 1:
**Input:**
99 1 10 2 1

**Output:**
1 -> 3 -> 5 -> 7 -> 9 -> 11 -> 10


## Example 2:

**Input:**
70 2 1 1 0 

**Output:**
use the stairs
