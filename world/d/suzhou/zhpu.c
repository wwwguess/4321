//ROOM: d/suzhou/zhpu.c
// by dwolf
//97.11.4

#include <ansi.h>
inherit ROOM;    

string look_zhaopai();

void create()
{
	set("short", MAG"�ӻ���"NOR);
	set("long", @LONG
	    ����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ������
�������������һֻ�����ϣ��к��Ź������ˡ�̯������һ������(zhaopai)��
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"north" : __DIR__"wroad4",
	]));
	set("objects", ([
		__DIR__"npc/lwliang" : 1,
]));                  
	set("item_desc", ([
		"zhaopai" : (: look_zhaopai :),
]));
	setup();
}      

string look_zhaopai()
{
	return "��ӭ���١����̳�ʵ������";
}





