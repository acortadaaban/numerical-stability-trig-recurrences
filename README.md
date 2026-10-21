Numerical Stability of Trigonometric Recurrences
Course project for Numerical Methods (UAB, 2024–2025), written in C and developed as a pair project.
What it does
Computes `cos(jx)` and `sin(jx)` for `j = 0, 1, ..., k` with four different algorithms and compares their accuracy and speed:
Function	Method
`trigrec0`	Direct computation with the standard `cos` and `sin` functions
`trigrec1`	Three-term recurrence from the sum formulas: `cos((j+1)x) = 2·cos(x)·cos(jx) − cos((j−1)x)`, and the same for `sin` (algorithm 2.2)
`trigrec2`	Rotation recurrence using the angle-addition formulas, starting from `cos(x)` and `sin(x)` (algorithm 2.3)
`trigrec3`	Improved recurrence (algorithm 2.4): updates small increments instead of full values, which limits rounding errors
Two command-line programs are included:
`trigrec_escr`: prints the values computed by each method.
`trigrec_temps_err`: measures execution time and the maximum error with respect to the direct method.
Build and run
```bash
make
./trigrec_escr k x          # k = number of multiples, x = angle
./trigrec_temps_err k x
```
Main results
Each algorithm improves numerical stability over the previous one, and only the improved recurrence (`trigrec3`) is numerically stable.
Experimental errors are generally larger than the theoretical bounds, which is attributed to the imprecision of floating-point operations.
The recurrences run at roughly 3·10⁸ arithmetic operations per second, which was used to estimate the cost of evaluating `sin` and `cos` directly.
Report
The full write-up of the project, with the software manual, tests and results (in Catalan), is in `docs/Memoria_Recurrencies_Trigonometriques.pdf`.
Authors
Albert Cortada, together with a course partner.
<!-- TODO: add your partner's name and GitHub link here if they agree, then delete this comment. -->
