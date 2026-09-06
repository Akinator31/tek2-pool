{-
-- EPITECH PROJECT, 2026
-- wolf3d
-- File description:
-- wolf3d
-}

module Utils.My where

myAppend :: [a] -> [a] -> [a]
myAppend [] b = b
myAppend (a : b) c = a : myAppend b c

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter f [] = []
myFilter f (a : b)
  | f a = a : myFilter f b
  | otherwise = myFilter f b

myFilterInvert :: (a -> Bool) -> [a] -> [a]
myFilterInvert f [] = []
myFilterInvert f (a : b)
  | not (f a) = a : myFilterInvert f b
  | otherwise = myFilterInvert f b

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition f a = (myFilter f a, myFilterInvert f a)

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort f [] = []
myQuickSort f (a : b) =
  let test = myPartition (f a) b
      smaller = myQuickSort f (mySnd test)
      bigger = myQuickSort f (myFst test)
   in myAppend (myAppend smaller [a]) bigger
