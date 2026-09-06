{-
-- EPITECH PROJECT, 2026
-- doop
-- File description:
-- doop
-}

import System.Exit (exitWith)
import GHC.IO.Exception (ExitCode (ExitFailure))
import GHC.Unicode (isDigit)
import Data.Maybe (isNothing)
import System.Environment (getArgs)

isStringDigit :: [Char] -> Int -> Int -> Bool
isStringDigit [] _ _ = True
isStringDigit ('-' : xs) 0 0 = isStringDigit xs 1 0
isStringDigit ('-' : xs) _ _ = False
isStringDigit (x : xs) signNumber digitNumber
  | isDigit x = isStringDigit xs signNumber (digitNumber + 1)
  | otherwise = False

readInt :: [Char] -> Maybe Int
readInt string
  | null string = Nothing
  | isStringDigit string 0 0 = Just (read string :: Int)
  | otherwise = Nothing

computeOperation :: Int -> String -> Int -> IO ()
computeOperation fst ops snd =
    case ops of
        "+" -> print (fst + snd)
        "-" -> print (fst - snd)
        "*" -> print (fst * snd)
        "/" | snd /= 0 -> print (div fst snd)
        "%" | snd /= 0 -> print (mod fst snd)
        _ -> exitWith (ExitFailure 84)

doop :: [String] -> IO ()
doop [a, b, c] =
  case (readInt a, readInt c) of
    (Just a, Just c) -> computeOperation a b c
    _ -> exitWith (ExitFailure 84)
doop list = exitWith (ExitFailure 84)

main :: IO ()
main = do
  args <- getArgs
  doop args
