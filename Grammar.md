```math
\text{START} \rightarrow \text{STMT}
\text{STMT} \rightarrow \$
\text{STMT} \rightarrow \text{STMT} \text{STMT}

\text{STMT} \rightarrow \text{ASMT}
\text{ASMT} \rightarrow VAR := \text{EXPR}

\text{STMT} \rightarrow \text{EXPR}

\text{EXPR} \rightarrow (\text{EXPR})
	\text{EXPR} \rightarrow \text{EXPR} \text{BIN\_OPER} \text{EXPR}
	\text{EXPR} \rightarrow \text{UN\_OPER} \text{EXPR}

	\begin{equation}
	\text{\text{UN\_OPER}} \rightarrow
	\begin{cases}
	-, ~
	\end{cases}
	\end{equation}

	\begin{equation}
	\text{\text{BIN\_OPER}} \rightarrow
	\begin{cases}
	+, - , *, /, =, >, <, >=, <=, ~=, %
	\end{cases}
	\end{equation}
```
