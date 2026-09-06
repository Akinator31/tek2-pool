{-
-- EPITECH PROJECT, 2026
-- G-PDG-300-TLS-3-1-RUSH2
-- File description:
-- SA OP
-}

module Operations.Sa where

sa :: ([Int], [Int]) -> ([Int], [Int])
sa ([], b) = ([], b)
sa ([x], b) = ([x], b)
sa (x:y:xs, b) = (y:x:xs, b)
