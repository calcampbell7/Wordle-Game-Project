# Wordle Game

A terminal-based Wordle game written in C. Guess the randomly selected six-letter word in six attempts or fewer.

## Prerequisites

Before building the game, make sure you have:

- A C compiler such as GCC
- The `make` build tool

## Setup

1. Clone the repository.
2. Open a terminal in the root directory of the project.
3. Build the executable:

   ```sh
   make
   ```

4. Start the game:

   ```sh
   ./wordgame
   ```

## How to Play

Enter a six-letter word for each guess. The game displays every letter with a colour-coded background:

- **Green** — the letter is in the word and in the correct position.
- **Yellow** — the letter is in the word but in the wrong position.
- **Grey** — the letter is not in the word.

You have six guesses. Good luck!
