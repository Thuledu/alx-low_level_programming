#!/usr/bin/python3

def island_perimeter(grid):
    """
    Returns the perimeter of the island described in the grid.

    Args:
    grid (list of list of integers): Represents the island grid where 0 is water and 1 is land.

    Returns:
    int: The perimeter of the island.

    Constraints:
    - Grid cells are connected horizontally/vertically (not diagonally).
    - Grid is rectangular, with width and height not exceeding 100.
    - Grid is completely surrounded by water, and there is one island (or nothing).
    - The island doesn’t have "lakes" (water inside that isn’t connected to the water around the island).
    """

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i-1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j-1] == 1:
                    perimeter -= 2

    return perimeter
