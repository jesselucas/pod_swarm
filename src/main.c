#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pd_api.h"

static PlaydateAPI *pd = NULL;
int update(void *);

int
eventHandler(PlaydateAPI *playdate, PDSystemEvent event, uint32_t arg)
{
	if (event == kEventInit) {
		pd = playdate;
		playdate->display->setRefreshRate(30);
		playdate->system->setUpdateCallback(update, NULL);
		// font =
		// pd−>graphics−>loadFont(”/System/Fonts/Asheville−Sans−14−Bold.pft”,
		// NULL);
		// pd−>graphics−>setFont(font);
	}

	return 0;
}

int
update(void *ud)
{
	printf("%lu\n", (uint64_t)ud);
	// pd->sprite->updateAndDrawSprites();
	pd->graphics->clear(kColorWhite);
	pd->graphics->drawText("Hello World!", strlen("Hello World!"),
			       kASCIIEncoding, 100, 100);
	pd->system->drawFPS(0, 0);
	return 1;
}
