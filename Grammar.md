# Structure

```math
\begin{align}
	\text{START} &\rightarrow \text{STMT} \\
	\text{STMT} &\rightarrow \begin{cases}
		\text{EXPR DELTA STMT'} \\
		\text{\epsilon}
	\end{cases} \\

	\text{DELTA} &rightarrow \begin{cases}
		\text{FOR} \\
		\text{WHILE} \\
		\text{IF} \\
		\text{\epsilon}
	\end{cases}
\end{align}
```

# Expressions

```math
\begin{align}
	\text{EXPR} &\rightarrow \begin{cases}
		\text{(EXPR)} \\
		\text{UN\_OPER EXPR} \\
		\text{id EXPR_ID} \\
		\text{lit EXPR_LIT} \\
		\text{break, continue, nil} \\
		\text{\{STMT\}}
	\end{cases}  \\
	
	\text{EXPR_ID} &\rightarrow \begin{cases}
		\text{BIN\_OPER EXPR} \\
		\text{:= EXPR} \\
		\text{=> STMT ELSE_IF ELSE} \\
		\text{(ARGS) EXPR_ID} \\
		\epsilon
	\end{cases} \\

	\text{EXPR_LIT} &\rightarrow \begin{cases}
		\text{BIN\_OPER EXPR} \\
		\text{=> STMT ELSE_IF ELSE} \\
		\epsilon
	\end{cases} \\

	\text{ARGS} &\rightarrow \text{\epsilon}, \text{EXPR ARGS'}
	\text{ARGS'} &\rightarrow \text{, ARGS}

	\text{UN\_OPER} &\rightarrow +, -, \~ \\
	\text{BIN\_OPER} &\rightarrow +, - , *, /, =, >, <, >=, <=, \~=, \%, \^ \\
\end{align}
```

# For loop

```math
\begin{align}
	\text{FOR\_LOOP} &\rightarrow \text{for id in EXPR}
\end{align}
```

# While loop

```math
\begin{align}
	\text{WHILE\_LOOP} &\rightarrow \text{while EXPR}
\end{align}
```

# If..elif..else

```math
\begin{align}
	\text{IF} &\rightarrow \text{=> STMT ELSE\IF} \\
	\text{ELSE\_IF} &\rightarrow \text{elif EXPR => STMT ELSE\_IF}, \epsilon \\
	\text{ELSE} &\rightarrow \text{else STMT}, \epsilon
\end{align}
```

# Builtins

```math
\begin{align}
	\text{PRINT\_STMT} &\rightarrow \text{print EXPR} \\
	\text{INPUT\_STMT} &\rightarrow \text{input} \\
	\text{SET\_FILE} &\rightarrow 
	\begin{cases}
		\text{setfin const::string}, \\
		\text{setfout const::string}, \\
		\text{setfin stdin}, \\
		\text{setfout stdout}
	\end{cases} \\
	\text{CLEAR\_FILE} &\rightarrow \text{clearf}
\end{align}
```
