# Infix Postfix Reasoning

## Table

| Symbol    | Precedence | Associativity |
| --------- | ---------- | ------------- |
| +, -      | 1          | L to R        |
| *, /      | 2          | L to R        |
| ^         | 3          | R to L        |
| - {Unary} | 4          | R to L        |
| ()        | 5          | L to R        |

### Notes

- With equal precedences, associativity can sometimes be from R to L.
- For e.g: a=b=c=5 -> (a=(b=(c=5)))
- Similarly, a^b^c -> (a^(b^c)) -> a^[bc^] -> abc^^ {postfix}
- Some Unary Operators include (deferencing (*), factorial (!), negation(-))
  - int *ptr; Infix(*ptr), Postfix(ptr*)
  - int n!; Infix(!n), Postfix(n!)
  - int log n; Infix(log n), Postfix(n log)
- All of the above unary operators are being evaluated from L to R
- -a+b*log n! -> Postfix -> ...[n!] -> (a-)+b*(n!log) -> [a-]+(bn!log) -> a-bn!log*+
