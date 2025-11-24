# Mino - Minimal Text Editor ✨📝

Mino is a **minimal and fast text editor** developed in **C** using the **ncurses** library.
It provides a simple terminal-based editing experience with support for opening, editing, and saving text files effortlessly.

---

## 🚀 Features

* Open and edit text files (`.txt`, `.c`, or any other filename)
* Save files easily 💾
* Smooth navigation across multiple lines, even with long files
* Works in any directory and can be launched globally after installation 🌍

---

## 🏗 Build Instructions

1. Clone or download the repository:

```bash
git clone https://github.com/eyu-447/mino
cd mino
```

2. Compile the project:

```bash
gcc src/*.c -Iinclude -lncurses -o mino
```

---

## 📌 Install Mino Globally

### Option 1: Using `sudo`

```bash
sudo cp mino /usr/local/bin/
sudo chmod +x /usr/local/bin/mino
```

Now you can run Mino from **anywhere**:

```bash
mino test.txt
```
---

## ✍ How to Use

* Open Mino with any existing or new text file:

```bash
mino example.txt
```

* Mino will automatically create the file if it doesn’t exist, defaulting to `.txt` extension.
* Use your usual navigation keys to move across lines and save your work. 💾

---

## 📝 License

Mino is **open-source**. You can use, modify, and distribute it freely. 🌟

---

> Mino is perfect for anyone who wants a **lightweight, fast terminal-based text editor**.
> Make your text editing simple, efficient, and fun! 😄
