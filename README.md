# Introduction-of-Algorithm
## NCTU Introduction of Algorithm Homework & related code
### HW0 -- PI
- HW 0. pi
- [score board](https://people.cs.nctu.edu.tw/~tdwu402/2018_Algo/HW0/HW0.html)
- [Reference](https://hackmd.io/s/HJvOt-zdQ)
### HW1 -- Bamboo Rat
- HW 1-1 Bamboo Rat I
- HW 1-2 Bamboo Rat II
- HW 1-1 Bamboo Rat III
- [score board](https://people.cs.nctu.edu.tw/~tdwu402/2018_Algo/HW1/HW1.html)
- [Reference](https://hackmd.io/s/HkZdfJb0X)
### HW2 -- DP problem
- HW 2-1 Minimum Maximum Difference Monotonic Paths
- HW 2-2 Longest Palindromic Subsequence
- HW 2-3 Number Of Red-Black Tree
- HW 2-4 Maximum Rectangle
- [score board](https://people.cs.nctu.edu.tw/~tdwu402/2018_Algo/HW2/HW2.html)
- [Analysis](https://hackmd.io/s/BkXyeVdCm)
### HW3 -- Graph
- HW 3-1 Alphabet path II (SCC)
- HW 3-2 Turret Game (Max Flow)
- HW 3-3 Most Valuable Path (Bellman-Ford)
- HW 3-4 Minimum K-th Smallest Edge Spanning Tree (MST)
- [score board](https://people.cs.nctu.edu.tw/~tdwu402/2018_Algo/HW3/HW3.html)
### Quiz0 
- Quiz 0-1 Another Huffman Code
- Quiz 0-2 DF-expression
- Quiz 0-3 Maximum Subarray 2
- Quiz 0-4 Locker Rental
- Quiz 0-5 Counting Tuples 2
- [score board](https://people.cs.nctu.edu.tw/~tdwu402/2018_Algo/Quiz0/Quiz0_rank.html)
### Quiz1
- Quiz 1-1 Rainbow Monotonic Paths
- Quiz 1-2 A 2-Player Game
-	Quiz 1-3 Matrix Multiplications
-	Quiz 1-4 Making a Detour
- [score board](https://people.cs.nctu.edu.tw/~tdwu402/2018_Algo/Quiz1/Quiz1_rank.html)
### HW4 -- NP & LP
- HW 4-0 Exercise LP Dye Factory
- HW 4-1 Hamiltonian path
- HW 4-2 Spanning Binary Tree
- HW 4-3 2-D Fractional Knapsack Problem with Deminishing Returns
- HW 4-4 Guessing Numbers
- [score board](https://people.cs.nctu.edu.tw/~tdwu402/2018_Algo/HW4/HW4.html)

## GLPK reference
1.Login to CS workstations
  - Create an account if you don't have one
  - Questions?
  - You may use an unix-like system instead
  - On Windows, you can either use virtual machine or Linux on Win10 instead (may not work properly)

2.Run the following commands in terminal
```
mkdir glpk
cd glpk/
curl -L people.cs.nctu.edu.tw/~schuang0216/Algo17/HW4/install | bash
```

3.Write your C/C++ codes under current directory
  - Use GLPK directly: ```#include "glpk.h"```
  - Use provided template(C++ only): ```#include "lp_solver.h"```

4.Compile your code with ```./compile filename.cpp```
For example, ```./compile sample.cpp```

5.Run the executable
  - ```./submission.out```

**6.If you don't really need an LP solver in the future, you may ignore the above installation guide.
You could simply modify the following sample code based on the problem definition and submit it to OJ.**
```
#include <iostream>
#include <vector>
#include "lp_solver.h"
using namespace std;

/*
** optimize z = c^T y  (optimize: GLP_MIN or GLP_MAX)
** subject to Ay <= b
** 
** return z
*/

//double lp_solver(int optimize, const vector<double>& c, const vector<vector<double> >& A, vector<double> &y, const vector<double> &b);

int main(){
    
    /*
     * The following code solves the linear program
     * 
     * minimize    7 y1 + 11 y2 + 13 y3
     * subject to  y1 - y3 <= 1
     *             2 y1 + y2 + 3 y3 <= 2
     *
     *
     * i.e. return min{c^T y : Ay <= b}
     */
    
    vector<vector<double> > A;
    A.resize(2);
    for(int i=0; i<2; ++i){
        A[i].resize(3);
    }	
    A[0][0] = 1, A[0][1] = 0, A[0][2] = -1;
    A[1][0] = 2, A[1][1] = 1, A[1][2] = 3;
    
    vector<double> y;
    y.resize(3);
    
    vector<double> b;
    b.resize(2);
    b[0] = 1, b[1] = 2;
    
    vector<double> c;
    c.resize(3);
    c[0] = 7, c[1] = 11, c[2] = 13;
    
    double z = lp_solver(GLP_MAX, c, A, y, b);
    
    cout << "the optimal objective value is " << z << endl;
    cout << "the optimal solution is (";	
    for(int i=0; i<3; ++i){
        cout << y[i] << ((i==2) ? "" : ",");
    }
    cout << ")" << endl;
    return 0;
}
```

- We use the same scripts for installation and compilation on the judge.
  - Please follow the above instructions to prevent errors.

- In the following LP problems, your answer will be considered correct if its absolute or relative error does not exceed \epsilonϵ.
  - Let's assume that your answer is aa and the answer of the judge is bb.
  - The checker program will consider your answer correct iff \frac{|a-b|}{\max(1, \, b)} \leq \epsilon max(1,b)∣a−b∣≤ϵ.

- When making a submission, submit the only file containing main function.
  - You don't have to submit any of the header files.

- To uninstall, simply remove the whole glpk directory.
