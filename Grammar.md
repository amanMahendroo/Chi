```math
\begin{align}
	\text{START} &\rightarrow \text{STMT} \\
	\text{STMT} &\rightarrow \begin{cases}
		\text{STMT STMT} \\
		\text{\$} \\
		\text{ASMT} \\
		\text{EXPR} \\
	\end{cases} \\
	\text{EXPR} &\rightarrow \begin{cases}
		\text{(EXPR)} \\
		\text{UN\_OPER EXPR} \\
		\text{EXPR BIN\_OPER EXPR}
	\end{cases}  \\
	\text{ASMT} &\rightarrow VAR := \text{EXPR} \\
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
