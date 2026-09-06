{-
-- EPITECH PROJECT, 2026
-- G-PDG-300-TLS-3-1-RUSH2
-- File description:
-- RB OP
-}

module Operations.Rr where
import Operations.Ra
import Operations.Rb

rr :: ([Int], [Int]) -> ([Int], [Int])
rr (a, b) = rb (ra(a, b))
