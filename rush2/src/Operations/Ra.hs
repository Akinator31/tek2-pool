{-
-- EPITECH PROJECT, 2026
-- G-PDG-300-TLS-3-1-RUSH2
-- File description:
-- RA OP
-}

module Operations.Ra where

ra :: ([Int], [Int]) -> ([Int], [Int])
ra ([], b) = ([], b)
ra ([a], b) = ([a], b)
ra (a:ab, b) = (ab ++ [a], b)
