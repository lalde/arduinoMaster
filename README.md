# arduinoMaster

Trying to sync the behavioural and imaging recordings on the calcium imaging rig

## Aim 

Arduino board sends 2 TTLs:
- TTL pulse to nVista DAQ box (ttl_out_status, pin 11) *once* at the beginning of the session to start the imaging acquisition
- TTL pulse at a frequency designed by the user with int freq = value (typically, 60 Hz) so that the behavioural camera is recording frames at 60 frames per second (ttl_out_bottomC, pin 12) 

This is what it looks like when monitoring the status of pin 11 and 12 with Saleae Logic: 

![saleae recording](https://github.com/lalde/arduinoMaster/blob/master/saleae.png)

Ideally, the user could define beforehand how long the recording session should last, ie. for how long does the arduino needs to send the 60Hz pulse on pin 12 and maintain the pulse high on pin 11.

**The script arduinoMasterLD.ino is an attempt to do so, however there are 2 issues:**
1) in the do...while loop, we are attempting to run the 60Hz sequence until a number of iterations have been reached. This number of iterations is the number of loops needed to cover the length of the recording session defined by the user (int recording_length_min). However, it doesn't behave as expected even though I *think* the maths are correct. Exemple if I put recording_length_min = 10 it will run not for 10min but for 10s. If I put it on 100, expecting it to run for 100s, well it doesn't do that either. 

2) Once the do...while loop has started, user cannot stop the script: arduino cannot check the else if condition as long as the if condition is not completed. I don't know what would be the good work around for that.

**ArduinoMaster_notimer.ino**
This one is just running the sequence continuously, but this behaviour is not optimal because:
- it sends the TTL pulses as soon as the sketch is uploaded 
- it cannot be stopped unless the arduino is plugged out


