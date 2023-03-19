
import configparser
import board
import adafruit_dotstar as dotstar
import time

NUM_PIXELS = int(144 / 2)

dots = dotstar.DotStar(
        board.SCK
        ,board.MOSI
        ,NUM_PIXELS
        ,brightness=0.3
)

def read_config():
        config = configparser.ConfigParser()
        config.read('./lights.ini')
        return (
                config.getint('All', 'R')
                ,config.getint('All', 'G')
                ,config.getint('All', 'B')
                ,config.getfloat('All', 'Brightness')
        )

while True:
        config = read_config()
        dots.fill(config[:3])
        dots.brightness = config[-1]

        time.sleep(0.5)
