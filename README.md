# Rock–Paper–Scissors that learns you

A small project with a real algorithm inside it. Two evenings to something that beats you;
six steps to something genuinely interesting.

**Note:** the `PRESERVE` folder in this directory is an earlier plan that was dropped. Ignore it.

**Language:** C++
**Pace:** ~5 hours/week average
**Rule:** only ever think about the current step.

---

## The honest framing

The bot will beat you a lot — but not by outsmarting you. **Humans cannot be random.** People
avoid repeating a move, over-switch after losing, and favour rock when rushed. The bot finds
those leaks.

If you ever played *truly* randomly, it could not beat you at all. Understanding why is the
point of step 5.

---

## The six steps

| # | Step | What it does | Status |
|---|------|--------------|--------|
| 1 | One round | Computer always plays rock. You type a move. It says who won. | ✅ done |
| 2 | A real game | Loops until you quit, keeps score | ✅ done |
| 3 | **A fair opponent** | Computer picks randomly | ⬅ **you are here** |
| 4 | Memory | It records what you played, and how often | |
| 5 | The exploiter | It best-responds to your frequencies — **starts beating you** | |
| 6 | The unexploitable one | Regret matching. Can't be beaten — but doesn't beat you either | |
| 7 | The experiment | Exploiter vs unexploitable, 100,000 rounds. Result surprises most people | |
| 8 | The camera | Play with your actual hand. Webcam instead of keyboard | planned |

Step 5 is the same algorithm used by the poker AIs that beat professionals. On a game small
enough to fit in one file.

---

## Current step — 3. A fair opponent

**Topic:** random numbers.

**Source:** the freeCodeCamp course doesn't cover this properly.

- [studyplan.dev — Random Number Generation](https://www.studyplan.dev/intro-to-programming/randomness) — no ads, clean
- Or the video: [C++ From Scratch: Random Numbers](https://www.youtube.com/watch?v=T-scGi6a8Zw)

Ignore `rand()` if you see it recommended elsewhere. Ignore the article's separate header
file and namespace — you're in one file, just take the three pieces.

**The idea:** modern C++ splits randomness into three parts, and the split is the point.

1. **Seeder** (`std::random_device`) — asks the OS for one unpredictable number, drawn from
   things like mouse movement and sensor timings. Slow, so used once.
2. **Engine** (`std::mt19937`) — takes that seed and produces an endless fast stream. Pure
   arithmetic: same seed in, same sequence out, every single time.
3. **Distribution** (`std::uniform_int_distribution`) — squashes the engine's huge raw numbers
   into your range without favouring any value.

Why three pieces instead of one function: keeping the seed lets you replay the exact same
"random" sequence later. That's how games let you share a generated map with a friend.

**Task:** the computer picks rock, paper or scissors at random each round. Everything else
stays as it is.

**Done when:**
1. ~60 rounds gives roughly a third each of rock / paper / scissors, and
2. running the program twice does **not** give the same sequence.

Condition 2 catches the most common mistake with this topic. Don't skip it.

---

## Step 8 — the camera (decided, not started)

Play with your real hand instead of typing. A webcam sees rock / paper / scissors.

**Decided design:** the bot **commits to its move before looking at the hand.** It picks,
locks it in, *then* reads the camera. No cheating.

(The alternative — look first, then choose — wins 100% of the time. A lab at the University
of Tokyo built exactly that. Interesting, but a different project: reaction speed, not
learning. Not what this is.)

**Why it comes last:**

- The camera is an **input swap**, not a new algorithm. It replaces `cin`. Steps 4–7 don't
  care where the move came from, so nothing needs rewriting.
- Hand detection is its own project — OpenCV in C++ on Windows is a real setup cost, and
  recognising a hand shape reliably is fiddly (lighting breaks skin-colour segmentation;
  counting fingers from contours is flaky). Weeks, not evenings.
- **The real reason:** if the camera misreads you 15% of the time *while* you're trying to
  tell whether the learning algorithm works, you can't separate the two failures. Get the bot
  beating you with typed input first. Then you *know* the bot is correct, and anything odd
  afterwards is the camera.

---

## Done

### 1. One round ✅
`if` / `else if` / `else`. All four branches correct, compiles clean under `-Wall`.
Split the logic into a `play()` function unprompted.
Nit: `cout << ("text")` — the brackets do nothing.

### 2. A real game ✅
`while` loop until `q`, score tracked correctly, invalid input correctly doesn't count.
Used **reference parameters** (`int &u`) to let `play()` update the scores — that's Chapter 9
material, reached three chapters early and used correctly.
Nits: stray `cout;` statement (a warning under `-Wall`); first prompt doesn't mention `q`;
the error message has no newline so it runs into the next prompt.

**Habit worth adopting now:** always compile with `-Wall`. It caught the dead statement here.

---

## Devlog

One line per session: date, what you did, what confused you.

<!-- 2026-08-09 — project chosen after a long search. Step 1 started. -->
