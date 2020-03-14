# arduinoMaster

Trying to sync the behavioural and imaging recordings on the calcium imaging rig

## Aim 

Arduino board sends 2 TTLs:
- TTL pulse to nVista DAQ box (ttl_out_status, pin 11) *once* at the beginning of the session to start the imaging acquisition
- TTL pulse at a frequency designed by the user with int freq = value (typically, 60 Hz) so that the behavioural camera is recording frames at 60 frames per second. 

![This is what it looks like](https://github.com/lalde/arduinoMaster/blob/master/saleae.png)
