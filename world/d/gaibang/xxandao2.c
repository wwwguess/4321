// Room: /d/gaibang/xxandao2.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�� �������ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG
	);

	set("exits", ([
			"west" : __DIR__"underxx",
			"east" : __DIR__"xxandao1",
	]));

        set("objects",([
                CLASS_D("gaibang") + "/jiang-sh" : 1,
        ]));
	setup();
	replace_program(ROOM);
}



