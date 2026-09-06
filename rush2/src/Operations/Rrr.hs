{-
-- EPITECH PROJECT, 2026
-- G-PDG-300-TLS-3-1-RUSH2
-- File description:
-- RRR OP
-}

module Operations.Rrr where
import Operations.Rra (rra)
import Operations.Rrb (rrb)

rrr :: ([Int], [Int]) -> ([Int], [Int])
rrr (a, b) = rrb (rra (a, b))
