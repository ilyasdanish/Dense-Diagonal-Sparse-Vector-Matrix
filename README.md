# Dense-Diagonal-Sparse-Vector-Matrix
Create four C++ classes. Dense vector , Dense matrix, Diagonal matrix, Sparse matrix (two versions)

These should be
simple implementations.
• Dense vector
• Dense matrix
• Diagonal matrix
• Sparse matrix (two versions)
Each class should have the following:
• Constructor, destructor, copy functions
• Keep a count of the call to each
• Have a debug to print out that the function was called
• Set an element function
• Get an element function
• Zero or one all elements function
• Set all elements to random, positive values function
• For matrices, a symmetric, positive definite (SPD) option
• Print object function
• Whatever else you believe is necessary
We can create a symmetric, positive definite matrix A=U^T+D+U, where
• U is a random strictly upper triangular matrix.
• Dii=-sum(Ai∗).

Dense matrices:
• Constructor(s) should assume either N×N or N×M.
• Use a standard (naive) C++ declaration
o double A[N][M];
Diagonal matrices:
• Constructor(s) should assume N×N with M nonzero diagonals.
• Use a standard (naive) C++ declaration
o double A[N][M];
o Int Offsets[M];
§ 0 is the main diagonal, lower ones are negative,
upper ones are positive.
• A symmetric matrix may not be possible unless the diagonal offsets are
symmetric.
Sparse matrices:
Constructor(s) should assume either N×N or N×M.
• Use 3 vectors to store the matrix:
o double A[nz];
o int IA[N+1], JA[nz];
• nz is the number of non zeros in A.
• IA[i] is an integer where row i begins in A.
• IA[N+1]=nz+1;
An alternative implementation, which stores the data differently, is
• double ∗A[N];
• int ∗JA[N], LA[N];
• Dynamically allocate each row’s non zeros and column indices.
• LA[i] is the number of non zeroes in row i.
For both storage schemes, the constructor should have the same vector arguments.
