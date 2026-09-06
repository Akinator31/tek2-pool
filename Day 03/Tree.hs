{-
-- EPITECH PROJECT, 2026
-- day3
-- File description:
-- day3
-}

data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree value tree =
    case tree of
        Empty -> Node Empty value Empty
        Node left v right
            | value < v -> Node (addInTree value left) v right
            | value >=v -> Node left v (addInTree value right)

instance Functor Tree where
    fmap func tree =
        case tree of
            (Node left value right) -> Node (fmap func left) (func value) (fmap func right)
            Empty -> Empty

listToTree :: Ord a => [a] -> Tree a
listToTree list = foldl (\acc x -> addInTree x acc) Empty list

treeToList :: Tree a -> [a]
treeToList tree =
    case tree of
        Empty -> []
        (Node Empty value Empty) -> [value]
        (Node left value right) ->
            treeToList left ++ [value] ++  treeToList right

treeSort :: Ord a => [a] -> [a]
treeSort list = treeToList (listToTree list)

instance Foldable Tree where
    foldr func bag Empty = bag
    foldr func bag (Node left value right) = foldr func (func value (foldr func bag right)) left

    foldl func bag Empty = bag
    foldl func bag (Node left value right) = foldl func (func (foldl func bag right) value) left
