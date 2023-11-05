```math
\begin{align}
START \rightarrow STMT
STMT \rightarrow \$
STMT \rightarrow STMT STMT

STMT \rightarrow ASMT
ASMT \rightarrow VAR := EXPR

STMT \rightarrow EXPR

EXPR \rightarrow (EXPR)
	EXPR \rightarrow EXPR BIN_OPER EXPR
	EXPR \rightarrow UN_OPER EXPR

	\begin{equation}
	\text{UN_OPER} \rightarrow
	\begin{cases}
	-, ~
	\end{cases}
	\end{equation}

	\begin{equation}
	\text{BIN_OPER} \rightarrow
	\begin{cases}
	+, - , *, /, =, >, <, >=, <=, ~=, %
	\end{cases}
	\end{equation}
\end{align}
	$$
```
