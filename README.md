# APowBModC
This is my solution for the a ^ b % c mathematical problem, implemented in C.
# The problem
> Three 4-byte integers are given, a, b and c. Calculate `(a ^ b) % c` without calculating `a ^ b`, bacause it can and probably will lead to an integer overflow.
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
The formula: `(175 ^ 235) % 257`
`235 = 11101011`

| # | d                     | t     |
| - |-----------------------| ------|
| 1 | `d = 175 % 257 = 175` | `t = (175 ^ 2)` |
# Note
If b == c, the answer will be `a % b`
