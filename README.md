# ⚽ FIFA SBC Squad Optimizer

This is a C++ program that finds the **cheapest possible squad** for completing a **Squad Building Challenge (SBC)** in FIFA. It searches for a team of 11 players whose average rating (with a correction factor) meets or exceeds a target value, using user-defined player prices.

---

## 🚀 Features

- Brute-force search through all valid team configurations
- Mimics EA’s SBC rating logic using a correction factor
- Supports fixed player ratings in specific positions
- Fully customizable price table and rating range
- Clear, well-commented code, ideal for learning and extension

---

## 🧠 How It Works

In FIFA, SBC squad rating is **not** calculated as a simple average. Instead, it uses a hidden algorithm that weights higher-rated players more heavily.

This program approximates that behavior by:
- Calculating the **average** player rating
- Adding a **correction factor**: the total amount by which players exceed the average
- Applying `floor((sum + correction) / 11)` to approximate SBC value

It searches for the cheapest team whose adjusted rating meets the goal.

---

## ⚙ Configuration

All customization is done in `main.cpp`.

---

### 💰 Set Player Prices

You can define the market price for each player rating:

```cpp
prices[81] = 750;
prices[82] = 1000;
prices[83] = 1200;
// ...

## 🙋‍♂️ Contribute

Pull requests are welcome! You can help by:

- Improving performance (e.g., recursive search)
- Adding chemistry or position constraints
- Creating a JSON input parser
- Adding a GUI or web version
