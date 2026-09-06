{-
-- EPITECH PROJECT, 2026
-- rush2
-- File description:
-- rush2
-}

import Data.Char (isDigit)
import Data.Maybe (fromJust, isNothing)
import GHC.IO.Exception (ExitCode (ExitFailure))
import Lib
import ProcedeFunc (formatList, procedeOp)
import System.Environment (getArgs)
import System.Exit (exitWith)
import System.IO (hPutStrLn, stderr)
import Text.Read (readMaybe)

procedeResult :: ([Int], [Int]) -> IO ()
procedeResult a =
  if (snd a /= []) || myQuickSort (<) (fst a) /= fst a
    then
      putStrLn ("KO: " ++ show a) >> exitWith (ExitFailure 84)
    else
      putStrLn "OK"

main :: IO ()
main = do
  input <- getArgs
  stdinput <- getLine
  let pushswap_ops = words stdinput
  let formatedInput = checkInput input
  if length formatedInput /= length input
    then exitWith (ExitFailure 84)
    else
      maybe (exitWith (ExitFailure 84))
      procedeResult (procedeOp pushswap_ops (formatList formatedInput))
