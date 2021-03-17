from collections import Counter
import sys
ecology = Counter(sys.stdin.read().split('\n')[:-1])
total_tree = sum(list(ecology.values()))
for tree in sorted(list(ecology.keys())):
    print(tree,'%.4f'%(ecology[tree]/total_tree*100))