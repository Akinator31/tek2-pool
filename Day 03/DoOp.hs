{-
-- EPITECH PROJECT, 2026
-- day3
-- File description:
-- day3
-}

import Data.Binary.Get (isEmpty)
import Data.Char (isDigit)
import Data.Maybe (isNothing)

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

myLength :: [a] -> Int
myLength [] = 0
myLength (_ : a) = 1 + myLength (a)

myElem :: (Eq a) => a -> [a] -> Bool
myElem a [] = False
myElem a (x : xs)
  | a == x = True
  | otherwise = myElem a xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv x y
  | y /= 0 = Just (div x y)
  | otherwise = Nothing

safeNth :: [a] -> Int -> Maybe a
safeNth [] number = Nothing
safeNth (x : xs) number =
  if number == 0
    then Just x
    else safeNth xs (number - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc = fmap (+ 1)

myLookup :: (Eq a) => a -> [(a, b)] -> Maybe b
myLookup a [] = Nothing
myLookup element (x : xs)
  | element == myFst x = Just (mySnd x)
  | otherwise = myLookup element xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo func _ Nothing = Nothing
maybeDo func Nothing _ = Nothing
maybeDo func (Just a) (Just b) = Just (func a b)

maybeDo2 :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo2 func a b =
  a >>= \valA ->
    b >>= \valB ->
      return (func valA valB)

maybeDo3 :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo3 func a b = do
  val1 <- a
  val2 <- b
  return (func val1 val2)

maybeDo4 :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo4 func a b = func <$> a <*> b

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

getLineLength :: IO Int
getLineLength = myLength <$> getLine

printAndGetLength :: String -> IO Int
printAndGetLength string = putStrLn string >> return (myLength string)

printMiddle :: Int -> Char -> IO ()
printMiddle nbChar char
  | nbChar /= 0 = putStr [char] >> printMiddle (nbChar - 1) char
  | otherwise = return ()

printLines :: Int -> Int -> IO ()
printLines n 1 =
  putStr ['+']
    >> printMiddle (n * 2 - 2) '-'
    >> putStrLn ['+']
printLines n i
  | n == i =
      putStr ['+'] >> printMiddle (n * 2 - 2) '-' >> putStrLn ['+']
        >> printLines n (i - 1)
  | otherwise = putStr ['|'] >> printMiddle (n * 2 - 2) ' '
        >> putStrLn ['|']
        >> printLines n (i - 1)

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox size
  | size <= 0 = return ()
  | otherwise = printLines size size

concatLines :: Int -> IO String
concatLines n = if n == 0 then return "" else getLine <> concatLines (n - 1)

getInt :: IO (Maybe Int)
getInt = readInt <$> getLine
