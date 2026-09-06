{-
-- EPITECH PROJECT, 2026
-- G-PDG-300-TLS-3-1-RUSH2
-- File description:
-- RRA OP
-}

module Operations.Rra where

rra :: ([Int], [Int]) -> ([Int], [Int])
rra ([], b) = ([], b)
rra ([x], b) = ([x], b)
rra (a, b) = (last a : init a, b)
