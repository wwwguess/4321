// forest1.c
//by dwolf
//97.11.8
             
#include <ansi.h>
inherit ROOM; 

string* npcs = ({
        "pig",
        "snake",
        "tiger",
});

void create()
{       

	int i = random(sizeof(npcs));
	set("short", BLK"ɭ��"NOR);
	set("long", @LONG
	  �����һ�ж��Ǿ�ֹ�ģ�����ҶҲ��ֹ������������������һ��������Ϣ
���������һ�оɵ�·���ƣ���������ҵ�·ʱ��ȴ������ָ�ŵأ��ǲ���Ԥʾ��ÿ
һ����������˶������������
LONG
	);

	set("exits", ([
		"east" : __DIR__"forest2.c",
		"south"	: __DIR__"forest2.c",
		"west" : __DIR__"forest3.c", 
		"north" : __DIR__"start.c",
	]));  

	set("objects", ([  
		__DIR__"npc/"+npcs[i] : 1]));
	setup();   
}
