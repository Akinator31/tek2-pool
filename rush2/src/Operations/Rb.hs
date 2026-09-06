{-
-- EPITECH PROJECT, 2026
-- G-PDG-300-TLS-3-1-RUSH2
-- File description:
-- RB OP
-}

module Operations.Rb where

rb :: ([Int], [Int]) -> ([Int], [Int])
rb (a, []) = (a, [])
rb (a, [x]) = (a, [x])
rb (a, x:xs) = (a, xs ++ [x])
