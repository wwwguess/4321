// Room: /d/suzhou/chufan.c
//by dwolf 
//97.11.5

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",MAG"厨房"NOR);
	set("long", @LONG
这是镖局的厨房,中间一张奇长无比的吃饭桌，上面摆著几盘菜一看就是镖局弟子吃饭
(chifan)的地方。
LONG
	);

	set("exits", ([
		"west"  :__DIR__"bjhyuan.c",
	]));

	setup();
}

void init()
{
        add_action("do_chifan", "chifan");

}

int do_chifan()
{
	object me;
	me = this_player();

	if( !me->query("mark/镖局") ) 
		return notify_fail("你不是镖局中人，想白吃啊？\n");
	
	me->start_busy(5);
	write(YEL "你坐下来饱饱地大吃了一顿\n" NOR);
	write(YEL "直吃得肚肥肠满才心满意足地站起身来\n" NOR);	
	me->set("food",350);
	me->set("water",350);
		return 1;
}
