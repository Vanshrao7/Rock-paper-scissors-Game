# Rock Paper Scissors

A rock paper scissors game in C++. I'm building it to learn the language properly.

Right now it just plays randomly, which is the boring part. The point of the project is what
comes after: the computer starts recording what I play, notices my patterns, and uses them
against me. People are bad at being random — we avoid repeating the same move, we switch too
much after losing — so once it's tracking that, it should beat me well over a third of the
time.

After that I want to build a second version that works the opposite way: instead of hunting
for my patterns, it plays in a way that can't be exploited at all. Then run the two against
each other and see what happens.

## Running it

```
g++ -std=c++17 -Wall main.cpp -o main
./main
```

Type `r`, `p` or `s` to play. `q` to quit.

## Where it's at

- [x] One round, computer always plays rock
- [x] Loops until you quit, keeps score
- [ ] Computer picks randomly — *written, but it plays the same sequence every run, so the seeding needs fixing*
- [ ] Remembers what I've played
- [ ] Predicts my next move and counters it
- [ ] A version that can't be exploited
- [ ] Run the two versions against each other
- [ ] Webcam input, so I can play with my actual hand

For the webcam version the computer picks its move *before* it looks at my hand. Looking
first would let it win every time, which isn't the point.

## Why I'm doing it this way

I've tried learning programming in big sittings before and I forget it almost immediately,
even with practice problems. So instead I'm building one project that keeps getting harder,
and picking up each new piece of C++ only when the project actually needs it.
