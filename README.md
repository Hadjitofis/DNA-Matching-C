# DNA Matching — Longest Common Subsequence in C

This project implements a C program that reads two DNA sequences from text files and identifies the longest shared substring between them — a practical problem inspired by bioinformatics and genetic analysis.

---

## 🚀 Features

✅ Reads two DNA input files (containing A, G, T, C bases)  
✅ Filters out invalid characters (non-DNA bases)  
✅ Finds the longest common continuous substring  
✅ Handles large input sequences efficiently  
✅ Prints the matching sequence to standard output

---

## 🏗 How to Build

Compile the program with:
```bash
gcc -Ofast -m32 -Wall -Wextra -Werror -pedantic -o dna dna.c -lm
```
🏃 How to Run
Basic usage:
```bash
./dna file1.dna file2.dna
```
Example:
```bash
./dna human.dna chimp.dna
```
If the two files are identical, the program outputs the full sequence. If no shared subsequence exists, it outputs nothing.
## 📊 Technical Details
  -  Only considers valid DNA bases: A, G, T, C

  -  Uses dynamic memory allocation to handle sequences of arbitrary size

  -  Uses a brute-force longest common substring search (can be optimized further)
## 🌍 Why This Matters
DNA sequence comparison is a cornerstone of bioinformatics, used for:

  -  Genetic similarity analysis between organisms

  -  Ancestry and evolutionary studies

  -  Medical research on gene sequences

This project demonstrates applying string algorithms and file handling in C to a real-world scientific problem.
## 💡 Future Ideas
  -  Optimize to use dynamic programming for faster substring search

  -  Add support for longest common subsequence (non-contiguous)

  -  Visualize DNA matches using a web or graphical interface
# 🛠 Author
Andreas Hadjitofis

Computer Science Student @ National and Kapodistrian University of Athens


