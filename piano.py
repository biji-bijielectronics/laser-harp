import pygame
import time
import serial

pygame.mixer.init()
ser = serial.Serial('/dev/ttyACM0', 115200)



SOUND_MAPPING = {
  9: ['samples/db6.ogg',1,False],
  8: ['samples/b5.ogg' ,1,False],
  7: ['samples/bb5.ogg',1,False],
  6: ['samples/ab5.ogg',1,False],
  5: ['samples/gb5.ogg',1,False],
  4: ['samples/eb5.ogg',1,False],
  3: ['samples/db5.ogg',1,False],
  2: ['samples/bb4.ogg',1,False],
  1: ['samples/ab4.ogg',1,False],
  0: ['samples/gb4.ogg',1,False]
}

sounds = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
is_loop = [False,False,False,False,False,False,False,False,False,False,False,False,False]

for key,data in SOUND_MAPPING.iteritems():
        soundfile, volume, loop = data
        sounds[key] =  pygame.mixer.Sound(soundfile)
        sounds[key].set_volume(volume);
        is_loop[key] = loop

sounds_playing = [False,False,False,False,False,False,False,False,False,False,False,False,False]

#print is_loop



def playSound(sound_id):
    if is_loop[sound_id]:
        if not sounds_playing[sound_id]:
            sounds[sound_id].play(loops = -1)
            sounds_playing[sound_id] = True
    else:
        sounds[sound_id].play()
        sounds_playing[sound_id] = True

def stopSound(sound_id):
    sounds[sound_id].stop()
    sounds_playing[sound_id] = False


for key,data in SOUND_MAPPING.iteritems():
	print key
	playSound(key)
	time.sleep(0.1)

while True:
	try:
		line  = ser.readline().strip()
		val = ord(line[0]) - 65
		

		if val > 10:
			val -= 32
			print 'stop' , val
			#stopSound(val)
		else:
			print 'play', val
			playSound(val)
	except Exception as e:
		print e		
