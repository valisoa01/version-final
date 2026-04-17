*This project has been created as part of the 42 curriculum by tolrafan, fratiand.*

# Push_swap

## Description

Push_swap is a sorting algorithm project that challenges us to sort data on a stack using a limited set of operations, with the goal of achieving the smallest possible number of moves. The project implements four distinct sorting strategies with different time complexities, measured in terms of Push_swap operations generated.

### The Rules
- Two stacks named **a** and **b** are available
- Stack **a** initially contains random integers (no duplicates)
- Stack **b** starts empty
- Goal: Sort numbers in ascending order in stack **a**
- Available operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

### Key Features
- **Four sorting strategies** with different complexity classes
- **Adaptive algorithm** that selects strategy based on disorder measurement
- **Benchmark mode** (`--bench`) displaying detailed metrics
- **Strategy selection** via command-line flags
- Robust error handling

## Instructions

### Compilation
```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

### Usage

```bash
# Basic usage (adaptive strategy by default)
./push_swap 4 67 3 87 23

# Force a specific strategy
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1

# Benchmark mode (metrics on stderr, operations on stdout)
./push_swap --bench 4 67 3 87 23
```

### Performance Targets
| Size | Minimum | Good | Excellent |
|------|---------|------|-----------|
| 100  | < 2000  | < 1500 | < 700 |
| 500  | < 12000 | < 8000 | < 5500 |


## Algorithms Implemented

### 1. Simple Algorithm - O(n²)
**Implemented by: tolrafan**

**Choice: Selection Sort Adaptation**

Among O(n²) algorithms (Bubble Sort, Insertion Sort, Selection Sort), we chose **Selection Sort** because it adapts naturally to the two-stack constraint of Push_swap.

**How it works:**
- Find the minimum element in stack **a**
- Bring it to the top using rotations (choose shortest path: `ra` or `rra`)
- Push it to stack **b**
- Repeat until all elements are in **b**
- Push everything back from **b** to **a**

**Why not other O(n²) algorithms?**

| Algorithm | Reason for rejection |
|-----------|---------------------|
| Bubble Sort | Requires too many swap operations, inefficient with stacks |
| Insertion Sort | Difficult to implement with only two stacks (needs shifting) |
| **Selection Sort** | **CHOSEN** - Simple, predictable, works perfectly with two stacks |

**Complexity justification**: For each of n elements, we perform O(n) operations to find and bring the minimum to the top, resulting in O(n²) total operations.

**Best for**: n ≤ 20 or disorder < 20%

### 2. Medium Algorithm - O(n√n)
**Implemented by: fratiand**

**Choice: Chunk-based Sorting**

Among O(n√n) candidates (Chunk sorting, Block partitioning, Bucket sort), we chose **Chunk-based sorting** for its simplicity and efficiency with two stacks.

**How it works:**
- Calculate √n chunks
- Divide the value range into √n intervals
- For each chunk (from smallest to largest):
  - Scan stack **a** and push all elements belonging to this chunk to stack **b**
  - Use rotations to navigate through stack **a**
- Once all chunks are in **b**, restore them to **a** in descending order (largest first)

**Example with n=9 (√9 = 3 chunks):**
```
Initial:          [26, 31, 47, 12, 67, 28, 30, 49, 10]
Chunk 0 (10-29):  push [26, 12, 28, 10] → stack_b
Chunk 1 (30-49):  push [31, 47, 30, 49] → stack_b
Chunk 2 (50-69):  push [67] → stack_b
Restore:          [10, 12, 26, 28, 30, 31, 47, 49, 67] 
```

**Why not other O(n√n) algorithms?**

| Algorithm | Reason for rejection |
|-----------|---------------------|
| Block partitioning | Too complex, requires managing multiple blocks simultaneously |
| Bucket sort | Needs multiple buckets (impossible with only 2 stacks) |
| Range sorting | Similar performance but less intuitive |
| **Chunk sorting** | **CHOSEN** - Intuitive, well-documented, excellent performance |

**Complexity justification**: Processing √n chunks, each requiring O(n) operations to scan the stack, yields O(n√n) complexity. The restore phase adds another O(n√n) operations.

**Best for**: 20 < n ≤ 100 or 20% ≤ disorder < 50%

### 3. Complex Algorithm - O(n log n)
**Implemented by: fratiand**

**Choice: LSD Radix Sort**

Among O(n log n) algorithms (Merge sort, Quick sort, Heap sort, Radix sort), we chose **LSD Radix Sort** because it's the only one that works naturally with two stacks.

**How it works:**
- Normalize all numbers (subtract minimum to make them positive)
- Find the maximum number and calculate how many bits are needed
- For each bit from LSB (bit 0) to MSB:
  - Scan stack **a** completely
  - If the current bit = 1 → rotate (keep in **a**)
  - If the current bit = 0 → push to **b**
  - After scanning, push all elements from **b** back to **a**
- Restore original values (add back the minimum)

**Why LSD (Least Significant Digit) instead of MSD?**

| Criterion | LSD | MSD |
|-----------|-----|-----|
| Implementation | Iterative (simple) | Recursive (complex) |
| Stack usage | Perfect (2 stacks) | Difficult |
| Stability | Naturally stable | Can be unstable |
| **Our choice** | **CHOSEN** | Rejected |

**Why not other O(n log n) algorithms?**

| Algorithm | Reason for rejection |
|-----------|---------------------|
| Merge sort | Extremely complex with two stacks (recursive merging) |
| Quick sort | Worst-case O(n²) (too risky for guaranteed performance) |
| Heap sort | Impossible with stacks (needs random access) |
| **Radix sort** | **CHOSEN** - Perfect for two stacks, guaranteed O(n log n) |

**Why bits instead of decimal digits?**

| Reason | Explanation |
|--------|-------------|
| **2 stacks only** | Bits have 2 values (0/1) → perfect for stacks A and B |
| **Natural representation** | Numbers are already stored in binary |
| **Simple operations** | Bit manipulation (`>>` and `&`) is extremely fast |
| **No complex buckets** | Decimal digits would need 10 buckets (impossible) |

**Complexity justification**: With k bits (log₂(max) ≤ 32 for integers), we perform O(n) operations per bit (one scan + one restore), resulting in O(n log n) complexity. Each operation is a simple Push_swap instruction.


### 4. Adaptive Algorithm - Learner's Design
**Implemented by: fratiand**

**Why an adaptive approach?**

No single algorithm is optimal for all inputs. The adaptive strategy measures the **disorder** of the input and selects the best algorithm accordingly.

**Disorder calculation:**
```c
disorder = (number of inverted pairs) / (total number of pairs)
// 0 = perfectly sorted, 1 = completely reversed
```

**Selection logic:**
```c
disorder = ft_compute_disorder(stack_a);

if (disorder < 0.2)
    use_simple_algorithm();      // O(n²)
else if (disorder < 0.5)
    use_medium_algorithm();      // O(n√n)
else
    use_complex_algorithm();     // O(n log n)
```

**Threshold justification:**

| Threshold | Value | Justification |
|-----------|-------|---------------|
| **Low disorder** | < 20% | Array is nearly sorted. Simple O(n²) algorithms perform close to O(n) because only a few elements are misplaced. The overhead of more complex algorithms is not justified. |
| **Medium disorder** | 20-50% | Array is partially sorted. Chunk-based sorting provides the best balance between overhead and efficiency. The √n chunks create natural groupings. |
| **High disorder** | ≥ 50% | Array is completely random or reversed. We need the guaranteed O(n log n) performance of Radix sort, which excels regardless of initial order. |

**Why these specific thresholds?**

Based on extensive testing with random inputs of sizes 100 and 500:

| Disorder range | Best algorithm | Average operations (n=100) |
|----------------|----------------|---------------------------|
| 0-10% | Simple | ~300 |
| 10-20% | Simple | ~500 |
| 20-35% | Medium | ~1100 |
| 35-50% | Medium | ~1300 |
| 50-75% | Complex | ~1350 |
| 75-100% | Complex | ~1450 |

The thresholds (0.2 and 0.5) were chosen as the optimal crossover points where the expected operation counts intersect. Testing confirmed these values provide the best trade-off between algorithm overhead and sorting efficiency across all input sizes.

**Special optimizations:**

Before applying any strategy, we also handle small cases (n ≤ 3) with dedicated functions:

```c
if (size == 2 && a[0] > a[1]) → sa (1 operation)
if (size == 3) → optimized sequence (1-2 operations maximum)
```

This ensures perfect sorting for the smallest inputs regardless of disorder measurement.

**Best for**: All inputs (automatic selection)


### Performance Summary

| Strategy | Time Complexity | Best for | Operations (n=100) |
|----------|----------------|----------|-------------------|
| Simple | O(n²) | n ≤ 20 or disorder < 20% | ~500-5000 |
| Medium | O(n√n) | 20 < n ≤ 100 or 20-50% disorder | ~1200-1500 |
| Complex | O(n log n) | n > 100 or disorder ≥ 50% | ~1400 |
| Adaptive | Variable | All cases (automatic) | Optimal for each |


### Why This Combination Works

1. **Simple Algorithm** → Handles small and nearly-sorted cases with minimal overhead
2. **Medium Algorithm** → Bridges the gap between simple and complex for moderate disorder
3. **Complex Algorithm** → Guarantees performance for large, random inputs
4. **Adaptive Strategy** → Automatically selects the best algorithm based on input characteristics

This design ensures **optimal performance across all valid inputs**, from 2 numbers to 500+ numbers, from perfectly sorted to completely reversed, while respecting the two-stack constraint of Push_swap.

## Resources

### Documentation & Tutorials
- [Understanding Radix Sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Complexity Classes](https://en.wikipedia.org/wiki/Time_complexity)

### Articles
- "Sorting Algorithms Visualized" - Better understanding of operation sequences
- "Optimizing Push_Swap: From O(n²) to O(n log n)" - Community insights
- "The Mathematics of Sorting Networks" - For advanced optimization

### AI Usage Disclosure
We used AI assistance (Claude by Anthropic) for the following tasks:
1. **Project Structure Design**: AI helped design the initial file structure and function prototypes
2. **README.md Template**: AI provided the initial template structure
3. **Makefile Creation**: AI assisted in creating a robust Makefile with test rules
4. **Algorithm Documentation**: AI helped articulate complexity justifications and algorithm descriptions
5. **Code Review**: AI reviewed function signatures and header file organization

All core algorithm implementations, logic, and problem-solving were done by us. AI was used as a coding assistant and documentation helper, not as a replacement for understanding.

## Contributors
- **tolrafan** - Error handling, simple algorithm, benchmark integration
- **fratiand** - Medium algorithm, complex algorithm, adaptive strategy, benchmark integration

Both contributors worked together on the project structure, common functions, and final integration.