/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_rpn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:10:47 by mdebbi            #+#    #+#             */
/*   Updated: 2019/03/16 21:30:42 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"


int get_size(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    return (i);

}

int priority_check(char op1, char op2)
{
    if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/' || op2 == '%'))
        return (-1);
    else if((op1 == '*' || op1 == '/' || op1 == '%') && (op2 == '*' || op2 == '/' || op2 == '%'))
        return (0);
    else if((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-'))
        return (0);
    else
        return(1);

    
}


char **exp_to_rpn(char **exp)
{
    int i = 0;
    char **rpn = malloc(sizeof(char *) * (get_size(exp) + 1));
    char **opstack = malloc(sizeof(char *) * get_size(exp));
    int sp = 0;//stack pointer
    while (*exp)
    {
        if((*exp[0] >='0' && *exp[0] <= '9') || (*exp[0] == '-' && *(*exp + 1) != '\0'))
            rpn[i++] = *exp;
        else
        {
            if(*exp[0] == ')')
                while(opstack[--sp][0] != '(')
                    rpn[i++] = opstack[sp];
            else if(sp == 0 || *exp[0] == '(')
                opstack[sp++] = *exp;
            else if (priority_check(*exp[0],opstack[sp-1][0]) <= 0)
            {
                    while((sp > 0 && priority_check(*exp[0],opstack[sp-1][0]) <= 0))
                        rpn[i++] = opstack[sp-- -1];
                    opstack[sp++] = *exp;
            }
            else
                    opstack[sp++] = *exp;
        }
        exp++;
    }
    while (--sp >= 0)
        rpn[i++] = opstack[sp];
    rpn[i] = 0;
    return (rpn);
}
