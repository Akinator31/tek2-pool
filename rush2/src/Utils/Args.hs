{-
-- EPITECH PROJECT, 2026
-- wolf3d
-- File description:
-- wolf3d
-}

module Utils.Args (checkInput) where

import Data.Maybe (isNothing)
import Text.Read (readMaybe)

stringToInt :: String -> Maybe Int
stringToInt = readMaybe

checkInput :: [String] -> [Maybe Int]
checkInput [] = []
checkInput (x : xs) =
  let parsed = stringToInt x
   in if isNothing parsed
        then []
        else parsed : checkInput xs
