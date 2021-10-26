/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:53:17 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/08 17:50:39 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_GAME_H
# define KEYS_GAME_H

# ifdef __linux__

#  define KEY_ESC 65307
#  define KEY_TAB 64289
#  define KEY_SPC 32
#  define KEY_ENTER 65293
#  define KEY_BCKSPC 65288
#  define KEY_LSHIFT 65505
#  define KEY_LCTRL 65507
#  define KEY_LOPT_ALT 65513
#  define KEY_RSHIFT 65506
#  define KEY_RCTRL 65508
#  define KEY_ROPT_ALT 65514
#  define KEY_1 49
#  define KEY_2 50
#  define KEY_3 51
#  define KEY_4 52
#  define KEY_5 53
#  define KEY_6 54
#  define KEY_7 55
#  define KEY_8 56
#  define KEY_9 57
#  define KEY_0 48
#  define KEY_MINUS 45
#  define KEY_EQ 61
#  define KEY_A 97
#  define KEY_B 98
#  define KEY_C 99
#  define KEY_D 100
#  define KEY_E 101
#  define KEY_F 102
#  define KEY_G 103
#  define KEY_H 104
#  define KEY_I 105
#  define KEY_J 106
#  define KEY_K 107
#  define KEY_L 108
#  define KEY_M 109
#  define KEY_N 110
#  define KEY_O 111
#  define KEY_P 112
#  define KEY_Q 113
#  define KEY_R 114
#  define KEY_S 115
#  define KEY_T 116
#  define KEY_U 117
#  define KEY_V 118
#  define KEY_W 119
#  define KEY_X 120
#  define KEY_Y 121
#  define KEY_Z 122

# else
#  ifdef __APPLE__

#   define KEY_ESC 53
#   define KEY_TAB 48
#   define KEY_SPC 49
#   define KEY_ENTER 36
#   define KEY_BCKSPC 51
#   define KEY_LSHIFT 257
#   define KEY_LCTRL 256
#   define KEY_LOPT_ALT 261
#   define KEY_RSHIFT 258
#   define KEY_RCTRL 269
#   define KEY_ROPT_ALT 262
#   define KEY_1 18
#   define KEY_2 19
#   define KEY_3 20
#   define KEY_4 21
#   define KEY_5 23
#   define KEY_6 22
#   define KEY_7 26
#   define KEY_8 28
#   define KEY_9 25
#   define KEY_0 29
#   define KEY_MINUS 27
#   define KEY_EQ 24
#   define KEY_A 0
#   define KEY_B 11
#   define KEY_C 8
#   define KEY_D 2
#   define KEY_E 14
#   define KEY_F 3
#   define KEY_G 5
#   define KEY_H 4
#   define KEY_I 34
#   define KEY_J 38
#   define KEY_K 40
#   define KEY_L 37
#   define KEY_M 46
#   define KEY_N 45
#   define KEY_O 31
#   define KEY_P 35
#   define KEY_Q 12
#   define KEY_R 15
#   define KEY_S 1
#   define KEY_T 17
#   define KEY_U 32
#   define KEY_V 9
#   define KEY_W 13
#   define KEY_X 7
#   define KEY_Y 16
#   define KEY_Z 6

#  endif
# endif
#endif