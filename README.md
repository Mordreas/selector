# selector

Simple commandline tool to allow a user to filter or select what to pass on between pipes.

test.txt:
```
line 1
line 2
line 3
```

example:
```
cat test.txt | ./selector
1) line 1
2) line 2
3) line 3

choose which line to pass through: 2
line 2
```

selecting multiple lines comma seperated:
```
cat test.txt | ./selector
1) line 1
2) line 2
3) line 3

choose which line to pass through: 1,3
line 1
line 3
```

selecting multiple lines through a range:
```
cat test.txt | ./selector
1) line 1
2) line 2
3) line 3

choose which line to pass through: 1-2
line 1
line 2
```
