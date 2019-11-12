# ZSL Grammar

### Basic Program Structure
- `program -> stmt`
- `stmt -> expr`

### Basic Program Data Types
- `digits -> digit digits`
- `digit -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9`
- `digits -> NULL_TERMINAL`

### Factors
- `factor -> digits`

### Expressions
- `expr -> term expr_prime`
- `expr_prime -> add_op expr_prime`
- `expr_prime -> sub_op expr_prime`
- `expr_prime -> NULL_TERMINAL`

### Operations
- `add_op -> +`
- `sub_op -> -`
- `mult_op -> *`
- `div_op -> /`

### Terms
- `term -> factor term_prime`
- `term_prime -> mult_op factor term_prime`
- `term_prime -> div_op factor term_prime`
- `term_prime -> NULL_TERMINAL`


