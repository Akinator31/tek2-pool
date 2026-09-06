{-
-- EPITECH PROJECT, 2026
-- day3
-- File description:
-- day3
-}

data Item = Sword | Bow | MagicWand deriving (Eq)

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

data Mob = Mummy | Skeleton Item | Witch (Maybe Item) deriving (Eq)

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create mob =
    case mob of
        "mummy" -> Just createMummy
        "doomed archer" -> Just createArcher
        "dead knight" -> Just createKnight
        "witch" -> Just createWitch
        "sorceress" -> Just createSorceress
        _ -> Nothing

equip :: Item -> Mob -> Maybe Mob
equip item mob =
    case mob of
        Skeleton i -> Just (Skeleton item)
        Witch i -> Just (Witch (Just item))
        _ -> Nothing

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton item) = "skeleton holding a " ++ show item
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just item))= "witch holding a " ++ show item

class HasItem object where
    getItem :: object -> Maybe Item
    hasItem :: object -> Bool
    hasItem object =
        case getItem object of
            Just object -> True
            Nothing -> False

instance HasItem Mob where
    getItem mob =
        case mob of
            Mummy -> Nothing
            Skeleton item -> Just item
            Witch Nothing -> Nothing
            Witch (Just item) -> Just item
