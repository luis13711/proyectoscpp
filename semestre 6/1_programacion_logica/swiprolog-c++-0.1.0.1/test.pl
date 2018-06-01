% samelength(?L1,?L2)
% if L1 and L2 arguments are lists with the same length
samelength([], []).
samelength([_|Xs], [_|Ys]) :-
        samelength(Xs, Ys).

% permutation(?L1, ?L2)
% if L1 and L2 are permutations of each other
permutation([], []).
permutation(L1, L2) :-
        L1 = [X|Xs],
        samelength(L1, L2),
        append(Anf, [X|Ende], L2),
        append(Anf, Ende, L2ohne),
        permutation(Xs, L2ohne).

permutation_0(L1, L2) :-
        writel(['L1 = ', L1, ', L2 = ', L2]),
        permutation(L1, L2),
        writel(['L1 = ', L1, ', L2 = ', L2]).


writel(Xs) :-
        writel_1(Xs),
        nl.
writel_1([]).
writel_1([X|Xs]) :-
        write(X),
        writel_1(Xs).


fptest :-
        fopre(a(b,c), 55).


one_result('one result').
