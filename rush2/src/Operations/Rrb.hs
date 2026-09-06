{-
-- EPITECH PROJECT, 2026
-- G-PDG-300-TLS-3-1-RUSH2
-- File description:
-- RRB OP
-}

module Operations.Rrb where

rrb :: ([Int], [Int]) -> ([Int], [Int])
rrb (a, []) = (a, [])
rrb (a, [b]) = (a, [b])
rrb (a, b) = (a, last b : init b)
