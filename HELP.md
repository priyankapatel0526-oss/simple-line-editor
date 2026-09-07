
# Simple Line Editor - Help

## Introduction

This is a simple command-line line editor written in C.

The editor allows the user to insert, delete, display, and search lines of text.

---

## Supported Commands

### 1. Insert a Line - `i`

Adds a new line at a specified line number.

**Example:**

```text
Enter command: i
Enter line number: 1
Enter text: Hello World
```

The new line is inserted at the specified position.

---

### 2. Delete a Line - `d`

Deletes a line from the document.

**Example:**

```text
Enter command: d
Enter line number to delete: 1
```

The selected line is deleted and the lines below it move up.

---

### 3. Display Document - `p`

Displays all current lines with their line numbers.

**Example:**

```text
Enter command: p

----- DOCUMENT -----
1. Hello World
2. This is my line editor
--------------------
```

---

### 4. Search - `f`

Searches for a word or phrase in the document and displays the line numbers where it is found.

**Example:**

```text
Enter command: f
Enter word or phrase to search: Hello

Found at line 1: Hello World
```

---

### 5. Count Lines and Words - `c`

Displays the total number of lines and words in the document.

**Example:**

```text
Enter command: c

----- STATISTICS -----
Number of lines : 2
Number of words : 6
----------------------
```

---

### 6. Help - `h`

Displays the list of available commands.

**Example:**

```text
Enter command: h
```

---

### 7. Quit - `q`

Exits the line editor.

**Example:**

```text
Enter command: q

Exiting line editor...
```

---

## Command Summary

| Command | Function              |
| ------- | --------------------- |
| `i`     | Insert a line         |
| `d`     | Delete a line         |
| `p`     | Display document      |
| `f`     | Search for text       |
| `c`     | Count lines and words |
| `h`     | Display help          |
| `q`     | Quit editor           |

## Notes

* Line numbers start from `1`.
* A maximum of 100 lines can be stored.
* Each line can contain up to 199 characters.
* The editor runs in the terminal.
* Commands can be entered using either uppercase or lowercase letters.
