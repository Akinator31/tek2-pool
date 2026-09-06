{-
-- EPITECH PROJECT, 2026
-- wolf3d
-- File description:
-- wolf3d
-}

module Operations.Pa where

import Utils.My (myAppend)

pa :: ([Int], [Int]) -> ([Int], [Int])
pa ([], a) = (a, [])
pa (a, []) = (a, [])
pa (l_a, first : l_b) = (myAppend [first] l_a, l_b)
