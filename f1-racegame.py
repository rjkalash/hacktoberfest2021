import pygame
import time
import random
import os

pygame.init()

screen_width = 400
screen_height = 600

btn_starting_x = 75
nw_gm_y = 400
exit_y = 460
btn_width = 242
btn_height = 50

black_color = (0, 0, 0)
white_color = (255, 255, 255)
red_color = (255, 0, 0)
redLight_color = (255, 21, 21)
gray_color = (112, 128, 144)
green_color = (0, 255, 0)
greenLight_color = (51, 255, 51)
blue_color = (0, 0, 255)

game_layout_display= pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption('F1 Race Road Game')
time_clock=pygame.time.Clock()

car_photo = pygame.image.load(os.getcwd() + '\\images/car.png')
left_c = pygame.image.load(os.getcwd() + '\\images/car_left.png')
right_c = pygame.image.load(os.getcwd() + '\\images/car_right.png')
photo_obstacle = pygame.image.load(os.getcwd() + '\\images/obstacle.png')
texture_photo = pygame.image.load(os.getcwd() + '\\images/texture.png')
(c_width, c_height) = car_photo.get_rect().size
(c_left_width, c_left_height) = left_c.get_rect().size
(c_right_width, c_right_height) = right_c.get_rect().size
(t_width, t_height) = photo_obstacle.get_rect().size
(txtwidth, txtheight) = texture_photo.get_rect().size

icon = pygame.image.load(os.getcwd() + '\\images/logo.png')
pygame.display.set_icon(icon)

image_background = pygame.image.load(os.getcwd() + '\\images/background.png')
image_background_still = pygame.image.load(os.getcwd() + '\\images/background_inv.png')
bckgrndRect = image_background.get_rect()

welcome_1 = pygame.mixer.Sound(os.getcwd() + '\\audio/intro1.wav')
welcome_2 = pygame.mixer.Sound(os.getcwd() + '\\audio/intro2.wav')
audio_crash = pygame.mixer.Sound(os.getcwd() + '\\audio/car_crash.wav')
audio_ignition = pygame.mixer.Sound(os.getcwd() + '\\audio/ignition.wav')
pygame.mixer.music.load(os.getcwd()+'\\audio/running.wav')

def things_dodged(counting, highest_score, everything_speed):
fnt = pygame.font.SysFont(None, 25)
score = fnt.render("Dodged: " + str(counting), True, green_color)
h_score = fnt.render("High Score: " + str(highest_score), True, green_color)
speed = fnt.render("Speed: " + str(everything_speed) + "Km/h", True, green_color)
game_layout_display.blit(score, (10, 0))
game_layout_display.blit(h_score, (10, 27))
game_layout_display.blit(speed, (screen_width - 125, 0))

def high_score_update(dodged):
high_scores = open(os.getcwd()+'\\textfile/high_score.txt', 'w')
temperd = str(dodged)
high_scores.write(temperd)

def things(th_x, th_y):
game_layout_display.blit(photo_obstacle, (th_x, th_y))

def car(x, y, direction):
if direction==0:
game_layout_display.blit(car_photo, (x, y))
if direction==-1:
game_layout_display.blit(left_c, (x, y))
if direction==1:
game_layout_display.blit(right_c, (x, y))

def text_objects(text, font, color):
txtSurf = font.render(text, True, color)
return txtSurf, txtSurf.get_rect()

def message_display_screen(txt, sh_x, sh_y, color, time_sleeping):
lar_txt = pygame.font.Font('freesansbold.ttf',50)
txtSurf, TxtRect = text_objects(txt, lar_txt, color)
TxtRect.center = ((screen_width / 2 - sh_x), (screen_height / 2 - sh_y))
game_layout_display.blit(txtSurf, TxtRect)
pygame.display.update()
time.sleep(time_sleeping)

def title_message_display(sh_x, sh_y, color):
lar_txt = pygame.font.Font('freesansbold.ttf',60)
txtSurf, TxtRect = text_objects("F1 Race Road Game", lar_txt, color)
TxtRect.center = ((screen_width / 2 - sh_x), (screen_height / 3 - sh_y))
game_layout_display.blit(txtSurf, TxtRect)
time.sleep(0.15)
pygame.display.update()

def title_msg():
animation_height=screen_height
pygame.mixer.Sound.play(welcome_1)
while animation_height &gt; -600:
game_layout_display.fill(white_color)
things(screen_width / 2 - t_width / 2, animation_height)
animation_height-=1.5
pygame.display.update()
title_message_display(0, 0, black_color)
time.sleep(0.1)
pygame.mixer.Sound.play(welcome_2)

def motion_texture(th_starting):
game_layout_display.blit(texture_photo, (0, th_starting - 400))
game_layout_display.blit(texture_photo, (0, th_starting))
game_layout_display.blit(texture_photo, (0, th_starting + 400))

def crash_function():
pygame.mixer.music.stop()
pygame.mixer.Sound.play(audio_crash)
message_display_screen("YOU CRASHED", 0, 0, red_color, 0)
while True:
playAgain = button("Play Again", btn_starting_x, nw_gm_y, btn_width, btn_height, greenLight_color, green_color)
exit_game = button("Quit", btn_starting_x, exit_y, btn_width, btn_height, redLight_color, red_color)
for event in pygame.event.get():
if event.type == pygame.QUIT or exit_game == 1 or (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE):
pygame.quit()
quit()
if playAgain== 1 or (event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE):
looping_gameplay()
pygame.display.update()
time_clock.tick(15)

def button(messages, x, y, wid, hei, in_act_color, act_color, action=None):
mouse = pygame.mouse.get_pos()
click = pygame.mouse.get_pressed()
if x + wid &gt; mouse[0] &gt; x and y+hei &gt; mouse[1] &gt; y:
pygame.draw.rect(game_layout_display, act_color, (x, y, wid, hei))
if click[0] == 1:
return 1
else:
pygame.draw.rect(game_layout_display, in_act_color, (x, y, wid, hei))

small_txt = pygame.font.Font('freesansbold.ttf',20)
TxtSurf, TxtRect = text_objects(messages, small_txt, white_color)
TxtRect.center = ((x + wid / 2), (y + hei / 2))
game_layout_display.blit(TxtSurf, TxtRect)

def welcome_gameplay():
welcome = True
game_layout_display.fill(white_color)
title_msg()
exit_game=0
while welcome:
for event in pygame.event.get():
if event.type == pygame.QUIT or exit_game == 1 or (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE):
pygame.quit()
quit()
playGame = button("New game", btn_starting_x, nw_gm_y, btn_width, btn_height, greenLight_color, green_color)
exit_game = button("Quit", btn_starting_x, exit_y, btn_width, btn_height, redLight_color, red_color)
if event.type == pygame.KEYDOWN:
if event.key == pygame.K_ESCAPE:
exit_game = 1
if playGame or (event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE):
welcome = False

pygame.display.update()
time_clock.tick(15)

def counting_three_two_one():
counting = 3
pygame.mixer.music.pause()
pygame.mixer.Sound.play(audio_ignition)
while counting &gt;= 0:
game_layout_display.blit(image_background, bckgrndRect)
car(screen_width * 0.40, screen_height * 0.6, 0)
if counting == 0:
message_display_screen ("GO!", 0, 0, green_color, 0.75)
pygame.mixer.music.play(-1)
else:
message_display_screen (str(counting), 0, 0, red_color, 0.75)
counting -= 1
time_clock.tick(15)

def gameplay_paused():
pygame.mixer.music.pause()
pause = True
while pause:
for event in pygame.event.get():
if event.type == pygame.QUIT or (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE): ###############or quit_game == 1
pygame.quit()
quit()
message_display_screen("pause", 0, 0, blue_color, 1.5)
if event.type == pygame.KEYDOWN:
if event.key == pygame.K_SPACE:
pygame.mixer.music.unpause()
return
pygame.display.update()
time_clock.tick(15)

def looping_gameplay():
pygame.mixer.music.play(-1)
display = 0
width_x=(screen_width * 0.4)
height_y=(screen_height * 0.6)
ch_x=0

th_st_x = random.randrange(8, screen_width - t_width - 8)
th_st_y = -600
th_speed = 5

tracking_y = 0
tracking_speed = 25

dodg=0
direction = 0

highest_score_txtfile = open(os.getcwd()+'/textfile/high_score.txt','r')
high_score = highest_score_txtfile.read()

gameExit = False
counting_three_two_one()

while not gameExit:
for event in pygame.event.get():
if event.type == pygame.QUIT or (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE):
pygame.quit()
quit()
if event.type == pygame.KEYDOWN:
if event.key == pygame.K_LEFT or event.key == pygame.K_a:
ch_x = -10
direction = -1
if event.key == pygame.K_RIGHT or event.key == pygame.K_d:
ch_x = 10
direction = 1
if event.key == pygame.K_SPACE:
gameplay_paused()
if event.type == pygame.KEYUP:
if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT or event.key == pygame.K_a or event.key == pygame.K_d:
ch_x = 0
direction = 0
width_x+=ch_x
game_layout_display.blit(image_background, bckgrndRect)

motion_texture(th_st_y)
things(th_st_x, th_st_y)
th_st_y += th_speed
car(width_x,height_y,direction)

things_dodged(dodg, high_score, th_speed)
if width_x &gt; screen_width - c_width or width_x &lt; 0:
crash_function()
if th_st_y &gt; screen_height:
th_st_y = 0 - t_height
th_st_x = random.randrange(0, screen_width)
dodg += 1
th_speed += 1
if dodg &gt; int(high_score):
high_score_update(dodg)
if height_y &lt; th_st_y+t_height-15 and width_x &gt; th_st_x-c_width-5 and width_x &lt; th_st_x+t_width-5:
crash_function()

pygame.display.update()
time_clock.tick(60)

welcome_gameplay()
looping_gameplay()
pygame.quit()
quit()
