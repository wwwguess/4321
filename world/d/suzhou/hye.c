//ROOM:/d/suzhou/hye.c
//by dwolf
//97.11.4 

#include <ansi.h>
inherit ROOM;

string* npcs = ({
        "xiaolu",
        "yetu",
        "xiaohou",
});


void create()
{
	int i = random(sizeof(npcs));

	set("short", MAG"��Ұ"NOR);
	set("long", @LONG
��������������Ļ�Ұ��Զ����ɽ��ɽ�嶸�ͣ��������ơ�����һЩСҰ��������ȥ��
ʮ������ϲ����ͻȻһֻС¹������������������ס��ץס����	
LONG
	);
	set("outdoors", "suzhou");

	set("exits", ([
		"north" : __DIR__"sgate",
                "southeast" : "/d/quanzhou/qzroad1",
	]));

        set("objects", ([
	__DIR__"npc/"+npcs[i] : 1]));
                                    

	setup();
}

