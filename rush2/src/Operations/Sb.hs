{-
-- EPITECH PROJECT, 2026
-- G-PDG-300-TLS-3-1-RUSH2
-- File description:
-- SB OP
-}

module Operations.Sb where

sb :: ([Int], [Int]) -> ([Int], [Int])
sb (a, []) = (a, [])
sb (a, [x]) = (a, [x])
sb (a, x:y:xs) = (a, y:x:xs)
