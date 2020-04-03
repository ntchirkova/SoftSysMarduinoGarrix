# Marduino Garrix
#### By Samantha Young and Nina Tchirkova
#### 4/3/2020

![](/brandingphoto.png)

## Project Goals

In this project we planned to make an Arduino Synthesizer. We wanted to create a program that can generate a waveform that will correspond with a sound. In order to create these sounds the arduino will synthesize different waves of varying frequencies to make pleasing tones. These waveforms will include sine waves, triangle waves, and square waves. For our MVP we wanted to make a device that we can control what noises it outputs. The sound it outputs would be an arduino synthesised waveform. To take our project further,  we considered creating an interface that allows users to select waveforms, save generated waveforms, and then playback various saved “songs” like you would be able to play songs on an “iPod”. We are excited to be working with electrical hardware integrated application of C however the main goal of this project is software focused, not circuit focused. By implementing an already existing SoftSysSynth circuit we can hit the ground running with the embedded systems side of this project.

## Learning Goals

#### Original Learning Goals:
Nina wanted to use this project to find an application for using C and through this learn more about C and its values. She was also excited to refresh my knowledge of circuits and Arduinos.

Sam was excited to learn C and do so in an embedded systems and hardware related application. She was interested in learning how to develop software that needs to integrate with hardware and understand the differences between embedded systems software and standalone software only applications. She also planned to use this project to improve my git practices and git hygiene.
 
#### Revised learning goals:

Through this project the team encountered several outside of class roadblocks (a switch to a remote curriculum due to COVID-19, family tragedy, etc.) and pressures that forced them to really focus in on our learning goals, figure out what was needed to be done in order to achieve them as well as determine how to change them to adapt to the new situation. 
Due to the corona pandemic, the learning goals regarding proper usage of git and git hygiene became even more critical for a successful project. Additionally the team both smooth remote working as learning goals. They wanted to learn how to pair program when in different physical locations. A main challenge of this was that only one person had the physical circuit and Arduino hardware.

## Outcome

We were successful in using an arduino and an accompanied circuit to play various waveforms of changing frequencies out of a speaker. The user can select one of three push buttons to play either a sine wave, square wave, or saw wave. Simultaneously, the user can adjust a slider that will vary the frequency of whatever waveform is currently being played in realtime. The slider was used to vary a voltage that was then read by the Arduino as an analog input. This input was used to determine what frequency the program would play. This system demonstrates how changes in frequency audibly impact different waveforms: sine, saw and square.

Please see this link for a video of the program on the arduino. 
https://www.youtube.com/watch?v=d14xPI23je4

[![](/marduino_youtube.PNG)](https://www.youtube.com/watch?v=d14xPI23je4 "Marduino Garrix - varied frequency and waves forms")

We achieved between the lower and middle bounds of our original project functionality goals. The final project included the use of a slider that changed a voltage to real time control the frequency of a specific waveform and buttons that allowed the user to pick between different kinds of waveforms.

With an increased focus on learning goals during these extraordinary circumstances, the team achieved our learning goals and some. From a remote working learning goal perspective, only Sam had the hardware, this required Nina to write all of her code without testing it. Nina needed to have a thorough understanding of how her code would run on an Arduino without being able to test, modify, tweak, guess or check. In the remote setup, Sam developed code and as well as tested Nina’s code on the Arduino. She needed to be able to read Nina’s code and understand how it worked well enough to debug and fix so that it could easily play on the Arduino. Through virtual pair programming sessions Nina and Sam were able to successfully code the Arduino to play different sounds of different frequencies. Though reluctant at first to do pair programming, the team actively tried to make this system work remotely through coding and sharing screens at the same time as well as thinking thought processes through out so that the other person in the zoom call could have input. 

![](/screenshot.png)

Another important learning goal for Sam was learning how to effectively version control with git. There were some growing pains when it came to achieving this learning goal, work was created and lost and rewritten. The team decided to use branches to separate Sam’s work and Nina’s based on specific functionality development. Understanding how the branches tracked one another and tracked master helped Sam better learn the git workflow. Because Nina has extensively used git in her internships and software classes she was able to help Sam along in learning to not fear git. Basic git functionalities like branching, rebasing, searching through reflogs etc were not just blindly completed but thoroughly understood. This was done through partner programming and drawing workflow trees on white boards. 

Because Nina specializes in software development and Sam specialized in hardware development, Nina was able to achieve her learning goal of better understanding and refreshing circuits knowledge with Sam’s help by really understanding the 8bit audio converter and the arduino. To do this the team watched oscilloscope videos to characterize different waveforms and understand what they looked like. By walking through the circuit diagram and R2R ladder Nina learned about how an analog signal can be constructed from a digital inputs through a specific process of voltage dividers that weights each digital input based on its binary significance and constructs the analog output signal.

Sam’s learning goal about learning the limitations of hardware and how to write software that can be written for hardware was actually throughout this project. An interesting learning moment from this project was when trying to debug the program using serial outputs. When the serial outputs were included the sine function sounded garbled, however when the print statements were removed the sine wave audibly sounded fine. This was a direct lesson in how software calls, though seemingly instantaneous sometimes, can take a not insignificant amount of time. In this case the length of the serial print call was long enough to delay the points played in the sine function so that the complete signal was unintelligible.

 
## Technical Decisions
For the wave functions, initially we wanted the input to be a frequency in Hz. However, for the sine function, in order to convert the frequency to radians we needed an accurate way to determine how many seconds had passed. Although, arduino has a millis() function that returns a time in milliseconds, we determined it did not take time very quickly. To see how it worked, we printed out its values, and it would show the same value for a few seconds and then switch to a much higher value. Since wave functions that produce sound have frequencies that are much higher than once per a few seconds we realized that we could not rely on the millis() function. To work around this, the slider outputted values from 1 to 10 where 1 was a low frequency and 10 was a high frequency. Each wave function interpreted the values from 1 to 10 to output a corresponding wave function.
Another decision we made was to not use the built in sine function in C. This is because sine is a computationally intense function and therefore could cause lag in the program. Instead, we used an array of sine values with an amplitude of 250, to adjust to the analog output of the arduino.

```
int sine(int freq) {
    rads = rads + freq;
    if (rads > len) {
        rads = rads%len;
    }
    return sine_arr[rads];
}
```

## Resources
The main resource we used was the project guide here: https://sites.google.com/site/softwaresystems2015/backlog/projects. We used this to understand the circuit and for example code.
