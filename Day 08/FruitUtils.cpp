/*
** EPITECH PROJECT, 2026
** FruitUtils
** File description:
** FruitUtils
*/

#include "FruitUtils.hpp"
#include "ABerry.hpp"
#include "ACitrus.hpp"
#include "IFruit.hpp"
#include "Lemon.hpp"
#include <cstddef>
#include <cstdio>
#include <vector>

void FruitUtils::sort(FruitBox& unsorted, FruitBox& lemon, FruitBox& citrus, FruitBox& berry) {
    std::vector<IFruit*> unsorted_fifo = unsorted.getFifo();

    for (size_t i = 0; i < unsorted_fifo.size(); i++)
        unsorted.popFruit();

    for (std::size_t i = 0; i < unsorted_fifo.size(); i++) {
        Lemon* lemon_fruit = dynamic_cast<Lemon*>(unsorted_fifo[i]);

        if (lemon_fruit) {
            if (!lemon.pushFruit(lemon_fruit))
                unsorted.pushFruit(lemon_fruit);
            continue;
        }

        ACitrus* citrus_fruit = dynamic_cast<ACitrus*>(unsorted_fifo[i]);

        if (citrus_fruit) {
            if (!citrus.pushFruit(citrus_fruit))
                unsorted.pushFruit(citrus_fruit);
            continue;
        }

        ABerry* berry_fruit = dynamic_cast<ABerry*>(unsorted_fifo[i]);

        if (berry_fruit) {
            if (!berry.pushFruit(berry_fruit))
                unsorted.pushFruit(berry_fruit);
            continue;
        }
        unsorted.pushFruit(unsorted_fifo[i]);
    }
}

FruitBox** FruitUtils::pack(IFruit** fruits, unsigned int boxSize) {
    FruitBox** result = NULL;
    size_t nb_fruits = 0;
    size_t nb_box = 0;
    int fruit_index = 0;

    if (boxSize == 0 || !fruits)
        return result;
    for (size_t i = 0; fruits[i]; i++)
        nb_fruits += 1;
    nb_box = nb_fruits / boxSize;
    if (nb_box * boxSize < nb_fruits)
        nb_box += 1;

    result = new FruitBox*[nb_box + 1];
    result[nb_box] = NULL;

    for (size_t i = 0; i < nb_box; i++) {
        result[i] = new FruitBox(boxSize);
        for (size_t e = 0; e < boxSize && fruits[fruit_index]; e++) {
            result[i]->pushFruit(fruits[fruit_index]);
            fruit_index += 1;
        }
    }
    return result;
}

IFruit** FruitUtils::unpack(FruitBox** fruitBoxes) {
    int nb_fruits = 0;
    IFruit** result = NULL;
    int fruit_index = 0;

    for (size_t i = 0; fruitBoxes[i]; i++)
        nb_fruits += fruitBoxes[i]->getFifo().size();
    result = new IFruit*[nb_fruits + 1];
    result[nb_fruits] = NULL;

    for (size_t i = 0; fruitBoxes[i]; i++) {
        int fruitBoxSize = fruitBoxes[i]->getFifo().size();
        while (fruitBoxSize != 0) {
            result[fruit_index] = fruitBoxes[i]->popFruit();
            fruitBoxSize -= 1;
            fruit_index += 1;
        }
    }
    return result;
}
