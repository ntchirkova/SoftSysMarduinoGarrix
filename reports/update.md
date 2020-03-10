#Marduino Garrix Project Update

Nina Tchirkova and Samantha Young

###Project Goals
In this project we would like to make an Arduino Synthesizer. We will create a program that can generate a waveform that will correspond with a sound. In order to create these sounds the arduino will synthesize different waves of varying frequencies. These waveforms will include sine waves, triangle waves, and square waves. For our MVP we would just like to make a device that we can control what noises it outputs. The sound it outputs will be an arduino synthesised waveform. To take our project further we can create an interface that allows users to select waveforms, save generated waveforms, and then playback various saved “songs” like you would be able to play songs on an “iPod”. We are excited to be working with electrical hardware integrated application of C however the main goal of this project is software focused, not circuit focused. By implementing an already existing SoftSysSynth circuit we can hit the ground running with the embedded systems side of this project.

###Learning Goals

####Nina:

I would like to use this project to find an application for using C and through this learn more about C and its values. I am also excited to refresh my knowledge of circuits and Arduinos.

####Sam:

Through this project I am excited to learn C and do so in an embedded systems and hardware related application. I am interested in learning how to develop software that needs to integrate with hardware and understand the differences between embedded systems software and standalone software only applications. I am also going to use this project to improve my git practices and git hygiene.

###Project Progress

Since the project started we have made significant progress. First, we acquired the synth circuit and read its documentation. Next we attached it to power to determine its functionality. After that we implemented very simple sine and saw wave functions. Right now we are working on being able to modulate the frequency of waves.
Nina is working on implementing sine, saw and pulse wave functions that can take in as input different frequencies. Initially we thought we could directly input the frequencies in Hz, but after doing some experimentation, we decided that the time function in arduino had too much lag to be used reliably for our purposes. So Nina is continuing to work on implementations for each type of wave that can vary the frequency but not in Hertz.
Sam has worked to integrate new hardware like an analog potentiometer and more buttons. The potentiometer is being used to vary the frequency of the waves being output on the speaker. She has also written the firmware to integrate this new hardware with the current sound playing framework. Some interesting challenges involved in integrating the new hardware is time delays that occur between pressing buttons/sliding sliders and hearing the outcome of those actions from the speaker.

###Links

Github: https://github.com/ntchirkova/SoftSysMarduinoGarrix
Trello: https://trello.com/b/1gRZIXd4/marduino-garrix