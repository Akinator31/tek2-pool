{-
-- EPITECH PROJECT, 2026
-- wolf3d
-- File description:
-- wolf3d
-}

module Operations.Pb where

import Utils.My (myAppend)

pb :: ([Int], [Int]) -> ([Int], [Int])
pb ([], []) = ([], [])
pb ([], [b]) = ([], [b])
pb (first : l_a, l_b) = (l_a, myAppend [first] l_b)
