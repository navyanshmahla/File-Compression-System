# RUN LENGTH ENCODING

Probably one of the most intuitive and easy-to-think of algorithm for data compression.
Say, you have a string and you want to compress it down, the very first thought that any person would have is to omit repeating the string characters. 
That's simple enough! The way you want to decode it back to original string must be lossless.

## The algo

Say you have a string: WWWWWWWWWWWWAAAAAAAAAAAQQQQQ
The above string contains 'W' 12 times, 'A' 10 times and 'Q' 5 times.

The possible way to omitting the repeating characters is by writing them once and then prefexing them with a number showing the count of times that character is repeated in the main string.

So the RUN LENGTH ENCODED string for the above example is: 12W10A5Q

Simple is that!


