{-
-- EPITECH PROJECT, 2026
-- my
-- File description:
-- my
-}

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x | x >= 0 = x
        | otherwise = -x

myMin :: Int -> Int -> Int
myMin x y | x < y = x
          | otherwise = y

myMax :: Int -> Int -> Int
myMax x y | x > y = x
          | otherwise = y

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "List can't be empty"
myHead (a:_) = a

myTail :: [a] -> [a]
myTail [] = error "List can't be empty"
myTail (_:a) = (a)

myLength :: [a] -> Int
myLength [] = 0
myLength (_:a) = 1 + myLength (a)

myNth :: [a] -> Int -> a
myNth [] x = error "List can't be empty"
myNth a x
    | x > myLength a = error "Index is out of range"
    | myIsNeg x = error "Index can't be negative"
myNth (a:_) 0 = a
myNth (_:a) x = myNth a (x - 1)

myTake :: Int -> [a] -> [a]
myTake x a
    | myIsNeg x = error "Index can't be negative"
    | x >= myLength a = a
myTake 0 _ = []
myTake x (a:b) = a : myTake (x - 1) b

myDrop :: Int -> [a] -> [a]
myDrop x a
    | myIsNeg x = error "Index can't be negative"
    | x >= myLength a = []
myDrop 0 a = a
myDrop x (_:b) = myDrop (x - 1) b

myAppend :: [a] -> [a] -> [a]
myAppend [] b = b
myAppend (a:b) c = a : myAppend b c

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:b) = myAppend (myReverse b) [a]

myInit :: [a] -> [a]
myInit [] = error "List can't be empty"
myInit (a) = myTake ((myLength (a)) - 1) a

myLast :: [a] -> a
myLast [] = error "List can't be empty"
myLast a = myHead (myDrop ((myLength (a)) - 1) a)

myZip :: [a] -> [b] -> [(a, b)]
myZip _ [] = []
myZip [] _ = []
myZip (a:b) (c:d) = (a,c) : myZip b d

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((a,b):xs) = (a: (myFst(myUnzip xs)), b: (mySnd(myUnzip xs)))

myMap :: (a -> b) -> [a] -> [b]
myMap f [] = []
myMap f (a:b) = f (a) : myMap f b

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter f [] = []
myFilter f (a:b)
    | f (a) == True = a : myFilter f b
    | otherwise = myFilter f b

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl f b [] = b
myFoldl f b (a:c) = (myFoldl f (f b a) c)

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr f b [] = b
myFoldr f b (a:c) = f a (myFoldr f b c)

myFilterInvert :: (a -> Bool) -> [a] -> [a]
myFilterInvert f [] = []
myFilterInvert f (a:b)
    | f (a) == False = a : myFilterInvert f b
    | otherwise = myFilterInvert f b

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition f a = (myFilter f a, myFilterInvert f a)

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort f [] = []
myQuickSort f (a:b) =
    let test = myPartition (f a) b
        smaller = myQuickSort f (mySnd test)
        bigger = myQuickSort f (myFst test)
    in myAppend (myAppend smaller [a]) bigger
