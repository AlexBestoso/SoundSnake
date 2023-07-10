# SoundSnake
A wrapper for ALSA and PulseAudio code that makes it easier to do audio output and microphone input.
<p>
	This code is currently capable of taking .wav files and playing them through your speaker. The best way to use this in your applications is to run it in a forked process.<br> I've provided a sample .wav file to test with, it plays a sine wave sound.
</p>

## Requirements
1. Alsa library. Install with `sudo apt-get install libclalsadrv-dev -y`
2. PulseAudio library. Install with `sudo apt-get install libpulse-dev -y`


