# Knucklebones Game Design
## Class Diagram

This class diagram will be some of the implementations I will use for my Knucklebones program. This is a draft to some ideas that were given to us in class and how they could potentially work and what they could potentially due. **Variables subject to change.**

### Dice Class
- **Attributes**:
  - `sides`: Represents the number of sides of the dice (typically 6).
  - `current_value`: Stores the current rolled value of the dice.
  
- **Methods**:
  - `roll()`: Rolls the die and assigns a random number between 1 and 6.
  - `get_value()`: Returns the current face value of the die.

- **Relationships**:
  - A `Dice` is used by a player to roll during the game.

---

### Player Class
- **Attributes**:
  - `name`: The players name or ID.
  - `score`: The players current score.
  - `dice_set`: A list or array of Dice objects that the player rolls.
  - `player_stats`: Tracks players stats.
  
- **Methods**:
  - `roll_dice()`: Rolls a die for the player and returns its value.
  - `place_die(column, value)`: Places a die with a specific value into the selected column on the players board.
  - `get_score()`: Returns the players current score by summing values and applying multipliers.
  - `update_score(points)`: Updates the players score with new points.

- **Relationships**:
  - A `Player` HAS-A `Dice`
  - A `Player` IS-A participant in the  `Game` 

---

### Board Class
- **Attributes**:
  - `grid`: A 3x3 matrix of the board

- **Methods**:
  - `place_die(place, value)`: Places a die on the board
  - `clear_die(place, value)`: Removes an opponent’s die

- **Relationships**:
  - A `Player` HAS-A `Board`

---

### Game Class
- **Attributes**:
  - `players`: A list of players in the game
  - `current_round`: Tracks the current round
  
- **Methods**:
  - `start_game()`: Sets up the game
  - `end_game()`: Ends the game and gets results
  - `get_winner()`: Compares scores and gets winner

- **Relationships**:
  - The `Game` class HAS-A `Player`

---

### Knucklebones Class
- **Attributes**:
  - `board`: The game board
  
- **Methods**:
  - `start_round()`: Starts a round
  - `end_round()`: Ends the current round and gets final scores
  - `get_winner()`: gets the winner
  
- **Relationships**:
  - `Knucklebones` IS-A `Game`
  - `Knucklebones` HAS-A `Board` and HAS-A `Player`

---

## Keywords Classification

### Necessary:
- `player stats`
- `grid`
- `winner`
- `name`
- `dice`

### Possible:
- `high score`
- `teams`
- `streak`
- `leaderboard`
- `userid`
- `team stats`

### Wishful:
- `chat`
- `messaging`
- `coins`
- `levels`
- `other games`
