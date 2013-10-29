# Lab 4 - C - "An LCD Driver"

### Objective

##### Write a driver in C for the MSP430 to be used with the LCD screen.
##### 

### Preliminary Design

##### Design API (Application Programming Interface)
###### -Use the code from the example in my header file

##### Turn assembly constructs from Lab 3 into usable C code
###### -The same pins will be used as in Lab 3 (saving a lot of time not figuring that all out again)

##### Implement software delays with C
###### -The __delay_cycles(num_cycles) macro seems like a good place to start for the software delays (same number of cycles as in Lab 3 as well)
##### 

### Implementation
#### Each void loop is similar to the subroutines used previously in assembly for Lab 3. The work was all pretty much taken care of in the previous lab, all there is now is converting it to C.
#### Google will be a valuable resource, along with forums about programming in C in order to use the correct syntax when setting the correct pins for MISO, SIMO, SS, and CLK. Using the same numbered pins as in Lab 3 will work fine.
#### The delays will be the same as in lab 3 as well. My MSP430 delay 1 was 46.6 cycles, so I will round that up to 47 and my delay 2 was 1628 so I will round that up to 1630.
##### 

### Testing Methodology / Results
#### Being hard-pressed for time after being on bedrest all of last week, I did not approach the coding with as much testing as I should have. I made use of committing my code often and with commit messages to explain what i was doing along the way.
#### My testing method boiled down to pretty much: 
##### 1. code  
##### 2. build  
##### 3. check errors  
##### 4. Google if not easily resolved on my own  
##### 5. recode  
##### 6. build -> back to 3 if there are still/new errors
##### 7. run
##### 8. check LCD
#### After each time I built my code I committed it to github and that is how I kept track of my progress.

### Observations
#### During a lab is not a fun time to be on bedrest. Had I not been, I would have collaborated more and/or tried to get EI and hopefully achieved A functionality, but it's not the end of the world. I managed to get the screen cleared without much trouble, but getting it to write and scroll gave me trouble. Baron helped me clear up my issues there.
##### 

### Conclusion
#### My LCD Driver performed simple functionality. I did not have time to make an attempt at implementing the buttons and try for B functionality. The lesson I wanted to take away from the last lab was to work ahead so I would not be hard pressed for time and get stressed, but my body and immune system had other plans. Regardless, I made the effort to at least get the screen cleared on my own until I could get some help.
#### Overall, not entirely pleased with only simple functionality, but based on the circumstances, it was better than nothing.
##### 

### Documentation
#### Collaborated with the Baron on the scrolling function of the code