```math
\begin{align}
\text{START} \rightarrow \text{STMT}
\text{STMT} \rightarrow \$
\text{STMT} \rightarrow \text{STMT} \text{STMT}

\text{STMT} \rightarrow \text{ASMT}
\text{ASMT} \rightarrow VAR := \text{EXPR}

\text{STMT} \rightarrow \text{EXPR}

\text{EXPR} \rightarrow (\text{EXPR})
	\text{EXPR} \rightarrow \text{EXPR} \text{BIN_OPER} \text{EXPR}
	\text{EXPR} \rightarrow \text{UN_OPER} \text{EXPR}

	\begin{equation}
	\text{\text{UN_OPER}} \rightarrow
	\begin{cases}
	-, ~
	\end{cases}
	\end{equation}

	\begin{equation}
	\text{\text{BIN_OPER}} \rightarrow
	\begin{cases}
	+, - , *, /, =, >, <, >=, <=, ~=, %
	\end{cases}
	\end{equation}
\end{align}
	$$
```
