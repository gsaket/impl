head -n2  *.cpp >log
grep -B1  "include" <log | grep = >todo
