# Labaratory Work for Data Structures and Algorithms

Idk why but I have an issue to read data from `coins.data` so I made a copy of it and changed it to `coins.txt`. Still I have an issue that I can not read first value, however, everything else is working properly. `e.what()` shows that the problem is `stoi` but honestly I am tired of trying to solve this issue, and in the end of the day the goal of this task is to show your knowledge of algorithms, so I made a dicision to ignore it.

Result:

```
Selection Sort Benchmark:
Number of Transpositions: 9999
Number of Comparisons: 49985001
Time: 74.543ms

Quick Sort Benchmark:
Number of Transpositions: 91573
Number of Comparisons: 195668
Time: 0.866ms
```

<img src="https://github.com/AndreyPerunov/DSA_Lab_1/blob/main/selection-sort.png" title="Selection Sort" alt="Selection Sort"/><br>
<img src="https://github.com/AndreyPerunov/DSA_Lab_1/blob/main/quick-sort.png" title="Quick Sort" alt="Quick Sort"/>

## Task

1. **In frame of this lab, you are required to:**

   1. Implement a software that reads a data set file (new line separated text file) line by line and upload it to static array of string data type. The data set file is presented in the individual taskChose and implement search algorithm to solve the problem according to individual task.
   1. Implement two sort algorithms according to individual task.
   1. Evaluate the speed of the algorithms on different numbers of elements in the array using time or number of comparisons or number of transpositions.
   1. Prepare the report about the completed tasks.

1. **The report should have the following structure (consider using the report template):**

   1. Title page (use the template provided in TSI LMS)
   1. Individual task
   1. Text description for applied algorithms specific to the task and the problem
   1. Source code
   1. Algorithm's benchmark performance (time in milliseconds, or number of comparisons, or number of transpositions). Include raw data and data visualisation.
   1. Proof of working software (i.e. source code and screen shots available in the report)
   1. Conclusions

1. **After completing the lab, the following files should be uploaded to TSI LMS:**

   1. Application (exe-file)
   1. Report (doc, docx, pdf)
   1. Source file (source.cpp or other)

**Attention!** Please do not zip files

## Individual Task

| Nr  | Data Set   | Sort algorithms                                                            |
| --- | ---------- | -------------------------------------------------------------------------- |
| 2   | Coins list | Sort coins by Market Value: Selection Sort; Quick Sort any other algorithm |
