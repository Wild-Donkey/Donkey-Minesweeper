# Donkey Minesweeper

> A small tool with Windows Minesweeper game

## Background

As a high school student learning Olympics Informatic. Sometimes we have to use Windows 7 computers at school. 

The idea of this project is from [Buffet](https://github.com/Buffett123). She made a application to help her to play this game.

But she failed to calculate the possibilities of each blocks to have a mine there. So I helped her to figure out this problem and start this project.

## How to use

If you can compile c++ codes, just download the `Main.cpp` and compile it. Or you can download the `Main.exe` and run it on Windows.

First, chose a region of the situation, the rows and colums shouldn't over `100`.

At the first line, you should input number of the rows and colums, then input the number of mines that you don't know.

From the second line to the end, input the situation of the blocks.

Each character describes the situation of a block.

If you don't know what's in the block, use `?`;

If you're sure there is a mine in the block, use `@`;

If you have explored the block, use a digit from `0` to `8` that is the numbers of the mines around it.

Then, the program will output all of the possible situations. In the output, `@` means mine, and ` ` means there's noting.

At the last of the output, is the possibilities of each blocks to have a mine.

## Attention

If the numbers of the `?` is to much (over `20` or more), it takes much time for the program to work.

Maybe I will add a function to let you know how many times left.