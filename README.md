
# Simple Line Editor in C

## Team Members

>Punya R Kandagal
>Priyanka KV
>Nivedita Hallad

## About the Project

This project is a simple command-line line editor developed in C.

The editor works with one line at a time and allows the user to insert, delete, display, and search lines of text.

## Features

### Core Features

* Insert a line at a specified line number
* Delete a line
* Display the complete document with line numbers

### Bonus Features

* Search for a word or phrase
* Count the total number of lines
* Count the total number of words
* Display help for available commands

## Data Structure

The program uses a **2D character array (array of strings)** to store the document.

```c
char document[100][200];
```

* Maximum number of lines: 100
* Maximum length of each line: 199 characters

An integer variable is used to keep track of the current number of lines:

```c
int lineCount = 0;
```

### Why this data structure?

A 2D character array is simple to understand and easy to implement for a small line editor.

When inserting a line, existing lines are shifted down.

When deleting a line, the lines below it are shifted up.

## Commands

| Command | Function              |
| ------- | --------------------- |
| `i`     | Insert a line         |
| `d`     | Delete a line         |
| `p`     | Display document      |
| `f`     | Search for text       |
| `c`     | Count lines and words |
| `h`     | Display help          |
| `q`     | Quit the editor       |

Both uppercase and lowercase commands are supported.

## How to Compile

Open the terminal in VS Code and run:

```bash
gcc editor.c -o editor
```

## How to Run

### Windows

```bash
.\editor.exe
```

### Linux / macOS

```bash
./editor
```

## Example

```text
==============================
       SIMPLE LINE EDITOR
==============================
Type 'h' for help.

Enter command: i
Enter line number (1 to 1): 1
Enter text: Hello World
Line inserted successfully.

Enter command: i
Enter line number (1 to 2): 2
Enter text: This is my line editor
Line inserted successfully.

Enter command: p

----- DOCUMENT -----
1. Hello World
2. This is my line editor
--------------------
```

## Error Handling

The program handles:

* Invalid line numbers
* Deleting from an empty document
* Inserting when the document is full
* Empty search text
* Invalid commands

## Files in the Project

```text
line-editor/
│
├── editor.c
├── HELP.md
└── README.md
```

## Project Requirements

The project is designed to run completely in the terminal using the C programming language and GCC compiler.

