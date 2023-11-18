# Structure

```math
\begin{align}
	\text{START} &\rightarrow \text{STMT} \\
	\text{STMT} &\rightarrow \begin{cases}
		\text{STMT'} \\
		\text{STMT' STMT} 
	\end{cases} \\
	\text{STMT'} &\rightarrow \begin{cases}
		\text{\$} \\
		\text{ASMT} \\
		\text{EXPR} \\
		\text{IF\_STMT} \\
		\text{FOR\_LOOP} \\
		\text{WHILE\_LOOP} \\
		\text{PRINT\_STMT}
	\end{cases} \\
\end{align}
```

# Expressions

```math
\begin{align}
	\text{EXPR} &\rightarrow \begin{cases}
		\text{(EXPR)} \\
		\text{UN\_OPER EXPR} \\
		\text{EXPR BIN\_OPER EXPR} \\
		\text{break} \\
		\text{continue} \\
		\text{nil}
	\end{cases}  \\
	\text{UN\_OPER} &\rightarrow
	\begin{cases}
		+, -, \~
	\end{cases} \\
	\text{BIN\_OPER} &\rightarrow
	\begin{cases}
		+, - , *, /, =, >, <, >=, <=, \~=, \%, \^
	\end{cases}
\end{align}
```

# Assignment

```math
\begin{align}
	\text{ASMT} &\rightarrow
	\begin{cases}
		\text{const ASMT} \\
		\text{id := EXPR} \\
		\text{id ( ARGS ) := EXPR}
	\end{cases} \\
	\text{ARGS} &\rightarrow 
	\begin{cases} \\
		\text{id} \\
		\text{id , ARGS}
	\end{cases}
\end{align}
```

# Scope expression

```math
\begin{align}
	\text{EXPR} &\rightarrow \text{\{ STMT \}}
\end{align}
```

# If .. else if .. else

```math
\begin{align}
	\text{IF\_STMT} &\rightarrow 
	\begin{cases}
		\text{EXPR => STMT} \\
		\text{IF\_STMT else STMT} \\
		\text{IF\_STMT else IF\_STMT}
	\end{cases}
\end{align}
```

# For loop

```math
\begin{align}
	\text{FOR\_LOOP} &\rightarrow \text{EXPR for id in id}
\end{align}
```

# While loop

```math
\begin{align}
	\text{WHILE\_LOOP} &\rightarrow \text{EXPR while EXPR}
\end{align}
```

# Builtins

```math
\begin{align}
	\text{PRINT\_STMT} &\rightarrow \text{print EXPR}
\end{align}
```
