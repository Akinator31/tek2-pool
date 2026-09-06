{-
-- EPITECH PROJECT, 2026
-- G-PDG-300-TLS-3-1-RUSH2
-- File description:
-- SC OP
-}

module Operations.Sc where
import Operations.Sb (sb)
import Operations.Sa (sa)

sc :: ([Int], [Int]) -> ([Int], [Int])
sc (a, b) = sb (sa (a, b))
