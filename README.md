# APowBModC
This is my solution for the pow(a, b) % c mathematical problem, implemented in C.
# The problem
> Three integers are given, a, b and c. Calculate `pow(a, b) % c` without calculating `pow(a, b)`. (a and b can be very big so that `pow(a, b)` can easily lead to an integer overflow in the computer.)
# The solution
#### Pseudocode
```
d = 1;
t = a;
x1 = b;
# standart loop for iterating over all binary digits starting from the last ones
while (x1 > 0) {
	if (x1 % 2 == 1) d = (d * t) % c;
	t = (t * t) % c;
	x1 /= 2;
}
# d is the result
```
#### Example
The formula: `pow(175, 235) % 257`
`235 = 11101011`

| # | d                              | t                                |
| - |------------------------------  | ---------------------------------|
| 0 | `d = 1`                        | `t = 175`                        |
| 1 | `d = (1 * 175) % 257 = 175`    | `t = pow(175, 2) % 257 = 42`     |
| 2 | `d = (175 * 42) % 257 = 154`   | `t = pow(42, 2) % 257 = 222`     |
| 3 | No changes, because x1 is even.| `t = pow(222, 2) % 257 = 197`    |
| 4 | `d = (154 * 197) % 257 = 12`   | `t = pow(197, 2) % 257 = 2`      |
| 5 | No changes, because x1 is even.| `t = pow(2, 2) % 257 = 4`        |
| 6 | `d = (12 * 4) % 257 = 48`      | `t = pow(4, 2) % 257 = 16`       |
| 7 | `d = (48 * 16) % 257 = 254`    | `t = pow(16, 2) % 257 = 256`     |
| 8 | `d = (254 * 256) % 253 = 3`    | We don't need to calculate this. |
#### Result: `3`
# Note
If b == c, the result will be `a % b`
