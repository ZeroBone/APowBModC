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

| # | d                              | t                              |
| - |------------------------------  | -------------------------------|
| 0 | `d = 1`                        | `t = 175`                      |
| 1 | `d = (1 * 175) % 257 = 175`    | `t = (175 ^ 2) % 257 = 42`     |
| 2 | `d = (175 * 42) % 257 = 154`   | `t = (42 ^ 2) % 257 = 222`     |
| 3 | No changes, because x1 is even.| `t = (222 ^ 2) % 257 = 197`    |
| 4 | `d = (154 * 197) % 257 = 12`   | `t = (197 ^ 2) % 257 = 2`      |
| 5 | No changes, because x1 is even.| `t = (2 ^ 2) % 257 = 4`        |
| 6 | `d = (12 * 4) % 257 = 48`      | `t = (4 ^ 2) % 257 = 16`       |
| 7 | `d = (48 * 16) % 257 = 254`    | `t = (16 ^ 2) % 257 = 256`     |
| 8 | `d = (254 * 256) % 253 = 3`    |We don't need to calculate this.|
#### Result: `3`
# Note
If b == c, the answer will be `a % b`
