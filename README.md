# Slot-Machine
This project is a minimal slot machine game written in C. You enter "yes" to play. Each spin generates three random symbols. Match symbols to win tokens:
- **Three matching symbols**: Jackpot! Win 200T
- **Two matching symbols**: Win 50T
- **No match**: Lose your bet

There is no strategy, just gamble and have fun!

## How to Build and Run
```bash
make
./slot_machine
```

## Game Rules
- Starting balance: 100 tokens
- Cost per spin: 20 tokens
- Game ends when you run out of tokens or choose to quit
