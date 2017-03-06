// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","饭堂");
	set("long", @LONG
	一个大饭堂,中间一张奇长无比的吃饭桌，上面摆著几盘菜
一看就是普通教众吃饭(chifan)的地方.�
LONG
	);

	set("exits", ([
		"east"  :__DIR__"dingfeng5.c",
	]));

	setup();
}

void init()
{
        add_action("do_chifan", "chifan");

}

int do_chifan()
{
	this_player()->start_busy(5);
	write(YEL "你坐下来饱饱地大吃了一顿\n" NOR);
	write(YEL "直吃得肚肥肠满才心满意足地站起身来\n" NOR);	
	this_player()->set("food",350);
	this_player()->set("water",350);
	return 1;
}
