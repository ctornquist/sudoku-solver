# Author: Jack Wagner
# Date: 6/1/2020
# Purpose: Animate the Sudoku board as it is solved by the 'solver' module

from cs1lib import *
from random import *
from cell import Cell
from time import *

WINDOW_WIDTH = 600
WINDOW_HEIGHT = 600

shift = 67

original = []
updated = []
count = 0
color = 0


def read_file(in_file):
    global updated, count, original
    file = open(in_file, "r")   # Open file of cell changes
    index = 0
    for line in file:
        if index < 80:
            row = line.split(" ")
            for num in row:
                c = Cell(index, num)
                original.append(c)
                index += 1
        else:
            new = line.split(" ")
            c = Cell(new[0], new[1])
            updated.append(c)
            count += 1

    # updated.reverse()


def animate():
    global updated, count, color
    img = load_image("board.jpg")   # Draw background of board
    draw_image(img, 0, 0)

    # Adjust text appearance
    set_font_bold()
    set_font_size(60)

    set_stroke_color(0, 0, 0)

    color = color + 1 / (count)
    set_stroke_color(0, 0, color)

    # if len(updated) != 0 and not solved:
    if len(updated) != 0:
        new = updated.pop()
        original[new.number].value = new.value
        original[new.number].change_color(color)

    for i in range(len(original)):  # Loop over all elements in the sudoku board
        horiz = i % 9               # Get horizontal and vertical shifts for ith cell
        vert = i // 9

        # set_stroke_color(0, 0, original[i].b)
        set_stroke_color(0, original[i].g, 0)

        draw_text(str(original[i].value), 18 + (shift - 1) * horiz, 55 + shift * vert)

    # sleep(.05)


read_file("test_file.txt")
start_graphics(animate, width=WINDOW_WIDTH, height=WINDOW_HEIGHT, title="Sudoku!")

# 1 2 4 3 6 7 9 8 5
# 5 6 7 1 8 9 2 3 4
# 8 9 3 2 4 5 1 6 7
# 2 3 5 4 9 6 7 1 8
# 7 1 9 5 2 8 3 4 6
# 6 4 8 7 1 3 5 9 2
# 9 8 1 6 7 2 4 5 3
# 3 7 6 9 5 4 8 2 1
# 4 5 2 8 3 1 6 7 9

