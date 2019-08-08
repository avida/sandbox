#!/usr/bin/env python3
from asciimatics.screen import Screen 
from asciimatics.scene import Scene
from asciimatics.effects import Stars, Cycle
from asciimatics.renderers import FigletText
import time

def demo(screen):
    posX = 0
    while True:
        time.sleep(.1)
        screen.clear()
        if posX >= 299:
            posX = 0
        screen.print_at('Hi', posX, 4, colour=2)
        posX += 1
        ev = screen.get_key()
        screen.refresh()
        if ev  in (ord('Q'), ord('q')):
            return
def effects_demo(screen):
    effects = [
     Cycle(screen, FigletText("Hello", font = 'big'), screen.height // 2 )
    ]
    screen.play([Scene(effects, 500)])
Screen.wrapper(effects_demo)


