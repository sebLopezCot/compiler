# ZSL Grammar

### Basic Program Structure
- `program -> stmt`
- `stmt -> expr`

### Basic Program Data Types
- `digits -> digits digit`
- `digits -> digit`
- `digit -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9`

### Expressions
- `expr -> expr + term`
- `expr -> expr - term`
- `expr -> term`

### Terms
- `term -> term * factor`
- `term -> term / factor`
- `term -> factor`

### Factors
- `factor -> digits`

