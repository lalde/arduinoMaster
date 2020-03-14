# arduinoMaster

Syncing nVista DAQ with bottom-up behavioural camera

## Utility

Arduino board sends 2 TTLs:
- TTL pulse to nVista DAQ box (ttl_out_status, pin 11) *once* at the beginning of the session to start the imaging acquisition
- TTL pulse at a frequency designed by the user with int freq = value (typically, 60 Hz) so that the behavioural camera is recording frames at 60 frames per second (ttl_out_bottomC, pin 12) 

The sessions starts upon user input 1 in the serial monitor. The session lasts for the amount of time defined *in minutes* by the user in int recording_length_min. If needed, the session can be stopped earlier upon user input 0.

This is what  the status of pin 11 and 12 look like with Saleae Logic: 

![saleae recording](https://github.com/lalde/arduinoMaster/blob/master/saleae.png)


Early contribution by @lalde and @miguelvmc, huge thanks to @VincentDR for fixing the code and making it work 🧚‍♂️🌟



