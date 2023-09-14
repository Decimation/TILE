/*
 *--------------------------------------
 * Program Name:
 * Author:
 * License:
 * Description:
 *--------------------------------------
*/

#include <ti/vars.h>
#include <ti/real.h>
#include <ti/getkey.h>
#include <ti/screen.h>
#include <stdio.h>
#include <string.h>
#include <ti/debug.h>
#include <debug.h>
#include <tice.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <assert.h>
#include <debug.h>

#define dbg_w(s, ...) dbg_sprintf(dbgout,s, ##__VA_ARGS__)

int main(void)
{
	int ret;

	os_ClrHome();
	dbg_ClearConsole();

	size_t sz;
	if (os_GetVarSize(OS_VAR_L1, &sz)){

	}

	for (int i = 0; i < sz; ++i) {
		real_t r;

		os_GetRealListElement(OS_VAR_L1,i, &r);
		dbg_w("%d %d\n",i,r);
	}

	dbg_w("%d\n",sz);

	ret = os_EvalVar(OS_VAR_Y1);

	if (ret == 0)
	{
		uint8_t type;
		void *ans;

		ans = os_GetAnsData(&type);
		if (ans != NULL && type == OS_TYPE_REAL)
		{
			real_t *real = ans;

			printf("result: %f\n", os_RealToFloat(real));
		}
	}

	if (ret == 0)
	{
		real_t real = os_FloatToReal(2.0);

		ret = os_SetRealVar(OS_VAR_A, &real);
	}

	if (ret == 0)
	{
		/* Tokenized representation of "A+A" */
		const char expression[] = "\x41\x70\x41";

		ret = os_Eval(expression, sizeof expression);
	}

	if (ret == 0)
	{
		uint8_t type;
		void *ans;

		ans = os_GetAnsData(&type);
		if (ans != NULL && type == OS_TYPE_REAL)
		{
			real_t *real = ans;

			printf("result: %f\n", os_RealToFloat(real));
		}
	}

	os_GetKey();

	return ret;
}


static void printText(const char* text, uint8_t xpos, uint8_t ypos)
{
	os_SetCursorPos(ypos, xpos);
	os_PutStrFull(text);
}
