// zoulang.c ����
// by yuer


#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	������һ�������ϣ����������м������ң��������������֡������Ǵ�
LONG
	);

	
	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"dadian",
		"west" : __DIR__"zoulang1",
		"east" : __DIR__"zoulang2",		     
	]));
      set("objects",([
		CLASS_D("mingjiao") + "/weiyixiao.c" : 1,
            ]));

	setup();
}


