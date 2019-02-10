#importation des librairies
from Tkinter import *
import websocket 

ws = websocket.WebSocket()
ws.connect("ws://192.168.1.50")

master = Tk()

def on():
	print "Led allume"
	ws.send("1")
def off():
	print "Led etteinte"
	ws.send("0")

Button(master, text="On", command = on).pack(side=LEFT, padx=5, pady=5)
Button(master, text="Off", command=off).pack(side=RIGHT, padx=5, pady=5)

master.mainloop()
