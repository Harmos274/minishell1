/*
** EPITECH PROJECT, 2018
** my_compute_power_rec.c
** File description:
** powerec
*/

int my_compute_power_rec (int nb, int p)
{
    int r = 1;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    r = nb * my_compute_power_rec(nb, (p - 1));
    if ((nb > 0 && r < 0) || (nb < 0 && p % 2 == 0 && r < 0))
        return (0);
    return (r);
}
