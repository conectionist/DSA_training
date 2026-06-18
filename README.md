# DSA Practice Project

This project is designed for practicing data structures and algorithms in a simple, low-friction way.

## Goal

- Keep the implementation logic in the `training` folders.
- Keep the correct/reference code in the `solutions` folders.
- Use one small entry point (`main.cpp`) to run the practice examples.
- Let the trainee uncomment only the section they want to test.

## Folder layout

- `main.cpp`  
  The single entry point for the project.

- `graphs/`  
  Graph-related practice files.
  - `graph_tests.h` contains reusable helpers and test data.
  - `graph_examples.h` contains runnable graph examples.
  - `training/` contains the stubbed graph implementations.
  - `solutions/` contains the reference implementations.

- `trees/`  
  A similar structure for future tree exercises.
  - `examples/` contains runnable examples.
  - `training/` is where trainee code goes.
  - `solutions/` contains reference code.

## How to use it

1. Open `main.cpp`.
2. Include the category header you want to practice.
3. Uncomment the example block you want to run.
4. Implement the corresponding method in the training file.
5. Build and run the project.

## Notes

- The solution folders are meant for reference only.
- The trainee should not need to change the main project structure often.
- The idea is to keep the workflow focused on one method at a time.
