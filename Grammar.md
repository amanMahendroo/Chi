# Structure

```math
\begin{align}
	\text{START} &\rightarrow \text{STMT} \\
	\text{STMT} &\rightarrow \begin{cases}
		\text{STMT'} \\
		\text{STMT' STMT} \\
		\text{\{ STMT \}}
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
		\text{id, const} \\
		\text{(EXPR)} \\
		\text{UN\_OPER EXPR} \\
		\text{EXPR BIN\_OPER EXPR} \\
		\text{id EXPR'} \\
		\text{const EXPR'} \\
		\text{INPUT_STMT} \\
		\text{break} \\
		\text{continue} \\
		\text{nil}
	\end{cases}  \\
	\text{EXPR'} &\rightarrow \text{BIN\_OPER EXPR EXPR', \epsilon}
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
	\begin{cases} 
		\text{id} \\
		\text{id , ARGS}
	\end{cases}
\end{align}
```

# If .. else if .. else

```math
\begin{align}
	\text{IF\_STMT} &\rightarrow 
	\begin{cases}
		\text{IF} &\rightarrow \text{EXPR => STMT ELSE\_IF ELSE} \\
		\text{ELSE\_IF} &\rightarrow \text{else EXPR => STMT ELSE\_IF, \epsilon} \\
		\text{ELSE} &\rightarrow \text{else STMT, \epsilon}
	\end{cases} \\
\end{align}
```

# For loop

```math
\begin{align}
	\text{FOR\_LOOP} &\rightarrow \text{STMT for id in id}
\end{align}
```

# While loop

```math
\begin{align}
	\text{WHILE\_LOOP} &\rightarrow \text{STMT while EXPR}
\end{align}
```

# Builtins

```math
\begin{align}
	\text{PRINT\_STMT} &\rightarrow \text{print EXPR}
	\text{INPUT\_STMT} &\rightarrow \text{input}
	\text{SET_FILE} &\rightarrow 
	\begin{cases}
		\text{setfin const::string}, \\
		\text{setfout const::string}, \\
		\text{setfin stdin}, \\
		\text{setfout stdout} \\
	\end{cases} \\
	\text{CLEAR_FILE} &\rightarrow \text{clearf}
\end{align}
```
