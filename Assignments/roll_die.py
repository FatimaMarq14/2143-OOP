import random
from PIL import Image

def roll_die():
    # List of dice images
    dice_images = ["diceRoll/1.png", "diceRoll/2.png", "diceRoll/3.png", 
               "diceRoll/4.png", "diceRoll/5.png", "diceRoll/6.png"]
    
    # Choose a random image
    chosen_image = random.choice(dice_images)
    
    print(f"You rolled: {chosen_image}")
    
    # Display the chosen image
    with Image.open(chosen_image) as img:
        img.show()

# Roll the die
roll_die()
