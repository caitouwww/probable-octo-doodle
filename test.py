import pygame
import random
from pygame.locals import *
from random import randint

SCREEN_WIDTH = 900
SCREEN_HEIGHT = 600
LOW_SPEED = 4
HIGH_SPEED = 10
FONT_COLOR = (00,150,00)
FONT_SIZE = 5
FONT_NOM = 20
FONT_NAME='simsun.ttc'
FREQUENCE = 10
times = 0


def randomspeed():
    return randint(LOW_SPEED, HIGH_SPEED)
def randompositon():
    return randint(0,SCREEN_WIDTH),randint(0,SCREEN_HEIGHT)
def randomname():
    return randint(0,100000)
def randomvalue():
    return randint(0,100)


class Word(pygame.sprite.Sprite):
    def __init__(self,bornposition):
        pygame.sprite.Sprite.__init__(self)
        self.value = randomvalue()
        self.font = pygame.font.Font(FONT_NAME,FONT_SIZE)
        self.image = self.font.render(str(self.value),True,FONT_COLOR)
        self.speed = randomspeed()
        self.rect = self.image.get_rect()
        self.rect.topleft = bornposition


    def update(self):
        self.rect = self.rect.move(0,self.speed)
        if self.rect.top > SCREEN_HEIGHT:
            self.kill()



pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH,SCREEN_HEIGHT))
pygame.display.set_caption("ViatorSun Code Rain")
clock = pygame.time.Clock()
group = pygame.sprite.Group()
group_count = int(SCREEN_WIDTH/FONT_NOM)

while True:
    time = clock.tick(FREQUENCE)
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()

    screen.fill((0,0,0))
    for i in range(0,group_count):
        group.add(Word((i*FONT_NOM,-FONT_NOM)))

    group.update()
    group.draw(screen)
    pygame.display.update()
