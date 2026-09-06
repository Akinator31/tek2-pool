{-
-- EPITECH PROJECT, 2026
-- G-PDG-300-TLS-3-1-PDGRUSH2-3
-- File description:
-- ProcedeFunc
-}

module ProcedeFunc where
import Data.Maybe (catMaybes)
import qualified Data.Map as M
import Data.Functor.Contravariant (Op)
import Lib
import Data.Tuple (swap)

formatList :: [Maybe Int] -> ([Int], [Int])
formatList a = (catMaybes a, [])

opFuncs :: M.Map String (([Int], [Int]) -> ([Int], [Int]))
opFuncs = M.fromList
  [
    ("sa", sa), ("sb", sb), ("sc", sc),
    ("pa", pa), ("pb", pb), ("ra", ra), 
    ("rb", rb), ("rr", rr), ("rra", rra),
    ("rrb", rrb), ("rrr", rrr)
  ]

procedeOp :: [String] -> ([Int], [Int]) -> Maybe ([Int], [Int])
procedeOp [] a = Just a
procedeOp (op:ops) a = case M.lookup op opFuncs of
  Nothing -> Nothing
  Just f -> procedeOp ops (f a)
