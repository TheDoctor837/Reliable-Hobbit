##################################################
#
#   Ian McNulty
#   09/11/18
#   Number Generator
#   Random number guessing game
#
##################################################
import random # For random number module

# The game itself
def guessing_game():

# Gives random number
    x = random.randrange(1, 201)

# Game loop
    while True:

# The question
        guess = int(input("What number am I thinking of? (between 1 and 200) "))

# Conditions for responses
    # Too high
        if int(guess) > int(x):
            print("Too high!")
            continue

    # Too low
        elif int(guess) < int(x):
            print("Too low!")
            continue

    # Correct answer
        elif int(guess) == int(x):
            print("\nCongratulations, thats the number!")
            break

    # In case of other answer
        else:
            continue

# Asking the player if they would like to play again
    another_game = str(input("Would you like to play again? \nY for another game, N for no. "))

# Conditionals on 2nd answer

    # Yes answer, restarts function
    if another_game == "y" or another_game == "Y":
        print("\nHere you go!")
        guessing_game()

    # No answer, ends function/program
    else:
        print("\nAlright!")

# Farewell
    print("\nHave a nice day!")

# Starts game
guessing_game()
