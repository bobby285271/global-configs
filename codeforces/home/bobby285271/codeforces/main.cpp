#if 0
proName="${0%.*}"
g++ -std=c++17 -O2 -Wall -lm -o $proName "$0"
./$proName "$@"
rm $proName
exit
#endif

#define _DEBUG
#include "codeforces.cpp"
